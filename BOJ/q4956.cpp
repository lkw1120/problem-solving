#include<bits/stdc++.h>
using namespace std;
int arr1[31][31];
int arr2[31][31];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int dist[31][31];
int W,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>W>>H;
        if(!W && !H) break;
        fill(&arr1[0][0],&arr1[30][31],0);
        fill(&arr2[0][0],&arr2[30][31],0);
        fill(&dist[0][0],&dist[30][31],0);
        for(int i=1;i<2*H;i++) {
            if(i%2) {
                for(int j=1;j<W;j++) {
                    cin>>arr1[i/2+1][j];
                }
            }
            else {
                for(int j=1;j<=W;j++) {
                    cin>>arr2[i/2+1][j];
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({1,1});
        dist[1][1] = 1;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == H && y == W) {
                break;
            }
            for(int i=0;i<4;i++) {
                int dx = x+dX[i];
                int dy = y+dY[i];
                if(0 < dx && dx <= H && 0 < dy && dy <= W && !dist[dx][dy]) {
                    if((i == 0 && arr1[x][y] == 0) 
                    || (i == 1 && arr2[dx][dy] == 0) 
                    || (i == 2 && arr1[dx][dy] == 0)
                    || (i == 3 && arr2[x][y] == 0)) {
                        dist[dx][dy] = dist[x][y]+1;
                        q.push({dx,dy});
                    }
                }
            }
        }
        ans = dist[H][W];
        cout<<ans<<"\n";
    }
    return 0;
}