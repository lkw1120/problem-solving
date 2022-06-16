#include<bits/stdc++.h>
using namespace std;
int cache[26] = {0};
int idx,cnt;
string str,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>str;
	ans = "I'm Sorry Hansoo";
	for(auto c: str) {
		idx = (int)(c - 'A');
		cache[idx]++;
	}
	cnt = 0;
	for(int i=0;i<26;i++) {
		if(cache[i]%2) {
			cnt++;
			idx = i;
		}
	}
	if(cnt < 2) {
		ans="";
		for(int i=0;i<26;i++) {
			for(int j=0;j<cache[i]/2;j++) {
				ans+=(char)(i+'A');
			}
		}
		if(cnt == 1) {
			ans+=(char)(idx+'A');
		}
		for(int i=25;i>=0;i--) {
			for(int j=0;j<cache[i]/2;j++) {
				ans+=(char)(i+'A');
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}