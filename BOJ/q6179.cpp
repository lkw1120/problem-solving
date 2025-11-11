#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Roller {
    ll x,y,r;
};
vector<Roller> roller;
vector<int> adj[1082];
bool visited[1082];
ll N,X,Y,R;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y>>R;
        roller.push_back({X,Y,R});
    }
    int start = -1;
    for(int i=0;i<N;i++) {
        if(roller[i].x == 0 && roller[i].y == 0) {
            start = i;
            break;
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            ll dx = roller[i].x - roller[j].x;
            ll dy = roller[i].y - roller[j].y;
            ll d2 = dx*dx + dy*dy;
            ll sum = roller[i].r + roller[j].r;
            if(d2 == sum*sum) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int last = start;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        last = cur;
        for(auto next: adj[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout<<roller[last].x<<" "<<roller[last].y<<"\n";
    return 0;
}