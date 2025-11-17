#include<iostream>
using namespace std;

class node{
    public:
    node* next;
    int val;
    node(int data){
        val = data;
        next = NULL;
    }
};

class linkedList{
    public:
    node* head;
    linkedList(){
        head = NULL;
    }

    void insertAtBeginning(int val){
        node* newNode = new node(val);
        newNode->next=head;
        head = newNode;
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

    void insertInBetween(int val){
        node* newNode = new node(val);
        node* currentNode = head;
        while(currentNode->next->val<val){
            currentNode=currentNode->next;
        }
        newNode->next=currentNode->next;
        currentNode->next=newNode;
    }

    void display(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void deleteFromBeginning(){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd(){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        if(head->next==NULL){ 
            delete head;
            head=NULL;
            return;
        }
        node* currentNode = head;
        while(currentNode->next->next!=NULL){
            currentNode=currentNode->next;
        }
        node* temp = currentNode->next;
        currentNode->next=NULL;
        delete temp;
    }

    void deleteSpecificNode(int val){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        if(head->val==val){
            deleteFromBeginning();
            return;
        }
        node* currentNode = head;
        while(currentNode->next!=NULL && currentNode->next->val!=val){
            currentNode=currentNode->next;
        }
        if(currentNode->next==NULL){
            cout<<"Value not found!"<<endl;
            return;
        }
        node* temp = currentNode->next;
        currentNode->next=currentNode->next->next;
        delete temp;
    }

    void search(int val){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        int count=1;
        node* temp = head;
        while(temp!=NULL && temp->val!=val){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            cout<<"Value not found!"<<endl;
        } else {
            cout<<"Position of node: "<<count<<endl;
        }
    }
};

int main(){
    linkedList ll;
    int choice, val;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert in Between (sorted)\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                ll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                ll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                ll.insertInBetween(val);
                break;
            case 4:
                ll.deleteFromBeginning();
                break;
            case 5:
                ll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                ll.deleteSpecificNode(val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                ll.search(val);
                break;
            case 8:
           ll.display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 0);

    return 0;
}
