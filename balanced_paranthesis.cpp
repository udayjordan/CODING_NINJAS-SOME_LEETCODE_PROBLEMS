#include<bits/stdc++.h>
#include<stack>
using namespace std;
bool fun(){
    stack<char>s1;
    string s="{[]}";
    for(int i=0;i<s.size();i++){
if(s[i]=='{'||s[i]=='['){
s1.push(s[i]);
}
else if(s[i]==']'){
    if(s1.top()=='['){
        s1.pop();
    }
    else{
        return false;
        break;
    }
}
else if(s[i]=='}'){
    if(s1.top()=='{'){
        s1.pop();
    }
    else{
        return false;
        break;
    }
}
    }
    return true;
    
}
int main(){
    cout<<fun();
}