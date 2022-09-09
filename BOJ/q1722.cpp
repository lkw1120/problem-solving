#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll facto[21] = {0};
bool check[21] = {false};
ll N,K,M,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	facto[0] = 1;
	for(int i=1;i<=20;i++) {
		facto[i] = facto[i-1]*i;
	}
	cin>>N;
	cin>>K;
	vector<int> v(N);
	if(K == 1) {
		cin>>M;
		for(int i=0;i<N;i++) {
			for(int j=1;j<=N;j++) {
				if(!check[j]) {
					if(facto[N-i-1] < M) {
						M-=facto[N-i-1];
					}
					else {
						v[i] = j;
						check[j] = true;
						break;
					}
				}
			}
		}
		for(auto item: v) {
			cout<<item<<" ";
		}
		cout<<"\n";
	}
	else {
		for(int i=0;i<N;i++) {
			cin>>v[i];	
		}
		ans = 0;
		for(int i=0;i<N;i++) {
			for(int j=1;j<v[i];j++) {
				if (!check[j]) {
					ans+=facto[N-i-1];
				}       
			}
			check[v[i]] = true;
		}
		cout<<ans+1<<"\n";
	}
	return 0;	
}