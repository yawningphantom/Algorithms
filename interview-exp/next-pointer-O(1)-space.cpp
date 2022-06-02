#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode *next;
      TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };


/*
          0
      1 ->   2
    3 ->   4 -> 5
    7 8  9 10 11 12

*/
void constructNextPointer(TreeNode * root){
    
    if(!root)
      return;

    TreeNode * current = root;

    while(current){

        TreeNode * temp = current;
        TreeNode * prevNonNullNode = NULL;
        TreeNode * firstNonNullNodeInNextLevel = NULL;

        while(temp){
          
          cout<<temp->val<<"\t";

          if(temp->left){
            if(!firstNonNullNodeInNextLevel)
              firstNonNullNodeInNextLevel = temp->left, prevNonNullNode = temp->left;
            else{
              prevNonNullNode->next =  temp->left;
              prevNonNullNode = temp->left;
            }
          }

          if(temp->right){
            if(!firstNonNullNodeInNextLevel)
              firstNonNullNodeInNextLevel = temp->right, prevNonNullNode = temp->right;
            else{
              prevNonNullNode->next = temp->right;
              prevNonNullNode = temp->right;
            }
          }
          temp = temp->next;  
        }
        current = firstNonNullNodeInNextLevel;
    }
}



int main() {
  auto root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);


  root->right->left->left = new TreeNode(6);
  root->right->left->right = new TreeNode(7);

  root->right->right->right = new TreeNode(9);
  constructNextPointer(root);
  return 0;
}
