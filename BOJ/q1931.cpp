#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<pair<int,int>> v;
int N,L,R,idx,ans;
bool compare(pair<int,int> a, pair<int,int> b) {
	if(a.second < b.second) {
		return true;
	}
	else if(a.second > b.second) {
		return false;	
	}
	else {
		return a.first < b.first;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>L>>R;
		v.push_back({L,R});
	}
	sort(v.begin(),v.end(),compare);
	ans = idx = 0;
	for(auto item:v) {
		if(idx<=item.first){
			idx=item.second;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;	
}