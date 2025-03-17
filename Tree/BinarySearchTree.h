#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <string>
#include <iostream>

using namespace std;
template<class T>
 class BinarySearchTree
 {
private:
    struct Node {
        T key_;
        Node<T>* left_;
        Node<T>* right_;
        Node<T>* prev_;
        Node(const T& key) : key_(key), left_(nullptr), right_(nullptr), prev_(nullptr) {}
    };
    Node<T>* root_;

    void clear(Node* node) {
        if (node) {
            clear(node->left_);
            clear(node->right_);
            delete node;
        }
    }
    size_t getNumberofNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + getNumberofNodes(node->left_) + getNumberofNodes(node->right_);
    }

    int getHeight(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left_), getHeight(node->right_));
    }

public:
    BinarySearchTree() : root_(nullptr) {}
    ~BinarySearchTree() {
        clear(root_);
    }
    BinarySearchTree(const BinarySearchTree& other) : root_(nullptr) {
        root_ = other.root_;
        clear(other.root_);
    }
    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this != &other) {
            clear(root_);
            root_ = other.root_;
            return *this;
        }
        return *this;
    }
    bool searchIterative(const T& key) const {
        Node<T>* current = root_;
        while (current != nullptr && current->key_ != key) {
            if (key < current->key_) {
                current = current->left_;
            }
            else {
                current = current->right_;
            }
        }
        return current != nullptr;
    }
    bool insert(const T& key) {
        Node<T>* newNode = new Node<T>(key);
        Node<T>* current = root_;
        Node<T>* prev = nullptr;
        while (current != nullptr) {
            prev = current;
            if (key < current->key_) {
                current = current->left_;
            }
            else {
                current = current->right_;
            }
        }
        if (prev == nullptr) {
            root_ = newNode;
        }
        else if (key < prev->key_) {
            prev->left_ = newNode;
        }
        else {
            prev->right_ = newNode;
        }
        newNode->prev_ = prev;
        return true;
    }
    size_t getNumberofNodes() const {
        return getNumberofNodes(root_);
    }

    int getHeight() const {
        return getHeight(root_);
    }

    void inorderTreeWalkIterative() const {

    }

    void inorderTreeWalkRecursive() const {

    }

    void walkByLevels() const {

    }

    void printTree() const {
        
    }

#endif
