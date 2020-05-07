#include <iostream>

using namespace std;

template <class T>
class TreeNode{

  public:

    T data; //Generic data
    TreeNode *left; //Left child
    TreeNode *right; //Right child

    TreeNode()
    {
      left = NULL;
      right = NULL;
    }

    TreeNode(T MyData)
    {
      data = MyData;
      left = NULL;
      right = NULL;
    }

    ~TreeNode()
    {

    }


}
