#ifndef AVL_H
#define AVL_H
#include "customErrorClass.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val){
        key = val;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

class AVLTree{
    public:
        AVLTree();
        ~AVLTree();

        void insert(int key);
        void remove(int key);
        void print();

    private:
        Node* root;
        Node* insert(Node* node, int key);
        Node* remove(Node* node, int key);
        Node* minValueNode(Node* node);

        int height(Node* node);
        int getBalanceFactor(Node* node);

        Node* rotateRight(Node* y);
        Node* rotateLeft(Node* x);

        void printTree(Node* root, int space);
        void destroyTree(Node* node);
};

#endif