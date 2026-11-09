#include<bits/stdc++.h>
using namespace std;
vector<pair<char,int>> v;
string S;
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    cin>>S;
    int size = S.size();
    char ch = '0';
    int cnt = 1;
    for(int i=1;i<size;i++) {
        if(S[i-1] == S[i]) {
            cnt++;
        }
        else {
            ch = S[i-1];
            v.push_back({ch,cnt});
            cnt = 1;
        }
    }
    v.push_back({S[size-1],cnt});
    ans = 0;
    for(int i=0;i<v.size();i++) {
        int sum = 0;
        if(v[i].first == '0') {
            for(int j=0;j<K*2;j++) {
                if(v.size() <= i+j) break;
                sum+=v[i+j].second;
            }
        }
        else {
            for(int j=0;j<K*2+1;j++) {
                if(v.size() <= i+j) break;
                sum+=v[i+j].second;
            }
        }
        ans = max(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}