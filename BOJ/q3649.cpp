#include<bits/stdc++.h>
using namespace std;
int X,N,L1,L2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>X) {
		cin>>N;
		X*=10000000;
		vector<int> v(N);
		for(int i=0;i<N;i++) {
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		bool flag = false;
		for(int i=0;i<N;i++) {
			int diff = X-v[i];
			int idx = lower_bound(v.begin(),v.end(),diff)-v.begin();
			if(idx != i && diff == v[idx]) {
				L1 = v[i];
				L2 = v[idx];
				flag = true;
				break;
			}
		}
		if(flag) {
			cout<<"yes"<<" "<<L1<<" "<<L2<<"\n";
		}
		else {
			cout<<"danger"<<"\n";
		}
	}
	return 0;	
}