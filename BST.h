//#ifndef BST
//#define BST

#include <iostream>
#include "TreeNode.h"

using namespace std;

template <class T>
class BST
{
  public:
    TreeNode<T> *root;


    BST()
    {
        root = NULL; //Empty tree
    }

    ~BST()
    {

    }

    void printTree(TreeNode<T> *node)
    {
      if(node == NULL)
      {
        return;
      }

      printTree(node->left);
      cout << node->data << endl;
      printTree(node->right);
    }

    TreeNode<T>* getMax()
    {
      TreeNode<T> *curr = root;
      if(root == NULL){
        return NULL; //No values in the tree
      }

      while(curr->right != NULL)
      {
        curr = curr->right; //Maximum value will be the furthest left child
      }

      return curr->data;
    }

    TreeNode<T>* getMin()
    {
      TreeNode<T> *curr = root;
      if(root = NULL){
        return NULL; //No values in the tree
      }

      while(curr->left != NULL)
      {
        curr = curr->left; //Minimum value will be the furthest left child
      }

      return curr->data;
    }


};

//#endif
