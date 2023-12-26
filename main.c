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


    raster_thread_t *rt0 = create_raster_thread();
    
    SDL_LockMutex(rt0->pause_mutex);
    
    raster_thread_t *rt1 = create_raster_thread();

    SDL_LockMutex(rt1->pause_mutex);

    raster_thread_t *rt2 = create_raster_thread();
    
    SDL_LockMutex(rt2->pause_mutex);

    raster_thread_t *rt3 = create_raster_thread();

    SDL_LockMutex(rt3->pause_mutex);


    init_raster_thread(rt0, simple_raster_thread_function, "rt0");
    init_raster_thread(rt1, simple_raster_thread_function, "rt1");
    init_raster_thread(rt2, simple_raster_thread_function, "rt2");
    init_raster_thread(rt3, simple_raster_thread_function, "rt3");


    raster_block_area_t rb0 = { true, create_vector_2(0, 0), create_vector_2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)};


    raster_block_area_t rb1 = { true, create_vector_2(WINDOW_WIDTH / 2, 0), create_vector_2(WINDOW_WIDTH, WINDOW_HEIGHT / 2)};

    raster_block_area_t rb2 = { true, create_vector_2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), create_vector_2(WINDOW_WIDTH, WINDOW_HEIGHT)};
    
    raster_block_area_t rb3 = { true, create_vector_2(0, WINDOW_HEIGHT / 2), create_vector_2(WINDOW_WIDTH, WINDOW_HEIGHT)};


    
    raster_block_area_t *blocks[] = { &rb0, &rb1, &rb2, &rb3, NULL };

    raster_thread_t *threads[] = { rt0, rt1, rt2, rt3, NULL };


    while (is_open)
    {

        Uint32 start_tick = SDL_GetTicks();


        SDL_Event event;
        
        while (SDL_PollEvent(&event) != 0)
        {
        
            if (event.type == SDL_QUIT)
            {
            
                is_open = false;
            
            }
        
        }


        fill_frame_buffer_rgb(fb, 0, 0, 0);


        multi_raster_triangle_on_frame_buffer(fb, tri, threads, blocks);


        SDL_Render_frame_buffer(renderer, fb);

        SDL_RenderPresent(renderer);


        Uint32 end_tick = SDL_GetTicks();


        Uint32 delay_time = end_tick - start_tick;

        SDL_Delay((1000 / 30 - (int)delay_time) <= 0 ? 0 : delay_time);

    }


    return EXIT_SUCCESS;

}


#if (defined(_WIN32) || defined(_win32)) && !defined(NDEBUG)

    #include <windows.h>


    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    {

        UNREFERENCED_PARAMETER(hPrevInstance);


        return main(__argc, __argv);

    }

#endif
