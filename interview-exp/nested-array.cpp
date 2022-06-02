#include <bits/stdc++.h>
using namespace std;

class NestedInteger
{
    public:
        /** @return true if this NestedInteger holds a single integer, rather than a nested list */
        bool isInteger();
     
        /** @return the single integer that this NestedInteger holds, if it holds a single integer
        * Return null if this NestedInteger holds a nested list */
        int getInteger();
     
        /** @return the nested list that this NestedInteger holds, if it holds a nested list
        * Return null if this NestedInteger holds a single integer */
        vector<NestedInteger> getList();
};

/*
  ->{ 1, {4, { 6, 2 } }
  LevelValues -> 1, 4 , 8

  8*1 + 4*2 + 1*3 = 19

  curLevelValue  = 6, 2
  Q ->  2
*/

int accumulateResultByLevel(vector<int> &LevelValues){
  int level = 1, result = 0;
  for(int i = LevelValues.size() -1;i>=0;i--){
    result+=(LevelValues[i]*level);
    level++;
  }
  return result;
}

void populateQueue(queue<NestedInteger> &Queue , vector<NestedInteger> &input){
  for(auto i:input)
    Queue.push(i);
}

int processQueueLevel(queue<NestedInteger> &Queue){
  int levelSize = Queue.size() , currentLevelValue = 0;
   while(levelSize--){
        if(Queue.front().isInteger()){
          currentLevelValue+=Queue.front().getInteger();
        }
        else{
          auto temp = Queue.front().getList();
          for(auto t: temp){
           Queue.push(t);
          }
        }
        Queue.pop();
      }
  return currentLevelValue;
};
  
int reverseDepthSum (vector<NestedInteger> &input)
{
    vector<int> LevelValues;
    queue<NestedInteger> Queue;
  
    populateQueue(Queue, input);
    
    while(!Queue.empty()){
      LevelValues.push_back(processQueueLevel(Queue));
    }

    return accumulateResultByLevel(LevelValues);
}


  

