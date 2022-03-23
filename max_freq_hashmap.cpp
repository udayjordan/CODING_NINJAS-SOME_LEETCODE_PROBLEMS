// @csalgo

// Coding Problem
// Problem Statement: Maximum Frequency Number
// Problem Level: EASY
// Problem Description:
// You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
// If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
// Input Format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.

// Output Format :
// The first and only line of output contains most frequent element in the given array.

// Constraints:
// 0 <= N <= 10^8
// Time Limit: 1 sec

// Sample Input 1 :
// 13
// 2 12 2 11 12 2 1 2 2 11 12 2 6

// Sample Output 1 :
// 2

// Sample Input 2 :
// 3
// 1 4 5

// Sample Output 2 :
// 1

// @csalgo




#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>

using namespace std;
 void maxfreq(int *arr,int size){
     unordered_map<int,int>c;
     int max;
    int e=1;
     vector<int>v;
for(int i=0;i<size;i++){
    if(c.count(arr[i])>0){
c[arr[i]]=e++;

    }
    else{
        c[arr[i]]=1;
        v.push_back(arr[i]);
    }
}
max=c[v[0]];
int d=v[0];
for(int j=1;j<v.size();j++){
if(max<c[v[j]]){
    max=c[v[j]];
d=v[j];
}

}
cout<<d;

 }
 int main(){
     int arr[]={12, 12 ,2 ,11 ,12 ,2 ,1 ,12 ,12 ,11, 12, 12, 6};
     maxfreq(arr,13);
 }