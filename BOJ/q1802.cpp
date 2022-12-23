#include<bits/stdc++.h>
using namespace std;
int T;
string input,ans;
void solve(string str) {
	int N,M;
	N = str.size();
	M = N/2;
	if(M == 0) return ;
	bool flag = true;
	for(int i=0;i<M;i++) {
		if(str[i] == str[N-i-1]) {
			flag = false;
		}
	}
	if(flag) {
		solve(str.substr(0,M));
		solve(str.substr(M+1));
	}
	else {
		ans = "NO";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>input;
		ans = "YES";
		solve(input);
		cout<<ans<<"\n";
	}
	return 0;
}