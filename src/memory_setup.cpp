
#include "main.hpp"

shared_buffer* Memory_setting() {
    int fd = shm_open("/sample_memory", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(shared_buffer)); 
    shared_buffer* shared = (shared_buffer*)mmap(NULL, sizeof(shared_buffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    
    shared->count = 0;
    
    sem_init(&shared->sem, 1, 1);

    char initial_buffer[BUFFER_SIZE] = {'A', 'B', '0', 'D', '0', '0', '0', 'E', 'F', 'G'};
    memcpy(shared->buffer, initial_buffer, sizeof(initial_buffer));

    return shared;
}

