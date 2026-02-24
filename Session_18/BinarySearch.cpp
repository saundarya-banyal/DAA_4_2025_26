#include<iostream>
using namespace std;

int main(){
    int n = 10;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    int mid;
    int l=0;
    int r= n-1;
    int lb=-1;

    while(l<=r){
        mid = (l+r)/2;

        if(arr[mid]>=key){
            lb=mid;
            cout<<"Element at index "<<mid+1;
            break;
        }
        else if(arr[mid]<key){
            r=mid-1;
        }
        else if(arr[mid]>key){
            l=mid+1;
        }
        else if(key>=mid){
            
        }
    }
}