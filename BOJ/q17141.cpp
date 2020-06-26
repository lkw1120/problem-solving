#include<bits/stdc++.h>
using namespace std;
const int MAX = 50;
int matrix[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<pair<int,int>> v;
int N,M,ans;
int bfs(vector<int> virus) {
    int lab[MAX][MAX] = {0};
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(matrix[i][j] != 2) {
                lab[i][j] = matrix[i][j];
            }
        }
    }
    int y,x,nY,nX;
    int t;
    queue<pair<pair<int,int>,int>> q;
    for(auto i:virus) {
        q.push({v[i],0});
        y = v[i].first;
        x = v[i].second;
        lab[y][x] = 2;
    }
    while(!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        t = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            nY = y+dY[i];
            nX = x+dX[i];
            if(0 <= nY && nY < N && 0 <= nX && nX < N) {
                if(lab[nY][nX] == 0) {
                    lab[nY][nX] = 2;
                    q.push({{nY,nX},t+1});
                }
            }
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!lab[i][j]) return -1;
        }
    }
    return t;
}
void select(vector<int> virus,int i) {
    if(virus.size() == M) {
        int res = bfs(virus);
        if(res != -1) {
            ans = (ans == -1)? res:min(ans,res);
        }
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
    ans = -1;
    select(virus,0);
    cout<<ans<<"\n";
    return 0;
}