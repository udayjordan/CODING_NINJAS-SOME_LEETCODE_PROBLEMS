// DP SOLUTION FOR 0/1KNAPSACK

// MEMOIZATION
#include<bits/stdc++.h>
using namespace std;

// TOP-DOWN APPROACH
void knapsack_1(int *val,int *wt,int w,int index,int n,int **arr){
for(int i=0;i<n+1;i++){
    for(int j=0;j<w+1;j++){
        if(i==0 || j==0){
            arr[i][j]=0;
        }
    }
}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=j){
               arr[i][j]= max(val[i-1]+arr[i-1][j-wt[i-1]],arr[i-1][j]);
            }
            else
arr[i][j]=arr[i-1][j];
        }
    }
cout<<arr[n][w];
}
int knapsack(int *val,int *wt,int w,int index,int n,int **arr){
// base condition
if(index==n || w==0){
    return 0;
}
if(arr[n][w]!=-1){
    return arr[n][w];
}
// condition
if(wt[index]<=w){
int x=val[index]+knapsack(val,wt,w-wt[index],index+1,n,arr);

int y=knapsack(val,wt,w,index+1,n,arr);
 arr[n][w]= max(x,y);
return arr[n][w];
}
else{
   arr[n][w]=knapsack(val,wt,w,index+1,n,arr); 
   return arr[n][w];
}

}

int main(){
int val[]={1,4,5,7};
int wt[]={1,3,4,5};
int weight=7;
int n=4;
int **arr=new int*[n+1];
for(int i=0;i<n+1;i++){
    arr[i]=new int[weight +1];
    for(int j=0;j<weight +1;j++){
        arr[i][j]=-1;
    }
}

cout<<knapsack(val,wt,weight,0,n,arr)<<"\n";
knapsack_1(val,wt,weight,0,n,arr);

}