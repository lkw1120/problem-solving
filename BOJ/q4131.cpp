#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,b;
int dist[1000001];
int M,N,S,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>S;
    a.resize(N);
    b.resize(N);
    fill(dist,dist+M,-1);
    for(int i=0;i<N;i++) {
        cin>>a[i]>>b[i];
    }
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == 0) break;
        for(int i=0;i<N;i++) {
            int next = (cur*a[i]+b[i])%M;
            if (dist[next] == -1) {
                dist[next] = dist[cur]+1;
                q.push(next);
            }
        }
    }
    ans = dist[0];
    cout<<ans<<"\n";
    return 0;
}