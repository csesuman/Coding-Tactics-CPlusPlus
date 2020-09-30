
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard
#include <stdexcept>      // std::logic_error

using namespace std;

mutex mtx;

int positiveChecker(int x) {

    if(  x %3 == 0 ) {
        throw std::logic_error( "Number can not be multiple of Three!" );
    }
    return x;
}

void display(int tId) {

    try{
        lock_guard<mutex> lock(mtx);
        positiveChecker(tId);

        cout<<"Number is "<<tId<<endl;


    }catch(std::logic_error& e) {

        cout<<"[Exception] : "<<e.what()<<"\n";
    }
}

mutex print;

void printMutex() {

    lock_guard<mutex> lock(print);


}

int main(){

    int n = 20;
    thread threads[n];

    for(int i = 0 ; i  < n  ; i++) {
        threads[i] = thread( display , i ) ;
    }

    for(int i = 0 ; i  < n  ; i++) {
        threads[i].join();
    }

    return 0;
}
