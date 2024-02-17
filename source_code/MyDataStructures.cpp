#include "MyDataStructures.hpp"


template <typename T>
void MyDataStructures::LinkedList::AddNode(struct node<T>* root, T value) {
    struct node<T> *new_node = new struct node<T>;
    new_node->value = value;
    new_node->next = nullptr;
    struct node<T> *last_node = GetLastNode(root);
    last_node->next = new_node;
    return;
}
template void MyDataStructures::LinkedList::AddNode<int>(struct node<int> *root,int value);

template <typename T>
struct node<T>* MyDataStructures::LinkedList::GetLastNode(struct node<T> *root) {
    struct node<T>* tmp = root;
    while(tmp->next!=nullptr) {
        tmp = tmp->next;
    }
    return tmp;
}
template struct node<int>* MyDataStructures::LinkedList::GetLastNode<int>(struct node<int> *root);

template <typename T>
bool MyDataStructures::LinkedList::Contains(struct node<T> *root,T value) {
    bool result = false;
    struct node<T> *tmp = root;
    while(tmp!=nullptr) {
        if(tmp->value == value) {
            result = true;
        }
        tmp = tmp->next;
    }
    return result;
}
template bool MyDataStructures::LinkedList::Contains<int>(struct node<int> *root,int value);

template <typename T>
void MyDataStructures::LinkedList::DeleteNode(struct node<T>* root,T value) {
    struct node<T>* tmp = root;
    if(root->value == value) {
        root = root->next;
    }
    else {
        while(tmp->next!=nullptr) {
            if(tmp->next->value == value) {
                tmp->next = tmp->next->next;
            }
        }
    }
} 
template  void MyDataStructures::LinkedList::DeleteNode<int>(struct node<int>* root,int value);

template <typename T>
struct node<T>* MyDataStructures::LinkedList::LinkedListInit(T value) {
    struct node<T>* new_node = new struct node<T>;
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}
template struct node<int>* MyDataStructures::LinkedList::LinkedListInit<int>(int);