#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
int M,N,ans;
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < M && 0 <= dy && dy < N && v[dx][dy] == '#') {
				v[dx][dy] = '.';
				q.push({dx,dy});
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>M>>N;
    v.resize(M);
    for(int i=0;i<M;i++) {
        cin>>v[i];
    }
    ans = 0;
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(v[i][j] == '#') {
                v[i][j] = '.';
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}