/******************************************************************************

BINARY SEARCH~ DRY CODE for already sorted elements

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
   int arr[]={10,12,15,20,30,40};
   int mid;
   int start=0;
  int  end=5;
   while(start<end){
       mid=(start+end)/2;
       if(arr[mid]==12){
           cout<<mid;
           break;
       }
       else if(arr[mid]<12){
           start=mid+1;
           end=5;
       }
       else if(arr[mid]>12){
           start=0;
           end=mid-1;
       }
   }
}
