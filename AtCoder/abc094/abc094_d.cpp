#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,A,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	if(2 < N) {
		A = v[N-1];
		int idx = lower_bound(v.begin(),v.end(),A/2)-v.begin();
		if(A/2-v[idx-1] < v[idx]-A/2) idx--;
		B = v[idx];
	}
	else {
		A = v[1];
		B = v[0];
	}
	cout<<A<<" "<<B<<"\n";
	return 0;
}