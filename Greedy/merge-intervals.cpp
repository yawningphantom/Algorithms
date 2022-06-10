
#include <bits/stdc++.h>
using namespace std;

struct Segment {
  int start;
  int end;
};

class DownloadTask {
  // add a segment into recombined file
  // start,end time
  list<Segment> M;
  public:


  void add(Segment segment) {

    cout<<"adding segment :: "<<segment.start<<" "<<segment.end<<endl;
    auto compare = [] (const  Segment &intv1, const Segment &intv2)
                          { return intv1.end < intv2.start; };
    // auto range = equal_range(M.begin(), M.end(), segment, compare);
    
    auto itr1 = lower_bound(M.begin(), M.end(), segment, compare);
    auto itr2 = upper_bound(M.begin(), M.end(), segment, compare);

    if(itr1 == itr2) {
      M.insert(itr1 , segment);
    } else {
        cout<<"lower bound   "<<itr1->start<<" "<<itr1->end<<endl;

        itr2--;
        cout<<"upper bound   "<<itr2->start<<" "<<itr2->end<<endl;

        itr2->start = min(segment.start, itr1->start);
        itr2->end = max(segment.end, itr2->end);
        M.erase(itr1, itr2);
    }
    cout<<"--> start"<<endl;
    for(auto m: M){
      cout<<m.start<<" "<<m.end<<endl;
    }
    cout<<"--> end"<<endl;

    return;
  }


  // find total length of downloaded segments
  int getFileSize() {
    int ans = 0;
    for(auto m: M){
      ans+= (m.end - m.start);
    }
    cout<<"ans --------------------> "<<ans<<endl;
    return ans;
  }
};

// To execute C++, please define "int main()"
int main() {
  DownloadTask task =  DownloadTask();
task.add({1, 3});
// task.add({4, 6});
// task.add({2, 5});
task.add({2, 3});


task.getFileSize(); // return 5
// task.add({ 10, 20 });
// task.add({ 25, 30 });
// task.getFileSize(); // return 20
// task.add({19, 29});
// task.getFileSize(); // return 25
  return 0;
}
