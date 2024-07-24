#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int arr[MAX];
int N,A,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(arr,arr+MAX,-1);
    cin>>N;
    int p = -1;
    K = 0;
    for(int i=0;i<N;i++) {
        cin>>A;
        if(0 <= p && arr[p] != A) {
            arr[A] = p;
        }
        p = A;
        K = max(K,A+1);
    }
    cout<<K<<"\n";
    for(int i=0;i<K;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}