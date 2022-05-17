#include<bits/stdc++.h>
using namespace std;
int N,M;
bool isUsed[9] = {false};
int ans[9] = {0};
void solve(int n) {
	if(n == M) {
		for(int i=0;i<M;i++) {
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=1;i<=N;i++) {
		if(!isUsed[i]) {
			isUsed[i] = true;
			ans[n] = i;
			solve(n+1);
			isUsed[i] = false;
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	solve(0);
	return 0;
}