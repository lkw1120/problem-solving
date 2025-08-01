#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v = {
    0,990,1010,1970,2030,2940,3060,
    3930,4060,4970,5030,5990,6010,7000
};
ll dp[34];
ll A,B,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    cin>>N;
    for(int i=0;i<N;i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int size = v.size();
    dp[0] = 1;
    for(int i=1;i<size;i++) {
        for(int j=0;j<i;j++) {
            int dist = v[i]-v[j];
            if(A <= dist && dist <= B) {
                dp[i]+=dp[j];
            }
        }
    }
    ans = dp[size-1];
    cout<<ans<<"\n";
    return 0;
}