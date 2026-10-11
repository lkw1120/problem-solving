#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<pair<int,int>> v1,v2;
map<int,int> mp1,mp2;
int arr[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        if(i%2) {
            mp1[arr[i]]++;
        }
        else {
            mp2[arr[i]]++;	
        }
    }
    for(auto item: mp1) {
        v1.push_back({item.second,item.first});	
    }
    for(auto item: mp2) {
        v2.push_back({item.second,item.first});	
    }
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());
    if(v1[0].second != v2[0].second) {
        ans = N-v1[0].first-v2[0].first;
    }
    else {
        if(v1.size() == 1 && v2.size() == 1) {
            ans = N/2;
        }
        else {
            ans = INT_MAX;
            if(2 <= v1.size()) {
                ans = min(ans,N-v1[1].first-v2[0].first);
            }
            if(2 <= v2.size()) {
                ans = min(ans,N-v1[0].first-v2[1].first);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}