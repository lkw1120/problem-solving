#include<bits/stdc++.h>
#define MAX 51
using namespace std;
vector<int> v;
int N,B,ans;
void solve() {
	bool isFinish = false;
	while(!isFinish) {
		isFinish = true;
		for(int i=0;i<N;i++) {
			if(v[i]%2 == 1) {
				v[i]--;
				ans++;	
			}
		}
		for(int i=0;i<N;i++) {
			if(v[i] != 0) isFinish = false;
		}
		if(!isFinish) {
			for(int i=0;i<N;i++) {
				v[i]/=2;
			}
			ans++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>B;
		if(B != 0) v.push_back(B);
	}
	N = v.size();
	ans = 0;
	solve();
	cout<<ans<<"\n";
	return 0;	
}