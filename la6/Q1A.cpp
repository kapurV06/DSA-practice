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
     if (x == 1)
  {
       newNode->next = head;
         tail->next = newNode;
    head = newNode;
  }
  else if (x == n + 1)
  {
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
  }
  else
  {
    temp = head;
    for (int i = 1; i < x - 1; i++)
    {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
  n++;
}
void deleteNode()
{
       cout << "Enter the node position you want to delete: ";
    int x;
    cin >> x;
     if (x < 1 || x > n)
  {
    cout << "Enter a valid value" << endl;
    return;
  }
  if (x == 1)
  {
    Node *tempNode = head;
          tail->next = head->next;
       head = head->next;
    delete tempNode;
  }
  else if (x == n)
  {
    temp = head;
    while (temp->next != tail)
    {
      temp = temp->next;
    }
    Node *tempNode = tail;
    temp->next = head;
    tail = temp;
    delete tempNode;
  }
  else
  {
    temp = head;
    for (int i = 1; i < x - 1; i++)
    {
      temp = temp->next;
    }
    Node *tempNode = temp->next;
    temp->next = temp->next->next;
    delete tempNode;
  }
  n--;
}
void searchNode()
{
  cout << "Enter the value you want to search: ";
  int x;
  cin >> x;
  temp = head;
  bool found = false;
  if (head == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  do
  {
    if (temp->val == x)
    {
      found = true;
      break;
    }
    temp = temp->next;
  } while (temp != head);
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
  temp = head;
  cout << "Circular Linked List: ";
  do
  {
    cout << temp->val << " ";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}
int main()
{
  int choice;
  while (true)
  {
    cout << "\n===== CIRCULAR LINKED LIST MENU =====\n";
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
