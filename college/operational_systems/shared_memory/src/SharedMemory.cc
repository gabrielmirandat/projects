#include "SharedMemory.h"

SharedMemory::SharedMemory()
{
}

SharedMemory::~SharedMemory()
{
}

void SharedMemory::errorHandler()
{
    std::cout << errno << std::endl;
    exit(-1);
}

void SharedMemory::create()
{
    if((shmId_ = shmget(0x1223, sizeof(int), IPC_CREAT|0x1ff)) < 0)
        errorHandler();
}

void SharedMemory::get()
{
    if((shmId_ = shmget(0x1223, sizeof(int), 0x1ff)) < 0)
        errorHandler();
}

void SharedMemory::attach()
{
    if(shmP_ = (void *) shmat(idshm, (char *)0, 0) == (void *)-1)
         errorHandler();
}

void SharedMemory::detach()
{
    if(shmdt(shmId_) < 0)
         errorHandler();
}

void SharedMemory::destroy()
{
    if(shmctl(shmId_, IPC_RMID, shmBuf_) < 0)
        errorHandler();
}
