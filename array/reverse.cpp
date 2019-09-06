#include<bits/stdc++.h>

using namespace std;

int main() {
  int l;
  cin>>l;
  int arr[l];
  for (int i = 0; i < l; i++) {
    cin>>arr[i];
  }
  cout<<"Original Array";
  for (int i = 0; i < l; i++) {
    cout<<arr[i]<<" ";
  }

  int a;
  for (int i = 0; i < l/2; i++) {
    a = arr[i];
    arr[i] = arr[l-i-1];
    arr[l-i-1] = a;
  }

  cout<<"Reversed array";
  for (int i = 0; i < l; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}
