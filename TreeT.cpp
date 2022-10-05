
#include "TreeT.h"

template<class T>
TreeT<T>::TreeT()
{
  root = nullptr;
  numNodes = 0;
}

template<class T>
TreeT<T>::~TreeT()
{

}

template<class T>
TreeT<T> &TreeT<T>::operator=(const TreeT &otherTree)
{
    return *this;
}

template<class T>
void TreeT<T>::Add(T value)
{

    //craft new node first
    Node* newNode = new Node;
    newNode->value = value;

    //Empty Tree - set root to newNode
    if (root == nullptr)
    {
        root = newNode;
        numNodes++;
        return;
    }

    //need a node to traverse with
    Node* curr = root;

    while (curr != nullptr)
    {
        if (value < curr->value)
        {
            if (curr->left == nullptr)
            {
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        }
        else if (value > curr->value)
        {
            if (curr->right == nullptr)
            {
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        }
        else
        {
            //The value already exists, so need to delete newNode
            delete newNode;
            return;
        }
    }

    numNodes++;

}

template<class T>
void TreeT<T>::Remove(T value)
{

    RemoveHelper(root, value);
/*
    Node* curr = root;

    while (curr != nullptr)
    {
        if (value < curr->value)
        {
            curr = curr->left;
        }
        else if (value > curr->value)
        {
            curr = curr->right;
        }
        else
        {
            //Value is found in tree -- Time to delete
            DeleteNode(curr);
        }
    }
*/

}

template<class T>
bool TreeT<T>::Contains(T value)
{
    Node* curr = root;

    while (curr != nullptr)
    {
        if (value < curr->value)
        {
            curr = curr->left;
        }
        else if (value > curr->value)
        {
            curr = curr->right;
        }
        else
        {
            return true;
        }
    }

    return false;
}

template<class T>
int TreeT<T>::Size()
{
    return 0;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder)
{

}

template<class T>
T TreeT<T>::GetNextItem()
{
    return nullptr;
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node)
{

}

template<class T>
void TreeT<T>::RemoveHelper(TreeT::Node *&subtree, T value)
{
    Node* curr = root;

    while (curr != nullptr)
    {
        if (value < curr->value)
        {
            curr = curr->left;
        }
        else if (value > curr->value)
        {
            curr = curr->right;
        }
        else
        {
            //Value is found in tree -- Time to delete
            DeleteNode(curr);
        }
    }
}

template<class T>
void TreeT<T>::DeleteNode(TreeT::Node* &node)
{
    Node* tempNode = node;

    //No Children
    //One Child
    //Two Children
    if (node->left == nullptr && node->right == nullptr)
    {
        delete node;
        node = nullptr;
    }
    else if (node->left == nullptr)
    {
        node = node->right;
        delete tempNode;
    }
    else if (node->right == nullptr)
    {
        node = node->left;
        delete tempNode;
    }
    else
    {
        //Find largest value of left subtree
        T predVal = GetPredecessor(node->left);
        node->value = predVal; //Changes Node value with predVal
        RemoveHelper(node->left, predVal);

    }

}

template<class T>
T TreeT<T>::GetPredecessor(TreeT::Node* curr)
{
    //Go right until the next value might be nullptr
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }

    return curr->value;
}

template<class T>
void TreeT<T>::CopyHelper(TreeT::Node *&thisTree, TreeT::Node *otherTree)
{

}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node)
{

}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node)
{

}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node)
{

}
