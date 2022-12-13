#include<bits/stdc++.h>
#define MAX 43
using namespace std;
int dp[MAX] = {0};
int T,V;
void preload() {
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<MAX;i++) {
		dp[i] = dp[i-1] + dp[i-2] + 1;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>T;
	while(T--) {
		cin>>V;
		for(int i=MAX-1;i>=0;i--) {
			if(dp[i] <= V) {
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;	
}