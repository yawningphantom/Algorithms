#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> A = { 3,1 ,2 ,5 ,3};
  int n= A.size(),as,as2,cs=0,cs2=0,amb,apb;
  as=(n*(n+1))/2;
  as2=(n*(n+1)*(2*n+1))/6;
  for(int i=0;i<n;i++){
    cs+=A[i];
    cs2+=pow(A[i],2);
  }

  amb = as -cs ;
  apb= (as2 -cs2)/amb;

  int b = abs(amb+apb)/2,a = abs(amb-apb)/2;

  cout<<a<<" "<<b;
  return 0;
}
