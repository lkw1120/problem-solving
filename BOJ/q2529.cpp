#include<bits/stdc++.h>
using namespace std;
bool checked[10] = {false};
vector<string> v,ans;
int K;
void solve(string str, int n, int idx) {
	if(idx == K) {
		ans.push_back(str);
		return ;
	}
	if(v[idx] == "<") {
		for(int i=n+1;i<10;i++) {
			if(checked[i]) continue;
			checked[i] = true;
			solve(str+to_string(i),i,idx+1);
			checked[i] = false;
		}
	}
	else {
		for(int i=0;i<n;i++) {
			if(checked[i]) continue;
			checked[i] = true;
			solve(str+to_string(i),i,idx+1);
			checked[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K;
	v.resize(K);
	for(int i=0;i<K;i++) {
		cin>>v[i];	
	}
	fill(checked,checked+10,false);
	for(int i=0;i<10;i++) {
		checked[i] = true;
		solve(to_string(i),i,0);
		checked[i] = false;
	}
	sort(ans.begin(),ans.end());
	cout<<ans[ans.size()-1]<<"\n";
	cout<<ans[0]<<"\n";
	return 0;
}