
#include "main.hpp"


int main() {
    shared_buffer* shared = Memory_setting();
    
    Running_belt((void*)shared);

    munmap(shared, sizeof(shared_buffer));
    shm_unlink("/sample_memory");
    return 0;
}

