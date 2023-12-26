#include "raster_thread.h"


raster_thread_t *create_raster_thread()
{

    raster_thread_t *new_thread = (raster_thread_t *)calloc(1, sizeof(raster_thread_t));

    if (new_thread == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        goto endoffunc;

    }


    new_thread->pause_mutex = SDL_CreateMutex();

    if (new_thread->pause_mutex == NULL)
    {

        fprintf(stderr, "TODO: %s.\n", SDL_GetError());


        free_raster_thread(new_thread);

        new_thread = NULL;


        goto endoffunc;

    }


    new_thread->kkill_mutex = SDL_CreateMutex();

    if (new_thread->kkill_mutex == NULL)
    {

        fprintf(stderr, "TODO: %s.\n", SDL_GetError());


        free_raster_thread(new_thread);

        new_thread = NULL;


        goto endoffunc;

    }

    SDL_LockMutex(new_thread->kkill_mutex);


    new_thread->block_mutex = SDL_CreateMutex();

    if (new_thread->block_mutex == NULL)
    {

        fprintf(stderr, "TODO: %s.\n", SDL_GetError());


        free_raster_thread(new_thread);

        new_thread = NULL;

    }


endoffunc:

    return new_thread;

}

bool init_raster_thread(raster_thread_t *thread, SDL_ThreadFunction fn, char *name)
{

    if (thread == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return;

    }


    thread->thread = SDL_CreateThread(fn, name, (void *)thread);

    if (thread->thread == NULL)
    {

        fprintf(stderr, "TODO: %s.\n", SDL_GetError());


        return false;

    }


    return true;

}


void free_raster_thread(raster_thread_t *thread)
{

    if (thread == NULL)
    {

        fprintf(stderr, "TODO: .\n");


        return;

    }


    if (thread->pause_mutex != NULL)
    {

        SDL_UnlockMutex (thread->pause_mutex);

        SDL_DestroyMutex(thread->pause_mutex);

    }

    if (thread->kkill_mutex != NULL)
    {

        SDL_UnlockMutex (thread->kkill_mutex);

        SDL_DestroyMutex(thread->kkill_mutex);

    }


    if (thread->block_mutex != NULL)
    {

        SDL_UnlockMutex (thread->block_mutex);

        SDL_DestroyMutex(thread->block_mutex);

    }


    free(thread);

}
