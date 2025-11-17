#include <iostream>
using namespace std;
struct Node
{
  int val;
  Node *next;
  Node *prev;
};
Node *head = NULL;
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
  head = NULL;
  Node *temp = NULL;
  cout << "Enter the values of your nodes:" << endl;
  for (int i = 0; i < n; i++)
  {
    Node *newNode = new Node();
    cin >> newNode->val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
      head = newNode;
      temp = head;
    }
    else
    {
      temp->next = newNode;
      newNode->prev = temp;
      temp = newNode;
    }
  }
}
void insertNode()
{
  cout << "Enter the position where you want to insert your node: ";
  int x;
  cin >> x;
  if (x < 1 || x > n + 1)
  {
    cout << "Enter a valid position" << endl;
    return;
  }
  Node *newNode = new Node();
  cout << "Enter the value of your node: ";
  cin >> newNode->val;
  newNode->next = NULL;
  newNode->prev = NULL;
  if (head == NULL)
  {
    head = newNode;
  }
  else if (x == 1)
  {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  else
  {
    Node *temp = head;
    for (int i = 1; i < x - 1 && temp->next != NULL; i++)
    {
      temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
      temp->next->prev = newNode;
    temp->next = newNode;
  }
  n++;
}
void deleteNode()
{
  cout << "Enter the node position you want to delete: ";
  int x;
  cin >> x;
  if (x < 1 || x > n || head == NULL)
  {
    cout << "Enter a valid value" << endl;
    return;
  }
  if (x == 1)
  {
    Node *tempNode = head;
    head = head->next;
    if (head != NULL)
      head->prev = NULL;
    delete tempNode;
  }
  else
  {
    Node *temp = head;
    for (int i = 1; i < x; i++)
      temp = temp->next;
    Node *tempNode = temp;
    if (temp->next != NULL)
      temp->next->prev = temp->prev;
    if (temp->prev != NULL)
      temp->prev->next = temp->next;
    delete tempNode;
  }
  n--;
}
void searchNode()
{
  cout << "Enter the value you want to search: ";
  int x;
  cin >> x;
  Node *temp = head;
  bool found = false;
  while (temp != NULL)
  {
    if (temp->val == x)
    {
      found = true;
      break;
    }
    temp = temp->next;
  }
  if (found)
    cout << "Found!" << endl;
  else
    cout << "Not found" << endl;
}
void display()
{
  if (head == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  Node *temp = head;
  cout << "Doubly Linked List: ";
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}
int main()
{
  int choice;
  while (true)
  {
    cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
    cout << "1. Create List\n";
    cout << "2. Insert Node\n";
    cout << "3. Delete Node\n";
    cout << "4. Search Node\n";
    cout << "5. Display List\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      createList();
      break;
    case 2:
      insertNode();
      break;
    case 3:
      deleteNode();
      break;
    case 4:
      searchNode();
      break;
    case 5:
      display();
      break;
    case 6:
      cout << "Exiting program..." << endl;
      return 0;
    default:
      cout << "Enter a valid choice." << endl;
    }
  }
}
