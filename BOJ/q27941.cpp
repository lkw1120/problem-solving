#include<bits/stdc++.h>
using namespace std;
int arr[11];
int X;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<2047;i++) {
        for(int j=0;j<11;j++) {
            cin>>X;
            arr[j]^=X;
        }
    }
    for(int j=0;j<11;j++) {
        cout<<arr[j]<<" ";
    }
    cout<<"\n";
    return 0;
}