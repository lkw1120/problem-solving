#include<bits/stdc++.h>
using namespace std;
unordered_set<int> st;
vector<int> v;
int K,sum,ans;
void find(int k, int num) {
	st.insert(num);
	if(k == K) return ;
	find(k+1,num);
	find(k+1,num+v[k]);
	find(k+1,num-v[k]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K;
	v.resize(K);
	sum = 0;
	for(int i=0;i<K;i++) {
		cin>>v[i];
		sum+=v[i];
	}
	find(0,0);
	ans = 0;
	for(int i=1;i<=sum;i++) {
		if(!st.count(i)) {
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}