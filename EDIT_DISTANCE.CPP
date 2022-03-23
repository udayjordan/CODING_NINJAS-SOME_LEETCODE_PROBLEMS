//BRUTE FORCE

#include<bits/stdc++.h>
using namespace std;
int edit_dis(string s,string t){
    
    if(s.size()==0 || t.size()==0){
      return max(s.size(),t.size());
    }

  if(s[0]==t[0]){
      return edit_dis(s.substr(1),t.substr(1));
  }
int  x=1+edit_dis(s.substr(1),t);
int y=1+edit_dis(s.substr(1),t.substr(1));
int z=1+edit_dis(s,t.substr(1));
return min(x,min(y,z));

}
//MEMOIZATION
int edit_dis_mem(string s,string t,int **output){
    int m=s.size();
    int n=t.size();
     if(s.size()==0 || t.size()==0){
      return max(s.size(),t.size());
    }
int ans;
  if(s[0]==t[0]){
      ans= edit_dis_mem(s.substr(1),t.substr(1),output);

  }
  if(output[m][n]!=-1){
return output[m][n];
  }
  else{
int  x=1+edit_dis_mem(s.substr(1),t,output);
int y=1+edit_dis_mem(s.substr(1),t.substr(1),output);
int z=1+edit_dis_mem(s,t.substr(1),output);
ans= min(x,min(y,z));
  }
  output[m][n]=ans;
  return output[m][n];
}
//DP SOLUTION
void edit_dis_dp(string s,string t,int **arr){
int m=s.size();
int n=t.size();

for(int i=0;i<n+1;i++){
arr[0][i]=i;
}
for(int j=1;j<=m;j++){
arr[j][0]=j;
}
 for(int i=1;i<m+1;i++){
for(int j=1;j<n+1;j++){
    if(s[m-i]==t[n-j]){
 arr[i][j]=arr[i-1][j-1];
    }
    else{
        arr[i][j]=min(1+arr[i-1][j],min(1+arr[i-1][j-1],1+arr[i][j-1]));
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
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    //cout<<edit_dis(s,t);
   // cout<<edit_dis_mem(s,t,output);
    edit_dis_dp(s,t,output);
}