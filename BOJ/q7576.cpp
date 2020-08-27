#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int dX[4] = {-1,0,1,0};
int dY[4] = {0,-1,0,1};
int box[MAX][MAX];
int visit[MAX][MAX];
queue<pair<int,int>> q;
int M,N,x,y,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    fill(&visit[0][0],&visit[MAX-1][MAX],1);
    cin>>M>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>box[i][j];
            if(box[i][j]==1) q.push({i,j});
            if(box[i][j]==0 || box[i][j]==1) visit[i][j] = 0;
        }
    }
    ans = 0;
    while(true) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int j=0;j<4;j++) {
                if(0 < x+dX[j] && x+dX[j] <= N 
                && 0 < y+dY[j] && y+dY[j] <= M
                && box[x+dX[j]][y+dY[j]] == 0
                && visit[x+dX[j]][y+dY[j]] == 0) {
                    q.push({x+dX[j],y+dY[j]});
                    box[x+dX[j]][y+dY[j]] = 1;
                    visit[x+dX[j]][y+dY[j]] = 1;
                }
            }
        }
        if(q.empty()) break;
        ans++;
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(box[i][j]==0) ans = -1;
        }
    }
    cout<<ans<<"\n";
	return 0;
}