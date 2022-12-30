#include<iostream>
#include<vector>
using namespace std;

// by trie
class trie{
    public:
    char data;
    int child_count;
    trie** arr;
    bool is_terminal;

    trie(char data){
        this->data = data;
        this->arr = new trie*[26];
        this->child_count = 0;
        for(int i=0;i<26;i++){
            this->arr[i] = NULL;
        }
        this->is_terminal = false;
    }
};

void insert_trie(trie* t, string a, int i = 0){
    if(i == a.size()){
        t->is_terminal = true;
        return;
    }
    int index = a[i] - 'a';
    // is not present
    if(t->arr[index] == NULL){
        trie* new_trie = new trie(a[i]);
        t->arr[index] = new_trie;
    }

    i++;

    t->child_count++;
    insert_trie(t->arr[index], a, i);

    return;
}

// implement a phoner directory
void phone_directory(trie* t, vector<string> &ans, string prefix){
    if(t == NULL){
        ans.push_back(prefix);
        return;
    }
    else if(t->is_terminal == true){
        ans.push_back(prefix);
    }
    string initial = prefix;
    for(int i=0;i<26;i++){
        if(t->arr[i] != NULL){
            prefix += 'a' + i;
            phone_directory(t->arr[i], ans, prefix);
            prefix = initial;
        }
    }
}

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    trie* t = new trie('#');
    for(int i=0;i<contactList.size();i++){
        insert_trie(t, contactList[i]);
    }

    vector<vector<string>> ans;
    string prefix = "";

    trie* ptr = NULL;
    for(int i=0;i<queryStr.size();i++){
        prefix += queryStr[i];
        // calculating trie* ptr;
        vector<string> vec1;
        ptr = t->arr[queryStr[i] - 'a'];
        if(ptr == NULL){
            vec1.push_back("");
            break;
        }
        else{
            phone_directory(ptr, vec1, prefix);
        }
        ans.push_back(vec1);
    }

    return ans;
}