// running_belt.cpp
#include "main.hpp"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/mman.h>
#include <fcntl.h>

using namespace std;

void* Running_belt(void* arg) {
    shared_buffer* shared = (shared_buffer*)arg;
    while (1) {
        sem_wait(&shared->sem);
        shared->count = shared->count + 1;
        if(shared->count == BUFFER_SIZE)
            shared->count = 0;  
        char data = shared->buffer[shared->count];
        LOG(LOGGER_LEVEL_INFO, "Running belt: %c ", data);
        sem_post(&shared->sem);
        usleep(500);
    }
    return NULL;
}

