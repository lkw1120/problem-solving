#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int N,K;
string ans;
void solve(string str, int n) {
	if(n == N) {
		v.push_back(str);
		return ;
	}
	for(int i=1;i<=3;i++) {
		if(n+i <= N) {
			solve(str+to_string(i)+"+",n+i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	solve("",0);
	if(K <= v.size()) {
		ans = v[K-1].substr(0,v[K-1].size()-1);
	}
	else {
		ans = "-1";	
	}
	cout<<ans<<"\n";
	return 0;	
}