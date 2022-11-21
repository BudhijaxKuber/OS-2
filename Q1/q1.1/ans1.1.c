#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

double time1;
double time2;
double time3;

void *counter_1(void *inp){
    struct timespec start, end;

    if (clock_gettime(CLOCK_REALTIME, &start) == -1){
        perror("ERROR!");
    }

    int var = 0;
    long long int val = 0;
    
    while(val < pow(2,32)){
        var = 1;
        val+=1;
    }

    if(clock_gettime(CLOCK_REALTIME, &end) == -1){
        perror("ERROR!");
    }

    double xx = end.tv_sec - start.tv_sec;
    double yy = (double)(end.tv_nsec - start.tv_nsec)/(double)1000000000L;

    time1 = xx + yy;
    return NULL;
}

void *counter_2(void *inp){
    struct timespec start, end;
    if(clock_gettime(CLOCK_REALTIME, &start) == -1){
        perror("ERROR")
    }

    int var = 0;
    long long int val = 0;
    
    while(val < pow(2,32)){
        var = 1;
        val+=1;
    }

    if(clock_gettime(CLOCK_REALTIME, &end) == -1){
        perror("ERROR!");
    }

    double xx = end.tv_sec - start.tv_sec;
    double yy = (double)(end.tv_nsec - start.tv_nsec)/(double)1000000000L;

    time2 = xx + yy;
    return NULL;
}

void* counter_3(void *inp){
    struct timespec start, end;
    if(clock_gettime(CLOCK_REALTIME, &start) == -1){
        perror("ERROR")
    }

    int var = 0;
    long long int val = 0;
    
    while(val < pow(2,32)){
        var = 1;
        val+=1;
    }

    if(clock_gettime(CLOCK_REALTIME, &end) == -1){
        perror("ERROR!");
    }

    double xx = end.tv_sec - start.tv_sec;
    double yy = (double)(end.tv_nsec - start.tv_nsec)/(double)1000000000L;

    time3 = xx + yy;
    return NULL;    
}

int main(){
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    struct sched_param param;
    param.sched_priority = 0;

    pthread_create(&thread1, NULL, &counter_1, NULL);
    int returnable = pthread_setschedparam(thread1, SCHED_OTHER, &param);
    if(returnable != 0){
        perror("ERROR\n")
    }

    pthread_create(&thread2, NULL, &counter_2, NULL);
    struct sched_param param1;
    param.sched_priority = 52;

    returnable = pthread_setschedparam(thread2, SCHED_FIFO, &param1);
    if (returnable != 0 ){
        perror("ERROR!");
    }
    int abc  = pthread_create(&thread3, NULL, &counter_3, NULL);

    if( abc !=0){
        perror("ERROR!");
    }

    struct sched_param param2;
    param2.sched_priority = 52;

    returnable = pthread_setschedparam(thread3, SCHED_RR, &param2);

    if(returnable != 0){
        perror("ERROR!")
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);


    printf("%lf" , time1);
    printf("%lf" , time2);
    printf("%lf" , time3);

    return 0;
}