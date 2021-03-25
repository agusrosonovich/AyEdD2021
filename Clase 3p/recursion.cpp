#include <cstdlib>
#include <iostream>

using namespace std;

//void impre(int v[],int n);
//int suma(int v[],int n);
//int mayor(int v[],int n);
//int multi(int, int);
void hanoi(char,char,char,int);

int main(int argc, char *argv[])
{   
    int v[6]={17,15,-8,30,5,-2};
    
	//cout<<"impre vector"<<endl; impre(v,5);
    //cout<<"suma vec="<<suma(v,5);
    //cout<<"mayor elem="<<mayor(v,5);
    //cout<<"multiplicacion de 5x7 recursiva="<<multi(5,7)<<endl;
    hanoi('a','b','c',3);//torre inicial (a), torre final (c), torre auxiliar (b)    
   
        system("PAUSE");
    return EXIT_SUCCESS;
}

void impre(int v[],int n)
{   if(n==0)cout<<v[n]<<endl;
    else{ 
          //cout<<"estoy yendo";
          //cout<<v[n]<<endl;// si descomento esto el arreglo se imprime al revez
          impre(v,n-1);
          //cout<<"estoy retornando"<<endl;
          cout<<v[n]<<endl;
          
          
    } 
}
int suma(int v[],int n){
    if(n==0)return v[n];
    
    else{
        //int s=suma(v,n-1);
        //s=s+v[n];
        //return s;
        return v[n]+suma(v,n-1);
    }
    //return v[n]+suma(v,n-1); para obviar el else
}

    
int mayor(int v[], int n){
    if(n==0) return v[n];
    else{
        int x = mayor(v,n-1);
        if (x>v[n]) return x;
        else{
            return v[n];
        }
    }

}
int multi(int x, int y){
    if (y==0)return 0;
    else{
        return x+multi(x,y-1);
    }



}
void hanoi(char a, char c, char b, int n){
    if(n>0){
        hanoi(a,b,c,n-1);
        cout<<"Mover"<<n<<" desde "<<a<<" hasta "<<c<<endl;
        hanoi(b,c,a,n-1);
    }

}
