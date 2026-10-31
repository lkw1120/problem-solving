#include<bits/stdc++.h>
using namespace std;
int arr[3];
int N,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Y;
    arr[0] = arr[1] = arr[2] = -1;
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            int k = N-(i+j);
            if(0 <= k && i*10000+j*5000+k*1000 == Y) {
                arr[0] = i;
                arr[1] = j;
                arr[2] = k;
            }
        }
    }
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
    return 0;
}