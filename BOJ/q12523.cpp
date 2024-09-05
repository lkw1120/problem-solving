#include<bits/stdc++.h>
using namespace std;
vector<int> v[11];
bool visited[11];
int T,N,F;
int find(int n) {
    fill(visited,visited+11,false);
    queue<int> q;
    q.push(n);
    visited[n] = true;
    int cnt = 0;
    while(!q.empty()) {
        n = q.front();
        q.pop();
        cnt++;
        for(int next: v[n]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        for(int i=0;i<11;i++) {
            v[i].clear();
        }
        cin>>N;
        for(int i=1;i<=N;i++) {
            cin>>F;
            v[F].push_back(i);
        }
        cout<<"Case #"<<t<<":"<<"\n";
        for(int i=1;i<=N;i++) {
            cout<<find(i)<<"\n";
        }
    }
    return 0;
}