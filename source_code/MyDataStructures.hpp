
template <typename T>
struct node {
    T value;
    node* next;

};
namespace MyDataStructures {
    namespace LinkedList {
        template <typename T>
        void AddNode(struct node<T>* root, T value);
        template <typename T>
        struct node<T>* GetLastNode(struct node<T> *root);
        template <typename T>
        bool Contains(struct node<T> *root,T value);
        template <typename T>
        void DeleteNode(struct node<T>* root,T value);
        template<typename T>
        struct node<T>* LinkedListInit(T value);
    }
}

template <typename T>
void MyDataStructures::LinkedList::AddNode(struct node<T>* root, T value) {
    struct node<T> *new_node = new struct node<T>;
    new_node->value = value;
    new_node->next = nullptr;
    struct node<T> *last_node = GetLastNode(root);
    last_node->next = new_node;
    return;
}

template <typename T>
struct node<T>* MyDataStructures::LinkedList::GetLastNode(struct node<T> *root) {
    struct node<T>* tmp = root;
    while(tmp->next!=nullptr) {
        tmp = tmp->next;
    }
    return tmp;
}

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

template <typename T>
void MyDataStructures::LinkedList::DeleteNode(struct node<T>* root,T value) {
    struct node<T> tmp = root;
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

template <typename T>
struct node<T>* MyDataStructures::LinkedList::LinkedListInit(T value) {
    struct node<T>* new_node =  new struct node<T>;
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}