#include<bits/stdc++.h>
#include<queue>
using namespace std;
void k_sorted(int *input,int n,int k){
priority_queue<int>pq;
    for(int i=0;i<k;i++){
pq.push(input[i]);

    }
int j=0;
for(int i=k;i<n;i++){
    pq.push(input[i]);
 input[j]=pq.top();
pq.pop();
j++;

}
while(!pq.empty()){
    input[j]=pq.top();
    pq.pop();
    j++;

}


}
int main(){
int arr[]={15,10,6,4,5,3};
k_sorted(arr,6,3);
for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
}
}