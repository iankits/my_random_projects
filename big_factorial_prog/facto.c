/**
   @Author Ankit Singh, 2008 
   @copyright devGeeks Lab
   
   Enjoy the BIG FACTORIAL. 
   In this program, all calculation takes place in array only, so there is 
   no way for overflow.
**********************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define max 999999

int a[max];
long no;

int main(int argc, char** argv){
  long temp=0, len,s,i,t,j,r,q, prev_len,len_index;
  a[0]=1;

  if (argc<2){
    printf("Usage: %s <INPUT NUMBER> \n\n",argv[0]);
    exit(0);
  }
  
  no=atol(argv[1]);
  a[0]=1;
  prev_len = len_index =0;
  for(i=1; i<=no; i++) {
    r=0;
    q=0;
    len=0;
    temp=0;
    
    if((prev_len != 0)) {
      if(prev_len != (max-1))
	len_index=prev_len+6;
      else
	len_index=max-1;
    } else
      len_index = 1; // for the first time into the loop
    
    // This loop is check how many array length is in used in calculation.
    //   eg. array has a[0]=x, a[1], a[3]=y values,
    //   this means till now program has utilized 3 spaces, 
    //   so len will return 3
    for(s=len_index+6;s>=0;s--) {
      if((a[s]!=0)|| (temp!=0)){
	len++;
	// DEBUG
	//printf("\ni=%ld, s=%ld, prev_len=%ld, len=%ld",i,s,prev_len,len);
	prev_len = len;
	temp=1;
      }
    }
    
    for(j=0;j<(len+6);j++){
      t=a[j]*i+q; // The main formula for solution. Explanation given below 
      
      // r is used to save the last digit.
      // taking example that t = 13.
      // r = 13 % 10
      // r = 3 
      // then r is saved on the array 
      r=t % 10;
      
      // q is used to save the first digit.
      //	taking example that t = 13.
      // q = 13 / 10
      // q = 1 
      // then q is saved on the array 
      q=t/10;
      
      a[j]=r; //inserting the value into the array
      
      // DEBUG
      //      printf("\n\tj=%ld, t(a[j]*i+q)=%ld, r(t%%10)=%ld, q(t/10)=%ld a[%ld]=%d",j,t,r,q,j,a[j]);
    }
  }

  printf("\n\nActual Length of the Factorial Array: %ld",prev_len);
  
  // Print the Calculated Factorial
  temp=0;
  printf("\nFactorial --> ");
//  for(i=max-1;i>=0;i--){
  for(i=prev_len+6;i>=0;i--){
    if((a[i]!=0) || (temp!=0)){
      printf("%d", a[i]);
      temp=1;
    }
  }
  printf("\n");
  
  return 0;
}

