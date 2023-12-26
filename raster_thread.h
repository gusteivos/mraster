
#ifndef RASTER_THREAD_H_
#define RASTER_THREAD_H_

    #include "raster_block_area.h"

    #include "bct.h"
    #include "frame_buffer.h"


    typedef struct raster_thread
    {

        SDL_Thread *thread;

        SDL_mutex  *pause_mutex;
        
        SDL_mutex  *kkill_mutex;

        raster_block_area_t *block;

        SDL_mutex           *block_mutex;


        /* TEMP? */
            frame_buffer_t *fb;

            vector_2_t *tri_vers;



        void *other;

    } raster_thread_t;


    extern raster_thread_t *create_raster_thread(void);

    extern bool init_raster_thread(raster_thread_t *thread, SDL_ThreadFunction fn, char *name);


    extern void free_raster_thread(raster_thread_t *thread);

#endif
