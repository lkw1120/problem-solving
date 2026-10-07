#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e9+1;
ll A,B,X,ans;
ll check(int x) {
    int size = to_string(x).size();
    return A*x+B*size;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>X;
    int low,high;
    low = 0;
    high = MAX;
    while(low+1 < high) {
        int mid = (low+high)/2;
            if(check(mid) <= X) {
                low = mid;
            }
            else {
                high = mid;
            }
    }
    ans = low;
    cout<<ans<<"\n";
    return 0;
}