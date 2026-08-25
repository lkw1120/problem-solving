#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> v;
int H,W;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>H>>W;
	v.resize(H);
	for(int i=0;i<H;i++) {
		cin>>v[i];	
	}
	ans = "Yes";
	for(int i=0;i<H;i++) {
		for(int j=0;j<W;j++) {
			if(v[i][j] == '#') {
				int cnt = 0;
				for(int k=0;k<4;k++) {
					int dx = i+dX[k];
					int dy = j+dY[k];
					if(0 <= dx && dx < H && 0 <= dy && dy < W && v[dx][dy] == '#') {
						cnt++;	
					}
				}
				if(cnt == 0) {
					ans = "No";	
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}