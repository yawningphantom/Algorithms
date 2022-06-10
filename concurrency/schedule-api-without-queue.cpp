#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

class SchedulerService{
  private:
    private:
    condition_variable CV;
    mutex Mutex;
    int concurrencyLimit;
    int currentTasks;
  public:
    
    SchedulerService(int concurrencyLimit){
      this->concurrencyLimit = concurrencyLimit;
      this->currentTasks = 0;
    }

    void schedule(function<void()> Job , nanoseconds timeDelay){
      unique_lock<mutex> Lock(Mutex);
      CV.wait(Lock, [this]{ return this->currentTasks < this->concurrencyLimit; });
      this->currentTasks++;

      thread p([this, Job, timeDelay](){
        cout<<timeDelay.count()<<endl;
        this_thread::sleep_for(timeDelay);
        Job();
        currentTasks--;
        CV.notify_one();
      });
      p.detach();
    }

    void wait() {
      unique_lock<mutex> lock(Mutex);
      CV.wait(lock, [&] {
        return currentTasks == 0; 
      });
      cout<<"All Tasks Completed"<<endl;
    }
};



int main() {
  auto task = [](int JobId){ 
    cout<<"Running Task :: ( "<<JobId<<" ) "<<endl;
    cout <<"Processing....." << endl; 
    cout<<"Task Completed :: ( "<<JobId<<" ) "<<endl;
  };
  auto start = chrono::high_resolution_clock::now();


  auto scheduler = SchedulerService(10);
  scheduler.schedule([task](){ task(1); }, 100ms);
  scheduler.schedule([task](){ task(2); }, 2ms);
  scheduler.schedule([task](){ task(3); }, 10ns);
  scheduler.schedule([task](){ task(4); }, 10ns);

  scheduler.wait();

  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  cout << "Waited: " << duration.count() << endl;
  return 0;
}