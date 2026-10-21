#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10][10];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        int low = i%10;
        int high = -1;
        int n = i;
        while(0 < n) {
            high = n%10;
            n/=10;
        }
        arr[high][low]++;
    }
    ans = 0;
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
              ans+=arr[i][j]*arr[j][i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}