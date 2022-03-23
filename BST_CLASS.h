#include <bits/stdc++.h>
using namespace std;
template <typename T>
class binary_tree_node{
public:
int data;


binary_tree_node<int> *next;

binary_tree_node<int> *left;
binary_tree_node<int> *right;
binary_tree_node(T data){
    this->data=data;
    left=NULL;
    right=NULL;
    next=NULL;

}
~binary_tree_node(){
    delete left;
    delete right;
}
};