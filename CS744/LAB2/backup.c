









#include <pthread.h>
#include <stdio.h>

int totalPrinting = 10000;
int bufferSize = 1000;

float queue[1000];


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


 pthread_mutex_t queue_head_lock = PTHREAD_MUTEX_INITIALIZER;
 int queue_head = 1;

 pthread_mutex_t queue_tail_lock = PTHREAD_MUTEX_INITIALIZER;
 int queue_tail = 0;

void *worker(void *data_ptr)
{
    int thread_id = *(int *)data_ptr;
    int dataProcessed = 0;

    for(int i = 0; i < totalPrinting; i++)
    {
        while(1)
        {
            pthread_mutex_lock(&queue_tail_lock);
            if(queue_tail != queue_head)
                break;
            pthread_mutex_unlock(&queue_tail_lock);
            //This sleep is to make the sync happen
            sleep(0);
        }

        // as it is circular Q, need to process its endpoints
        int ptr = getNextInQueue(&queue_tail);
        float data = queue[ptr];
        pthread_mutex_unlock(&queue_tail_lock);

        dataProcessed++;
        printf("\tconsumed = %f \t by %d  [Consumption Till now = %d]\n", data, thread_id, dataProcessed);
        
    }
}


void *master(void *data_ptr)
{
    int thread_id;

    for(int i = 0; i < totalPrinting; i++)
    {
        float value = (i);

        while(1)
        {
            pthread_mutex_lock(&queue_head_lock);

            if((queue_head + 1) % bufferSize != queue_tail)
                break;

            pthread_mutex_unlock(&queue_head_lock);
            sleep(0);
        }

        queue[queue_head] = value;
        printf("produced = %f\n", value);
        getNextInQueue(&queue_head);
        pthread_mutex_unlock(&queue_head_lock);
    }

}


int main()
{
    int totalNoOfThreads = 5;
    pthread_t threads[totalNoOfThreads];
    int data[totalNoOfThreads];
    int i;
    data[0] = 0;
    pthread_create(&threads[0], NULL, master, &data[0]);

    for(i=1; i < totalNoOfThreads; i++)
    {
        data[i] = i;
        pthread_create(&threads[i], NULL, worker, &data[i]);
    }

    for(int i = 0; i < totalNoOfThreads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

