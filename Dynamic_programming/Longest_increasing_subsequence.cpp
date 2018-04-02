/*The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence
  such that all elements of the subsequence are sorted in increasing order.
  For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int LIS( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );

    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    return max;
}
int main(){
  int x , array[5]={1,4,6,8,2};
  int n = sizeof(array)/sizeof(array[0]);
  cout<<n;
  x = LIS(array,n);
  cout<<x;
  return 0;
}
