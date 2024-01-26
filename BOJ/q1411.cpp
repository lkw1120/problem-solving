#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
string str;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>str;
		int size = str.size();
		map<char,int> tmp;
		for(int j=0;j<size;j++) {
			if(!tmp[str[j]]) {
				tmp[str[j]] = j+1;
			}
			str[j] = 'a'+tmp[str[j]]-1;
		}
		mp[str]++;
	}
	ans = 0;
	for(auto item: mp) {
		int cnt = item.second;
		ans+=(cnt*(cnt-1))/2;
	}
	cout<<ans<<"\n";
	return 0;
}