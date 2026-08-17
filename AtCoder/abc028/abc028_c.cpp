#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int arr[5];
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<5;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<5;i++) {
        for(int j=i+1;j<5;j++) {
            for(int k=j+1;k<5;k++) {
                v.push_back(arr[i]+arr[j]+arr[k]);
            }
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ans = v[v.size()-3];
    cout<<ans<<"\n";
    return 0;
}