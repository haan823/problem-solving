#include <iostream>
#include <string>

using namespace std;

class TrieNode{
public:
    TrieNode **children;
    bool isEnd;
    bool isHit;
    TrieNode(){
        isEnd = false;
        children = new TrieNode*[26];
    }
    TrieNode* getChild(char c){
        return children[c-'A'];
    }
    bool hasChild(char c){
        return (children[c-'A'] != nullptr);
    }
};

TrieNode* root;

void insert(string word){
    TrieNode* current = root;
    for(int i=0; i<word.size(); i++){
        char c = word[i];
        if(current->hasChild(c) == false){
            current->children[c-'A'] = new TrieNode();
        }
        current = current->getChild(c);
    }
    current->isEnd = true;
}

bool checkword(string word){
    TrieNode* current = root;
    for(int i=0; i<word.size(); i++){
        char c = word[i];
        if(current->hasChild(c)){
            current = current->children[c-'A'];
        }
        else{
            return false;
        }
    }
    return current->isEnd;
}

int main(){
    root = new TrieNode();
    insert("ABC");
    if(checkword("AB")){
        cout << "true" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
    if(checkword("ABE")){
        cout << "true" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
    if(checkword("ABC")){
        cout << "true" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
    if(checkword("ABCD")){
        cout << "true" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
}