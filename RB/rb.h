#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
using namespace std;

//ANSI escape codes for colors

#define RED_COLOR "\033[1;31m"
#define BLACK_COLOR "\033[1;30m"
#define RESET_COLOR "\033[0m"

//group of constants
enum Color {RED, BLACK};

struct Node
{
    int data;
    Node* left;
    Node* right;
    Color color;
    Node* parent;

    Node(int key){
        data = key;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        color = RED;
    }
};

class RBTREE
{
    private:
        Node* root;
        Node* TNULL; //for NIL nodes
        void leftRotate(Node* y);
        void rightRotate(Node* y);

        void insertR(Node*& root, Node*& node);
        void insertFix(Node* k);

        Node* removeR(Node* node, int key);
        void deleteFix(Node* x);
        void transplant(Node* u, Node* v);
        Node* successor(Node* node);

        void deleteSubtree(Node* node);
        void print(Node* root, int space);
    public:
        RBTREE();
        ~RBTREE();
        void insert(int key);
        void remove(int key);

        void printTree();
};

#endif