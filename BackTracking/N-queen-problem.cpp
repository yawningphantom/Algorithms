//A simple program to solve the N-queen problem using BackTracking

#include<iostream>

using namespace std;

bool isSafe(int board[][10], int i , int j , int n){
  // check the row
  for(int row = 0; row < n ;row++){
    if(board[row][j] == 1 ){
      return false;
    }
  }

  int x = i;
  int y = j;

  //check the left diagonal
   while (x >= 0 && y >= 0 ) {
     if(board[x][y] == 1 ){
       return false;
     }
     x--;
     y--;
   }


  //check the right diagonal
  while (x >= 0 && y < 0 ) {
    if(board[x][y] == 1 ){
      return false;
    }
    x--;
    y++;
  }

  return true;
}

bool nQueenProblem(int board[][10] , int i , int n){
  if(i==n){
    //all queens placed

     for (int i= 0;i < n; i++) {
       for(int j=0;j<n;j++){
           // if(board[i][j] == 1){
           // cout<<"Q";
           // }
           // else{
           //  cout<<"_";
           // }
           cout<<board[i][j]<<" ";
       }
       cout<<endl;
     }

     return true;
  }

  //recursive case
  for(int j=0;j<n ;j++){
    // check if the position of placing the queen is safe
     if(isSafe(board, i , j , n )){

       //placing the queen
        board[i][j] = 1 ;
        bool puttingNextQueen  = nQueenProblem(board , i+1 , n);
        if(puttingNextQueen){
         return true;
        }

        //removing the queen
        board[i][j] = 0;
     }
  }

 return false;

}

int main(){
  int n;
  cout<<"Enter N";
  cin>>n;
  int board[10][10] = {0};
  if(nQueenProblem(board , 0 , n)){
    cout<<"that's how the queen can be placed";
  }
  else{
    cout<<"queens cannot be placed";

  }
  return 0;
}
