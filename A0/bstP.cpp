#include "bstP.h"


MyException noroot("No Root Node!");
MyException dupe("Duplicate Value");

node::node(int value)
{
    data = value;
    leftChild = nullptr;
    rightChild = nullptr;
}

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    clearTree(root);
    // or call deleteNode
}

void BST::clearTree(node* node)
{
    if (root == nullptr)
        throw MyException("No Root node!");
        return;

    clearTree(node->leftChild);
    clearTree(node->rightChild);
    delete node;
}

void BST:: insertNode(node*& root, int data)
{
    // complete this
    if(root == nullptr){
        //if there is no root node yet, create one and make new node the root
        root = new node(data);
        return;
    }
    if(data == root->data){
        //error duplicate
        
        throw MyException("Error Found Duplicate!");
        return;
    }
    else if(data < root->data){
     //recursive call to keep moving down the left side
        insertNode(root->leftChild, data);
    }else{
        //recursive call to move down the right side
        insertNode(root->rightChild, data);
    }
}

node* BST:: searchNode(node*& root, int data)
{
    // complete this
    if(root == nullptr){
        //error node not found or no root
        throw MyException("No Root node!");
        return nullptr;
    }
    if(data == root->data){
        return root;
    }
    else if(data < root->data){
        //recursive call to move down left side
        return searchNode(root->leftChild, data);
    }else{
        //recursive call to move down right side
        return searchNode(root->rightChild, data);
    }

}

void BST:: deleteNode(node*& root, int data)
{
    // complete this
    if(root == nullptr){
        //error data not found
        throw MyException("Data not found!");
        return;
    }
    if(data < root->data){
        deleteNode(root->leftChild, data);
    }
    else if(data > root->data){
        deleteNode(root->rightChild, data);
    }
    else{
        //if node has no children
        if(root->leftChild == nullptr && root->rightChild == nullptr){
            //remove node
            delete root;
            root = nullptr;
        }
        //if node has only a left child
        else if(root->rightChild == nullptr){
            node* oldnode = root;
            root = root->leftChild;
            delete oldnode;
        }
        //if node has only a right child
        else if(root->leftChild == nullptr){
            node* oldnode = root;
            root = root->rightChild;
            delete oldnode;
        }
        //if node has two children >:(
        else{
            node* successor = root->leftChild;
            while(successor->rightChild != nullptr){
                successor = successor->rightChild;
            }
            root->data = successor->data;
            //recursively search subtree to delete original node of successor
            deleteNode(root->leftChild, successor->data);
        }
    }
    
}


void BST::preorder(node* root)
{
    //base case = end
    if(root == nullptr){
        return;
    }
    //printing for preorder
    cout << root->data << " ";
    
    //left
    preorder(root->leftChild);

    //right
    preorder(root->rightChild);
}

void BST::inorder(node* root)
{
    //base case = end
    if(root == nullptr){
        return;
    }
    //left
    inorder(root->leftChild);
    //printing for inorder
    cout << root->data << " ";
    //right
    inorder(root->rightChild);
}
void BST::postorder(node* root)
{
    //base case = end
    if(root == nullptr){
        return;
    }
    //left
    postorder(root->leftChild);
    //right
    postorder(root->rightChild);
    //printing for postorder
    cout << root->data << " ";
}

int BST::height(node* node)
{
    //base case = end
     if(root == nullptr){
        return -1;
     }
     //left subtree recursion
     int lh = height(root->leftChild);
     //right subtree recursion
     int rh = height(root->rightChild);
     //find which subtree is taller and add one for root
     if(lh >= rh){
        return lh+1;
     }else{
        return rh+1;
     }
}
bool BST:: isBalanced(node* root)
{
    if(root == nullptr){
        //error no tree
        
        throw MyException("No Root node!");
        return true;
    }

    int lh = height(root->leftChild);
    int rh = height(root->rightChild);

    //if heights are different
    if(rh != lh){
        return false;
    }
    bool rb = isBalanced(root->rightChild);
    bool lb = isBalanced(root->leftChild);
    if(rb == true && lb == true){
        return true;
    }else{
        return false;
    }

}

void BST::printTree(node* root, int space) {
    const int COUNT = 10; 

    if (root == nullptr) {
        
        //throw MyException("No Root node!");
        return;
    }

    // Increase the distance between levels
    space += COUNT;

    // Print the right child first (to appear on top)
    printTree(root->rightChild, space);

    // Print the current node after right child

    for (int i = COUNT; i < space; i++) {
        cout << " "; // Indentation for tree depth
    }
    cout << root->data << endl;

    // Print the left child
    printTree(root->leftChild, space);
}

