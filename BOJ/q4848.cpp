#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string s1,s2,ans;
int T;
void preload() {
	v.resize(16);
	v[0] = "{}";
	for(int i=1;i<16;i++) {
		v[i] = "{";
		for(int j=0;j<i;j++) {
			v[i]+=v[j];
			if(j < i-1) v[i]+=",";
		}
		v[i]+="}";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>T;
	while(T--) {
		cin>>s1>>s2;
		int a = find(v.begin(),v.end(),s1)-v.begin();
		int b = find(v.begin(),v.end(),s2)-v.begin();
		ans = v[a+b];
		cout<<ans<<"\n";
	}
	return 0;
}