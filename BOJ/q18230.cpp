#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int N,A,B,tile,sum,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>A>>B;
	for(int i=0;i<A;i++) {
		cin>>tile;
		v1.push_back(tile);
	}
	for(int i=0;i<B;i++) {
		cin>>tile;
		v2.push_back(tile);
	}
	sort(v1.begin(),v1.end(),greater<int>());
	sort(v2.begin(),v2.end(),greater<int>());
	if(N%2) {
		sum+=v1[0];
		v1.erase(v1.begin());
		N--;
	}
	int tile1,tile2;
	while(N > 0) {
		tile1 = tile2 = 0;
		if(v1.size() >= 2) {
			tile1 = v1[0]+v1[1];
		}
		if(v2.size() >= 1) {
			tile2 = v2[0];
		}
		if(tile1 > tile2) {
			sum+=tile1;
			if(v1.size() >= 2) {
				v1.erase(v1.begin(),v1.begin()+2);
			}
		}
		else {
			sum+=tile2;
			if(v2.size() >= 1) {
				v2.erase(v2.begin());
			}
		}
		N-=2;	
	}
	ans = sum;
	cout<<ans<<"\n";
	return 0;	
}