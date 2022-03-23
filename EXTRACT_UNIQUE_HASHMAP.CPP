// @csalgo

// Chapter Assignment
// Problem Statement: Extract Unique characters
// Problem Level: EASY
// Problem Description:
// Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
// Input format:
// The first and only line of input contains a string, that denotes the value of S.

// Output format :
// The first and only line of output contains the updated string, as described in the task.

// Constraints :
// 0 <= Length of S <= 10^8
// Time Limit: 1 sec

// Sample Input 1 :
// ababacd

// Sample Output 1 :
// abcd

// Sample Input 2 :
// abcde

// Sample Output 2 :
// abcde



// =====Answer=====
// Correct Option: 

// @csalgo









#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
void extract_unique(char *arr,int size){
unordered_map<char,int>c;
vector<char>v;
for(int i=0;i<size;i++){

if(c.count(arr[i])==0){
c[arr[i]]=1;
v.push_back(arr[i]);
}

}
for(int i=0;i<v.size();i++){
    cout<<v[i];
}

}
int main(){
int size;
cin>>size;
char arr[100];
for(int i=0;i<size;i++){
    cin>>arr[i];
}
extract_unique(arr,size);
}