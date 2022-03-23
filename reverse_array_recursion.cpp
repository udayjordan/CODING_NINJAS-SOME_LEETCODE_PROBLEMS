

// my SOLUTION ...BETTER SOLUTION IS STRIVER ONE .....IN COPY

#include<bits/stdc++.h>
using namespace std;
void insert(int *arr,int n,int temp){
    
    for(int i=n-1;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;

}
void reverse_array(int *arr,int n){
if(n==0){
    return;
}
int temp=arr[n-1];
reverse_array(arr,n-1);
insert(arr,n,temp);

}
int main(){
   int arr[]={1,2,3,4,5,8,9,10};
   reverse_array(arr,8);
   for(int i=0;i<8;i++){
       cout<<arr[i];
   }
}
