#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

// To execute C++, please define "int main()"
int main() {

  return 0;
}

/**

Given a list of strings denoting function name, START or END marker, and timestamp. Calls can be nested and one function can call child functions. 
For example:

"abc,START,100" 
"def,START,150", 
"def,END,180", 
"abc,END,200"
Inclusive time is defined as all the time spent on a particular function, including time spent on its child calls. 
Exclusive time is defined as the time spent on a particular function only, excluding time spent on its child calls.
In the above example, inclusive time for function "abc" is 200-100=100, while exclusive time for function "abc" is (200-100) - (180-150) = 70

Given such list of strings, figure out the inclusive and exclusive time for any given function call.  

Note that the calls can span multiple levels and nested. 

"abc,START,100", 
 "def,START,150", 
 "hij,START,170", 
 "hij,END,200", 
 "def,END,220", 
"job4,START,230", 
"job4,END,250", 
"abc,END,300"

-> abc, start, 100 
  def  , 30
  70, 40 +=

 
20

abc -  300 - 100 , 70 + 20 = 110



Note that you can assume the inputs are well formed, and there are no out-of-order calls. For example, "abc, START,100" will always appear before "abc,END,300".

For"abc", it should output:
 inclusive time=200
 exclusive time=110


 static void parseJobTime(String[] input, String jobName, int[] result) {

}
*/

//   struct Node{ string type; string jobName; int time; int overhead; };


// Node getNode(string s){




// };




// vector<int> parseJobTime(vector<string> input, string inputJobName){

//   stack<Node> Stack;


//   for(auto job: input){
//       auto jobNode = getNode(job);
//       /*  
//       "abc,START,100" 
// "def,START,150", 
// "def,END,180", 
// "abc,END,200"

//       { "abc" , START , 100 , 30}
//       { "abc" , END , 200 , 0 }


//       "abc,START,100", 
//       "def,START,150", 
//       "hij,START,170", 
//       "hij,END,200", 
//       "def,END,220", 
//       "job4,START,230", 
//       "job4,END,250", 
//       "abc,END,300"
//       "abc,START,350"
//       "abc,END,450"




//       { "abc" , START , 100 , 70}
//       { "job4" , START , 230 , 250}



//       -> input n string, avg *l

//         time complexity ->  O(n) -> single loop -> 
//         space complexity -> O(n) ( stack and the unordered map)
//       */

//       unordered_map<string, vector<int> > M;

//       if(!Stack.empty() and  ( Stack.top().jobName == jobNode.jobName)   ){
        
//         int currentOverhead =  jobNode.time - Stack.top().time;
        
//         // if(jobNode.jobName == inputJobName){
//         //   M[inputJobName]
//         //   // return { currentOverhead ,  currentOverhead - Stack.top().overhead }; 
//         // }

//         M[jobNode.jobName][0] += currentOverhead;
//         M[jobNode.jobName][1] += (currentOverhead - Stack.top().overhead);


//         Stack.pop();
//         if(!Stack.empty())
//           Stack.top().overhead += currentOverhead;

//       }
//       else
//         Stack.push(jobNode);
//   }

//   return { -1, -1};
// }



/**
     * Given a matrix of following relationships between N LinkedIn users (with ids from 0 to N-1):
     * followingMatrix[i][j] == true iff user i is following user j
     * thus followingMatrix[i][j] doesn't imply followingMatrix[j][i].
     * Let's also agree that followingMatrix[i][i] == false.
     *
     * An influencer is a user who is:
     * - followed by everyone else and
     * - not following anyone herself/himself
     *
     * This method should return the influencer's id in a given matrix of following relationships,
     * or return -1 if there is no influencer in this group.
     
    matrix[i][j]  =true;
    O(n^2)

    i -> j = 1 ( i follows j) -> i not a influencer
    i -> j = 0 ( i doesn't follow j) -> j  cannot be an influencer

    run a loop -> i ,j 

    candidate = 0 , 1
    0, 2


    [0][1] -> false

    [0][2] -> true

    2 ,3 

    loop from 0 to N-1




    no influencers?

*/

/*
{ { 0, 0, 1, 0 },
{ 0, 0, 1, 0 },
{ 0, 0, 0, 0 },
 { 0, 0, 1, 0 } }
  

*/

int findInfluencer(vector<vector<int>> & A){

    int candidate = 0;
    // 2 , 3
    // 
    for(int i = 1; i< A.size();i++){
        if(A[candidate][i]){
          candidate = i;
        }
    }

    for(int i = 0 ; i < A.size();i++){
        if(i == candidate)
          continue;
        
        if(A[candidate][i] or A[i][candidate])
          return -1;
    }

    return candidate;
}