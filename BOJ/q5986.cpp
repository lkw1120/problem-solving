#include<bits/stdc++.h>
using namespace std;
char arr[101][101][101];
int dX[6]={1,0,0,-1,0,0};
int dY[6]={0,1,0,0,-1,0};
int dZ[6]={0,0,1,0,0,-1};
int N,ans;
void find(int x, int y, int z) {
    queue<tuple<int,int,int>> q;
    q.push({x,y,z});
    arr[x][y][z] = '#';
    while(!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop();
        for(int i=0;i<6;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            int dz = z+dZ[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= N 
               && 0 < dz && dz <= N && arr[dx][dy][dz] == '*') {
                arr[dx][dy][dz] = '#';
                q.push({dx,dy,dz});
            }
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            for(int k=1;k<=N;k++) {
                cin>>arr[i][j][k];
            }
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            for(int k=1;k<=N;k++) {
                if(arr[i][j][k] == '*') {
                    ans++;
                    find(i,j,k);
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}