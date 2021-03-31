
/* ########### DIVISON ENTERA #################
div_ent(dv,dr)=div_ent2(dv,dr,0)

div_ent2(dv,dr,cc)={
    (cc,dv) dv<dr 
    div_ent2(dv-dr,dr,cc+1) dv>=dr 
}*/
//programa C 
/*int main(){

po par_ord=div_ent(dv,dr);

}
struct po{
    int cociente;
    int resto;}
po div_ent2(int dv, int dr, int co){
    if(dv>=dr){
        return div_ent2(dv-dr,dr,co+1);
    }
    else{
        return (co,dv);
    }
}
po div_ent(int dv, int dr){
    return div_ent2(dv,dr,0);
}
*/
/* ############ Secuencia de fibonacci ############
f(x)=1 si x==1
    =1 si x==2
    f(x-1)-f(x-2) si x>2

int fib(x){
    if(x<=2){
        return 1;
    }
    else {
        return fib(x-1)+fib(x-2);

    }
    despliegue
    fib(5)=fib(4)+fib(3)
        =fib(3)+fib(2)+fib(2)+fib(1)
        =fib(2)+fib(1)+fib(2)+fib(2)+fib(1)
    fib(7)=fib(6)+fib(5)
        =fib(5)+fib(4)+ib(2)+fib(1)+fib(2)+fib(2)+fib(1)
        =fib(2)+fib(2)+fib(1)+fib(4)+fib(2)+fib(1)+fib(2)+fib(2)+fib(1)

fib(x)=1 si x=1
    = 1 si x=2
    fib2(3,1,1,x) x>2



fib2(y,a1,a2,x)=fib2(y+1,a1+a2,a1,x) si y<x
        = a1+a2              si y=x

fib(5)=fib2(3,1,1,5)
    =fib2(4,2,1,5)
    =fib2(5,3,2,5)
    =5
fib(6)=fib2(3,1,1,6)
    =fib2(4,2,1,6)
    =fib2(5,3,2,6)
    =fib2(6,5,3,6)
    =8


    


f1=1
f2=1
f3=2
f4=3
f5=5
f6=8
f7=13
f8=21

int fib2(int y,int a1, int a2, int x){
    if(y==x){
        return a1+a2;
    }else{
        return fib2(y+1,a1+a2,a1,x);
    }
}

int fib(int x){
    if(x<=2){
        return 1;

    }
    else{
        return fib2(3,1,1,x)
    }
}
int main (){
    fib(x)
}




