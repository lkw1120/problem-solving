#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int N,M,L;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	L = 0;
	for(int i=0;i<N;i++) {
		cin>>v[i];
		L+=v[i].size();
	}
	int lines = (M-L)/(N-1);
	int rest = (M-L)%(N-1);
	for(int i=1;i<N;i++) {
		if(v[i][0] > '_' && 0 < rest) {
			v[i] = "_" + v[i];
			rest--;
		}
	}
	for(int i=N-1;i>0;i--) {
		if(v[i][0] < '_' && 0 < rest) {
			v[i] = "_" + v[i];
			rest--;
		}
	}
	for(int i=0;i<N;i++) {
		ans+=v[i];
		if(i < N-1) {
			for(int j=0;j<lines;j++) {
				ans+="_";
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}