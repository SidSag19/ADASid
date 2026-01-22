#include <iostream>
using namespace std;

int bounce(int vel,int n){
    if (vel<1){
        return n;
    }
    
    else {
     bounce(0.575*vel,n+1);}
}

int main(){
    int a;
    a=bounce(5,0);
    cout<<a;
}