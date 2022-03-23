#include <iostream>
using namespace std;

int main() {
  int a[5]={10,5,15,17,9};
 
  
  int max=a[0];
  
  for(int j=1;j<=4;j++){
      if(max<a[j]){
          max=a[j];
      }
    
    
  }cout<<max;
	
}