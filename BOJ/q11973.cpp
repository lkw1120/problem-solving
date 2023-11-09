#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,ans;
int check(int r) {
    int cnt = 1;
    int left = v[0];
    for(int i=1;i<N;i++) {
        if(left+2*r < v[i]) {
            left = v[i];
            cnt++;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l,r;
    l = v[0];
    r = v[N-1]-v[0];
    while(l <= r) {
		int mid = (l+r)/2;
		int cnt = check(mid);
		if(K < cnt) {
			l = mid+1;
		}
		else {
			r = mid-1;
			ans = mid;
		}
	}
	cout<<ans<<"\n";
    return 0;
}