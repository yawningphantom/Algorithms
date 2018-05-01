// C/C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

struct Item
{
   int value, weight;
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int curWeight = 0;  // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)
    double x[n]={0};
    // Looping through all Items
    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
            x[i] = 1;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            x[i] = ((double) remain / arr[i].weight);
            break;
        }
    }

    cout<<"The items selected";
    for (int i = 0; i < n; i++)
    { cout<<x[i]<<"  ";}

    return finalvalue;
}

// driver program to test above function
int main()
{   int n,W,i,a,b;
    cout<<"Enter the number of items and the weight of knapsack respectively";
    cin>>n>>W;

    // Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    Item arr[n];
    cout<<"Enter the value and  weight of each item";

    for(int i = 0;i<n;i++){
      cin>>a>>b;
     arr[i].value =  a;
     arr[i].weight = b;
    }


    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}
