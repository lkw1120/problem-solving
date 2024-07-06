#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int adj[101][101];
int N,M,A,B,ans;
void init() {
    fill(&adj[0][0],&adj[100][101],INF);
    for(int i=1;i<=100;i++) adj[i][i] = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        adj[A][B] = adj[B][A] = 1;
    }
    for(int j=1;j<=N;j++) {
        for(int i=1;i<=N;i++) {
            if(i == j) continue;
            for(int k=1;k<=N;k++) {
                if(i == k || j == k) continue;
                if(adj[i][j] + adj[j][k] < adj[i][k]) {
                    adj[i][k] = adj[i][j] + adj[j][k];   
                }
            }
        }
    }
    int a,b;
    a = b = 0;
    ans = INT_MAX;
    for(int i=1;i<=N;i++) {
        for(int j=i+1;j<=N;j++) {
            int cnt = 0;
            for(int k=1;k<=N;k++) {
                if(i == k || j == k) continue;
                cnt+=min(adj[i][k],adj[j][k])*2;
            }
            if(cnt < ans) {
                a = i;
                b = j;
                ans = cnt;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<ans<<"\n";
    return 0;
}