#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<ll> S,T,dp;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    S.resize(N);
    T.resize(N);
    dp.resize(N);
    for(int i=0;i<N;i++) {
        cin>>S[i];
    }
    for(int i=0;i<N;i++) {
        cin>>T[i];
    }
    int tmp = 0;
    for(int i=1;i<N;i++) {
        if(T[i] < T[tmp]) {
            tmp = i;
        }
    }
    for(int i=0;i<N;i++) {
        dp[i] = T[i];
    }
    int cur = tmp;
    for(int i=0;i<N;i++) {
        int next = (cur+1)%N;
        dp[next] = min(dp[next],dp[cur]+S[cur]);
        cur = next;
    }
    for(int i=0;i<N;i++) {
        cout<<dp[i]<<"\n";
    }
    return 0;
}