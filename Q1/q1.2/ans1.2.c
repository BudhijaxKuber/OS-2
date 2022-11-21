#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>



double time1;
double time2;
double time3;


int main(){
    // yha kuch kuch krna h
    struct timespec start, end1, end2, end3;

    clock_gettime(CLOCK_REALTIME, &start); 

    int kuber = fork();

    if(kuber == 0){
        struct sched_param param;
        param.sched_priority = 0;

        sched_setsched(kuber, SCHED_RR, *param);

        excel("bash1.sh", NULL);
    }


    int kuber2 = fork();

    if(kuber2 == 0){
        struct sched_param param;
        param.sched_priority = 0;

        sched_setsched(kuber2, SCHED_FIFO, *param);

        excel("bash2.sh", NULL);
    }

    int kuber3 = fork();

    if(kuber3 == 0){
        struct sched_param param;
        param.sched_priority = 0;

        sched_setsched(kuber3, SCHED_OTHER, *param);

        excel("bash3.sh", NULL);
    }

    int x = waitpid(-1, NULL , 0);

    if(x==kuber){
        clock_gettime(CLOCK_REALTIME, &end1); 
    
        double xx = end1.tv_sec - start.tv_sec;
        double yy = (double)(end1.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time1 = xx + yy;
    }

    else if(x==kuber2){
        clock_gettime(CLOCK_REALTIME, &end2); 
    
        double xx = end2.tv_sec - start.tv_sec;
        double yy = (double)(end2.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time2 = xx + yy;
    }

    else if(x==kuber3){
        clock_gettime(CLOCK_REALTIME, &end3); 
    
        double xx = end3.tv_sec - start.tv_sec;
        double yy = (double)(end3.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time3 = xx + yy;
    }


    int y = waitpid(-1, NULL , 0);

    if(y==kuber){
        clock_gettime(CLOCK_REALTIME, &end1); 
    
        double xx = end1.tv_sec - start.tv_sec;
        double yy = (double)(end1.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time1 = xx + yy;
    }

    else if(y==kuber2){
        clock_gettime(CLOCK_REALTIME, &end2); 
    
        double xx = end2.tv_sec - start.tv_sec;
        double yy = (double)(end2.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time2 = xx + yy;
    }

    else if(y==kuber3){
        clock_gettime(CLOCK_REALTIME, &end3); 
    
        double xx = end3.tv_sec - start.tv_sec;
        double yy = (double)(end3.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time3 = xx + yy;
    }

    int z = waitpid(-1, NULL , 0);

    if(z==kuber){
        clock_gettime(CLOCK_REALTIME, &end1); 
    
        double xx = end1.tv_sec - start.tv_sec;
        double yy = (double)(end1.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time1 = xx + yy;
    }

    else if(z==kuber2){
        clock_gettime(CLOCK_REALTIME, &end2); 
    
        double xx = end2.tv_sec - start.tv_sec;
        double yy = (double)(end2.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time2 = xx + yy;
    }

    else if(z==kuber3){
        clock_gettime(CLOCK_REALTIME, &end3); 
    
        double xx = end3.tv_sec - start.tv_sec;
        double yy = (double)(end3.tv_nsec - start.tv_nsec)/(double)1000000000L;

        time3 = xx + yy;
    }

    printf("%lf", time1);
    printf("%lf", time2);
    printf("%lf", time3);
}