#include <stdlib.h>
#include <iostream>

using namespace std;
/*
void swap(int x, int y){
  int c;
  c=x;
  x=y;
  y=c;
}
*/
void swap1(int *x, int *y){
  int c;
  c=*x;
  *x=*y;
  *y=c;
}

int main() {
  
  int a;
  int b;
  a=4;
  b=8;
  
  
  int *p,*q;
  p=&a;
  *p=7;
  
  
swap1(&a,&b);
  
  swap(a,b);
  
  int c=b;
  b=a;
  a=c;

cout <<"el valor de a es: " << a << " y b: "<< b << " y el puntero p " << *p << " y " << p << endl;
  
  
  p=(int *)malloc(sizeof(int)*4); 
  //es absolutamente equivalente a int p[4];
  *p=10;
  q=(int *)malloc(sizeof(int)*1);
  *q=3;
  
  p[0]=4;
  p[1]=5;
  p[2]=9;
  p[3]=21;
//  cout <<"el valor de a es: " << a << " y b: "<< b << endl;
  
//  cout <<"el valor de p es: " << *p << " y q vale: "<< *q << endl;
  
  for(int i=0 ; i<4 ; i++){
    cout << "p["<<i<<"] vale " << p[i] << endl;
  }
  
  free(p);
  free(q);
  //libera memoria que se reservo anteriormente
  return 0;
}