#include<bits/stdc++.h>
using namespace std;
int fibo[21] = {0};
int dp[81] = {0};
string input;
int N,ans;
void init() {
	fibo[0] = fibo[1] = 1;
	for(int i=2;i<21;i++) {
		fibo[i] = fibo[i-1]+fibo[i-2];	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>N;
	cin>>input;
	for(int i=0;i<N-3;i++) {
		if(input.substr(i,4) == "long") {
			dp[i] = 1;
		}
		if(4 <= i && dp[i]) {
			dp[i]+=dp[i-4];
		}
	}
	ans = 1;
	for(int i=0;i<N;i++) {
		if(dp[i]) {
			int cnt = 0;
			for(int j=i;j<N;j+=4) {
				if(!dp[j]) break;
				cnt++;
			}
			ans*=fibo[cnt];
			i+=cnt*4;
		}
	}
	cout<<ans<<"\n";
	return 0;
}