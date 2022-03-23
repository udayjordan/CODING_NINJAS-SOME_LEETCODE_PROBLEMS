/******************************************************************************

FOR N=6; this is a dry code for ~BUBBLE SORT 

*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{
  int arr[6]={10,1,7,9,14,5};
  for(int i =0;i<=5;i++){
  for(int j=0;j<5;j++)
  {
  if(arr[j]>arr[j+1]){
  int temp=arr[j];
  arr[j]=arr[j+1];
  arr[j+1]=temp;
  }
}}
for(int k=0;k<6;k++)
cout<<arr[k]<<" ";
}