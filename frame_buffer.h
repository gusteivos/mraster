
#ifndef FRAME_BUFFER_H_
#define FRAME_BUFFER_H_

    #include <SDL2/SDL.h>

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>


    typedef struct frame_buffer
    {

        Uint16 width;

        Uint16 height;

        Uint32 *pixels;

        Uint32 format;

    } frame_buffer_t;


    frame_buffer_t *create_frame_buffer(Uint16 width, Uint16 height);


    bool set_frame_buffer_rgba(frame_buffer_t *fb, Uint16 x, Uint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    bool fill_frame_buffer_rgba(frame_buffer_t *fb, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    bool SDL_Render_frame_buffer(SDL_Renderer *renderer, frame_buffer_t *fb);


    void free_frame_buffer(frame_buffer_t *fb);


    #define set_frame_buffer_rgb(fb, x, y, r, g, b) set_frame_buffer_rgba(fb, x, y, r, g, b, 255)

    #define fill_frame_buffer_rgb(fb, r, g, b) fill_frame_buffer_rgba(fb, r, g, b, 255)

#endif
