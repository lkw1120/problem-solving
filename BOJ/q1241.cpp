#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int arr[MAX] = {0};
vector<int> v;
vector<int> cnt;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	cnt.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	for(int i=0;i<N;i++) {
		arr[v[i]]++;
	}
	for(int i=0;i<N;i++) {
		for(int j=1;j<=sqrt(v[i]);j++) {
			if(v[i]%j == 0) {
				if (v[i]/j != j) {
					cnt[i]+=(arr[j] + arr[v[i]/j]);
				}
				else {
					cnt[i]+=arr[j];
				}
			}
		}
	}
	for(auto ans: cnt) {
		cout<<ans-1<<"\n";
	}
	return 0;	
}