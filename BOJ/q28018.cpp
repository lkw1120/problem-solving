#include<bits/stdc++.h>
using namespace std;
int arr[1000009];
int N,A,B,Q;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A>>B;
        arr[A]++;
        arr[B+1]--;
    }
    int now = 0;
    for(int i=1;i<=1000000;i++) {
        now+=arr[i];
        arr[i] = now;
    }
    cin>>Q;
    while(Q--) {
        cin>>A;
        cout<<arr[A]<<"\n";
    }
    return 0;
}