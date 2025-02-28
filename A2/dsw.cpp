#include "dsw.h"
MyException noroot("No Root Node!");
MyException dupe("Duplicate key");
MyException nokey("Key not found!");
// ----------------------- Private -------------------------------- 
int findsize(Node* node){
    if(node == nullptr){
        return 0;
    }
    int leftside = findsize(node->left);
    int rightside = findsize(node->right);

    return 1 + leftside + rightside;

}
void BST::rotateRight(Node*& node) {
    if (node == nullptr || node->left == nullptr) 
        return;

    Node* leftChild = node->left;   // get the node to rotate (left child of parent)
    node->left = leftChild->right; // nodes right child gets adopted as parents left child
    leftChild->right = node;       // parent becomes right child of node
    node = leftChild;              // replace parent by node
}


void BST::rotateLeft(Node*& node) {
    if (node == nullptr || node->right == nullptr) 
        return;

    Node* rightChild = node->right;  // get the node to rotate (right child of parent)
    node->right = rightChild->left;  // nodes left child gets adopted as parents right child 
    rightChild->left = node;         // parent becomes left child of node   
    node = rightChild;               // replace parent by node
}

void BST::createVine() {
    if (root == nullptr) {
        throw MyException("No root found!");
        return;
    }
        

    Node* grandparent = nullptr;
    Node* parent = root;
    Node* child = root->right;

    while (parent != nullptr) 
    {
        int childtreesize = findsize(child);
        
        if (child != nullptr && childtreesize > 2)
        {
            rotateLeft(parent);
            if (grandparent == nullptr)
                root = parent;
            else
                grandparent->right = parent;
            child = parent->right;
        } else {
            grandparent = parent;
            parent = parent->right;
            if (parent != nullptr)
                child = parent->right;
        }
    }
}

void BST::rebuildTree(int size) {
    // Get the largest perfect subtree
    int highestPowerOf2 = (int)pow(2, log2(size + 1));

    int m = (size + 1) - highestPowerOf2;  // Extra nodes

    // Initial rotation
    performRotations(m);
    // Subsequent rotations 
    for (size = (size - m) / 2; size > 0; size /= 2)
        performRotations(size);
}


// Perform left rotations on every second node
void BST::performRotations(int count) {
    Node* grandparent = nullptr;
    Node* parent = root;
    Node* child = root->left;

    for (int i = 0; i < count; i++) {
        if (child == nullptr) {
            throw MyException("Child not found1");
            break;
        }
            

        rotateRight(parent);
        if (grandparent == nullptr)
            root = parent;
        else
            grandparent->left = parent;

        grandparent = parent;
        parent = parent->left;
        if (parent != nullptr)
            child = parent->left;
    }
}

void BST::printTree(Node* root, int space) {
    const int COUNT = 10;

    if (root == nullptr) {
        throw MyException("No root found!");
        return;
    }

    space += COUNT;

    // Print the right child first
    printTree(root->right, space);

    // Print current node
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->data << endl;

    // Print left child
    printTree(root->left, space);
}

// ------------------- Public ---------------------------------

BST::BST() {
    root = nullptr;
}

BST::~BST() {
   deleteTree(root);
}

void BST::deleteTree(Node* node) {
    if (node == nullptr) 
        return;

   deleteTree(node->left);
   deleteTree(node->right);

   delete node;
}


void BST::insert(int val) {
   Node* newNode = new Node(val);
   if (root == nullptr) {
       root = newNode;
       return;
   }

   Node* curr = root;
   Node* parent = nullptr;

   while (curr != nullptr) {
       parent = curr;
       if (val < curr->data)
           curr = curr->left;
       else
           curr = curr->right;
   }

   if (val < parent->data)
       parent->left = newNode;
   else
       parent->right = newNode;
}

void BST::dswBalance() {
   if (root == nullptr) 
       return;

   // Step 1: Flatten tree into vine
   createVine();

   // Print vine
   cout << "After Phase 1:";
   display();

   // Step 2: Count the number of nodes
   int size = 0;
   Node* temp = root;
   while (temp != nullptr) {
       size++;
       temp = temp->left;
   }

   // Step 3: Rebuild tree to balance it
   rebuildTree(size);
}

void BST::display() {
   cout << endl;
   printTree(root, 0);
   cout << endl;
}