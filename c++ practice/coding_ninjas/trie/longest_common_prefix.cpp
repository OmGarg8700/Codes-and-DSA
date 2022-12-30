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

int search_trie(trie* t, string a, int i = 0){
    if(i == a.size()){
        if(t->is_terminal == true){
            return 1;
        }
        return 0;
    }

    int index = a[i] - 'a';
    if(t->arr[index] == NULL){
        return 0;
    }
    i++;
    return search_trie(t->arr[index], a, i);
}

// by using trie approach
void return_ans(trie* t, string &ans){
    int count = 0;
    int index = -1;
    for(int i=0;i<26;i++){
        if(t->arr[i] != NULL){
            count++;
            index = i;
        }
    }

    if(t->is_terminal == true){
        return;
    }
    else if(count == 1){
        ans += 'a' + index;
        return_ans(t->arr[index], ans);
    }

    else{
        return;
    }
}



// by using simple approach
string longestCommonPrefix(vector<string> &arr, int n){
    vector<vector<int>> prefix;
    vector<int> vec1(26,0);

    for(int i=0;i<n;i++){
        string element = arr[i];
        for(int j=0;j<element.size();j++){
            int index = element[j] - 'a';
            int a = prefix.size();
            if((a - 1) < j){
                prefix.push_back(vec1);
            }
            prefix[j][index]++;
        }
    }

    int index = -1;
    string ans = "";
    for(int i=0;i<prefix.size();i++){
        int max_element = 0;
        for(int j=0;j<26;j++){
            if(max_element < prefix[i][j]){
                max_element = prefix[i][j];
                index = j;
            }
        }

        if(max_element == n){
            ans += 'a' + index;
        }
        else{
            return ans;
        }
    }

    return ans;
}

int main(){
    // vector<string> arr;
    // arr.push_back("applejuice");
    // arr.push_back("applepie");
    // arr.push_back("apple");
    // // arr.push_back("codingninja");
    
    
    // cout<<longestCommonPrefix(arr, 2);

    // by trie
    trie* t = new trie('#');

    insert_trie(t, "a");
    insert_trie(t, "ab");
    insert_trie(t, "abc");

    // cout<<search_trie(t, "apple");
    string ans = "";
    return_ans(t, ans);
    cout<<ans;
    return 0;
}