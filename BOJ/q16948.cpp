#include<bits/stdc++.h>
#define MAX 200
using namespace std;
bool visited[MAX][MAX] = {false};
int dX[6] = {-2,-2,0,0,2,2};
int dY[6] = {-1,1,-2,2,-1,1};
int r1,r2,c1,c2;
int N,ans;

void solve(int x, int y) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    ans = -1;
    visited[x][y] = true;
    while(q.size() > 0) {
        x = q.front().first.first;
        y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(x == r2 && y == c2) {
            if(ans > cnt || ans < 0) ans = cnt;
        }
        for(int i=0;i<6;i++) {
            if(0 <= x+dX[i] && x+dX[i] < N
            && 0 <= y+dY[i] && y+dY[i] < N
            && !visited[x+dX[i]][y+dY[i]]) {
                visited[x+dX[i]][y+dY[i]] = true;
                q.push({{x+dX[i],y+dY[i]},cnt+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    cin>>r1>>c1>>r2>>c2;
    solve(r1,c1);
    cout<<ans<<"\n";
	return 0;
}