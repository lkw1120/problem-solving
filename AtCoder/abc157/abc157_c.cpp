#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,M,S,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>S>>C;
		v.push_back({S,C});
	}
	ans = -1;
	for(int i=0;i<1000;i++) {
		string str = to_string(i);
		if(str.size() != N) continue;
		bool flag = true;
		for(auto item: v) {
			if(str[item.first-1] != '0'+item.second) {
				flag = false;
			}
		}
		if(flag) {
			ans = i;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}