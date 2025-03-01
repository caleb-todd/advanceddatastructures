#include "avl.h"

int main(){
    AVLTree avl;

    //insert into avl
    cout << "Insert some numbers"<< endl;
    avl.insert(37);
    avl.insert(23);
    avl.insert(27);
    avl.insert(11);
    avl.insert(29);
    avl.insert(7);
    avl.insert(25);
    avl.print();
    cout << "Remove 11"<< endl;
    avl.remove(11);
    avl.print();
    cout << "Insert some numbers"<< endl;
    avl.insert(6);
    avl.insert(5);
    avl.insert(4);
    avl.print();
    cout << "Remove 6"<< endl;
    avl.remove(6);
    avl.print();
}