#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int val;
    node(int data){
        val = data;
        next=NULL;
    }
};
class linkedList{
    public:
    node* head;
    linkedList(){
        head = NULL;
    }
    void insertAtEnd(int val){
        node* newNode = new node(val);
        newNode->next=NULL;
        node* temp = head;
        if(head==NULL){
            head = newNode;
            return;
        }
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newNode;
    }
    void display(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void deleteKey(int key){
        
        if(head == NULL){return;}
        while(head!=NULL and head->val==key){
            node* temp = head;
            head = head->next;
            delete temp;
        }
        node* currentNode = head;
        while(currentNode->next!=NULL){
            if(currentNode->next->val==key){
                node* temp = currentNode->next;
                currentNode->next=currentNode->next->next;
                
                delete temp;
            }
            else{
            currentNode=currentNode->next;}
        }
    }

};
int main(){
    int key = 1;
    linkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(3);
    ll.insertAtEnd(1);
    ll.display();
    ll.deleteKey(1);
    ll.display();
    return 0;
}
