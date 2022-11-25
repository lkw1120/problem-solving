#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,cnt,sum,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	sort(v.begin(),v.end());
	ans = 0;
	do {
		cnt = sum = 0;
		int arr[101] = {0};
		arr[0] = v[0];
		sum = v[0];
		for(int i=1;i<N;i++) {
			arr[sum] = v[i];
			sum+=v[i];
		}
		for(int i=0;i<50;i++) {
			if(arr[i] != 0 && arr[i+50] != 0) {
				cnt++;	
			}
		}
		ans = max(ans,cnt);
	} while(next_permutation(v.begin(),v.end()));
	cout<<ans<<"\n";
	return 0;	
}