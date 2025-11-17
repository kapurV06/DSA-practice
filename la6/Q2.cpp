#include <iostream>
using namespace std;
struct Node
{
  int val;
  Node *next;
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
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
      newNode->next = head; // circular link
    }
    else
    {
      tail->next = newNode;
      newNode->next = head;
      tail = newNode;
    }
  }
}
void display()
{
  if (head == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  temp = head;
  cout << "Circular Linked List: ";
  do
  {
    cout << temp->val << " ";
    temp = temp->next;
  } while (temp != head);
  cout << temp->val;
  cout << endl;
}
int main()
{
  createList();
  display();
}
