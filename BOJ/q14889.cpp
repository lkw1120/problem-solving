#include<bits/stdc++.h>
using namespace std;
int arr[21][21] = {0};
bool check[21] = {false};
int N,ans;
void solve(int x, int n) {
	if (x == N/2) {
		int start,link;
		start = 0;
		link = 0;
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				if(check[i] && check[j]) {
					start+=arr[i][j];
				}
				if(!check[i] && !check[j]) {
					link+=arr[i][j];
				}
			}
		}
		ans = min(ans,abs(start-link));
		return ;
	}
	for(int i=n;i<N;i++) {
		check[i] = true;
		solve(x+1,i+1);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
		}
	}
	ans = INT_MAX;
	solve(0,1);
	cout<<ans<<"\n";
	return 0;
}