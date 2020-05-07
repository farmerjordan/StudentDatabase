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

    bool isEmpty()
    {
      return (root == NULL);
    }

    void insert(T nodeValue)
    {
      //Add check if the value already exists in the tree

      TreeNode<T> *node = new TreeNode<T>(nodeValue);

      if(isEmpty())
      {
        root = node; //Tree is empty, make the inserted node the root
      }else //Tree is not empty
      {
        TreeNode<T> *curr = root; //Start at the root
        TreeNode<T> *parent;

        while(curr != NULL) //While you aren't at the bottom of the tree
        {
            parent = curr;
            if(nodeValue < curr->data)//Go left
            {
              curr = curr->left;
              if(curr == NULL) //Reached insertion point
              {
                parent->left = node;
                break; //insertion complete
              }
            }else //Go right
            {
              curr = curr->right;
              if(curr == NULL)
              {
                parent->right = node;
                break;
              }
            }
        }
      }
    }

};

//#endif
