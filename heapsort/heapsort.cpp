// Metodo de Ordenamiento Heapsort
// 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void impre(int *v);
void heapsort(int arr[], unsigned int N);
int c=0,m=0;

int main(int argc, char *argv[])
{int i,j,pos,aux,b;
 int a[MAX]={3,12,5,35,10,2,50,7,30,8};
 /*for(i=0;i<MAX;i++){
                    a[i]=int(rand());
 }
 */
 impre(a);
 
 
  heapsort(a,MAX);
  puts("\n---------------------------------");
  impre(a);
 
  printf("\n cantidad de comparaciones= %d  movimientos= %d",c,m);
  printf("\n\n");
  system("PAUSE");	
  return 0;
}
void impre(int *v)
{ int i;
  printf("\n");
  for(i=0;i<MAX;i++)
     printf("\n %3d   %3d",i,v[i]);
}

void heapsort(int arr[], unsigned int N) 
{   
    if(N==0) return; // heap est� vacio?
    int t; // valor temporario
    unsigned int n = N, parent = N/2, index, child; //indices del heap
    
    while (1) { // while hasta que este ordenado
        if (parent > 0) { 
            // primera etapa - ordenar el heap
            t = arr[--parent];  // valor temporario
            m++;
        } else {
            // segunda etapa - extraer elementos
            printf("\n parent:%3d   n:%3d",parent,n);impre(arr);
            n--;                // achico el heap
            if (n == 0) return; // termin�
            t = arr[n];         // valor temporario
            arr[n] = arr[0];    // valor mas grande>> a su posicion final
            m=m+2;
        }
        /* insert operation - pushing t down the heap to replace the parent */
        // operaci�n de inserci�n
        index = parent; // inicio con el padre
        child = index * 2 + 1; // hijo izquierdo
        printf("\n parent:%3d   child:%3d  t:%3d",parent,child,t);
        while (child < n) {
            c++;// busco el hijo mayor
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++; // mayor hijo es el derecho
            }
            c++;// el hijo es > temporario
            if (arr[child] > t) {
                arr[index] = arr[child]; // sobreescribo con el hijo
                m++;
                index = child; // muevo index
                child = index * 2 + 1; // recalculo hijo izq
            } else break; // encontr� el lugar para temporario
        }// fin while (child<n)
        arr[index] = t; m++;// temporario a su nuevo lugar
    }// fin while(1)
}