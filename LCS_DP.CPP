// so IN THIS PROBLEM
//WE WILL BE GIVEN TWO STRINGS LIKE S:"abcdefgh"...LIKE KUCH BHI AND t:"dasbc"

// and we have to find the solution i.e longest common subsequence and find its length and return 
// ** SO main edge case or the main case int his problem will be if my 1st element of S and 1st ele
//ment of t are same if they are not we have choices like
//1.we will exclude the 1st element of S and call recursion on entire string (by entire i mean both s and t)
//2.same case as 1. will be true for t
//3.we are excluding both the first elment of S and t.


// BRUTE FORCE
// complexity worst O(3^n)
#include<bits/stdc++.h>
using namespace std;
int lcs_rec(string s,string t){
// BASE CASE ... WHAT CAN BE MY BASE CASE IN GENERAL WHEN EITHER OF TWO S OR T ENDS
if(s.size()==0 || t.size()==0){
    return 0;
}
// MAIN CASE AND THE KEY CASE FOR THE ENTIRE BRUTE FORCE
if(s[0]==t[0]){
    return 1+lcs_rec(s.substr(1),t.substr(1));

}
//these are no. of possible cases
int a=lcs_rec(s.substr(1),t);
int b=lcs_rec(s,t.substr(1));
int c=lcs_rec(s.substr(1),t.substr(1));

return max(a,max(b,c));


}
// MEMOIZATION 

int lcs_mem(string s,string t,int **output){
    int m=s.size();
    int n=t.size();
if(s.size()==0 || t.size()==0){
    return 0;
}

if(output[m][n]!=-1){
    return output[m][n];
}
int ans;
if(s[0]==t[0]){
     ans=1+lcs_mem(s.substr(1),t.substr(1),output);

}

else{
int a=lcs_mem(s.substr(1),t,output);
int b=lcs_mem(s,t.substr(1),output);
int c=lcs_mem(s.substr(1),t.substr(1),output);

 ans=max(a,max(b,c));
}
output[m][n]=ans;
return output[m][n];
}

void lcs_dp(string s,string t,int **arr){
    int m=s.size();
    int n=t.size();
    // so first thing is initialization
    for(int i=0;i<=n;i++){
        arr[0][i]=0;
    }
    for(int j=1;j<=m;j++){
        arr[j][0]=0;
    }
    for(int i=1;i<m+1;i++){
for(int j=1;j<n+1;j++){
    if(s[m-i]==t[n-j]){
 arr[i][j]=1+arr[i-1][j-1];
    }
    else{
        arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
    }
}
    }
    cout<<arr[m][n];


}
int main(){
    string s;
string t;
cin>>s>>t;
    int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i]=new int[n+1];
     for (int j=0;j<n+1;j++){
         output[i][j]=-1;
     }
    }


//cout<<lcs_rec(s,t);
//cout<<lcs_mem(s,t,output);
lcs_dp(s,t,output);
}