#include "BlackRedTree.hpp"


template <typename T>
struct node<T>* MyDataStructures::BlackRedTree::TreeInitialization(T value) {
    struct node<T>* new_node = new struct node<T>;
    new_node->up = nullptr;
    new_node->right = nullptr;
    new_node->left = nullptr;
    new_node->value = value;
    new_node->colour = NodeColour::black;
    return new_node;
}
template struct node<int>* MyDataStructures::BlackRedTree::TreeInitialization<int>(int value);

template <typename T>
bool MyDataStructures::BlackRedTree::Contains(struct node<T>* root, T value) {
    f(root == nullptr) {
        return false;
    }
    else {
        if(root->value == value) {
            return true;
        }
        else {
            if(root->value < value) {
                return MyDataStructures::BinaryTree::Contains(root->left,value);
            }
            else {
                return MyDataStructures::BinaryTree::Contains(root->right,value);
            }
        }
    }
}
template bool MyDataStructures::BlackRedTree::Contains(struct node<int>* root,int value);


template <typename T>
void MyDataStructures::BlackRedTree::AddNode(struct node<T>* root, T value) {
    struct node<T>* new_node = new struct node<T>;
    new_node->up = nullptr;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->value = value;
    new_node->colour = NodeColour::red;
    MyDataStructures::BlackRedTree::InsertNode(root,new_node);
    MyDataStructures::BlackRedTree::FixBlackRedTree(new_node);
}

template <typename T>
void MyDataStructures::BlackRedTree::InsertNode(struct node<T>* root, struct node<T>* node_to_add) {
    if(root->value < node_to_add->value) {
        if(root->left == nullptr) {
            root->left = node_to_add;
            node_to_add->up = root;
        }
        else {
            MyDataStructures::BinaryTree::InsertNode(root->left,node_to_add);
        }
    }
    else {
        if(root->right == nullptr) {
            root->right = node_to_add;
            node_to_add->up = root;
        }
        else {
            MyDataStructures::BinaryTree::InsertNode(root->right,node_to_add);
        }
    }
}

template <typename T>
void MyDataStructures::BlackRedTree::FixBlackRedTree(struct node<T>* node_to_fix) {
    if(node_to_fix->up->colour == NodeColour::black) {
        return;
    }
    
}
