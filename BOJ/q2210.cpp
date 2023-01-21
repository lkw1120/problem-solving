#include <bits/stdc++.h>
using namespace std;
int arr[5][5] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<int> v;
int ans;
void dfs(int x, int y, int num, int cnt) {
    if (5 < cnt) {
        v.push_back(num);
        return ;
    }
	for(int i=0;i<4;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
		if(0 <= dx && dx < 5 && 0 <= dy && dy < 5) {
        	dfs(dx,dy,num*10 + arr[dx][dy],cnt+1);
		}
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            dfs(i,j,0,0);
        }
    }
    sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	ans = v.size();
	cout<<ans<<"\n";
	return 0;
}