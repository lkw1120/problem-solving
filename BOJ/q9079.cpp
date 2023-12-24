#include<bits/stdc++.h>
using namespace std;
char coin[3][3];
int arr[3][3];
int T,ans;
void copy() {
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			arr[i][j] = (coin[i][j] == 'H')? 0: 1;
		}
	}
}
void flip(int r, int c, int k) {
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if((1<<i)&r) {
				arr[i][j] = 1-arr[i][j];
			}
		}
	}
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if((1<<j)&c) {
				arr[i][j] = 1-arr[i][j];
			}
		}
	}
	if((1<<0)&k) {
		for(int i=0;i<3;i++) {
			arr[i][i] = 1-arr[i][i];	
		}
	}
	if((1<<1)&k) {
		for(int i=0;i<3;i++) {
			arr[i][2-i] = 1-arr[i][2-i];	
		}
	}
}
bool check() {
	int cnt = 0;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cnt+=arr[i][j];
		}
	}
	return (cnt == 9 || cnt == 0);
}
int count(int r, int c, int k) {
	int cnt = 0;
	while(r) {
		cnt+=r%2;
		r/=2;
	}
	while(c) {
		cnt+=c%2;
		c/=2;
	}
	while(k) {
		cnt+=k%2;
		k/=2;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				cin>>coin[i][j];
			}
		}
		ans = INT_MAX;
		for(int r=0;r<9;r++) {
			for(int c=0;c<9;c++) {
				for(int k=0;k<4;k++) {
					copy();
					flip(r,c,k);
					if(check()) {
						ans = min(count(r,c,k),ans);
					}
				}
			}
		}
		if(ans == INT_MAX) {
			cout<<-1<<"\n";	
		}
		else {
			cout<<ans<<"\n";	
		}
	}
	return 0;
}