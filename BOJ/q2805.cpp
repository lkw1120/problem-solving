#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> v;
ll N,M,ans;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	sort(v.begin(),v.end());
    ll l,r;
	l = 0;
	r = v.back();
	ans = 0;
    while(l <= r) {
        ll sum = 0;
        ll mid = (l+r)/2;
		for(int i=0;i<N;i++) {
            if(0 < v[i]-mid) {
				sum+=v[i]-mid;
			}
        }
        if(M <= sum){
            l = mid+1;
			ans = max(ans,mid);
        }
        else {
			r = mid-1;
		}
    }
	cout<<ans<<"\n";
    return 0;
}