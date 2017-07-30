#ifndef SHARED_MEM_H_
#define SHARED_MEM_H_

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

class SharedMemory
{

private:
    int shmId_;
    void *shmP_;
    struct shmid_ds shmBuf_;

    void errorHandler();
public:
    explicit SharedMemory();
    virtual ~SharedMemory();

    void create();
    void get();
    void attach();
    void detach();
    void destroy();
};

#endif //SHARED_MEM_H_
