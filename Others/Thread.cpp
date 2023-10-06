#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

void TaskA(){
    for(int i = 0; i<7; i++){
        sleep(1);
        printf("TASK A : %d\n",i);
        fflush(stdout);
    }
}

void TaskB(){
    for(int i = 0; i<7; i++){
        sleep(1);
        printf("TASK B : %d\n",i);
        fflush(stdout);
    }
}

int main()
{
    thread t1(TaskA);
    thread t2(TaskB);
    t1.join();
    t2.join();

    return 0;
}