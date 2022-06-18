#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
string str1,str2;
char dp[MAX] = {};
int N,ans;
void flip(int idx) {
	if(dp[idx] == '0') dp[idx] = '1';
	else dp[idx] = '0';
}
int solve(int x) {
	int cnt = 0;
	for(int i=0;i<N;i++) {
		dp[i] = str1[i];
	}
	if(x == 1) {
		flip(0);
		flip(1);
		cnt++;
	}
	for(int i=1;i<N;i++) {
		if(str2[i-1] != dp[i-1]) {
			flip(i-1);
			flip(i);
			flip(i+1);
			cnt++;
		}
	}
	if(dp[N-1] != str2[N-1]) {
		cnt = -1;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	cin>>str1>>str2;
	int a,b;
	a = solve(0);
	b = solve(1);
	if(a < 0 && b < 0) {
		ans = -1;
	}
	else {
		if(a > 0 && b > 0) ans = min(a,b);
		else if(a < 0) ans = b;
		else if(b < 0) ans = a;
	}
	cout<<ans<<"\n";
}