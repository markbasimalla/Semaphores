

#include <semaphore.h>
#include <iostream>
#include <pthread.h>
#include <cstring>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "logger.h"
#include "log_levels.h"
#include "log_config.h"

using namespace std;

#define BUFFER_SIZE 10

struct shared_buffer {
    char buffer[BUFFER_SIZE];
    int count;
    sem_t sem;
};

shared_buffer* Memory_setting();
void* Running_belt(void* arg);
void* Activate_motor(void* arg);


