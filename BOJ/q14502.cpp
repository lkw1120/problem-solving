#include<bits/stdc++.h>
#define MAX 8
using namespace std;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int labMap[MAX][MAX] = {0};
int spreadMap[MAX][MAX] = {0};
int N,M,ans;

void mapCopy() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            spreadMap[i][j] = labMap[i][j];
        }
    }
}
void spread(int x,int y) {
    spreadMap[x][y] = -1;
    for(int i=0;i<4;i++) {
        if(0 <= x+dX[i] && x+dX[i] < N 
        && 0 <= y+dY[i] && y+dY[i] < M 
        && spreadMap[x+dX[i]][y+dY[i]] == 0) {
                spread(x+dX[i],y+dY[i]);
        }
    }
}
void check() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(spreadMap[i][j] == 2) spread(i,j);
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(spreadMap[i][j] == 0) cnt++;
        }
    }
    if(cnt > ans) ans = cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    ans = 0;
    cin>>N>>M;
    vector<pair<int,int>> virus;
    for(int i=0;i<N;i++) { 
        for(int j=0;j<M;j++) {
            cin>>labMap[i][j];
            if(labMap[i][j] == 0) 
                virus.push_back({i,j});
            
        }
    }
    int SIZE = virus.size();
    for(int i=0;i<SIZE-2;i++) {
        for(int j=i+1;j<SIZE-1;j++) {
            for(int k=j+1;k<SIZE;k++) {
                mapCopy();
                spreadMap[virus[i].first][virus[i].second] = 1;
                spreadMap[virus[j].first][virus[j].second] = 1;
                spreadMap[virus[k].first][virus[k].second] = 1;
                check();
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}