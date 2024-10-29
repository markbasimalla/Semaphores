// activate_motor.cpp
#include "main.hpp"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/mman.h>
#include <fcntl.h>

using namespace std;

void* Activate_motor(void* arg) {
    shared_buffer* shared = (shared_buffer*)arg;
    while (1) {
        sem_wait(&shared->sem);
        if (shared->buffer[shared->count] == '0')
           LOG(LOGGER_LEVEL_INFO, "Motor Status: OFF");
        else
           LOG(LOGGER_LEVEL_INFO, "Motor Status: ON");        
        sem_post(&shared->sem);
        usleep(500);
    }
    return NULL;
}

