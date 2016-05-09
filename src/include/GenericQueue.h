/*
   GenericQueue.h

   extending a simple thread save version of a queue

   JTM, 9.4.2016

*/

#include <pthread.h>
#include <list>

using namespace std;

template <typename T> class GenericQueue
{
    list<T>          m_queue;
    pthread_mutex_t  m_mutex;
    //pthread_cond_t   m_condv; 

  public:
    GenericQueue() {
        pthread_mutex_init(&m_mutex, NULL);
        //pthread_cond_init(&m_condv, NULL);
    }
    
    ~GenericQueue() {
        pthread_mutex_destroy(&m_mutex);
        //pthread_cond_destroy(&m_condv);
    }

    void add(T item) {
        pthread_mutex_lock(&m_mutex);
        m_queue.push_back(item);
        //pthread_cond_signal(&m_condv);
        pthread_mutex_unlock(&m_mutex);
    }

    T remove() {
        pthread_mutex_lock(&m_mutex);
	/*
        while (m_queue.size() == 0) {
            pthread_cond_wait(&m_condv, &m_mutex);
        }
	*/
	
	T item = NULL;
        if (m_queue.size() == 0) {
	  // nothing there ... queue returns NULL
	} else {
	  item = m_queue.front();
	  m_queue.pop_front();
	}
        pthread_mutex_unlock(&m_mutex);
        return item;
    }

    int size() {
        pthread_mutex_lock(&m_mutex);
        int size = m_queue.size();
        pthread_mutex_unlock(&m_mutex);
        return size;
    }

    void clear() {
        pthread_mutex_lock(&m_mutex);
	m_queue.clear();
        pthread_mutex_unlock(&m_mutex);      
    }
};

