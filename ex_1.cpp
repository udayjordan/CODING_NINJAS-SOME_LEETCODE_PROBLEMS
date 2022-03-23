#include<bits/stdc++.h>
using namespace std;
int ans=0;
int sum_N(int n){
    if(n==0){
        return 0;
    }
    ans=n+sum_N(n-1);
    return ans;

}
int main(){
    cout<<sum_N(3);
}