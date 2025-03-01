#include "avl.h"
MyException noroot("No Root Node!");
MyException dupe("Duplicate key");
MyException nokey("Key not found!");
//++++++++++PRIVATE++++++++++++
AVLTree::AVLTree(){
    root = nullptr;
}

AVLTree::~AVLTree(){
    destroyTree(root);
}

void AVLTree::destroyTree(Node* node){
    if(node){
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

int AVLTree::height(Node* node){
    if(node){
        return node->height;
    }else{
        return -1;
    }
}

int AVLTree::getBalanceFactor(Node* node){
    if(node){
        return height(node->right) - height(node->left);
    }else{
        return 0;
    }
}

Node* AVLTree::rotateRight(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) +1;
    x->height = max(height(x->left), height(x->right)) +1;
    return x;
}
Node* AVLTree::rotateLeft(Node* y){
    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(height(y->left), height(y->right)) +1;
    x->height = max(height(x->left), height(x->right)) +1;
    return x;
}

void AVLTree::printTree(Node* root, int space){
    const int COUNT = 10;

    if (root == nullptr) {
        //throw MyException("No root found!");
        return;
    }

    space += COUNT;

    // Print the right child first
    printTree(root->right, space);

    // Print current node
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->key << endl;

    // Print left child
    printTree(root->left, space);
}

Node* AVLTree::insert(Node* node, int key){
    //if there is no root
    Node* newNode = new Node(key);
    if(node == nullptr){
        return newNode;
    }

    //recursively find the spot to insert the node
    if(key < node->key){
        node->left = insert(node->left, key);
    }else if(key > node->key){
        node->right = insert(node->right, key);
    }else{
        throw MyException("Error- duplicate key entered");
        return node;
    }

    //update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    //find balance factor

    int bf = getBalanceFactor(node);

    //do rotations if tree is unbalanced

    //if left heavy, rotate right
    if(bf < -1 && key < node->left->key){
        return rotateRight(node);
    }

    //if right heavy, rotate left
    if(bf > 1 && key > node->right->key){
        return rotateLeft(node);
    }

    //left right = left rotate right rotate
    if(bf < -1 && key > node->left->key){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    //right left = right rotate left rotate
    if(bf > 1 && key < node->right->key){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    //throw MyException("no changes made");
    return node; //no rotations
}
Node* AVLTree::minValueNode(Node* node){
    Node* i = node;
    while(i->left != nullptr){
        i = i->left;//i++
    }
    return i;
}
Node* AVLTree::remove(Node* node, int key){
    //1st: remove the node
    if(node == nullptr){
        return node;//no node?
    }
    if(key < node->key){
        node->left = remove(node->left, key);//move left, recursive call
    }else if(key > node->key){
        node->right = remove(node->right, key); //move right, recursive call
    }else{//found
        //case 1: no children
        if(node->left == nullptr && node->right == nullptr){
            node = nullptr;
        }else if(node->right == nullptr){//case two: only left child
            node = node->left;
        }else if(node->left == nullptr){//case 3: only right child
            node = node->right;
        }else{//both children exist
            Node* m = minValueNode(node->right);//get successor
            node->key = m->key; //copy value
            node->right = remove(node->right, m->key);//delete old successor node
        }
    }

    if(node == nullptr){
        return node; //no node?
    }

    //step 2: verify height
    node->height = 1 + max(height(node->left), height(node->right));

    //see if we are balanced still
    int bf = getBalanceFactor(node);

    //if not...

    //left heavy right rotate
    if(bf < -1 && getBalanceFactor(node->left) <= 0){
        return rotateRight(node);
    }
    //right heavy left rotate
    if(bf > 1 && getBalanceFactor(node->right) >= 0){
        return rotateLeft(node);
    }
    //left right left rotate right rotate
    if(bf < -1 && getBalanceFactor(node->left) > 0){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    //right left right rotate left rotate
    if(bf > 1 && getBalanceFactor(node->right) < 0){
        node->right = rotateRight(node->right);
        return rotateLeft(node);

    }
    return node;
}


//++++++++++++PUBLIC++++++++++++

void AVLTree::insert(int key){
    root = insert(root, key);
}
void AVLTree::remove(int key){
    root = remove(root, key);
}
void AVLTree::print(){
   cout << endl;
   printTree(root, 0);
   cout << endl;
}