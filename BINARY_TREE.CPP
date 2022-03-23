//CODE TO TAKE INPUT LEVEL WISE AND PRINT RECURSIVELY
// ......
// .....
// CODE TO TAKE INPUT RECURSIVELY AND PRINT recursively i)PRE-ORDER
                                                       // ii)POST-ORDER
                                                       // III) INORDER
// .......
// 

//TO DO PRINT LEVELWISE


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
void print_levelwise(binary_tree_node<int>*root){
    if(root==NULL){
        return;
    }
    queue<binary_tree_node<int>*>q;
    q.push(root);
    while(q.size()!=0){
        binary_tree_node<int>* front=q.front();
        cout<<front->data<<" ";
        q.pop();
        if(front->left!=NULL){
q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }

}
//preorder traversal
void print_binary_tree(binary_tree_node<int>*root){
 
    if(root==NULL){
        return;
    }
   cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<",";
    }
cout<<endl;
print_binary_tree(root->left);
print_binary_tree(root->right);

}
//IN-ORDER TRAVERSAL
void print_inorder(binary_tree_node<int>*root){
   
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
   cout<<root->data<<" " ;
   print_inorder(root->right);

}
// post-order TRAVERSAL
void print_post_order(binary_tree_node<int>*root){
   
    if(root==NULL){
        return;
    }
    print_post_order(root->left);
   
   print_post_order(root->right);
   cout<<root->data<<" " ;

}
//ENTERING DATA RECURSIVELY
 binary_tree_node<int> * insert_node(){
     int data;
 cout<<"enter the node";
 cin>>data;
 if(data==-1){
     return NULL;
 }
 binary_tree_node<int> *root=new binary_tree_node<int>(data);
 binary_tree_node<int> *leftchild=insert_node();
 binary_tree_node<int> *rightchild=insert_node();
 root->left=leftchild;
 root->right=rightchild;
 return root;



 }
 //entering DATA LEVEL WISE 
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
int main(){
binary_tree_node<int> *root=insert_data();
print_post_order(root);
delete root;
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1