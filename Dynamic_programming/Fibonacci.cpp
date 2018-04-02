//program to calculate nth number of fibonacci sequence using dynamic programming
//This program uses memoization as it stores the value of a computation that might be required in the future

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
  cout<<"Enter the number\n";
  cin>>n;
  d = fibonacci(n);
  cout<<"The "<<n<<"th number in fibonacci series is :-> "<<d;
  return 0;
}
