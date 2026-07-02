#include<bits/stdc++.h>
using namespace std;
char arr[6][6];
int H,W,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>H>>W>>K;
	for(int i=0;i<H;i++) {
		for(int j=0;j<W;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = 0;
	for(int r=0;r<(1<<H);r++) {
		for(int c=0;c<(1<<W);c++) {
			int cnt = 0;
			for(int i=0;i<H;i++) {
				for(int j=0;j<W;j++) {
					if((1<<i)&r || (1<<j)&c) continue ;
					if(arr[i][j] == '#') cnt++;
				}
			}
			if(cnt == K) ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}