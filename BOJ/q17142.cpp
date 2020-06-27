#include<bits/stdc++.h>
using namespace std;
const int MAX = 50;
int matrix[MAX][MAX] = {0};
int lab[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<pair<int,int>> v;
queue<pair<int,int>> q;
int N,M,ans;
void bfs() {
    int y,x,nY,nX;
    int t;
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            nY = y+dY[i];
            nX = x+dX[i];
            if(0 <= nY && nY < N && 0 <= nX && nX < N) {
                if(matrix[nY][nX] != 1 && lab[nY][nX] == -1){
                    lab[nY][nX] = lab[y][x] + 1;
                    q.push({nY, nX});
                }
            }
        }
    }
    t = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(matrix[i][j] == 0) {
                if(lab[i][j] == -1) {
                    return ;
                }
                else {
                    t = max(t,lab[i][j]);
                }
            }
        }
    }
    ans = min(ans,t);
}
void select(vector<int> virus,int i) {
    if(virus.size() == M) {    
        fill(&lab[0][0],&lab[MAX-1][MAX],-1);
        for(auto i:virus) {
            lab[v[i].first][v[i].second] = 0;
            q.push(v[i]);
        }
        bfs();
        return ;
    }
    if(i < v.size()) {
        select(virus,i+1);
        virus.push_back(i);
        select(virus,i+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>matrix[i][j];
            if(matrix[i][j] == 2) {
                v.push_back({i,j});
            }
        }
    }
    vector<int> virus;
    ans = INT_MAX;
    select(virus,0);
    if(ans == INT_MAX) ans = -1;
    cout<<ans<<"\n";
    return 0;
}