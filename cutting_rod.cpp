#include<bits/stdc++.h>
using namespace std;

// TOP-DOWN APPROACH
/* int length[]={1,2,3,4,5,6,7,8};
int price[]={1,5,8,9,10,17,17,20};
N=8;//(size of the rod)
*/
void knapsack_1(int *val,int *len,int N,int n,int **arr){
for(int i=0;i<n+1;i++){
    for(int j=0;j<N+1;j++){
        if(i==0 || j==0){
            arr[i][j]=0;
        }
    }
}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=N;j++){
            if(len[i-1]<=j){
               arr[i][j]= max(val[i-1]+arr[i][j-len[i-1]],arr[i-1][j]);
            }
            else
arr[i][j]=arr[i-1][j];
        }
    }
cout<<arr[n][N];
}
int main(){
 int len[]={1,2,3,4,5,6,7,8};
int val[]={1,5,8,9,10,17,17,20};
int N=8;//(size of the rod)
int n=8;
int **arr=new int*[n+1];
for(int i=0;i<n+1;i++){
    arr[i]=new int[N+1];
    for(int j=0;j<N +1;j++){
        arr[i][j]=-1;
    }
}


knapsack_1(val,len,N,n,arr);

}