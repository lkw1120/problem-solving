#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int n = 1<<N;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    int mid = n/2;
    int l = 0;
    int r = mid;
    for(int i=1;i<mid;i++) {
        if(v[i] > v[l]) {
            l = i;
        }
    }
    for(int i=mid+1;i<n;i++) {
        if(v[i] > v[r]) {
            r = i;
        }
    }
    ans = (v[l] < v[r])? l+1: r+1;
    cout<<ans<<"\n";
    return 0;
}