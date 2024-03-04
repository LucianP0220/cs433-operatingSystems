/**
* Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author (TODO: Amanuel Biru/Lucian Pate)
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include<stdlib.h>
#include "buffer.h"
#include <unistd.h>
#include<semaphore.h>
#include<pthread.h>
using namespace std;

//create mutex lock and semaphores
sem_t sem_empty, sem_full;
pthread_mutex_t pthread_lock;



// global buffer object
Buffer buffer;

// Producer thread function
  
void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);
    
    while (true) {
        /* sleep for a random period of time */
        usleep(rand()%1000000);
        //acquire the semaphore and lock
        sem_wait(&sem_empty);
        pthread_mutex_lock(&pthread_lock);
       
        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        } 
        else {
            cout << "Producer error condition"  << endl;    // shouldn't come here
        }
         //release the semaphore and lock
         pthread_mutex_unlock(&pthread_lock);
         sem_post(&sem_full);
    }
}

// Consumer thread function

 
void *consumer(void *param) {
    buffer_item item;

    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);
        //acquire the semaphore and lock
        sem_wait(&sem_full);
        pthread_mutex_lock(&pthread_lock);
        
        if (buffer.remove_item(&item)) {
            cout << "Consumer " << ": Removed item " << item << endl;
            buffer.print_buffer();
        } 
        else {
            cout << "Consumer error condition" << endl;    // shouldn't come here
        }
    //release the semaphore and lock
      pthread_mutex_unlock(&pthread_lock);
      sem_post(&sem_empty);
    }
}

int main(int argc, char *argv[]) {
    // we init each of the datatypes for the call of producer and consumer
    int time_sleeper;
    int p_count;
    int c_count;

    //if the count does not equal to 4 we will contiue the process 
    if(argc != 4){
        cout << "Usage: " << argv[0] << "[sleep][producer#][consumer#]   " << endl;
        return 1;
        }
    time_sleeper = strtol(argv[1], NULL, 0);
    p_count = strtol(argv[2], NULL, 0);
    c_count = strtol(argv[3], NULL, 0);
        
   
    ///buffer.print_buffer(); // assuming buffer object has an init_buffer() method
    sem_init(&sem_empty, 0, buffer.get_size()); // initialize sem_empty with buffer size
    sem_init(&sem_full, 0, 0); // initialize sem_full with 0
    pthread_mutex_init(&pthread_lock, NULL); // initialize pthread_lock





// the producer thread executes each statement within the index and inputs the data through the index of the array
pthread_t producer_thread[p_count];
    for (int i = 0; i < p_count; i++) {
        int *producer_id = new int(i + 1); // the producer  ID  insert its own ID into the buffer
        pthread_create(&producer_thread[i], NULL, producer, producer_id);
    }
// the consumer thread executes each statement within the index and inputs the data through the index of the array
    pthread_t consumer_thread[c_count];
    for (int j = 0; j < c_count; j++) {
        pthread_create(&consumer_thread[j], NULL, consumer, NULL);
    }

    //the main thread which sleep after each interation 
    sleep(time_sleeper);

 /* TODO: 6. Exit */
    exit(0);
}