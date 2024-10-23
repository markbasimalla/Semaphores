
#include "main.hpp"

int main() {
    shared_buffer* shared = Memory_setting();

    Activate_motor((void*)shared);

    munmap(shared, sizeof(shared_buffer));
    shm_unlink("/sample_memory");
    return 0;
}

