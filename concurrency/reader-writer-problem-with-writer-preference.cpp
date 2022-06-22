#include <bits/stdc++.h>
#include <condition_variable>
#include <cstdlib>
#include <mutex>
#include <queue>
using namespace std;
// N readers -> 1 writer


class BlockingQueue{
  int writers;
  int writing;
  int readers;
  int reading;
  unsigned int maxCapacity;
  mutex M;
  condition_variable CV;
  priority_queue<int> Q;
  public:

  BlockingQueue(int maxCapacity){
    this->writers = 0;
    this->writing = 0;
    this->readers = 0;
    this->reading = 0;
    this->maxCapacity = maxCapacity;
  }

  void reader(int readerId){
    unique_lock<mutex> L1(M);

    CV.wait(L1, [&](){ 
      return writers == 0;
    });

    CV.wait(L1, [&](){ 
      return (writing == 0) and !Q.empty();
    });

    reading++;
    L1.unlock();

    cout<<" Reader :: -> "<<readerId<<" is reading :: value -> "<<Q.top()<<endl;

    
    unique_lock<mutex> L2(M);
    reading--;
    CV.notify_all();
    L2.unlock();

  }

  void writer(int writerId){
    unique_lock<mutex> L1(M);
    // CV.wait(L1, [this](){
    //   return Q.size() < maxCapacity; 
    // });
    writers++;

    CV.wait(L1, [this](){ 
      return reading == 0 or writing == 0;
    });

    writing++;
    L1.unlock();

    int x = ( writerId + rand() )% 10;
    cout<<" Writer :: -> "<<writerId<<" is writing -> "<<x<<endl;
    Q.push(x);
    
    unique_lock<mutex> L2(M);
    writing--;
    writers--;
    L2.unlock();
    CV.notify_all();
  }

};

// To execute C++, please define "int main()"
int main() {

  BlockingQueue  b(10);


  thread r(([&](){ b.writer(5); }) );
  thread t(([&](){ b.writer(7); }) );
  thread s(([&](){ b.reader(3);; }) );
  thread q(([&](){ b.reader(2); }) );
  thread v(([&](){ b.reader(7); }) );
  thread w(([&](){ b.reader(9); }) );
  thread w1(([&](){ b.reader(9); }) );
  thread w2(([&](){ b.reader(9); }) );
  thread w3(([&](){ b.reader(9); }) );
  thread w4(([&](){ b.reader(9); }) );



  thread u(([&](){ b.writer(9); }) );
  thread p(([&](){ b.reader(19); }) );

  thread w5(([&](){ b.reader(29); }) );
  thread w6(([&](){ b.reader(39); }) );
  thread w7(([&](){ b.reader(49); }) );
  thread w8(([&](){ b.reader(59); }) );
  thread w9(([&](){ b.reader(69); }) );
  thread w10(([&](){ b.reader(79); }) );



  p.join();
  q.join();
  r.join();
  s.join();
  t.join();
  u.join();

  v.join();
  w.join();
  w1.join();
  w2.join();
  w3.join();
  w4.join();
  w5.join();

  w6.join();
  w7.join();
  w8.join();
  w9.join();
  w10.join();




  return 0;
}
