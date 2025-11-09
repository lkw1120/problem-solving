#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 210;
struct Rect {
    int x1,y1,x2,y2;
};
Rect rects[MAX_N];
bool visited[MAX_N];
vector<int> adj[MAX_N];
int T,N,ans;
bool intersect(Rect a, Rect b) {
    return !(a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1);
}
void dfs(int x) {
    visited[x] = true;
    for(int y: adj[x]) {
        if(!visited[y]) {
            dfs(y);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=0;i<N;i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for(int i=0;i<N;i++) {
            cin>>rects[i].x1>>rects[i].y1>>rects[i].x2>>rects[i].y2;
        }
        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                if(intersect(rects[i],rects[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<N;i++) {
            if(!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        ans = cnt;
        cout<<ans<<"\n";
    }
    return 0;
}