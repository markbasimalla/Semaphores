
#include "main.hpp"

void* Running_belt(void* arg) {
    shared_buffer* shared = (shared_buffer*)arg;
    while (1) {
        sem_wait(&shared->sem);
        while (shared->buffer[shared->count] != '0') {
            LOG(LOGGER_LEVEL_INFO, "%c", shared->buffer[shared->count]);
            shared->count = (shared->count + 1);
            if (shared->count == BUFFER_SIZE)
                shared->count = 0;  
        }
        sem_post(&shared->sem);
        sleep(1);
    }
    return NULL;
}

