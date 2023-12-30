#include "color_buffer.h"


color_buffer_t *create_color_buffer(Uint16 width, Uint16 height)
{

    color_buffer_t *new_buffer = (color_buffer_t *)malloc(sizeof(color_buffer_t));

    if (new_buffer == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        goto endoffunc;

    }


    new_buffer->width  = width;

    new_buffer->height = height;


    new_buffer->pixel_format_ = SDL_AllocFormat(new_buffer->_pixel_format = SDL_PIXELFORMAT_RGB888); /* or SDL_PIXELFORMAT_ARGB8888* */


    new_buffer->color_data = (Uint32 *)malloc(new_buffer->width * new_buffer->height * sizeof(Uint32));

    if (new_buffer->color_data == NULL || new_buffer->pixel_format_ == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        free_color_buffer(new_buffer);

        new_buffer = NULL;

    }


endoffunc:

    return new_buffer;

}

bool set_color_buffer_rgba(color_buffer_t *buffer, Uint8 r, Uint8 g, Uint8 b, Uint8 a, Uint16 x, Uint16 y)
{

    if (buffer == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }

    if (x >= buffer->width && y >= buffer->height)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }


    buffer->color_data[y * buffer->width + x] = SDL_MapRGBA(buffer->pixel_format_, r, g, b, a);


    return false;

}

bool fill_color_buffer_rgba(color_buffer_t *buffer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{

    if (buffer == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }


    for (int q = 0; q < buffer->width * buffer->height; q++)
    {

        buffer->color_data[q] = SDL_MapRGBA(buffer->pixel_format_, r, g, b, a);

    }


    return false;

}


bool SDL_Render_color_buffer(SDL_Renderer *renderer, color_buffer_t *buffer)
{

    if (renderer == NULL || buffer == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return true;

    }

    SDL_Texture *texture = SDL_CreateTexture(renderer,
                                buffer->_pixel_format,
                                SDL_TEXTUREACCESS_STREAMING,
                                buffer->width,
                                buffer->height);

    SDL_UpdateTexture(texture, NULL, buffer->color_data, buffer->width * sizeof(Uint32));

    SDL_RenderCopy(renderer, texture, NULL, NULL);

    SDL_DestroyTexture(texture);

    return false;

}


void free_color_buffer(color_buffer_t *buffer)
{

    if (buffer == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return;

    }


    if (buffer->pixel_format_ != NULL)
    {
     
        SDL_FreeFormat(buffer->pixel_format_);
    
    }

    if (buffer->color_data != NULL)
    {

        free(buffer->color_data);

    }


    free(buffer);

}
