#include<bits/stdc++.h>
using namespace std;
vector<int> v,res;
int N,X;
void solve(int left, int right) {
	if(left < right) {
		int mid = (left+right)/2;
		solve(left,mid);
		solve(mid+1,right);
		res.push_back(v[mid]);
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
	cin>>X;
	for(int i=0;i<N;i++) {
		if(v[i] == -1) v[i] = X;	
	}
	sort(v.begin(),v.end());
	solve(0,N);
	for(auto item: res) {
		cout<<item<<" ";
	}
	cout<<"\n";
	return 0;
}