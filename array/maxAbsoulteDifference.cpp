#include<bits/stdc++.h>

using namespace std;

int f(int a, int b, int c, int d) {
  return abs(a-b)+ abs(c-d);
}


int main(){
  vector<int> A = {1,3,-1};

  int mb1=INT_MIN,mb2=INT_MAX,mc1=INT_MIN,mc2=INT_MAX;
  for (int i = 0; i < A.size(); i++) {
    mb1 = max(A[i]-i,mb1);
    mc1 = max(A[i]+i,mc1);

    mb2 = min(A[i]-i,mb2);
    mc2 = min(A[i]+i,mc2);
  }
  if(abs(mb2 - mb1)>abs(mc2 - mc1)){
    cout<<abs(mb1 - mb2);
  }
  else{
    cout<<abs(mc1 - mc2);
  }

  return 0;
}
