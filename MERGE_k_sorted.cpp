// @csalgo

// Chapter Assignment
// Problem Statement: Merge K sorted arrays
// Problem Level: MEDIUM
// Problem Description:
// Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
// Hint : Use Heaps.
// Input Format :
// Line 1 : Integer K
// Line 2 : Arrays 1 size (n1)
// Line 3 : Array 1 elements (separated by space)
// Line 4 : Array 2 size (n2)
// and so on for next arrays

// Sample Input 1 :
// 4
// 3
// 1 5 9
// 2
// 45 90
// 5
// 2 6 78 100 234
// 1
// 0

// Sample Output 1 :
// 0 1 2 5 6 9 45 78 90 100 234



// =====Answer=====
// Correct Option: 

// @csalgo







////done by taking help from gfg

#include<bits/stdc++.h>
using namespace std;
#include <queue>
vector<int> merge_k_sorted(vector<vector<int>>arr,int k){
typedef pair<int,pair<int,int>>pq;
vector<int>output;
priority_queue<pq,vector<pq>,greater<pq>>q;
for(int i=0;i<k;i++){
q.push({arr[i][0],{i,0}});
}
while(!q.empty()){
pq current=q.top();
q.pop();
int x= current.second.first;            //x is the array index
int y=  current.second.second;           //y is the element index
output.push_back(current.first);

if(y+1<arr[x].size()){
q.push({arr[x][y+1],{x,y+1}});

}
}
return output;

}
int main(){
vector<vector<int>>arr{ { 2, 6, 12 },
                              { 1, 9 },
                              { 23, 34, 90, 2000 } };

vector<int> output=merge_k_sorted(arr,3);
for(int i=0;i<output.size();i++){
    cout<<output[i]<<endl;
}
}