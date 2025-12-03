#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
struct node
{
  int val;
  node *left;
  node *right;
};
node *root = NULL;
node *createNode(node *root)
{
  int x;
  cout << "Enter the Value of Node or -1 for NULL :";
  cin >> x;
  if (x == -1)
  {
    return NULL;
  }
  node *newNode = new node();
  newNode->val = x;
  newNode->left = NULL;
  newNode->right = NULL;
  cout << "Enter the node to the left of " << x << ":" << endl;
  newNode->left = createNode(newNode->left);
  cout << "Enter the node to the right of " << x << ":" << endl;
  newNode->right = createNode(newNode->right);
  return newNode;
}
vector<int> inorder(node *root, vector<int> v)
{
  if (root == NULL)
  {
    return v;
  }
  v = inorder(root->left, v);
  v.push_back(root->val);
  v = inorder(root->right, v);
  return v;
}
int main()
{
  root = createNode(root);
  vector<int> r = inorder(root, v);
  if (is_sorted(r.begin(), r.end()))
  {
    cout << "The tree is BST" << endl;
  }
  else
  {
    cout << "The tree is not BST" << endl;
  }
}
