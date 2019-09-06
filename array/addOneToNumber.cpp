#include<bits/stdc++.h>

using namespace std;

int main(){

  vector<int> A = { 2,9};

  while(A[0] == 0 && A.size() >=2){
    A.erase(A.begin());
  }

  int n = A.size();
  for (int i = n-1; i >= 0; i--) {

    if(A[i] == 9){
      A[i] = 0;
    }
    else{
      A[i]++;
      break;
    }
  }

  if(A[0] == 0){
    A.insert(A.begin(),1);
  }

  for (int i = 0; i < A.size(); i++) {
    cout<<A[i]<<"\t";
  }
}
