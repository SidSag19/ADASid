#include <iostream>
using namespace std;

//To find kth smallest in an array

int partition(int a[], int low, int high) {
    int v = a[low];
    int i = low;
    int j = high + 1;

    do {
        do { i++; } while (i <= high && a[i] < v);
        do { j--; } while (a[j] > v);

        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i < j);

    a[low] = a[j];
    a[j] = v;
    return j;
}

int findksmallest(int a[],int low,int high,int k){
    int p=partition(a,low,high);
    if(p==k-1){
        return a[p];
    }
    else if(p>k-1){
        return findksmallest(a,low,p-1,k);
    }
    else{
        return findksmallest(a,p+1,high,k);
    }
}

int main(){
    int arr[7]={6,5,13,7,1,2,25};
    int res=findksmallest(arr,0,7,3);
    cout<<"kth smallest is "<<res; 
    return 0;
}