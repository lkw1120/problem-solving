#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin>>N>>K;
    int low = 1;
    int high = K;
    int ans = -1;
    while (low <= high) {
        int cnt = 0;
        int mid = (low + high) / 2;
        for (int i = 1; i <= N; i++)
            cnt += min(mid / i, N);
        if (cnt < K)
            low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}