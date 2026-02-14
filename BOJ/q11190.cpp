#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int deg[10001];
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    bool flag = true;
    for(int i=1;i<=N;i++) {
        if(deg[i] == 0) {
            flag = false;
            break;
        }
    }
    if(flag) {
        vector<bool> v(N+1,false);
        vector<bool> blocked(N+1,false);
        for(int i=1;i<=N;i++) {
            if(!blocked[i]) {
                v[i] = true;
                blocked[i] = true;
                for(auto j: adj[i]) {
                    blocked[j] = true;
                }
            }
        }
        for(int i=1;i<=N;i++) {
            cout<<(v[i]? "house": "pub")<<" ";
        }
        cout<<"\n";
    }
    else {
        cout<<"Impossible"<<"\n";
    }
    return 0;
}