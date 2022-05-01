#include<bits/stdc++.h>

using namespace std;

class Trie {
    public:
        bool isEnd;
        vector<Trie *> children;
    Trie(){
        isEnd = false;
        children = vector<Trie *>(26 , NULL);
    }
};

void insertIntoTrie(string word, Trie * root){
    Trie * ptr = root;
    for(char c : word){
        int index = c - 'a';
        if(!ptr->children[index])
            ptr->children[index] = new Trie();
        ptr = ptr->children[index];
    }

    ptr->isEnd = true;
}


bool search(string word , Trie * root){
    Trie * ptr = root;
    for(char c: word){
        cout<<c<<endl;
        int index = c - 'a';
        cout<<index<<endl;
        if(!ptr->children[index])
            return false;
        ptr = ptr->children[index];
    }
    if(ptr->isEnd)
        cout<<"found '"<<word<< "' in Trie"<<endl;
    return ptr->isEnd;
}


int main(){

    vector<string> Symbols = { "hello" , "help", "helper"};
    Trie * root = new Trie();
    for(string symbol : Symbols){
        insertIntoTrie(symbol, root);
    }

    search("help" , root);
    return 0;
}