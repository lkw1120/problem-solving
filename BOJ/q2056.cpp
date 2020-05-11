#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
vector<int> adj[MAX];
queue<int> q;
int indeg[MAX] = {0};
int cost[MAX] = {0};
int ans[MAX] = {0};
int N,M,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>cost[i];
        cin>>M;
        for(int j=0;j<M;j++) {
            cin>>n;
            adj[n].push_back(i);
            indeg[i]++;
        }
    }
    for(int i=1;i<=N;i++) {
        if(indeg[i] == 0) {
            q.push(i);
            ans[i] = cost[i];
        }
    }
    while(!q.empty()) {   
        n = q.front();
        q.pop();
        for(auto m : adj[n]) {
            ans[m] = max(ans[m],ans[n]+cost[m]);
            if(--indeg[m] == 0) {
                q.push(m);
            }
        }
    }
    cout<<*max_element(ans,ans+N+1)<<"\n";
    return 0;
}