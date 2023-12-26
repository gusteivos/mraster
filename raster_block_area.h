
#ifndef RASTER_BLOCK_H_
#define RASTER_BLOCK_H_

    #include <stdbool.h> 
    #include <stdio.h>
    
    #include "vectors/vector2.h"


    typedef struct raster_block_area
    {

        bool completed;

        vector_2_t begin;

        vector_2_t end;

    } raster_block_area_t;


#endif
