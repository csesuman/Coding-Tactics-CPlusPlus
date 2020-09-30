
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>


class Semaphore {

private :
    std::mutex mtx;
    std::condition_variable cv;
    int cnt =  0;
public :
    Semaphore(int cnt) {
        this->cnt = cnt;
    }
    inline void notify(int tid) {
        std::unique_lock<std::mutex> lck( mtx );
        cnt++;
        std::cout<<"Thread id " << tid << " notified Another one!! " << std::endl;
        cv.notify_one();
    }

    inline void wait(int tid) {
        std::unique_lock<std::mutex> lck(mtx);
        while(cnt==0) {
            std::cout << " Thread is waiting :: id => " << tid << std::endl;
            cv.wait(lck);
            std::cout << " thread is running :: id => " << tid << std::endl;
        }
        cnt--;
    }
};
