#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int arr1[10001];
int arr2[10001];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        mp.clear();
        cin>>N;
        if(N == 0) break;
        for(int i=1;i<=N;i++) {
            cin>>arr1[i];
            mp[arr1[i]]++;
        }
        cin>>M;
        for(int i=1;i<=M;i++) {
            cin>>arr2[i];
            mp[arr2[i]]++;
        }
        vector<int> v1,v2;
        int sum = 0;
        for(int i=1;i<=N;i++) {
            if(mp[arr1[i]] == 2) {
                v1.push_back(sum+arr1[i]);
                sum = 0;
            }
            else {
                sum+=arr1[i];
            }
        }
        v1.push_back(sum);
        sum = 0;
        for(int i=1;i<=M;i++) {
            if(mp[arr2[i]] == 2) {
                v2.push_back(sum+arr2[i]);
                sum = 0;
            }
            else {
                sum+=arr2[i];
            }
        }
        v2.push_back(sum);
        int size = v1.size();
        ans = 0;
        for(int i=0;i<size;i++) {
            ans+=max(v1[i],v2[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}