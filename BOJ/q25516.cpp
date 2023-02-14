#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> node;
vector<int> apple;
int N,K,P,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    node.resize(N);
    apple.resize(N);
    for(int i=0;i<N-1;i++) {
        cin>>P>>C;
        node[P].push_back(C);
    }
    for(int i=0;i<N;i++) {
        cin>>apple[i];
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        int now = q.front().first;
        int k = q.front().second;
        ans+=apple[now];
        q.pop();
        if(k < K) {
            for(auto next: node[now]) {
                q.push({next,k+1});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}