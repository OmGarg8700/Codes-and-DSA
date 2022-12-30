#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        this->data = val;
        this->next = NULL;  
    }
};

node* Problem_5(node* head, int n){
    // Traverse the LL till n and we get n+1 node from begining
    // Traverse remaining: root will move till temp has made n moves
    node* temp = head;
    while(n > 0){
        temp = temp->next;
        n--;
    }
    while(temp != NULL){
        temp = temp->next;
        head = head->next;
    }
    return head;
}

// -----------Floyd Cycle finding algorithm-------------
bool Problem_9(node* head){
    node* slow_ptr = head;
    node* fast_ptr = head->next;
    while(fast_ptr != NULL && fast_ptr->next != NULL){
        if(slow_ptr == fast_ptr){
            return true;
        }
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return false;
}
node* Problem_11(node* head){
    node* slow_ptr = head;
    node* fast_ptr = head->next;
    node* ans = NULL;
    // LOOP CHECK
    while(fast_ptr != NULL && fast_ptr->next != NULL){
        if(slow_ptr == fast_ptr){
            ans = slow_ptr;
            break;
        }
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    // NOW starting from head move only one step
    if(ans != NULL){
        slow_ptr = head;
        while(slow_ptr != ans){
            slow_ptr = slow_ptr->next;
            ans = ans->next;
        }
        return slow_ptr;
    }
    return NULL;
}
// --------------------------------------------------------

// Reverse Linked list in a recursive way
node* Problem_16(node* head, node* &ans){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        ans = head;
        return head;
    }
    node * ptr = Problem_16(head->next, ans);
    ptr->next = head;
    return head;
}

// ---------------Important Question----------------
node* Problem_20(node* head1, node* head2){
    stack<node*> s1;
    stack<node*> s2;
    while(head1 != NULL){
        s1.push(head1);
    }
    while(head2 != NULL){
        s2.push(head2);
    }
    node* temp = NULL;
    while(s1.top() == s2.top()){
        temp = s1.top();
        s1.pop();
        s2.pop();
    }
    return temp;
}
// Efficient Approach
node* Problem_23(node* head1, node* head2){
    if(head1 != NULL && head2 != NULL){
        int length1 = 0;
        int length2 = 0;
        node* temp1 = head1;
        node* temp2 = head2;

        while(temp1 != NULL){
            length1++;
        }while(temp2 != NULL){
            length2++;
        }

        int difference = length2 - length1;
        // Now move difference steps in longer LL
        if(difference >= 0){
            while(difference){
                difference--;
                head2 = head2->next;
            }
        }
        else{
            while(difference){
                difference++;
                head1 = head1->next;
            }
        }
        // Now Just compare
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1;
    }
    else{
        return NULL;
    }
}
// ------------------------------------------------------

node* Problem_31(node* head1, node* head2){
    if(head1 == NULL && head2 == NULL){
        return NULL;
    }
    node* ans = new node(0); // Dummy node
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            ans->next = head1;
            ans = ans->next;
            head1= head1->next;
        }
        else{
            ans->next = head2;
            ans = ans->next;
            head2 = head2->next;
        }
    }
    while(head1 != NULL){
        ans->next = head1;
        ans = ans->next;
        head1= head1->next;
    }
    while(head2 != NULL){
        ans->next = head2;
        ans = ans->next;
        head2= head2->next;
    }
    return ans->next;
}

// Reverse a Linked list
node* reverse(node* head, node* next_pointer_for_prev){
    node* temp = head;
    node* prev = next_pointer_for_prev;
    node* curr = head;

    while(curr != NULL){
        curr = head->next;
        temp->next = prev;
        prev = head;
        head = curr;
    }

    return prev;
}

// Reverse in k-pairs
void Problem_32(node* head){
    
}


node* Problem_35(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast != head && fast->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }

    // now to split the lists
    node* temp = slow->next;
    slow->next = head;

    node* second = temp;
    while(second->next != head){
        second = second->next;
    }
    second->next = temp;
    return temp;
}

int main(){

    return 0;
}