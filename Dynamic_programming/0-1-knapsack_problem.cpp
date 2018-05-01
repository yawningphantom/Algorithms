#include<iostream>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W , int vt[] , int wt[]){
   int n = 3;
   int K[n+1][W+1],i,w;

   for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]
                        = max(vt[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

   for(int l = 0 ; l<n+1 ;l++)
   {
     for(int m=0;m<w+1;m++){
       cout<<K[l][m]<<"  ";
     }
     cout<<"\n";
   }

   return K[n][W];
}


int main(){
  int W , vt[] = { 2, 3, 5 },wt[]={ 2, 3, 4 };;
  cout<<"enter the size of the knapsack";
 cin >>W;
 int k =knapsack(W , vt , wt  );
 cout<<k;
}
