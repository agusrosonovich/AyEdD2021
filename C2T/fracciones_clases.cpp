#include <stdio.h>
#include <iostream>


using namespace std;
// declaracion de la clase
class Fracc {
    private:
            int num,den;
    public:
    
            Fracc();
            Fracc(int nn,int dd);
            // Fracc(int nn=1, int dd= 1);
            ~Fracc(){cout<<"soy el destructor de Fracc"<<endl;}; // Alt 126 = ~
            int getNum(){return num;}
            int getDen(){return den;}
            void set(int x, int y);
            Fracc sum(Fracc a);
            /*string toString();
			Fracc sum(Fracc a);
			Fracc mul(Fracc a);*/
};
Fracc::Fracc() { //constructor por defecto
    num=1;
    den=1;
}
Fracc::Fracc(int nn,int dd){//constructor con 2 parametros{
    num=nn;
    den=dd;

}
void Fracc::set(int x, int y){
    num=x;
    den=y;
}
Fracc Fracc::sum(Fracc a){
      Fracc aux;
      aux.set(num*a.den+a.num*den,a.den*den);
      return aux;      
}
int main(){
    Fracc f;
    Fracc g(1,2);
    Fracc *ff= new Fracc(); //puntero de una clase y en vez de pasarle el malloc le paso new
    Fracc *gg= new Fracc(9,3); 
    
    /* Fracc a[10];
    Fracc *a;
    a=(Fracc *)malloc(sizeof(Fracc)*10)*/ 
    
    cout<<f.getNum()<<f.getDen()<<endl;
    cout<<g.getNum()<<g.getDen()<<endl;
    f.set(3,4);
    cout<<f.getNum()<<f.getDen()<<endl;
    cout<<ff->getNum()<<ff->getDen()<<endl;
    cout<<gg->getNum()<<gg->getDen()<<endl;

    f=ff->sum(g);
    cout<<f.getNum()<<f.getDen()<<endl;

    delete(ff);
    delete(gg);
    return 0;

}