#include <algorithm>
#include <bits/stdc++.h>
#include <condition_variable>
#include <mutex>
#include <pthread.h>
#include <queue>
#include <thread>

using namespace std;

class FizzBuzz {
private:
    int n;
    condition_variable CV;
    mutex M;
    int counter;
public:
    FizzBuzz(int n) {
        this->n = n;
        counter = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
      while(true){
        unique_lock<mutex> Lock(M);
        CV.wait(Lock, [&](){ return 
          (counter >n) or
          ( (counter % 3) == 0 and (counter % 5 != 0) );  });
        if(counter > n)
          return;
        printFizz();
        counter++;
        CV.notify_all();
        Lock.unlock();
      }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
      while(true){

        unique_lock<mutex> Lock(M);
        CV.wait(Lock, [&](){ return 
          (counter >n) or
          ((counter % 3) != 0 and (counter % 5) == 0);  });
        if(counter > n)
          return;
        printBuzz();
        counter++;
        CV.notify_all();
        Lock.unlock();
      }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
      while(true){
        unique_lock<mutex> Lock(M);
        CV.wait(Lock, [&](){ return 
          (counter >n) or 
          ((counter % 3) == 0 and (counter % 5) == 0 );  });
        if(counter > n)
          return;
        printFizzBuzz();
        counter++;
        CV.notify_all();
        Lock.unlock();
      }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
      while(true){
        unique_lock<mutex> Lock(M);
        CV.wait(Lock, [&](){ return (counter >n) or
        ( (counter % 3) != 0 and (counter % 5) != 0 );  });
        if(counter > n)
          break;
        printNumber(counter);
        counter+=1;
        CV.notify_all();
      }
    }
};



int main() {

  auto fizz = [](){ cout<<"FIZZ"<<endl;};
  auto buzz = [](){ cout<<"BUZZ"<<endl;};
  auto fizzbuzz = [](){ cout<<"FIZZBUZZ"<<endl;};

    auto n = [&](int n){ cout<<n<<endl;};

  auto F = FizzBuzz(15);
  thread p(([&](){ F.fizz(fizz); }) );
  thread q(([&](){ F.buzz(buzz); }) );
  thread r(([&](){ F.fizzbuzz(fizzbuzz); }) );
  thread s(([&](){ F.number(n); }) );

  p.join();
  q.join();
  r.join();
  s.join();
  return 0;
}
