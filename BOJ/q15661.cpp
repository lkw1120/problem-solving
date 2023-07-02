#include<bits/stdc++.h>
using namespace std;
int arr[21][21] = {0};
bool visited[21] = {false};
int N,ans;
void solve(int sum, int n) {
	if(sum > N/2) {
		return ;
	}
	if(sum) {
		int sum1 = 0;
		int sum2 = 0;
		for(int i=0;i<N;i++) {
			for(int j=i+1;j<N;j++) {
				if(visited[i] && visited[j]) {
					sum1+=(arr[i][j]+arr[j][i]);
				}
				if(!visited[i] && !visited[j]) {
					sum2+=(arr[i][j]+arr[j][i]);
				}
			}
		}
		ans = min(abs(sum1-sum2),ans);
		
	}
	for(int i=n;i<N;i++) {
		visited[i] = true;
		solve(sum+1,i+1);
		visited[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin>>arr[i][j];
		}
	}
	ans = INT_MAX;
	solve(0,0);
	cout<<ans<<"\n";
	return 0;
}