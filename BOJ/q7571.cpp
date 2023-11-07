#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v1.resize(M);
	v2.resize(M);
	for(int i=0;i<M;i++) {
		cin>>v1[i]>>v2[i];	
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int x,y;
	x = v1[M/2];
	y = v2[M/2];
	ans = 0;
	for(int i=0;i<M;i++) {
		ans+=abs(v1[i]-x)+abs(v2[i]-y);
	}
	cout<<ans<<"\n";
	return 0;
}