#include<bits/stdc++.h>

using namespace std;
template <typename T>
class binary_tree_node{
public:
int data;
binary_tree_node<int> *left;
binary_tree_node<int> *right;
binary_tree_node(T data){
    this->data=data;
    left=NULL;
    right=NULL;
}
~binary_tree_node(){
    delete left;
    delete right;
}
};
binary_tree_node<int>*insert_data(){
    int data;
    cout<<"enter the root data"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    binary_tree_node<int> *root=new binary_tree_node<int>(data);
    queue<binary_tree_node<int>*>Q;
    Q.push(root);
    while(Q.size()!=0){

binary_tree_node<int> *front=Q.front();
Q.pop();
int leftchild_data;
cout<<"enter the left child of "<<front->data<<endl;
cin>>leftchild_data;
if(leftchild_data!=-1){
   binary_tree_node<int> *leftchild=new binary_tree_node<int>(leftchild_data); 
   front->left=leftchild;
   Q.push(leftchild);
}
int rightchild_data;
cout<<"enter the right child of "<<front->data<<endl;
cin>>rightchild_data;
if(rightchild_data!=-1){
   binary_tree_node<int> *rightchild=new binary_tree_node<int>(rightchild_data); 
   front->right=rightchild;
   Q.push(rightchild);
}



    }
    return root;

}
pair<int,int>heightDiameter(binary_tree_node<int>*root){
if(root==NULL){
    pair<int,int>p;
    p.first=0;
    p.second=0;
    return p;

}
pair<int,int>firstans=heightDiameter(root->left);
pair<int,int>secondans=heightDiameter(root->right);
int lh=firstans.first;
int rh=secondans.first;
int ld=firstans.second;
int rd=secondans.second;

int height= 1 + max(lh,rh);
int diameter=max(lh+rh,max(ld,rd));
pair<int,int>p;
p.first=height;
p.second=diameter;
return p;



}
// THIS CODE HAS THE WORST TIE-COMPLEXITY
//O(n^2)
// int height_BT(binary_tree_node<int>* root){
//     if(root==NULL){
//         return 0;
//     }
//     int lh=height_BT(root->left);
// int rh=height_BT(root->right);
// return 1+ max(lh,rh);
// }
// int diameter_BT(binary_tree_node<int>* root){
//     if(root==NULL){
//         return 0;
//     }
//     int option1=height_BT(root->left)+height_BT(root->right);
//     int option2=diameter_BT(root->left);
//     int option3=diameter_BT(root->right);
//     return max(option1,max(option2,option3));
// }

int main(){
binary_tree_node<int> *root=insert_data();
pair<int,int>p=heightDiameter(root);
cout<<"height :"<<p.first<<"diameter :"<<p.second;
delete root;
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1