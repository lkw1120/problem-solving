#include<bits/stdc++.h>
using namespace std;
string input;
int K,ans;
int solve(string str, int n) {
	int cnt = 0;
	for(int i=0;i<K;i++) {
		if(str[((n+i)%str.size())] == 'b') cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	K = 0;
	for(int i=0;i<input.size();i++) {
		if(input[i] == 'a') K++;
	}
	ans = INT_MAX;
	for(int i=0;i<input.size();i++) {
		ans = min(ans,solve(input,i));
	}
	cout<<ans<<"\n";
	return 0;	
}