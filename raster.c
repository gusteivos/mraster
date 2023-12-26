#include "raster.h"


int simple_raster_thread_function(void *arg)
{

    if (arg == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return EXIT_FAILURE;

    }

    raster_thread_t *this = (raster_thread_t *)arg;

    
    void **othres = (void **)this->other; /* For the future. */


    while (1)
    {


        int try_block_mutex = SDL_TryLockMutex(this->block_mutex);

        if (try_block_mutex == 0)
        {


            if (this->block != NULL && this->block->completed == false)
            {


                float triangle_area = BCT_triangle_area_2d(this->tri_vers[0], this->tri_vers[1], this->tri_vers[2]);


                Uint16 min_x = this->block->begin.x, max_x = this->block->end.x, min_y = this->block->begin.y, max_y = this->block->end.y;


                for (int32_t y = min_y; y < max_y; y++)
                {

                    for (int32_t x = min_x; x < max_x; x++)
                    {

                        float alpha, beta, gamma;

                        BCT_area(this->tri_vers[0], this->tri_vers[1], this->tri_vers[2], create_vector_2(x, y), &alpha, &beta, &gamma, triangle_area);

                        if (alpha >= 0 && beta >= 0 && gamma >= 0 && round(alpha + beta + gamma) == 1.0f)
                        {

                            set_frame_buffer_rgb(this->fb, x, y, 255, 255, 255);

                        }

                    }

                }


                this->block->completed = true;


            }


            SDL_UnlockMutex(this->block_mutex);

        }
        else if (try_block_mutex == SDL_MUTEX_TIMEDOUT)
        {

            continue;
 
        }
        else
        {

            fprintf(stderr, "Error when trying to lock the block_mutex, thread: %s, error: %s\n", SDL_GetThreadName(this->thread), SDL_GetError());


            return EXIT_FAILURE;

        }


        SDL_LockMutex  (this->pause_mutex);

        SDL_UnlockMutex(this->pause_mutex);


        int try_kkill_mutex = SDL_TryLockMutex(this->kkill_mutex);

        if (try_kkill_mutex == 0)
        {

            SDL_UnlockMutex(this->kkill_mutex);


            break;

        }
        else if (try_kkill_mutex == SDL_MUTEX_TIMEDOUT)
        {

            continue;

        }
        else
        {

            fprintf(stderr, "Error when trying to lock the kkill_mutex, thread: %s, error: %s\n", SDL_GetThreadName(this->thread), SDL_GetError());


            return EXIT_FAILURE;

        }
        
    }


    return EXIT_SUCCESS;

}


bool single_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3])
{


    float triangle_area = BCT_triangle_area_2d(tri_vers[0], tri_vers[1], tri_vers[2]);


    /*

        TODO:
            Implement minimum and maximum rasterization limitation.

    */

    Uint16 min_x = 0, max_x = fb->width, min_y = 0, max_y = fb->height;


    for (int32_t y = min_y; y < max_y; y++)
    {

        for (int32_t x = min_x; x < max_x; x++)
        {

            float alpha, beta, gamma;

            BCT_area(tri_vers[0], tri_vers[1], tri_vers[2], create_vector_2(x, y), &alpha, &beta, &gamma, triangle_area);

            if (alpha >= 0 && beta >= 0 && gamma >= 0 && round(alpha + beta + gamma) == 1.0)
            {

                set_frame_buffer_rgb(fb, x, y, 255, 255, 255);

            }

        }

    }


    return false;

}


bool multi_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3], raster_thread_t *threads[], raster_block_area_t *blocks[])
{

    if (fb == NULL || threads == NULL || blocks == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }


    int current_thread_index = 0;

    int current_block_index = 0;


    raster_block_area_t *current_block = NULL;

    while ((current_block = blocks[current_block_index]) != NULL)
    {

        
        while (true)
        {

            raster_thread_t *current_thread = threads[current_thread_index];

            if (current_thread == NULL)
            {
            
                current_thread_index = 0;

                SDL_Delay(1);


                continue;
            
            }            


            SDL_UnlockMutex(current_thread->pause_mutex);


            if (current_thread->block == NULL || current_thread->block->completed == true)
            {


                SDL_LockMutex(current_thread->pause_mutex);


                current_thread->fb = fb;

                current_thread->tri_vers = tri_vers;


                current_block->completed = false;


                SDL_LockMutex(current_thread->block_mutex);

                current_thread->block = current_block;
    
                SDL_UnlockMutex(current_thread->block_mutex);



                SDL_UnlockMutex(current_thread->pause_mutex);


                break;


            }


            current_thread_index++;

        }
        



        current_block_index++;

    }

    current_thread_index = 0;


    bool all_treads_are_free = true;

    while (true)
    {

        raster_thread_t *current_thread = threads[current_thread_index];


        if (current_thread == NULL)
        {
        
            current_thread_index = 0;


            if (all_treads_are_free == true)
            {
            
                // printf("threads, OKY.\n");
            

                break;
            
            }

            
            all_treads_are_free = true;
            
            continue;
        
        }


        if (current_thread->block != NULL)
        {

            if (current_thread->block->completed == true)
            {

                SDL_LockMutex(current_thread->block_mutex);

                current_thread->block = current_block;
    
                SDL_UnlockMutex(current_thread->block_mutex);


                current_thread->fb = NULL;

                current_thread->tri_vers = NULL;


                SDL_LockMutex(current_thread->pause_mutex);


            }
            else
            {
                
               all_treads_are_free = false;

            }

        }


        current_thread_index++;

    }


    return false;

}
