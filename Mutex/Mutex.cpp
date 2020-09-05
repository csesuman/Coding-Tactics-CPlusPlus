#include<iostream>
#include<thread>
#include<mutex>


using namespace std;

mutex door;

void func(int value);

void P1(){
    for(int i=0;i<5;i++){
        func(1);
    }
}

void P2(){
    for(int i=0;i<5;i++){
        func(2);
    }
}

void P3(){
    for(int i=0;i<5;i++){
        func(3);
    }
}

void func(int value){

    door.lock();

    cout<<"My thread No : "<<value<<endl;

    door.unlock();
}

int main(){

    thread t1 = thread(P1);
    thread t2 = thread(P2);
    thread t3 = thread(P3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
