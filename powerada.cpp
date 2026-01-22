#include <iostream>
using namespace std;

int power(int a,int b){
    if (b==0) return 1;
    long int half=power(a,b/2);
    
    if (b%2==0){
        return half*half; }
    
    else
        return a*half*half;
}

int main(){
    int c;
    c=power(4,8);
    cout<<c;
}