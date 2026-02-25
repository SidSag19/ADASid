#include <iostream>
using namespace std;

void maxmin(int a[],int low,int high,int &min,int &max){
    if (low==high){
        max=min=a[low];
    }
    else if (low==high-1){
        if (a[low]<=a[high]){
            min=a[low];
            max=a[high];
        }
        else{
            min=a[high];
            max=a[low];
        }
        return;
    }
        int mid=low+(high-low)/2;
        int max1,min1;
        maxmin(a,low,mid,min,max);
        maxmin(a,mid+1,high,min1,max1);

        if(max<max1){
            max=max1;
        }
        if(min>min1){
            min=min1; }
}

int main(){
    int a[8]={3,5,1,8,2,4,7,6};
    int max,min;
    maxmin(a,0,7,min,max);
    cout<<"Max is "<<max<<" and Min is "<<min;
}