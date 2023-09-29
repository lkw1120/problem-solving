#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1001;
vector<pair<int,int>> v;
int arr[MAX] = {0};
ll N,L,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	ans = 0;
	while(N--) {
		fill(arr,arr+MAX,0);
		cin>>L;
		int l,r,start,end,sum;
		l = r = start = end = 0;
		sum = INT_MIN;
		for(int i=1;i<=L;i++) {
			cin>>arr[i];
			if(arr[i-1]+arr[i] <= arr[i]) {
				l = r = i;
			}
			else {
				arr[i]+=arr[i-1];
				r = i;
			}
			if(sum < arr[i] || (sum == arr[i] && r-l < end-start)) {
				sum = arr[i];
				start = l;
				end = r;
			}
		}
		v.push_back({start,end});
		ans+=sum;
	}
	cout<<ans<<"\n";
	for(auto item: v) {
		cout<<item.first<<" "<<item.second<<"\n";	
	}
	return 0;
}