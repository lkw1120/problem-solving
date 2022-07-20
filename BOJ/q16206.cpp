#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int N,M,cake,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>cake;
		if(cake%10) {
			v2.push_back(cake);	
		}
		else {
			v1.push_back(cake);	
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	ans = 0;
	int cut,cnt;
	cut = cnt = 0;
	for(auto item: v1) {
		while(item > 0 && cut < M) {
			item-=10;
			cnt++;
			if(item > 0) {
				cut++;
			}
		}
		if(item == 10) cnt++;
	}
	for(auto item: v2) {
		while(item/10 > 0 && cut < M) {
			item-=10;
			cnt++;
			cut++;
		}
	}
	ans = cnt;
	cout<<ans<<"\n";
	return 0;
}