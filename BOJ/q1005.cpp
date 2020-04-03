#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
vector<pair<int,int>> build;
int cost[MAX] = {0};
int indeg[MAX] = {0};
int ans[MAX] = {0};
int T,N,K,X,Y,W;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>T;
    while(T--) {
        memset(cost,0,sizeof(cost));
        memset(indeg,0,sizeof(indeg));
        memset(ans,0,sizeof(ans));
        build.clear();
        cin>>N>>K;
        for(int i=1;i<=N;i++) {
            cin>>cost[i];
        }
        for(int i=0;i<K;i++) {
            cin>>X>>Y;
            build.push_back({X,Y});
            indeg[Y]++;
        }
        cin>>W;
        queue<int> q;
        for(int i=1;i<=N;i++) {
            if(indeg[i] == 0) {
                ans[i] = cost[i];
                q.push(i);
            }
        }
        while(!q.empty()) {
            int b = q.front();
            q.pop();
            for(int i=0;i<K;i++) {
                X = build[i].first;
                Y = build[i].second;
                if(X == b) {
                    ans[Y] = max(ans[Y],ans[b]+cost[Y]);
                    if(--indeg[Y] == 0) {
                        q.push(Y);
                    }
                }
            }
        }
        cout<<ans[W]<<"\n";
    }
    return 0;
}