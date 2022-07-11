#include<bits/stdc++.h>
#define MAX 251
using namespace std;
string cache[MAX] = { "" };
int input;
string ans;
string add(string a, string b) {
	int sum = 0;
	string result = "";
	while(!a.empty() || !b.empty() || sum) {
		if(!a.empty()) {
			sum += a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()) {
			sum += b.back()-'0';
			b.pop_back();
		}
		result.push_back((sum%10)+'0');
		sum/=10;
	}
	reverse(result.begin(),result.end());
	return result;
}
string solve(int N) {
	string result = cache[N];
	if(result.size() == 0) {
		for(int i=3;i<=N;i++) {
			if(cache[i].size() != 0) continue;
			cache[i] = add(add(cache[i-2],cache[i-2]),cache[i-1]);
		}
		result = cache[N];
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cache[0] = cache[1] = "1";
	cache[2] = "3";
	while(cin>>input) {
		ans = solve(input);
		cout<<ans<<"\n";
	}
	return 0;
}