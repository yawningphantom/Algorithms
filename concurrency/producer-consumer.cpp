#include <bits/stdc++.h>
#include <condition_variable>
#include <mutex>
#include <queue>

using namespace std;

mutex M;
condition_variable CV;
const int bufferSize = 10;
queue<int> Q;


void producer(int tasks){
  while(tasks--){
    unique_lock<mutex> Lock(M);
    CV.wait(Lock, []{ return Q.size() < bufferSize; });
    cout<<"producing task :: "<<tasks<<endl;
    Q.push(tasks);
    Lock.unlock();
    CV.notify_one();
  }
}

void consumer(){
  while(true){
    unique_lock<mutex> Lock(M);
    CV.wait(Lock, []{ return !Q.empty(); });
    cout<<"consuming task :: "<<Q.front()<<endl;
    Q.pop();
    Lock.unlock();
    CV.notify_one();
  }
}



int main() {

  thread p(producer, 30);
  thread q(consumer);
  p.join();
  q.join();
  return 0;
}
