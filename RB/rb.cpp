#include "rb.h"

//+++++++++++++PUBLIC+++++++++++++++++

RBTREE::RBTREE()
{
    TNULL = new Node(0);
    TNULL->color = BLACK;
    //TNULL->left = nullptr:
    //TNULL->right = nullptr;
    //TNULL->parent = nullptr;

    root = TNULL;
}

RBTREE::~RBTREE()
{
    deleteSubtree(root);
    delete TNULL;
}

void RBTREE::insert(int key){
    Node* node = new Node(key);
    //node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    //node->parent = nullptr;
    //node->color = RED;

    if(root == TNULL)
    {
        root = node;
        root->color = BLACK;
        return;
    }

    insertR(root, node);
    insertFix(node);
}

void RBTREE::remove(int key)
{
    root = removeR(root, key);
}

void RBTREE::printTree()
{
    if(root == TNULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    print(root, 0);
}

//++++++++++++PRIVATE+++++++++++++++++

void RBTREE::leftRotate(Node* y)
{
    Node* x = y->right;
    y->right = x->left; //adoption

    if(x->left != TNULL){ //updating parent of adopted left
        x->left->parent = y;
    }
    //update parent of x
    x->parent = y->parent;
    if(y->parent == nullptr){
        root = x;
    }else if(y == y->parent->left){
        y->parent->left = x;
    }else{
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}


void RBTREE::insertR(Node*& root, Node*& node){

}

void RBTREE::insertFix(Node* k){


    Node* uncle;
    //always when parent is red - violates property 3
    while(k->parent->color == RED){
        //parent is right child
        if(k->parent == k->parent->parent->right){
            uncle = k->parent->parent->left;
            //case 2: red uncle
            if(uncle->color == RED){
                uncle->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                //update k if there are any new violations up the tree
                k = k->parent->parent;
            }else{//uncle is black
                if(k == k->parent->left) {//case 3 -> triangle case
                    k = k->parent;
                    rightRotate(k);
                }
                //case 4 - line case
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        }else{//parent is left child (mirror image of the prev one)
            uncle = k->parent->parent->right;
            //case 2-> red uncle
            if(uncle->color == RED){
                uncle->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }else{//uncle is black
                if(k == k->parent->right){//case 3: triangle case
                    k = k->parent;
                    leftRotate(k);
                }
                //case 4
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }
        if(k == root){
            break;
        }
    }
    root->color = BLACK;
}


Node* RBTREE::removeR(Node* node, int key){
    if(node == TNULL){
        cout << "Key is not found in the tree" << endl;
        return node;
    }

    if(key < node->data){
        node->left = removeR(node->left, key);
    }else if(key > node->data){
        node->right = removeR(node->right, key);
    }
    else{
        Node* y = node; // node to be deleted
        Node* x; //replacement for delted node
        Color y_original_color = y->color;
        if(node->left == TNULL){//case 1: no left child
            x = node->right;
            transplant(node, node->right);
        }else if(node->right == TNULL){ // case 2: no right child
            x = node->left;
            transplant(node, node->left);
        }else{//case 3: both children present
            y = successor(node->right);
            y_original_color = y->color;
            x = y->right; // right child of successor

            if(y->parent != node){
                transplant(y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }
            transplant(node, y);
            y->left = node->left;
            y->left->parent = y;
            y->color = node->color;
        }
        delete node;
        if(y_original_color == BLACK){
            deleteFix(x);
        }
    }
    return root;
}

void RBTREE::deleteFix(Node* x){

}

void RBTREE::transplant(Node* u, Node* v){

}