#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int arr[MAX][2];
vector<pair<int,int>> v;
int n,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if(arr[x][0] == 0) {
            arr[x][0] = i;
        }
        arr[x][1] = i;
    }
    for(int i=1;i<MAX;i++) {
        if(arr[i][0] != 0) {
            v.push_back({arr[i][1],arr[i][0]}); 
        }
    }
    sort(v.begin(),v.end());
    ans = 0;
    int tmp = 0;
    for(auto [r,l]: v) {
        if(tmp < l) {
            ans++;
            tmp = r;
        }
    }
    cout<<ans<<"\n";
    return 0;
}