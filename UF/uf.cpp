#include "uf.h"

WeightedQuickUnion::WeightedQuickUnion(int n)
{
    this->n = n;
    parent = new int[n];
    size = new int[n];
    //initialize parent and size array
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    for(int i = 0; i<n; i++){
        size[i] = 1;
    }
}

WeightedQuickUnion::~WeightedQuickUnion()
{
    delete[] parent;
    delete[] size;

}

int WeightedQuickUnion::find(int p)
{
    while(p != parent[p]){ //root is its own parent
        parent[p] = parent[parent[p]]; //path compression
        p = parent[p];//follow the parent until you reach the root

    }
    return p;
}

void WeightedQuickUnion::Union(int p, int q){
    int rootp = find(p);
    int rootq = find(q);

    if(rootp == rootq){
        return;
    }
    //union by size/rank - make smaller tree child of larger tree
    if(size[rootp] < size[rootq])
    {
        parent[rootp] = rootq;
        //update the size
        size[rootq] += size[rootp];
    }else{
        parent[rootq] = rootp;
        size[rootp] += size[rootq];
    }

}

bool WeightedQuickUnion::connected(int p, int q){
    return find(p) == find(q);
}

void WeightedQuickUnion::print(){
    cout << "Parent Array: ";
    for(int i = 0; i< n; i++){
        //cout << "[" <<i << "]" << parent[i] << "";
        cout << parent[i] << " ";
    }
    cout << endl;
    cout << "Size:         ";
    for(int i = 0; i< n; i++){
        //cout << "[" <<i << "]" << size[i] << "";
        cout << size[i] << " ";
    }
    cout << endl;
}