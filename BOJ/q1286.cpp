#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<string> v;
string str;
ll abc[26];
ll N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>str;
		v.push_back(str+str);
	}
	for(int i=0;i<N;i++) {
		v.push_back(v[i]);	
	}
	N*=2,M*=2;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			ll cnt = (i+1)*(N-i)*(j+1)*(M-j);
			abc[v[i][j]-'A']+=cnt;
		}
	}
	for(int i=0;i<26;i++) {
		cout<<abc[i]<<"\n";	
	}
	return 0;
}