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
      newNode->next = head;
    }
    else
    {
      tail->next = newNode;
      newNode->next = head;
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
  int count = 0;
  temp = head;
  do
  {
    count++;
    temp = temp->next;
  } while (temp != head);
  cout << "Number of nodes in Circular Linked List: " << count << endl;
  cout << "Approximate total memory used: " << count * sizeof(Node) << " bytes" << endl;
}
int main()
{
  createList();
  size();
  return 0;
}
