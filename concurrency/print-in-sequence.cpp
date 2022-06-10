#include <bits/stdc++.h>
#include <condition_variable>
#include <mutex>
using namespace std;

class Foo {
    int Count;
    condition_variable CV;
    mutex M;
public:
    Foo() {
      Count = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> LG(M);
        cout<<"first called"<<endl;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        Count = 2;
        CV.notify_all();
        LG.unlock();

    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> LG(M);
        CV.wait(LG, [this]{ return Count == 2 ? true : false; });
        // printSecond() outputs "second". Do not change or remove this line.

        cout<<"second called"<<endl;
        printSecond();
        Count = 3;
        CV.notify_all();
        LG.unlock();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> LG(M);
        CV.wait(LG, [this]{ cout<<Count<<endl;return Count == 3 ? true : false; });

        cout<<"third called"<<endl;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        LG.unlock();

    }
};




int main() {
  auto t = Foo();

  auto t1 = [](){
    cout<<"1 : "<<endl;
  };

    auto t2 = [](){
    cout<<"2 : "<<endl;
  };
  
    auto t3 = [](){
    cout<<"3 : "<<endl;
  };
  
  thread q( [&](){ t.second(t2); });

  thread p( [&](){ t.third(t3); });


  thread r( [&](){ t.first(t1); });


  p.join();
  q.join();
  r.join();


  return 0;
}
