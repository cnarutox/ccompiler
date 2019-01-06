#include <iostream>
#include "unit.h"
#define X 3
int a=1;
int b,c=3;
int d=1+2*3;
bool e=true;
int fun();
int funWithBlock(){
    a=12;
    b=23;
}
int funWithParam(int p);
int funWithParams(int p,int p2,...);
funWithParam(param);
funWithParams(param,param2);
goto loop:
loop:
int main(){
    if(a==true){
        a+=2;
    }else{
        a++;
    }
    a=(int)2;
    while(a!=false)
    {
        a=a*(b+2);
    }
    do{
        a>>=2;
    }while(a||c&&b);
    for(int i=0;i<10;i++){
        if(a==2){
                continue;
        }
        a+=b;
    }
    switch(a){
        case 1:
            funWithParam(1);
            break;
        case 2:
            funWithParam(2);
            break;
        default:
            fun();
    }
    return 0;
}
a=a*(b+2);