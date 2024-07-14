#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
int arr[MAX];
unordered_set<int> st;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    ans = 0;
    int p = 1;
    for(int i=1;i<=N;i++) {
        while(st.count(arr[i])) {
            st.erase(arr[p]);
            p++;
        }
        st.insert(arr[i]);
        ans+=(i-p+1);
    }
    cout<<ans<<"\n";
    return 0;
}