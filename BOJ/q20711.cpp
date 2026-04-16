#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100001;
const int MAX_ID = 100001;
vector<int> days[MAX_N];
int arr[MAX_ID];
int n,k,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin>>k;
        days[i].resize(k);
        for(int j=0;j<k;j++) {
            cin>>days[i][j];
        }
    }
    for(int i=n;i>=1;i--) {
        int tmp = 1;
        for(auto item: days[i]) {
            tmp = max(tmp,arr[item]+1);
        }
        for(auto item: days[i]) {
            arr[item] = tmp;
        }
        ans = max(ans,tmp);
    }
    cout<<ans<<"\n";
    return 0;
}