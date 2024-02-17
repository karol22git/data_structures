
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
