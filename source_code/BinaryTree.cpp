#include "BinaryTree.hpp"
#include  <iostream>

template <typename T>
struct node<T>* MyDataStructures::BinaryTree::BinaryTreeInit(T value) {
    struct node<T>* new_node = new struct node<T>;
    new_node->value = value;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}
template struct node<int>* MyDataStructures::BinaryTree::BinaryTreeInit<int>(int value);

template <typename T>
void MyDataStructures::BinaryTree::AddNode(struct node<T>* root, T value) {
    struct node<T>* new_node = new struct node<T>;
    new_node->value = value;
    new_node->right = nullptr;
    new_node->left = nullptr;
    MyDataStructures::BinaryTree::InsertNode(root,new_node);
}
template void MyDataStructures::BinaryTree::AddNode<int>(struct node<int>* root, int value);

template <typename T>
void MyDataStructures::BinaryTree::InsertNode(struct node<T>* root, struct node<T>* node_to_add) {
    if(root->value < node_to_add->value) {
        if(root->left == nullptr) {
            root->left = node_to_add;
        }
        else {
            MyDataStructures::BinaryTree::InsertNode(root->left,node_to_add);
        }
    }
    else {
        if(root->right == nullptr) {
            root->right = node_to_add;
        }
        else {
            MyDataStructures::BinaryTree::InsertNode(root->right,node_to_add);
        }
    }
}
template void MyDataStructures::BinaryTree::InsertNode<int>(struct node<int>* root, struct node<int>* node_to_add);

template <typename T>
bool MyDataStructures::BinaryTree::Contains(struct node<T>* root, T value) {
    if(root == nullptr) {
        return false;
    }
    else {
        if(root->value == value) {
            return true;
        }
        else {
            if(root->value < value) {
                MyDataStructures::BinaryTree::Contains(root->left,value);
            }
            else {
                MyDataStructures::BinaryTree::Contains(root->right,value);
            }
        }
    }
    
}
template bool MyDataStructures::BinaryTree::Contains(struct node<int>* root, int value);

template <typename T>
void MyDataStructures::BinaryTree::DeleteNode(struct node<T>* root, T value) {
    if(root->value < value) {
        if(root->left->value == value) {
            if(root->left->left == nullptr && root->left->right == nullptr) {
                root->left = nullptr;
            }
            else if(root->left->left != nullptr && root->left->right != nullptr) {
                MyDataStructures::BinaryTree::InsertNode(root->left->right,root->left->left);
                root->left = root->left->right;
            }
            else {
                if(root->left->left == nullptr) {
                    root->left = root->left->right;
                }
                else {
                    root->left = root->left->left;
                }
            }
        }
        else {
            MyDataStructures::BinaryTree::DeleteNode(root->left,value);
        }
    }
    else {
        if(root->right->value == value) {
            if(root->right->left == nullptr && root->right->right == nullptr) {
                root->right = nullptr;
            }
            else if(root->right->left != nullptr && root->right->right != nullptr) {
                MyDataStructures::BinaryTree::InsertNode(root->right->right,root->right->left);
                root->right = root->right->right;
            }
            else {
                if(root->right->left == nullptr) {
                    root->right = root->right->right;
                }
                else {
                    root->right = root->right->left;
                }
            }
        }
        else {
            MyDataStructures::BinaryTree::DeleteNode(root->right,value);
        }
    }
}
template void MyDataStructures::BinaryTree::DeleteNode<int>(struct node<int>* root, int value);

template <typename T>
void MyDataStructures::BinaryTree::ReadInorder(struct node<T>* root) {
    if(root != nullptr) {
        MyDataStructures::BinaryTree::ReadInorder(root->left);
        std::cout<<root->value<<" ";
        MyDataStructures::BinaryTree::ReadInorder(root->right);
    }
}
template void MyDataStructures::BinaryTree::ReadInorder<int>(struct node<int>* root);