#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include <pthread.h>

#define SLEEP_NANOSEC 100

int number_to_produce;

//add request to queue
void *generate_requests_loop(void *data)
{
  int ret;
  int thread_id = *((int *)data);


  while(1)
    {
      printf("Produced item %d\n", number_to_produce);
      number_to_produce++;

      //add more core here

      //optional sleep to allow workers to run
      struct timespec delay;	
      delay.tv_sec = 0;
      delay.tv_nsec = SLEEP_NANOSEC;
      nanosleep(&delay, NULL);
    }

}

int main(int argc, char *argv[])
{
 
  int prod_thread_id = 0;
  pthread_t prod_thread;
  number_to_produce = 0;

  //create master thread
  pthread_create(&prod_thread, NULL, generate_requests_loop, (void *)&prod_thread_id);

  sleep(1);
    
  return 0;
}
