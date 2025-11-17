#include <iostream>
using namespace std;
struct Node
{
  int val;
  Node *next;
  Node *prev;
};
Node *head = NULL;
Node *tail = NULL;
Node *temp = NULL;
int n = 0;
void createList()
{
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  if (n < 1)
  {
    cout << "Enter a valid value" << endl;
    return;
  }
  cout << "Enter the values of your nodes:" << endl;
  for (int i = 0; i < n; i++)
  {
    Node *newNode = new Node();
    cin >> newNode->val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }
}
void size()
{
  if (head == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  int i = 0;
  temp = head;
  while (temp != NULL)
  {
    i++;
    temp = temp->next;
  }
  cout << "Size of doubly linked list: " << i * sizeof(Node) << " bytes" << endl;
}
int main()
{
  createList();
  size();
}
