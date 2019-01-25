#include <pthread.h>
#include <stdio.h>

int totalPrinting = 10000;
int bufferSize = 1000;

int buf[1000];


int getNextInQueue(int *i)
{
    int prev;
    int next;
    do
    {
        prev = *i;
        next = (prev + 1) % bufferSize;
    } while(!__sync_bool_compare_and_swap(i, prev, next));
    return prev;
}
int threadiProcessing[4];

 pthread_mutex_t countMutex = PTHREAD_MUTEX_INITIALIZER;

 pthread_mutex_t buf_front = PTHREAD_MUTEX_INITIALIZER;
 int queue_head = 1;

 pthread_mutex_t buf_rare = PTHREAD_MUTEX_INITIALIZER;
 int queue_tail = 0;

void *worker(void *data_ptr)
{
    int thread_id = *(int *)data_ptr;
    int dataProcessed = 0;

    for(int i = 0; i < totalPrinting; i++)
    {
        while(1)
        {
            //printf("here %d %d %d %d\n",thread_id, i, queue_tail, queue_head);
            int totalProcessing = threadiProcessing[0]+threadiProcessing[1]+threadiProcessing[2]+threadiProcessing[3];
            float avgProcessing = totalProcessing / 4;

            if (totalProcessing >= totalPrinting)
            {
                return 0;
            }
            
            pthread_mutex_lock(&buf_rare);
            if(queue_tail != queue_head)
                break;
            pthread_mutex_unlock(&buf_rare);
            //This sleep is to make the sync happen
            sleep(0);
        }

        // as it is circular Q, need to process its endpoints
        int ptr = getNextInQueue(&queue_tail);
        int data = buf[ptr];
        pthread_mutex_unlock(&buf_rare);

        dataProcessed++;
        threadiProcessing[thread_id-1] = dataProcessed;
        printf("\tconsumed = %d \t by %d  [ Consumption Till now = %d ]\n", data, thread_id, dataProcessed);
        
    }
}


void *master(void *data_ptr)
{
    int thread_id;

    for(int i = 0; i < totalPrinting; i++)
    {
        int value = (i);

        while(1)
        {

            if((queue_head + 1) % bufferSize != queue_tail)
                break;

            sleep(0);
        }

        buf[queue_head] = value;
        pthread_mutex_unlock(&buf_front);
        getNextInQueue(&queue_head);
        printf("produced = %d\n", value);
    }

}


int main()
{
    int totalNoOfThreads = 5;
    pthread_t threads[totalNoOfThreads];
    int threadIds[totalNoOfThreads];
    int i;
    threadIds[0] = 0;
    pthread_create(&threads[0], NULL, master, &threadIds[0]);

    for(i=1; i < totalNoOfThreads; i++)
    {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, worker, &threadIds[i]);
    }

    for(int i = 0; i < totalNoOfThreads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
