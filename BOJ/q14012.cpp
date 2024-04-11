#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+1;
int arr1[MAX];
int arr2[MAX];
vector<pair<int,int>> v;
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr1[i];
    }
    for(int i=1;i<=N;i++) {
        cin>>arr2[i];
    }
    for(int i=1;i<=N;i++) {
        v.push_back({arr1[i],arr2[i]});
    }
    sort(v.begin(),v.end());
    ans = M;
    for(int i=0;i<N;i++) {
        int a = v[i].first;
        int b = v[i].second;
        if(a < b && a <= ans) {
            ans+=(b-a);
        }
    }
    cout<<ans<<"\n";
    return 0;
}