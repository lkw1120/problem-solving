#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	sort(v.begin(),v.end());
	ans = v[0];
	for(int i=1;i<N;i++) {
		if(v[i] < ans*(i+1)) {
			ans = v[i]/(i+1);	
		}
	}
	cout<<ans<<"\n";
	return 0;
}