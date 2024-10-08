#include<bits/stdc++.h>
using namespace std;
int arr[301];
int res[301];
int N,M,ans;
void solve(int l, int r) {
    for(int i=1;i<=N;i++) {
        res[i] = arr[i];
    }
    for(int i=1;i<=N;i++) {
        if(l <= res[i] && res[i] <= r) {
            int p = i;
            for(int j=i+1;j<=N;j++) {
                if(l <= res[j] && res[j] <= r) {
                    if(res[j] < res[p]) {
                        p = j;
                    }
                }
            }
            if(res[p] < res[i]) {
                swap(res[i],res[p]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    cin>>M;
    while(M--) {
        int l,r;
        cin>>l>>r;
        solve(l,r);
        for(int i=1;i<=N;i++) {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}