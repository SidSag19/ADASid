#include <iostream>
using namespace std;

int binarysearch(int arr[],int low,int high,int elem){
    int mid=low + (high-low)/3;
    // int mid=(low+high)/3;
    if (low>high){
        return -1;}

    if (low<=high){
        if (arr[mid]==elem) return mid;

        else if (arr[mid]>elem){
            return binarysearch(arr,low,mid-1,elem);
        }

        else
            return binarysearch(arr,mid+1,high,elem);
    }

}

int main(){
    int arr[8]={1,2,4,6,7,10,11,12};
    int result=binarysearch(arr,0,7,18);
    if (result==-1){
        cout<<"Not found";
    }
    else 
    cout<<"Found at "<<result;
    return 0;
}