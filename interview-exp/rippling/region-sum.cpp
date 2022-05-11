#include<bits/stdc++.h>

using namespace std;

int main() {
   
    vector<vector<int>> A = {
       {0,0,0,0,0,0},
       {0,1,1,1,1,1},
       {0,1,1,1,1,1},
       {0,1,1,1,1,1},
       {0,1,1,1,1,1},
   };
   
    vector<vector<int>> result(A.size());
   int r = 3;
    
   for(int i=1; i< A.size();i++){
       int c = 0;
       for(int j=1; j < A[i].size();j++){
           A[i][j] =  c + A[i][j];
           c = A[i][j];
       }
   }
    
   for(int i=1; i< A.size();i++){
       for(int j=0; j < A[i].size();j++){
           A[i][j] += A[i-1][j];
       }
   }
    
   for(int i=1; i< A.size();i++){
       for(int j=1; j < A[i].size();j++){
           
           int ans = 0;
           int bottomRow = i + r >= A.size() ? A.size() - 1 : i + r ;
           int bottomCol = j + r >= A[i].size() ? A[i].size() - 1 : j + r ;
           int topRow = i - r < 1 ? 1: i - r ;
           int topCol = j - r < 1 ? 1 : j - r;
           
           ans = A[bottomRow][bottomCol] + A[topRow-1][topCol-1] - A[topRow-1][bottomCol] - 
               A[bottomRow][topCol - 1]; 
           
           result[i].push_back(ans);
       }
   }
    
    for(auto a : result ){
        for(auto b: a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}