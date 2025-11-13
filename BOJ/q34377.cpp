#include<bits/stdc++.h>
using namespace std;
unordered_map<string,vector<string>> adj;
unordered_map<string,bool> visited;
unordered_map<string,int> dist;
string start;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>start;
    for(int i=0;i<N;i++) {
        string a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    ans = -1;
    while(!q.empty()) {
        string cur = q.front();
        q.pop();
        if(cur == start && 0 < dist[cur]) {
            ans = dist[cur];
            break;
        }
        for(auto next: adj[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                dist[next] = dist[cur]+1;
                q.push(next);
            }
        }
    }
    if(0 < ans) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"NO BLACK HOLE"<<"\n";
    }
    return 0;
}