#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int T,A,B;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>A>>B;
        arr[i]=A+B;
    }
    for(int j=0;j<T;j++)
    cout<<arr[j]<<endl;
    
}