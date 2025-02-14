#include "splay.h"

SplayTree::SplayTree() 
{
    root = nullptr; 
}

// aka Zig
SplayTree::Node* SplayTree::rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// aka Zag
SplayTree::Node* SplayTree::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splaying :)
SplayTree::Node* SplayTree::splay(Node* root, int key) {
    // complete this
    
    //if there is no root, or if root is the key
    if(root == nullptr || root->key == key){
        return root;
    }

    //if the key is in the left subtree
    if(key < root->key){
        //in the case that left is  null
        if(root->left == nullptr){
            return root;
        }

        //zig zig
        Node* leftnode = root->left;
        if(key < leftnode->key){ //if the key is less than this, go left again
            leftnode->left = splay(leftnode->left, key); //recursively splay the left side
            root = rotateRight(root); //then rotate root to finish
        }
        //zig zag
        else if(key > leftnode->key){//if the key is more than this, go right
            leftnode->right = splay(leftnode->right, key);//recursively splay right side
            if(leftnode->right != nullptr){//if right of this isn't null...
                leftnode = rotateLeft(leftnode);
            }
        }

        //do final right rotation
        if(leftnode == nullptr){ //in case leftnode is now null
            return root;
        }else{
            return rotateRight(root);
        }
    }
    //otherwise, key is in right subtree
    else{
        if(root->right == nullptr){//in case right is null
            return root;
        }
        //zag zag
        Node* rightnode = root->right;
        if(key > rightnode->key){ //if key is more than right node.. go right
            rightnode->right = splay(rightnode->right, key); //recursively splay right side
            root = rotateLeft(root); //rotate root to finish
        }
        //zag zig
        else if(key < rightnode->key){//if key is less than right side.. go left
            rightnode->left = splay(rightnode->left, key); //recursively splay left side
            if(rightnode->left != nullptr){//in case leftnode is null
                root->right = rotateRight(rightnode);
            }
        }
        //do final left rotation
        if(root->right == nullptr){//in case rightnode is now null
            return root;
        }else{
            return rotateLeft(root);
        }
    }
}


SplayTree::Node* SplayTree::insertNode(Node* root, int key) {
    // complete this
    //if the tree is empty, make the tree
    if(root == nullptr){
        return new Node(key);
    }
    //splay the tree, so the key will be at the root
    root = splay(root, key);

    //if key is already in tree, error
    if(root->key == key){
        return root;
    }

    //create new node
    Node* newnode = new Node(key);

    //attach subtrees depending on key
    if(key < root->key){
        newnode->right = root; //old root becomes rchild
        newnode->left = root->left; //left subtree becomes new nodes left subtree
        root->left = nullptr; //snap old root left subtree link

    }else{
        newnode->left = root; //old root becomes lchild
        newnode->right = root->right; //right subtree becomes new nodes right subtree
        root->right = nullptr; //snip old root right link
    }
    return newnode;
}


SplayTree::Node* SplayTree::deleteNode(Node* root, int key) {
    // complete this
    if (root == nullptr){
        //ERROR! NO TREE
        return nullptr;
    }

    root = splay(root, key); //splay to bring key to root

    //if no key, return root without change
    if(root->key != key){
        //ERROR! NO KEY!
        return root;
    }
    //if no children
    if(root->left == nullptr && root->right == nullptr){
        delete root;
        return nullptr;
    }
    //no left child = right subtree
    if(root->left == nullptr){
        Node* newroot = root->right;
        delete root;
        return newroot;
    }
    //no right child = left subtree
    if(root->right == nullptr){
        Node* newroot = root->left;
        delete root;
        return newroot;
    }
    //both children
    //splay left to bring largest to root
    Node* newroot = splay(root->left, key);
    newroot->right = root->right;
    delete root;
    return newroot;
}


void SplayTree::insert(int key) {
    root = insertNode(root, key);
}


void SplayTree::remove(int key) {
    root = deleteNode(root, key);
}


bool SplayTree::search(int key) {
    root = splay(root, key);
    return (root && root->key == key);
}


void SplayTree::printTree(Node* root, int space) {
    const int COUNT = 10; 

    if (root == nullptr) {
        return;
    }

    // Increase the distance between levels
    space += COUNT;

    // Print the right child first (to appear on top)
    printTree(root->right, space);

    // Print the current node after right child

    for (int i = COUNT; i < space; i++) {
        cout << " "; // Indentation for tree depth
    }
    cout << root->key << endl;

    // Print the left child
    printTree(root->left, space);
}

void SplayTree::display() {
    printTree(root, 0);
    cout << endl;
}
