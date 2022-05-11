// Your old code in java15 has been preserved below.
//  /* 
//  Your previous Plain Text content is preserved below:
//   //    Design a stack with operations on middle element
//   //    Implement a stack which will support following operations ?
//   //    1) push() which adds an element to the top of stack.
//   //    2) pop() which removes an element from top of stack.
//   //    3) findMiddle() which will return middle element of the stack.
//   //    4) deleteMiddle() which will delete the middle element.
//  //  Push and pop are standard stack operation
//   */


/*

    1<->2<->3<-><->5<->6 
    mid = 4 -> nex
    
    4
    
*/
 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

class Node{
    public:
        int data;
        Node * next ;
        Node * prev;
        
        Node(int value){
            data = value;
            next = NULL;
            prev = NULL;
        }
};

// 1 <-> 2

/*
    
    
*/
class StackWithMiddle{
    
    public:
        Node * root;
        Node * middle;
        int stackSize = 0;
    
    StackWithMiddle(int value){
        
        root = new Node(value);
        middle = root;
        stackSize++;
    };
    
    int top(){
        if(!root)
           return INT32_MIN;
        return root->data;
    }
    //  6 <->  5 <-> 4
    void push(int value){
        Node * ptr = new Node(value);
        ptr->next = root;
        root->prev = ptr;
        root = ptr;
        stackSize++;
        
        if(stackSize  & 1){
            middle = middle->prev;
        }
        
        // cout<<stackSize<<" "<<middle->data<<" "<<root->data<<endl;
        
        // update the middle
    }
    
    void pop(){
        if(!stackSize)
            return;
            
        Node * ptr = root;
        root = root->next;
        root->prev = NULL;
        delete ptr;
        stackSize--;
        
        if(!(stackSize  & 1)){
            middle = middle->next;
        }
    }
    
    int findMiddle(){
        if(!stackSize)
            return INT32_MIN;
        
        return middle->data;
    }
    
    bool deleteMiddle(){
        if(!stackSize)
            return false;
        
        if(middle == root){
            Node *ptr = middle;
            middle = middle->next;
            delete ptr;
            stackSize--;
            return true;
        }
        

        Node * ptr = middle;
        Node * ptrPrev = middle->prev;
        Node * ptrNext = middle->next;
        
        if(stackSize & 1){
            middle = middle->next;
        } else {
            middle = middle->prev;
        }
        
        ptrPrev->next = ptrNext;
        ptrNext->prev = ptrPrev;
        
        delete ptr;
        stackSize--;
        
        return true;
    }
};

int main() {
    
    StackWithMiddle * stack = new StackWithMiddle(4);
    // cout<<stack->findMiddle()<<endl;
    stack->push(5);
    // cout<<stack->findMiddle()<<endl;

    stack->push(6);
    // cout<<stack->findMiddle()<<endl;
    
    stack->push(7);
    
    
    // cout<<stack->findMiddle()<<endl;
        stack->push(8);
    
    
    // cout<<stack->findMiddle()<<endl;
    
    
    // stack->push();
    stack->pop();
    cout<<stack->findMiddle()<<endl;
    
    stack->pop();
    cout<<stack->findMiddle()<<endl;
    
    
    

    return 0;
}


