#include <cstdlib>
#include <iostream>
#include <ostream>
#include <time.h>
#include <sstream>

using namespace std;
int tiros=0;
int hundidos=0;
int averiados=0; 
bool mapa[10][10];  // El arreglo es un mapa bidimensional de 10x10 de tipo booleano.

// CLASE COORDENADA

class coord{            // Tipo de dato coordenada
private:
    int x;
    int y;
public:
	
	coord(int i, int j) {
			x = i;
			y = j;
	};
	void setx(int i) { x=i; };
	void sety(int i) { y=i; };
	int getx() { return x; };
	int gety() { return y; };
	string imprimir(){
    return "(" + std::to_string(getx()) + ";" + std::to_string(gety()) + ")";
  };bool verif() {
    if (!mapa[this->getx()][this->gety()]){ //Si la posicion es false, disparamos.
      mapa[this->getx()][this->gety()]=true;
      tiros++;
      return true;
    }
    return false;
  };
};
  
// CLASE PILA

class Pila {
	private:
		coord d[10];
		int p;
	public:
		Pila() {p=-1;};
		void apilar(coord x) {d[++p] = x;};
		coord tope(void) {return d[p];};
		void desapilar(void) {p--;};
		bool pilaVacia() {return p==-1;};
    int size() {return p+1;};
    };

// CLASE COLA

class Cola {
	private:
		Pila d[100];
		int h;
    int t;
	public:
		Cola() {
      h=0;
      t=-1;
    };
		void encolar(Pila x) {d[++t] = x;};
		Pila tope(void) {return d[h];};
		void desencolar(void) {h++;};
		bool colaVacia() {return h>t;};
    void llenar() {
      Pila *p;
      coord *pos;
      for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        pos = new coord(i,j);
	      p=new Pila();
	      p->apilar(*pos); 
        this->encolar(*p);
        }
      }
    };
    
};

// CLASE BARCO

class Barco
{
private:
    coord pos[4];       // Posiciones de cada casillero que ocupa el barco.
                        // Si ocupa menos de 4 casilleros, los vacios se llenan con null.
    int tipo;           // El tipo de barco se distingue por la cantidad de casilleros que ocupa.
};

void disparo(Pila *p)
{ 
  coord *c=new coord();
  Pila *p2=new Pila();
  char caso;
  cout<<"Que hay en la posicion ("<<p->tope().imprimir()<<endl;
  cin>>caso;
  switch (caso){

    case 'a':
    p->desapilar();
    tiros++;


    
    
    case 'h':
    tiros++;
    hundidos++;
    while (p->size()>0){
      p->desapilar();
    }
// c->setx(p->tope().getx)
    case 'v':
    
    tiros++;

     if (averiados==0){//primer disparo del turno en el que averias un barco
    
    //Apilar en direcciones adyacentes     
    c->setx(p->tope().getx()+1);  //Derecha
    p->apilar(*c);

    c->setx(p->tope().getx()-2);  //Izquierda
    p->apilar(*c);
    
    c->setx(p->tope().getx()+1);

    c->sety(p->tope().gety()+1);  //Arriba
    p->apilar(*c);
    
    c->sety(p->tope().gety()-2);  //Abajo
    p->apilar(*c);
 
    averiados++;
    while (p->size()>1){
    disparo(p);
    }
  }
    
    else if (averiados==1) {  //averiados !=0
   // c->setx(p->tope().getx());
   // c->sety(p->tope().gety());
   // p2->apilar(*c);


    if(p2->tope().gety()<p->tope().gety()+1){ //Caso apilar hacia arriba

    
    c->sety(p->tope().gety()+2);  //y+2 pongo primero el elemento ultimo a diparar
    p2->apilar(*c);

    c->sety(p->tope().gety()-1); //y+1 pongo ultimo el elemento primero a diparar
    p2->apilar(*c);
    
    }
    

    if(p2->tope().gety()>p->tope().gety()-1){ //Caso apilar hacia abajo

    
    c->sety(p->tope().gety()-2); //y-2
    p2->apilar(*c);

    c->sety(p->tope().gety()+1); //y-1
    p2->apilar(*c);

    }
    
    
    if(p2->tope().getx()<p->tope().getx()+1){ //Caso apilar hacia Derecha

    
    c->setx(p->tope().getx()+2); //x+2
    p2->apilar(*c);
    
    c->setx(p->tope().getx()-1); //x+1
    p2->apilar(*c);

    } 

    
    if(p2->tope().getx()>p->tope().getx()-1){ //Caso apilar hacia Izquierda

    
    c->setx(p->tope().getx()-2); //x-2
    p2->apilar(*c);

    c->setx(p->tope().getx()+1); //x-1
    p2->apilar(*c);

    }

    p=p2;

 
    
    
    
    }
    
    else if(averiados==2){
        averiados++;
        p->desapilar();
        disparo(p);
    }

    p->desapilar();
    hundidos++;
    break;
  
}

}



int main ()
{
		srand(time(NULL));		
    for (int i=0; i<10; i++){
		  for  (int j=0; j<10; j++){
		    mapa[i][j]=false;
			}
		}
        
    Cola *c= new Cola();
    c->llenar();

    if(c->tope().tope().verif()){ //Pregunta si podés disparar
      disparo((c->tope()));//Si se puede disparar
      c->desencolar();
    }
    else {
      c->desencolar();
    }
    
  /*cout<<c->tope().tope().getx()<<";"<<c->tope().tope().gety()<<endl;
  c->desencolar();
  cout<<c->tope().tope().getx()<<";"<<c->tope().tope().gety()<<endl;
  c->desencolar();
  cout<<c->tope().tope().getx()<<";"<<c->tope().tope().gety()<<endl;
	*/
  	return 0;

}

