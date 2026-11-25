#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,X,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    cin>>X;
    sort(v.begin(),v.end());
    int l,r;
    l = 0;
    r = N-1;
    while(l < r) {
        int sum = v[l]+v[r];
        if(sum == X) {
            ans++;
            l++;
            r--;
        }
        else if(sum < X) {
            l++;
        }
        else {
            r--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}