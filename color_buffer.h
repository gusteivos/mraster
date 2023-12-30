
#ifndef COLOR_BUFFER_H_
#define COLOR_BUFFER_H_

    #include <SDL2/SDL.h>

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>


    typedef struct color_buffer
    {

        Uint16 width;

        Uint16 height;

        Uint32 *color_data;

        Uint32           _pixel_format ;

        SDL_PixelFormat * pixel_format_;

    } color_buffer_t;


    extern color_buffer_t *create_color_buffer(Uint16 width, Uint16 height);


    extern bool set_color_buffer_rgba (color_buffer_t *buffer, Uint8 r, Uint8 g, Uint8 b, Uint8 a, Uint16 x, Uint16 y);

    extern bool fill_color_buffer_rgba(color_buffer_t *buffer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);


    extern bool SDL_Render_color_buffer(SDL_Renderer *renderer, color_buffer_t *buffer);


    extern void free_color_buffer(color_buffer_t *buffer);


    #define set_color_buffer_rgb (buffer, r, g, b, x, y) set_color_buffer_rgba (buffer, r, g, b, 255, x, y)

    #define fill_color_buffer_rgb(buffer, r, g, b)       fill_color_buffer_rgba(buffer, r, g, b, 255)

#endif
