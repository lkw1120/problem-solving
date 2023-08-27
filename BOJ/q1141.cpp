#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int N,size,ans;
bool compare(string a, string b) {
	if(a.size() != b.size()) {
		return a.size() < b.size();	
	}
	else {
		return a < b;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	sort(v.begin(),v.end(),compare);
	ans = N;
	for(int i=0;i<N;i++) {
		int size = v[i].size();
		for(int j=i+1;j<N;j++) {
			if(v[j].substr(0,size) == v[i]) {
				ans--;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}