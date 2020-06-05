#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
bool visit[MAX] = {false};
int F,S,G,U,D,ans;
int bfs(int s, int cnt) {
    queue<pair<int,int>> q;
    q.push({s,cnt});
    visit[s] = true;
    while(!q.empty()) {
        s = q.front().first;
        cnt = q.front().second;
        q.pop();
        if(s == G) return cnt;
        if(s-D > 0 && !visit[s-D]) {
            visit[s-D] = true;
            q.push({s-D,cnt+1});
        }
        if(s+U <= F && !visit[s+U]) {
            visit[s+U] = true;
            q.push({s+U,cnt+1});
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>F>>S>>G>>U>>D;
    ans = bfs(S,0);
    if(ans == -1) {
        cout<<"use the stairs"<<"\n";
    }
    else {
        cout<<ans<<"\n";
    }
    return 0;
}