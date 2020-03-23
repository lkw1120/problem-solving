#include<bits/stdc++.h>
#define MAX 101
using namespace std;
char area[MAX][MAX] = {};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N, ans[2] = {0};
void dfs(bool visited[][MAX],int x, int y) {
    for(int i=0;i<4;i++) {
        if(0<= x+dX[i] && x+dX[i] < N
        && 0<= y+dY[i] && y+dY[i] < N
        && area[x][y] == area[x+dX[i]][y+dY[i]]
        && !visited[x+dX[i]][y+dY[i]]) {
            visited[x+dX[i]][y+dY[i]] = true;
            dfs(visited,x+dX[i],y+dY[i]);
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        string str;
        cin>>str;
        for(int j=0;j<N;j++) {
            area[i][j] = str[j];
        }
    }
    bool visited[MAX][MAX] = {false};
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                dfs(visited,i,j);
                ans[0]++;
            }
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visited[i][j] = false;
            if(area[i][j] == 'G')
                area[i][j] = 'R';
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                dfs(visited,i,j);
                ans[1]++;
            }
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<"\n";
	return 0;
}