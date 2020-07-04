#include<bits/stdc++.h>
using namespace std;
vector<string> v;
bool alphabet[26] = {false};
int N,K,ans;
void solve(int k, int idx) {
	if(k >= K) {
		int cnt = 0;
		for(auto word: v) {
			bool flag = true;
			for(int i=0;i<word.size();i++) {
				if(!alphabet[word[i]-'a']) {
					flag = false;
					break;
				}
			}
			if(flag) cnt++;
		}
		ans = max(ans,cnt);
		return ;
	}
	if(idx < 26) {
		switch(idx) {
			case 'a'-'a':
			case 'n'-'a':
			case 't'-'a':
			case 'i'-'a':
			case 'c'-'a':
				solve(k,idx+1);
				break;
			default:
				alphabet[idx] = true;
				solve(k+1,idx+1);
				alphabet[idx] = false;
				solve(k,idx+1);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	string word;
	for(int i=0;i<N;i++) {
		cin>>word;
		v.push_back(word.substr(4,word.size()-8));
	}
	ans = 0;
	if(K >= 5) {
		alphabet['a'-'a'] = true;
		alphabet['n'-'a'] = true;
		alphabet['t'-'a'] = true;
		alphabet['i'-'a'] = true;
		alphabet['c'-'a'] = true;
		solve(5,0);
	}
	cout<<ans<<"\n";
    return 0;
}