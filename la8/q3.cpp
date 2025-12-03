#include <iostream>
using namespace std;

struct node
{
  int val;
  node *left;
  node *right;
};

node *root = NULL;

node *insert(node *root, int x)
{
  if (root == NULL)
  {
    node *newNode = new node();
    newNode->val = x;
    newNode->left = newNode->right = NULL;
    return newNode;
  }
  if (x == root->val)
  {
    cout << "Duplicate value " << x << " not allowed.\n";
    return root;
  }
  if (x < root->val)
    root->left = insert(root->left, x);
  else
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

node *deleteNode(node *root, int x)
{
  if (root == NULL)
    return NULL;

  if (x < root->val)
    root->left = deleteNode(root->left, x);
  else if (x > root->val)
    root->right = deleteNode(root->right, x);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    else if (root->left == NULL)
    {
      node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL)
    {
      node *temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      node *temp = root->right;
      while (temp->left != NULL)
        temp = temp->left;
      root->val = temp->val;
      root->right = deleteNode(root->right, temp->val);
    }
  }
  return root;
}

int minDepth(node *root)
{
  if (root == NULL)
    return 0;
  if (root->left == NULL)
    return minDepth(root->right) + 1;
  if (root->right == NULL)
    return minDepth(root->left) + 1;
  int leftDepth = minDepth(root->left);
  int rightDepth = minDepth(root->right);
  return min(leftDepth, rightDepth) + 1;
}

int maxDepth(node *root)
{
  if (root == NULL)
    return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return max(leftDepth, rightDepth) + 1;
}

int main()
{
  int n;
  cout << "Enter number of elements in BST: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x;
    cout << "Enter value: ";
    cin >> x;
    root = insert(root, x);
  }

  cout << "\n=== Inorder Traversal ===\n";
  inorder(root);
  cout << endl;

  cout << "\nEnter node to insert: ";
  cin >> n;
  root = insert(root, n);

  cout << "\n=== Inorder after insertion ===\n";
  inorder(root);
  cout << endl;

  cout << "\nEnter node to delete: ";
  cin >> n;
  root = deleteNode(root, n);

  cout << "\n=== Inorder after deletion ===\n";
  if (root)
    inorder(root);
  else
    cout << "Tree is empty.";
  cout << endl;

  cout << "\nMax Depth of BST: " << maxDepth(root)
       << "\nMin Depth of BST: " << minDepth(root) << endl;

  return 0;
}
