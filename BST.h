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
      cout << node->data.id << endl;
      printTree(node->right);
    }

    //Looking at it now, I think this method and the printTree method, they look the exact same
	  void printInOrder(TreeNode<T> *node)
	  {
		  if (node != NULL)
		  {
			  printInOrder(node->left);
			  cout << node->data<<endl;
			  printInOrder(node->right);
		  }
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

    bool search(T nodeValue)
    {
      if(isEmpty()) //If the tree is empty, the value to be found won't exist
      {
        return false;
      }else //The tree has values
      {
        TreeNode<T> *curr = root;

        while(curr->data != nodeValue)
        {
          if(nodeValue < curr->data)
          {
            curr = curr->left;
          }else
          {
            curr = curr->right;
          }

          if(curr == NULL) //Value wasn't found
          {
            return false;
          }
        }
        return true;
      }
    }

    TreeNode<T>* getNode(T node)
    {
      TreeNode<T> *curr = root;

      while(curr->data != node)
      {
        if(node < curr->data)
        {
          curr = curr->left;
        }else
        {
          curr = curr->right;
        }
      }


      return curr;
    }

    bool deleteNode(T nodeValue)
    {
      if(isEmpty()) //Can't delete a node from an empty tree, nothing to delete
      {
        return false;
      }

      TreeNode<T> *parent = root;
      TreeNode<T> *curr = root;
      bool isLeft = true; //Tells us if the node is a left or a right node

      while(curr->data != nodeValue) //Haven't found the node yet
      {
        parent = curr;
        if(nodeValue < curr->data)
        {
          isLeft = true;
          curr = curr->left;
        }else
        {
          isLeft = false;
          curr = curr->right;
        }

        if(curr == NULL)
        {
            return false;
        }
      }

      //If we make it to here, that means we found the value to delete
      if(curr->left == NULL && curr->right == NULL) //If the node to be deleted is a leaf node
      {
        if(curr == root) //Is root node
        {
          root = NULL;
        }else if(isLeft) //Is left node
        {
          parent->left = NULL;
        }else //Is right node
        {
          parent->right = NULL;
        }
      }else if(curr->left == NULL)//Only a right child
      {
        if(curr == root) //Is root node
        {
          root = curr->right;
        }else if(isLeft) //Is left node
        {
          parent->left = curr->right;
        }else //Is right node
        {
        parent->right = curr->right;
        }
      }else if(curr->right == NULL) //Only  left child
      {
        if(curr == root) //Is root node
        {
          root = curr->left;
        }else if(isLeft) //Is left node
        {
          parent->left = curr->left;
        }else //Is right node
        {
          parent->right = curr->left;
        }
      }else //Node to be deleted has two children
      {
        TreeNode<T> *successor = getSuccessor(curr);

        if(curr == root)
        {
          root = successor;
        }else if(isLeft)
        {
          parent->left = successor;
        }else
        {
          parent->right = successor;
        }

        successor->left = curr->left;
      }
      return true;
    }

    TreeNode<T>* getSuccessor(TreeNode<T> *node)
    {
      TreeNode<T> *curr = node->right;
      TreeNode<T> *sp = node; //Successors parent
      TreeNode<T> *successor = node;

      while(curr != NULL)
      {
        sp = successor;
        successor = curr;
        curr = curr->left;
      }

      //if successor is not the right child of the node to be deleted
      if(successor != node->right)
      {
        sp->left = successor->right;
        successor->right = node->right;
      }

      return successor;
    }
};

//#endif
