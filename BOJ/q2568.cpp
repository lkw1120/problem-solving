#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<int> lis,idx,res;
int N,A,B;
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
    for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	sort(v.begin(),v.end());
	lis.push_back(v[0].second);
	idx.push_back(0);
	for(int i=1;i<N;i++) {
		int now = v[i].second;
		if(lis.back() < now) {
			idx.push_back(lis.size());
			lis.push_back(now);
		}
		else {
			int pos = lower_bound(lis.begin(),lis.end(),now)-lis.begin();
			lis[pos] = now;
			idx.push_back(pos);
		}
	}
	cout<<N-lis.size()<<"\n";
	int len = lis.size()-1;
	for(int i=idx.size()-1;i>=0;i--) {
		if(len == idx[i]) {
			len--;
		}
		else {
			res.push_back(v[i].first);	
		}
	}
	reverse(res.begin(),res.end());
	for(auto item: res) {
		cout<<item<<"\n";	
	}
	return 0;
}