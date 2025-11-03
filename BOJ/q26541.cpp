#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,N,ans;
int check(char ch){
    if(ch == 'R') return 1;
    if(ch == 'B') return 2;
    if(ch == 'G') return 4;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        vector<vector<char>> v(N,vector<char>(N));
        vector<vector<int>> visited(N,vector<int>(N,0));
        int x,y;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>v[i][j];
                if(v[i][j] == 'S') {
                    x = i,y = j;
                }
            }
        }
        deque<tuple<int,int,int>> dq;
        dq.push_back({x,y,0});
        visited[x][y]|=(1<<0);
        ans = 0;
        while(!dq.empty()) {
            x = get<0>(dq.front());
            y = get<1>(dq.front());
            int t = get<2>(dq.front());
            dq.pop_front();
            if(v[x][y] == 'X') {
                ans = __builtin_popcount(t);
                break;
            }
            else {
                for(int i=0;i<4;i++) {
                    int dx = x+dX[i];
                    int dy = y+dY[i];
                    if(0 <= dx && dx < N && 0 <= dy && dy < N) {
                        int dt = t|check(v[dx][dy]);
                        if(visited[dx][dy] & (1<<dt)) continue;
                        if(dt == t) {
                            dq.push_front({dx,dy,dt});
                        }
                        else {
                            dq.push_back({dx,dy,dt});
                        }
                        visited[dx][dy]|=(1<<dt);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}