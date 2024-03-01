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
    if(node_to_fix->up->up->left = node_to_fix->up) {
        if(node_to_fix->up->up->right->colour == NodeColour::red) {
            node_to_fix->up->colour=NodeColour::black;
            node_to_fix->up->up->right->colour=NodeColour::black;
            node_to_fix->up->up->colour=NodeColour::red;
            if(node_to_fix->up->up->up == nullptr) {
                node_to_fix->up->up->colour=NodeColour::black;
                return;
            }
            else {
                FixBlackRedTree(node_to_fix->up->up);
                return;
            }
        }
        if(node_to_fix->up->up->right->colour==NodeColour::black && node_to_fix->up->right== node_to_fix) {
            struct node<T> *grandparent = node_to_fix->up->up;
            struct node<T>* parent = node_to_fix->up;
            struct node<T> *leftChild = node_to_fix->left;

            
            node_to_fix->up = grandparent;
            grandparent->left = node_to_fix;

            parent->up = node_to_fix;
            parent->right = node_to_fix->left;
            if(leftChild!=nullptr) {
                leftChild->up = parent;
            }
            node_to_fix->left = parent;
            FixBlackRedTree(node_to_fix->left);
            return;
        }
        struct node<T>* grandgrandparent = node_to_fix->up->up->up;
        bool left;
        if(grandparent->left = node_to_fix->up->up) {
            left = true;
        }
        else {
            left = false;
        }
        struct node<T>* bRight = node_to_fix->up->right;

        node_to_fix->up->right = node_to_fix->up->up;
        node_to_fix->up->up->parent = node_to_fix->up->right;
        node_to_fix->up->up->up = grandgrandparent;
        if(left) {
            grandgrandparent->left = node_to_fix->up;
        }
        else {
            grandgrandparent->right = node_to_fix->up;
        }

        node_to_fix->up->right->left= bRight;
        if(bRight!=nullptr) {
            bRight->up = node_to_fix->up->right;
        }
        node_to_fix->up->colour=NodeColour::black;
        return;
    }
    else {
        if(node_to_fix->up->up->left->colour == NodeColour::red) {
            node_to_fix->up->colour=NodeColour::black;
            node_to_fix->up->up->left->colour=NodeColour::black;
            node_to_fix->up->up->colour=NodeColour::red;
            if(node_to_fix->up->up->up == nullptr) {
                node_to_fix->up->up->colour=NodeColour::black;
                return;
            }
            else {
                FixBlackRedTree(node_to_fix->up->up);
                return;
            }
        }
        if(node_to_fix->up->up->right->colour==NodeColour::black && node_to_fix->up->left== node_to_fix) {
            struct node<T>* grandparent = node_to_fix->up->up;
            struct node<T>* rChild = node_to_fix->right;

            grandparent->right = node_to_fix;
            node_to_fix->right = node_to_fix->up;
            node_to_fix->up = grandparent;
            node_to_fix->right->up = node_to_fix;

            node_to_fix->right->left = rChild;
            if(rChild!=nullptr) {
                rChild->up = node_to_fix->right;
            }
            FixBlackRedTree(node_to_fix->right);
            return;
        }
        
    }
}
