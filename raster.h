
#ifndef RASTER_H_
#define RASTER_H_

    #include "raster_thread.h"


    int simple_raster_thread_function(void *arg);


    bool single_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3]);

    bool multi_raster_triangle_on_frame_buffer(frame_buffer_t *fb, vector_2_t tri_vers[3], raster_thread_t *threads[], raster_block_area_t *blocks[]);

#endif
