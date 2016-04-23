/*
   GenericThread.cpp
*/

#include "GenericThread.h"

static void* runGenericThread(void* arg)
{
    return ((GenericThread*)arg)->run();
}

GenericThread::GenericThread() : m_tid(0), m_running(0), m_detached(0) {}

GenericThread::~GenericThread()
{
    if (m_running == 1 && m_detached == 0) {
        pthread_detach(m_tid);
    }
    if (m_running == 1) {
        pthread_cancel(m_tid);
    }
}

int GenericThread::start()
{
    int result = pthread_create(&m_tid, NULL, runGenericThread, this);
    if (result == 0) {
        m_running = 1;
    }
    return result;
}

int GenericThread::join()
{
    int result = -1;
    if (m_running == 1) {
        result = pthread_join(m_tid, NULL);
        if (result == 0) {
            m_detached = 0;
        }
    }
    return result;
}

int GenericThread::detach()
{
    int result = -1;
    if (m_running == 1 && m_detached == 0) {
        result = pthread_detach(m_tid);
        if (result == 0) {
            m_detached = 1;
        }
    }
    return result;
}

pthread_t GenericThread::self() {
    return m_tid;
}
