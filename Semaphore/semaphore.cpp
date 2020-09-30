#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

#include "semaphore.h"

using namespace std;

int main() {

    Semaphore sem(1);

    thread s1([&]() {
        while(true) {
            this_thread::sleep_for(std::chrono::seconds(5));
            sem.wait( 1 );
        }
    });
    thread s2([&]() {
        while(true){
            sem.wait( 2 );
        }
    });
    thread s3([&]() {
        while(true) {
            this_thread::sleep_for(std::chrono::seconds(3));
            sem.wait( 3 );
        }
    });
    thread s4([&]() {
        while(true) {
            this_thread::sleep_for(std::chrono::seconds(2));
            sem.wait( 4 );
        }
    });

    thread s5([&]() {
        while(true) {
            this_thread::sleep_for(std::chrono::seconds(2));
            sem.wait( 5 );
        }
    });

    thread s6([&]() {
        while(true) {
            this_thread::sleep_for(std::chrono::seconds(1));
            sem.notify( 6 );
        }
    });


    s1.join();
    s2.join();
    s3.join();
    s4.join();
    s5.join();
    s6.join();


    return 0;
}
