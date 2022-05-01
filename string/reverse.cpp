#include<bits/stdc++.h>

using namespace std;


int main(){
  string s = "1245432";

  // cin>>s;
  cout<<"Original string \n"<<s;
  int n = s.length();
  for (int i = 0; i < n/2; i++) {
    swap(s[i],s[n-i-1]);
  }

  cout<<"\nReversed String \n"<<s;

  return 0;
}
