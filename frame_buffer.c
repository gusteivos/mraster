#include "frame_buffer.h"


frame_buffer_t *create_frame_buffer(Uint16 width, Uint16 height)
{

    frame_buffer_t *new_fb = (frame_buffer_t *)malloc(sizeof(frame_buffer_t));

    if (new_fb == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        goto endoffunc;

    }


    new_fb->width  = width;

    new_fb->height = height;


    new_fb->pixel_format = SDL_AllocFormat(new_fb->format = SDL_PIXELFORMAT_RGB888); /* or SDL_PIXELFORMAT_ARGB8888* */


    new_fb->pixels = (Uint32 *)malloc(new_fb->width * new_fb->height * sizeof(Uint32));

    if (new_fb->pixels == NULL || new_fb->pixel_format == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        free_frame_buffer(new_fb);

        new_fb = NULL;

    }


endoffunc:

    return new_fb;

}

bool set_frame_buffer_rgba(frame_buffer_t *fb, Uint16 x, Uint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{

    if (fb == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }


    fb->pixels[y * fb->width + x] = SDL_MapRGBA(fb->pixel_format, r, g, b, a);


    return false;

}

bool fill_frame_buffer_rgba(frame_buffer_t *fb, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{

    if (fb == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }


    for (int q = 0; q < fb->width * fb->height; q++)
    {

        fb->pixels[q] = SDL_MapRGBA(fb->pixel_format, r, g, b, a);

    }


    return false;

}


bool SDL_Render_frame_buffer(SDL_Renderer *renderer, frame_buffer_t *fb)
{

    if (renderer == NULL || fb == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }

    SDL_Texture *texture = SDL_CreateTexture(renderer,
                                fb->format,
                                SDL_TEXTUREACCESS_STREAMING,
                                fb->width,
                                fb->height);

    SDL_UpdateTexture(texture, NULL, fb->pixels, fb->width * sizeof(Uint32));

    SDL_RenderCopy(renderer, texture, NULL, NULL);

    SDL_DestroyTexture(texture);

    return false;

}


void free_frame_buffer(frame_buffer_t *fb)
{

    if (fb == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return;

    }


    if (fb->pixel_format != NULL)
    {
     
        SDL_FreeFormat(fb->pixel_format);
    

        if (fb->pixels != NULL)
        {

            free(fb->pixels);

        }


    }


    free(fb);

}
