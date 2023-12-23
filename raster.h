
#ifndef RASTER_H_
#define RASTER_H_

    #include "bct.h"
    #include "frame_buffer.h"


    typedef struct raster_block_area
    {

        bool complete;

        vector_2_t beginning;

        vector_2_t end;

    } raster_block_area_t;
    

    typedef struct raster_thread
    {

        raster_block_area_t *block;

        SDL_Thread *thread;

        SDL_mutex *mutex;

        frame_buffer_t *fb;

        vector_2_t *tri_vers;

    } raster_thread_t;


    int simple_raster_thread_function(void *arg);

    raster_thread_t *create_raster_thread(SDL_ThreadFunction fn);
    

    bool single_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3]);

    bool multi_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3], raster_thread_t *threads, raster_block_area_t *blocks);

#endif
