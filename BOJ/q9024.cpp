#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int T,N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>K;
        v.clear();
        v.resize(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int l,r,gap;
        l = 0;
        r = N-1;
        gap = INT_MAX;
        ans = 0;
        while(l < r) {
            int sum = v[l]+v[r];
            if(abs(sum-K) < gap) {
                gap = abs(sum-K);
                ans = 1;
            }
            else if(abs(sum-K) == gap) {
                ans++;
            }
            if(sum < K) {
                l++;
            }
            else if(K < sum) {
                r--;
            }
            else {
                l++;
                r--;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}