#include<bits/stdc++.h>
#define MAX 501
using namespace std;
vector<int> v[MAX];
int cost[MAX] = {0};
int indeg[MAX] = {0};
int ans[MAX] = {0};
int N,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>cost[i];
        while(true){
            cin>>n;
            if(n == -1) break;
            v[n].push_back(i);
            indeg[i]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        n = q.front();
        q.pop();
        int size = v[n].size();
        for(int m=0;m<size;m++) {
            ans[v[n][m]]= max(ans[v[n][m]],ans[n]+cost[n]);
            if(--indeg[v[n][m]] == 0) {
                q.push(v[n][m]);
            }
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<ans[i]+cost[i]<<"\n";
    }
    return 0;
}