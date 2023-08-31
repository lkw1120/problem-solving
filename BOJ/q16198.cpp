#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
void solve(vector<int> w, int sum) {
	if(w.size() == 2) {
		ans = max(ans,sum);
		return ;
	}
	int W = w.size();
	for(int i=1;i<W-1;i++) {
		vector<int> tmp;
		for(int j=0;j<W;j++) {
			if(j != i) {
				tmp.push_back(w[j]);	
			}
		}
		solve(tmp,sum+w[i-1]*w[i+1]);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	ans = 0;
	solve(v,0);
	cout<<ans<<"\n";
	return 0;
}