#include "depth_buffer.h"


depth_buffer_t *create_depth_buffer(Uint16 width, Uint16 height)
{


    depth_buffer_t *new_buffer = (depth_buffer_t *)malloc(sizeof(depth_buffer_t));

    if (new_buffer == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        goto endoffunc;

    }


    new_buffer->width  = width;

    new_buffer->height = height;


    new_buffer->depth_data = (float *)malloc(new_buffer->width * new_buffer->height * sizeof(float));

    if (new_buffer->depth_data == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        free_depth_buffer(new_buffer);

        new_buffer = NULL;

    }


endoffunc:

    return new_buffer;

}


bool set_depth_buffer            (depth_buffer_t *buffer, float value, Uint16 x, Uint16 y);

bool fill_depth_buffer           (depth_buffer_t *buffer, float value);

bool set_defalt_rule_depth_buffer(depth_buffer_t *buffer, float value, Uint16 x, Uint16 y);


bool get_depth_buffer (depth_buffer_t *buffer, float *value, Uint16 x, Uint16 y);


void free_depth_buffer(depth_buffer_t *buffer)
{

    if (buffer == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return;

    }

    if (buffer->depth_data != NULL)
    {

        free(buffer->depth_data);

    }


    free(buffer);

}
