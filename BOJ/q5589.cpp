#include<bits/stdc++.h>
using namespace std;
int arr[10][10000];
int sum[10000];
int R,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = 0;
	for(int r=0;r<(1<<R);r++) {
		for(int c=0;c<C;c++) {
			int cnt = 0;
			for(int i=0;i<R;i++) {
				if((1<<i)&r) {
					if(arr[i][c]^0) {
						cnt++;
					}
				}
				else {
					if(arr[i][c]^1) {
						cnt++;	
					}
				}
			}
			sum[c] = cnt;
		}
		int tmp = 0;
		for(int i=0;i<C;i++) {
			tmp+=max(sum[i],R-sum[i]);
		}
		ans = max(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}