#include<bits/stdc++.h>
using namespace std;
int N,M;
int ans[9] = {0};
void solve(int n) {
	if(n > M) {
		for(int i=1;i<=M;i++) {
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=ans[n-1]+1;i<=N;i++) {
		ans[n] = i;
		solve(n+1);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	solve(1);
	return 0;
}