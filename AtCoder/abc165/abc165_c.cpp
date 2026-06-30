#include<bits/stdc++.h>
using namespace std;
int A[50],B[50],C[50],D[50];
int arr[11];
int N,M,Q,ans;
void solve(int idx) {
    if(idx > N) {
        int score = 0;
        for(int i=0;i<Q;i++) {
            if(arr[B[i]]-arr[A[i]] == C[i]) {
                score+=D[i];
            }
        }
        ans = max(ans,score);
        return ;
    }
    for(int i=arr[idx-1];i<=M;i++) {
        arr[idx] = i;
        solve(idx+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>Q;
    for(int i=0;i<Q;i++) {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    arr[0] = 1;
    solve(1);
    cout<<ans<<"\n";
    return 0;
}