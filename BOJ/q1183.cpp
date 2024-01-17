#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back(A-B);
	}
	sort(v.begin(),v.end());
	ans = N%2? 1: abs(v[N/2]-v[N/2-1])+1;
	cout<<ans<<"\n";
	return 0;
}