#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,L,a,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>L;
    for(int i=0;i<N;i++) {
        cin>>a;
        v.push_back(a);
    }
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(),v.end());
    int low, high;
    low = 1;
    high = L-1;
    while(low <= high) {
        int mid = (low+high)/2;
        int cnt = 0;
        for(int i=1;i<v.size();i++) {
            if(v[i]-v[i-1] > mid) {
                cnt+=(v[i]-v[i-1]-1)/mid;
            }
        }
        if(cnt > M) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    ans = low;
    cout<<ans<<"\n";
    return 0;
}