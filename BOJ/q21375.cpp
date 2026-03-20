#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const string code = "UUNNVHVHBA";
string str;
vector<int> v;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    int len = code.size();
    v.resize(len,INF);
    ans = INF;
    for(int i=0;i<str.size();i++) {
        for(int j=len-1;j>=0;j--) {
            if(str[i] != code[j]) continue;
            int tmp;
            if(j == 0) {
                tmp = 0;
            } 
            else {
                if(v[j-1] == INF) continue;
                tmp = i+v[j-1];
            }
            if(j == len-1) {
                ans = min(ans,tmp);
            }
            v[j] = min(v[j],tmp-(i+1));
        }
    }
    cout<<ans<<"\n";
    return 0;
}