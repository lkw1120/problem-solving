#include<bits/stdc++.h>
using namespace std;
string S,T;
int ans;
void solve(string t) {
	if(t.size() < S.size()) return;
	if(t == S) {
		ans = 1;
		return ;
	}
	if(t[t.size()-1] == 'A') {
		solve(t.substr(0,t.size()-1));
	}
	else {
		t = t.substr(0,t.size()-1);
		reverse(t.begin(),t.end());
		solve(t);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>S>>T;
	solve(T);
	cout<<ans<<"\n";
	return 0;
}