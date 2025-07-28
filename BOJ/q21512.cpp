#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50001;
const int MAX_P = 1001;
const int INF = INT_MAX;
int arr[MAX_N];
int cost[MAX_P];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    cin>>M;
    fill(cost,cost+MAX_P,INF);
    for(int i=0;i<M;i++) {
        int b,c;
        cin>>b>>c;
        cost[b] = min(c,cost[b]);
    }
    for(int i=MAX_P-1;i>0;i--) {
        cost[i-1] = min(cost[i],cost[i-1]);
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        int p = arr[i];
        ans+=cost[p];
    }
    cout<<ans<<"\n";
    return 0;
}