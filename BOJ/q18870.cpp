#include<bits/stdc++.h>
using namespace std;
vector<int> v,vv;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	vv.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
		vv[i] = v[i];
	}
	sort(vv.begin(),vv.end());
	vv.erase(unique(vv.begin(),vv.end()),vv.end());
	for(int i=0;i<N;i++) {
		auto idx = lower_bound(vv.begin(),vv.end(),v[i])-vv.begin();	
		cout<<idx<<" ";
	}
	cout<<"\n";
	return 0;
}