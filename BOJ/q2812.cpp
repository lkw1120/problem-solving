#include<bits/stdc++.h>
using namespace std;
deque<char> dq;
string str,ans;
int N,K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    cin>>str;
    for(int i=0;i<N;i++) {
        while(K != 0 && !dq.empty() && dq.back() < str[i]) {
            dq.pop_back();
            K--;
        }
        dq.push_back(str[i]);
    }
    for(int i=0;i<dq.size()-K;i++) {
        ans+=dq[i];
    }
    cout<<ans<<"\n";
    return 0;
}