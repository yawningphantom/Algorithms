#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> A = { -2,1};
  int s = A[0];
  vector<int> D;
  if(A.size() == 1){
      cout<<A[0];
      return 0;
  }
  D.push_back(A[0]);
  for(int i=1;i<A.size();i++){
     s = max(s+A[i],A[i]);
     D.push_back(s);
  }
  int ma = D[0];
  for (int i = 1; i < D.size(); i++) {
    if(ma < D[i]){
      ma = D[i];
    }
  }

  cout<<ma;
  return 0;
}
