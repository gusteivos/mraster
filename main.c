#include "main.h"


bool is_open = false;


SDL_Window *window = NULL;

SDL_Renderer *renderer = NULL;




int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {

        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());


        return EXIT_FAILURE;

    }


    if ((window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
    {

        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());


        return EXIT_FAILURE;

    }

    is_open = true;

    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
    
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());


        return EXIT_FAILURE;
    
    }


    frame_buffer_t *fb = create_frame_buffer(WINDOW_WIDTH, WINDOW_HEIGHT);

    vector_2_t tri[] = { create_vector_2(WINDOW_WIDTH * 0.5, 0), create_vector_2(0, WINDOW_HEIGHT), create_vector_2(WINDOW_WIDTH, WINDOW_HEIGHT) };


    raster_thread_t *rt = create_raster_thread(simple_raster_thread_function);


    raster_block_area_t rb0 = { true, create_vector_2(0, 0), create_vector_2(WINDOW_WIDTH, 360)};

    raster_block_area_t rb1 = { true, create_vector_2(0, 360), create_vector_2(WINDOW_WIDTH, WINDOW_HEIGHT)};

    rt->block = &rb0;

    rt->fb = fb;

    rt->tri_vers = tri;

    SDL_LockMutex(rt->mutex);

    while (is_open)
    {

        SDL_Event event;
        
        while (SDL_PollEvent(&event) != 0)
        {
        
            if (event.type == SDL_QUIT)
            {
            
                is_open = false;
            
            }
        
        }

        fill_frame_buffer_rgb(fb, 0, 0, 0);

        
        /* TEMP: */

            rt->block = &rb0;

            rb0.complete = false;

            SDL_UnlockMutex(rt->mutex);


            while (rb0.complete == false)
            {

            }

            SDL_LockMutex(rt->mutex);

            rt->block = &rb1;

            rb1.complete = false;

            SDL_UnlockMutex(rt->mutex);

            while (rb1.complete == false)
            {
                
            }

            SDL_LockMutex(rt->mutex);



        SDL_Render_frame_buffer(renderer, fb);

        SDL_RenderPresent(renderer);


        SDL_Delay(16);

    }


    return EXIT_SUCCESS;

}


#if (defined(_WIN32) || defined(_win32)) && !defined(NDEBUG)

    #include <windows.h>
    

    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    {

        UNREFERENCED_PARAMETER(hPrevInstance);


        return main(argc, argv);

    }

#endif
