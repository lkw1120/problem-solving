#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> block;
vector<int> v;
int H,W,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>H>>W;
	v.resize(W);
	for(int i=0;i<W;i++) {
		cin>>v[i];
	}
	block.resize(W);
	for(int i=0;i<W;i++) {
		block[i].resize(H);
		for(int j=0;j<H;j++) {
			block[i][j] = 1;
		}
	}
	for(int i=0;i<W;i++) {
		for(int j=0;j<H;j++) {
			if(j < v[i]) block[i][j] = 0; 
		}
	}
	for(int j=H-1;j>=0;j--) {
		for(int i=0;i<W;i++) {
			if(block[i][j] == 0) break;
			else block[i][j] = 0;
		}
		for(int i=W-1;i>=0;i--) {
			if(block[i][j] == 0) break;
			else block[i][j] = 0;
		}
	}
	ans = 0;
	for(int i=0;i<W;i++) {
		for(int j=0;j<H;j++) {
			if(block[i][j]) ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;	
}