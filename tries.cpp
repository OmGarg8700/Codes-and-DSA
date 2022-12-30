#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode** arr;
    bool isTerminal;

    // Parameterized constuctor
    TrieNode(char data){
        this->data = data;
        this->arr = new TrieNode*[26];
        for(int i=0;i<26;i++){
            this->arr[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// TrieNode* insert_string(TrieNode* root, string word, int i){

// }
TrieNode* insert_string(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return root;
    }

    char index = word[0] - 'a';
    //present
    if(root->arr[index] != NULL){
        root->arr[index] = insert_string(root->arr[index], word.substr(1));
    }
    else{
        root->arr[index] = new TrieNode(word[0]);
        root->arr[index] = insert_string(root->arr[index], word.substr(1));
    }

    return root;
}

int search_string(TrieNode* root, string word){
    if(word.length() == 0){
        if(root->isTerminal == true){
            return 1;
        }
        return 0;
    }

    int index = word[0] - 'a';
    // present
    int ans = 0;
    if(root->arr[index] != NULL){
        ans = search_string(root->arr[index], word.substr(1));
    }
    else{
        return 0;
    }

    return ans;
}

void delete_string(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    int index = word[0] - 'a';
    // always present
    delete_string(root->arr[index], word.substr(1));
}

void delete_word(TrieNode* root, string word){
    if(search_string(root, word) == 1){
        delete_string(root, word);
    }
    return;
}

int main(){
    TrieNode* root = new TrieNode('#');
    root = insert_string(root, "hello");

    cout<<search_string(root, "hello");

    delete_word(root, "hello");

    cout<<search_string(root, "hello");


    return 0;
}