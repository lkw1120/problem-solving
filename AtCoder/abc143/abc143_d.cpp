#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=i+1;j<N;j++) {
			for(int k=j+1;k<N;k++) {
				if(v[k] < v[i]+v[j]) {
					ans++;
				}
		    }
		}
	}
	cout<<ans<<"\n";
	return 0;
}