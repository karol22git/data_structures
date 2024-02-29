
enum NodeColour {
    black  = 1,
    red = 2
};

template <typename T>
struct node {
    struct node<T>* up;
    struct node<T>* left;
    struct node<T>* right;
    T value;
    NodeColour colour;
};

namespace MyDataStructures {
    namespace BlackRedTree {
        template <typename T> 
        void AddNode(struct node<T>* root, T value);

        template <typename T>
        void InsertNode(struct node<T>* root, struct node<T>* node_to_add);

        template <typename T>
        bool Contains(struct node<T>* root, T value);

        template <typename T>
        struct node<T>* TreeInitialization(T value);

        template <typename T>
        void DeleteNode(struct node<T>* root, T value);

        template <typename T>
        void FixBlackRedTree(struct node<T>* node_to_fix);
    }
}