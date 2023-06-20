#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string str;
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ans = 0;
	for(int i=0;i<M;i++) {
		cin>>str;
		int size = str.size();
		int l,r,mid;
		l = 0;
		r = N-1;
		while(l <= r) {
			mid = (l+r)/2;
			if(v[mid] < str) {
				l = mid+1;
			}
			else if(str < v[mid]) {
				r = mid-1;
			}
			if(str == v[mid].substr(0,size)) {
				ans++;
				break;	
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}