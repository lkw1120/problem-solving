#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
vector<pair<int,int>> node[MAX];
bool isChecked[MAX] = {false};
int N,from,to,weight,ans;
void solve(int n, int w) {
	if(isChecked[n]) return ;
	isChecked[n] = true;
	if(ans == 0 || ans < w) {
		ans = w;
		to = n;
	}
	for(auto item: node[n]) {
		solve(item.first, w+item.second);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N-1;i++) {
		cin>>from>>to>>weight;
		node[from].push_back({to,weight});
		node[to].push_back({from,weight});
	}
	ans = 0;
	solve(1,0);
	memset(isChecked,0,sizeof(isChecked));
	solve(to,0);
	cout<<ans<<"\n";
	return 0;
}