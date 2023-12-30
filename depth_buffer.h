
#ifndef DEPTH_BUFFER_H_
#define DEPTH_BUFFER_H_

    #include <SDL2/SDL.h>

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>


    typedef struct depth_buffer
    {

        Uint16 width;

        Uint16 height;

        float *depth_data;

    } depth_buffer_t;


    extern depth_buffer_t *create_depth_buffer(Uint16 width, Uint16 height);


    extern bool set_depth_buffer            (depth_buffer_t *buffer, float value, Uint16 x, Uint16 y);

    extern bool fill_depth_buffer           (depth_buffer_t *buffer, float value);

    extern bool set_defalt_rule_depth_buffer(depth_buffer_t *buffer, float value, Uint16 x, Uint16 y);


    extern bool get_depth_buffer (depth_buffer_t *buffer, float *value, Uint16 x, Uint16 y);


    extern void free_depth_buffer(depth_buffer_t *buffer);

#endif
