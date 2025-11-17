#include <iostream>
using namespace std;
struct Node
{
  char val;
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
bool Palindrome()
{
  if (head == NULL)
  {
    cout << "List is empty" << endl;
    return true;
  }
  Node *fast = head;
  Node *slow = head;
  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  temp = slow->prev;
  if (n % 2 == 0)
  {
    while (temp != NULL && slow != NULL)
    {
      if (temp->val != slow->val)
      {
        return false;
      }
    }
    temp = temp->prev;
    slow = slow->next;
    return true;
  }
  slow = slow->next;
  while (temp != NULL && slow != NULL)
  {
    if (temp->val != slow->val)
    {
      return false;
    }
      temp =temp->prev;
    slow= slow->next;
  }
  return true;
}
int main()
{
      createList();
  if (Palindrome())
  {
      cout << "The list is palindrome" << endl;
  }
  else
  {
    cout << "The list is not palindrome" << endl;
  }
}
