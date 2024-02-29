#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int arr[10];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    int l,r;
    l = r = 0;
    int cnt = 0;
    while(l <= r) {
        if(r == N) break;
        if(cnt <= 2) {
            if(arr[v[r]] == 0) {
                cnt++;
            }
            arr[v[r]]++;
            r++;
        }
        else {
            arr[v[l]]--;
            if(arr[v[l]] == 0) {
                cnt--;
            }
            l++;
        }
        if(cnt <= 2) {
            ans = max(ans,r-l);
        }
    }
    cout<<ans<<"\n";
    return 0;
}