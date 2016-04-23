/*
   GenericThread.h

*/

#include <pthread.h>

class GenericThread
{
  public:
    GenericThread();
    virtual ~GenericThread();

    int start();
    int join();
    int detach();
    pthread_t self();
    
    virtual void* run() = 0;
    
  private:
    pthread_t  m_tid;
    int        m_running;
    int        m_detached;
};

