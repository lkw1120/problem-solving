#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>B;
	v.resize(N*M);
	for(int i=0;i<N*M;i++) {
		cin>>v[i];
	}
	int time = INT_MAX;
	int high = 0;
	for(int h=0;h<=256;h++) {
		int add = 0;
		int remove = 0;
		for(int i=0;i<N*M;i++) {
			if(v[i] < h) {
				add+=(h-v[i]);
			}
			if(h < v[i]) {
				remove+=(v[i]-h);
			}
		}
		if(add <= remove+B) {
			int t = remove*2+add;
			if(t <= time) {
				time = t;
				high = h;
			}
		}
	}
	cout<<time<<" "<<high<<"\n";
	return 0;
}