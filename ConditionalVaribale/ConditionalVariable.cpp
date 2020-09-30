#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

std::mutex mtx;
bool ready = false;
condition_variable cv;

void printNumber(int id) {
    unique_lock<std::mutex> lck(mtx); // Just a variable declaration

    while(!ready) {
        cout<<"Thread waiting => "<<id<<"\n";
        cv.wait(lck); // cv wait until lck variable aquire mtx
    }

    cout<<" Thread okay  " << id << endl;
    cout<<" Thread okay  " << id << endl;
}

void startAll() {
    unique_lock<mutex> lck(mtx);
    ready = true;
    cv.notify_all();
//    cout<<"WOW "<<endl;
}

int main() {

    thread threads[10];

    for(int i = 0 ; i < 10 ; i ++ )
        threads[i] = thread(printNumber,i);


//    cout<<" 10 threads are ready!! " << endl;

    startAll() ;

    for(auto &th : threads)  th.join();

    return 0;
}



//http://www.cplusplus.com/reference/condition_variable/condition_variable/
