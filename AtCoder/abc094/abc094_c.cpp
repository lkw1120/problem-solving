#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	v1.resize(N);
	v2.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v1[i];
		v2[i] = v1[i];
	}
	sort(v2.begin(),v2.end());
	for(int i=0;i<N;i++) {
		int idx = lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
		if(idx < N/2) {
			cout<<v2[N/2]<<"\n";	
		}
		else {
			cout<<v2[N/2-1]<<"\n";
		}
	}
	return 0;
}