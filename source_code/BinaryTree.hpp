
template <typename T>
struct node {
    T value;
    struct node<T>* right;
    struct node<T>* left;
};

namespace MyDataStructures {
    namespace BinaryTree {
        template <typename T>
        void AddNode(struct node<T>* root, T value);

        template <typename T> 
        struct node<T>* BinaryTreeInit(T value);

        template <typename T>
        bool Contains(struct node<T>* root,T value);

        template <typename T>
        void DeleteNode(struct node<T>* root,T value);

        template <typename T>
        void InsertNode(struct node<T>* root, struct node<T>* node_to_add);

        template <typename T>
        void ReadInorder(struct node<T>* root);
    }
}