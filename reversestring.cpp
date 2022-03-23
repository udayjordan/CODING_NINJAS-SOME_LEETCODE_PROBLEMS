#include <iostream>

using namespace std;

int main()
{
    string str;
    cout<<"enter the string to be reversed";
    cin>>str;
    int start=0;
    int end=str.length()-1;
    while(start<end){
        int tem=str[start];
        str[start]=str[end];
        str[end]=tem;
        start++;
        end--;
    }cout<<str;

    return 0;
}