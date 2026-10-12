#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;
int arr[MAX];
int N,M,L,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    L = INT_MAX;
    H = 0;
    for(int i=0;i<N;i++) {
        cin>>M;
        L = min(L,M);
        H = max(H,M);
        arr[M-1]++;
        arr[M]++;
        arr[M+1]++;
    }
    ans = 0;
    for(int i=L;i<=H;i++) {
        ans = max(ans,arr[i]);
    }
    cout<<ans<<"\n";
    return 0;
}