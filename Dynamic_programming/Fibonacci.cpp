//program to calculate nth number of fibonacci sequence using dynamic programming
#include<iostream>
using namespace std;
int lookup_array[10] = {0};

int fibonacci(int n)
{
  if(lookup_array[n] == 0){
    if(n <= 1)
      lookup_array[n]=n;
    else
      lookup_array[n] = fibonacci(n-1) + fibonacci(n-2);
  }
  return lookup_array[n];
}

int main()
{
  int n,d;
  cout<<"Enter the number";
  cin>>n;
  d = fibonacci(n);
  cout<<d;
  return 0;
}
