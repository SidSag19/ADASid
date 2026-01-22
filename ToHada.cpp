#include <iostream>
using namespace std;

void Hanoi(int n,char f,char u,char t){
    if (n==1){
        cout<<"Move disc "<<f<<"->"<<t<<endl;}
    
    else {
        Hanoi(n-1,f,t,u);
        cout<<"Move disc "<<f<<"->"<<t<<endl;
        Hanoi(n-1,u,f,t);
    }
}

int main(){
    Hanoi(3,'a','b','c');
    return 0;
}