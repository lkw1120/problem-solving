#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool check[1001];
int N,M,S;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>S;
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(S);
    check[S] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next: adj[cur]) {
            if(!check[next]) {
                check[next] = true;
                q.push(next);
            }
        }
    }
    bool flag = true;
    for(int i=0;i<N;i++) {
        if(!check[i]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout<<"yes"<<"\n";
    }
    else {
        cout<<"no"<<"\n";
    }
    return 0;
}