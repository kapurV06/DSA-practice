#include <iostream>
using namespace std;
struct node
{
  int val;
  node *left;
  node *right;
};
node *root = NULL;
node *create()
{
  cout << "enter the node value of tree: ";
  int x;
  cin >> x;
  if (x == -1)
    return NULL;
  node *newNode = new node();
  newNode->val = x;
  cout << "Enter the value of left child or press -1 for NULL " << endl;
  newNode->left = create();
  cout << "Enter the value of right child or press -1 for NULL" << endl;
  newNode->right = create();
  return newNode;
}
void inorder(node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}
void preorder(node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(node *root)
{
  if (root == NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}
int main()
{
  root = create();
  cout << "===== Inorder Binary Tree=====" << endl;
  inorder(root);
  cout << endl;
  cout << "===== Preorder Binary Tree=====" << endl;
  preorder(root);
  cout << endl;
  cout << "===== Postorder Binary Tree=====" << endl;
  postorder(root);
  cout << endl;
  return 0;
}
