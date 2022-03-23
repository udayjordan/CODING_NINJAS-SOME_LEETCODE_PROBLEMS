#include<bits/stdc++.h>
using namespace std;
#include<queue>
bool check_maxheap(int *arr,int n){
    int parentindex=0;
    int lchildindex=2*parentindex+1;
    int rchildindex=2*parentindex+2;
while(rchildindex<n){
if(arr[parentindex]<arr[lchildindex] || arr[parentindex]<arr[rchildindex]){
    return false;
}
parentindex++;
lchildindex=2*parentindex+1;
 rchildindex=2*parentindex+2;

}
return true;
}

int main(){
    int arr[]={20,48, 18, 6, 14, 11, 9, 4};
    cout<<check_maxheap(arr,8);

}