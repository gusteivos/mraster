#include "raster.h"


int simple_raster_thread_function(void *arg)
{

    if (arg == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return EXIT_FAILURE;

    }

    raster_thread_t *this = (raster_thread_t *)arg;


    while (1)
    {


        if (this->block != NULL && this->block->complete == false)
        {

            double triangle_area = BCT_triangle_area_2d(this->tri_vers[0], this->tri_vers[1], this->tri_vers[2]);


            Uint16 min_x = this->block->beginning.x, max_x = this->block->end.x, min_y = this->block->beginning.y, max_y = this->block->end.y;

            
            for (int32_t y = min_y; y < max_y; y++)
            {

                for (int32_t x = min_x; x < max_x; x++)
                {

                    double alpha, beta, gamma;

                    BCT_area_bct_2d(triangle_area, this->tri_vers[0], this->tri_vers[1], this->tri_vers[2], create_vector_2(x, y), &alpha, &beta, &gamma);

                    if (alpha >= 0 && beta >= 0 && gamma >= 0 && round(alpha + beta + gamma) == 1.0)
                    {

                        set_frame_buffer_rgb(this->fb, x, y, 255, 255, 255);

                    }

                }

            }


            do
            {

                this->block->complete = true;

            } while (this->block->complete == false);
            
        }


        SDL_LockMutex  (this->mutex);

        SDL_UnlockMutex(this->mutex);

    }

    return 0;

}


raster_thread_t *create_raster_thread(SDL_ThreadFunction fn)
{

    raster_thread_t *new_rasthr = NULL;

    if (fn == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        goto endoffunc;

    }



    new_rasthr = (raster_thread_t *)malloc(sizeof(raster_thread_t));

    if (new_rasthr == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        goto endoffunc;

    }


    new_rasthr->block = NULL;

    new_rasthr->fb = NULL;

    new_rasthr->mutex = SDL_CreateMutex();

    new_rasthr->tri_vers = NULL;

    
    new_rasthr->thread = SDL_CreateThread(fn, "rasthr", (void *)new_rasthr);

    if (new_rasthr->thread == NULL)
    {

        SDL_DestroyMutex(new_rasthr->mutex);

        new_rasthr->mutex = NULL;


        free(new_rasthr);

    }    


endoffunc:

    return new_rasthr;

}


bool single_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3])
{


    double triangle_area = BCT_triangle_area_2d(tri_vers[0], tri_vers[1], tri_vers[2]);

    
    /*

        TODO:
            Implement minimum and maximum rasterization limitation.

    */

    Uint16 min_x = 0, max_x = fb->width, min_y = 0, max_y = fb->height;

    
    for (int32_t y = min_y; y < max_y; y++)
    {

        for (int32_t x = min_x; x < max_x; x++)
        {

            double alpha, beta, gamma;

            BCT_area_bct_2d(triangle_area, tri_vers[0], tri_vers[1], tri_vers[2], create_vector_2(x, y), &alpha, &beta, &gamma);

            if (alpha >= 0 && beta >= 0 && gamma >= 0 && round(alpha + beta + gamma) == 1.0)
            {

                set_frame_buffer_rgb(fb, x, y, 255, 255, 255);

            }

        }

    }


    return false;

}


bool multi_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3], raster_thread_t *threads, raster_block_area_t *blocks)
{





    return true;

}



