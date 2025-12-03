#include <iostream>
using namespace std;
struct node
{
  int val;
  node *left;
  node *right;
};
node *insert(node *root, int x)
{
  if (root == NULL)
  {
    node *newNode = new node();
    newNode->val = x;
    newNode->left = newNode->right = NULL;
    return newNode;
  }
  if (x < root->val)
    root->left = insert(root->left, x);
  else if (x > root->val)
    root->right = insert(root->right, x);
  return root;
}
void inorder(node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}
bool searchNonRecursive(node *root, int n)
{
  while (root != NULL)
  {
    if (root->val == n)
      return true;
    else if (n < root->val)
      root = root->left;
    else
      root = root->right;
  }
  return false;
}
bool recursiveSearch(node *root, int n)
{
  if (root == NULL)
    return false;
  if (root->val == n)
    return true;
  if (n < root->val)
    return recursiveSearch(root->left, n);
  else
    return recursiveSearch(root->right, n);
}
node *findMin(node *root)
{
  while (root && root->left != NULL)
    root = root->left;
  return root;
}
node *findMax(node *root)
{
  while (root && root->right != NULL)
    root = root->right;
  return root;
}
node *inorderSuccessor(node *root, int val)
{
  node *successor = NULL;
  node *current = root;
  while (current)
  {
    if (val < current->val)
    {
      successor = current;
      current = current->left;
    }
    else if (val > current->val)
    {
      current = current->right;
    }
    else
    {
      // Node found
      if (current->right != NULL)
        successor = findMin(current->right);
      break;
    }
  }
  return successor;
}
node *inorderPredecessor(node *root, int val)
{
  node *predecessor = NULL;
  node *current = root;
  while (current)
  {
    if (val > current->val)
    {
      predecessor = current;
      current = current->right;
    }
    else if (val < current->val)
    {
      current = current->left;
    }
    else
    {
      // Node found
      if (current->left != NULL)
        predecessor = findMax(current->left);
      break;
    }
  }
  return predecessor;
}
int main()
{
  node *root = NULL;
  int x;
  cout << "Enter values to insert into BST (-1 to stop): ";
  while (true)
  {
    cin >> x;
    if (x == -1)
      break;
    root = insert(root, x);
  }
  cout << "\n===== Inorder Traversal of BST =====\n";
  inorder(root);
  cout << endl;
  // Searching
  cout << "\nEnter value to search: ";
  cin >> x;
  cout << "\n=== Non-Recursive Search ===\n";
  if (searchNonRecursive(root, x))
    cout << "Element found (Non-Recursive)\n";
  else
    cout << "Element not found (Non-Recursive)\n";
  cout << "\n=== Recursive Search ===\n";
  if (recursiveSearch(root, x))
    cout << "Element found (Recursive)\n";
  else
    cout << "Element not found (Recursive)\n";
  cout << "\nMinimum element in BST: " << findMin(root)->val << endl;
  cout << "Maximum element in BST: " << findMax(root)->val << endl;
  cout << "\nEnter the element to find its inorder successor: ";
  cin >> x;
  node *succ = inorderSuccessor(root, x);
  if (succ)
    cout << "Inorder successor of " << x << " is: " << succ->val << endl;
  else
    cout << "Inorder successor does not exist for " << x << endl;
  cout << "\nEnter the element to find its inorder predecessor: ";
  cin >> x;
  node *pred = inorderPredecessor(root, x);
  if (pred)
    cout << "Inorder predecessor of " << x << " is: " << pred->val << endl;
  else
    cout << "Inorder predecessor does not exist for " << x << endl;
  return 0;
}
