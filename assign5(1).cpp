#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"give size of array for selection sort:";
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        int w;
        cout<<"element "<<i+1<<":";
        cin>>w;
        arr[i]=w;
    }
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        swap(arr[i],arr[min_idx]);
    }
    cout<<"sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}