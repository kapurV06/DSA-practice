#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node *next;
};

Node *head = NULL;
  Node *tail = NULL;

void createList()
{
  int n;
     cout << "Enter the number of nodes: ";
  cin >>n;
  if (n <1)
    return;

  cout << "Enter the values: ";
  for (int i = 0; i < n; i++)
  {
    Node *newNode = new Node();
    cin >> newNode->val;
    newNode->next = NULL;
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  char choice;
  cout << "Make it circular? (y/n): ";
  cin >> choice;
  if (choice == 'y' || choice == 'Y')
    tail->next = head;
}

bool isCircular(Node *head)
{
  if (head == NULL)
    return false;
  Node *temp = head->next;
     while(temp != NULL && temp != head)
    temp = temp->next;
  return(temp == head);
}

int main(){
  createList();
  if (isCircular(head))
    cout << "The list is circular" << endl;
  else
    cout << "The list is not circular" << endl;
  return 0;
}
