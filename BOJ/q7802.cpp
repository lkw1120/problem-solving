#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4+1;
string code[7] = {
    ".--",
    "-.",
    "---",
    "..",
    "--..",
    "--.-",
    ".-."
};
char arr[MAX];
int dp[MAX];
string str,ans;
char decode(int n) {
    for(int i=0;i<7;i++) {
        string tmp = str.substr(n);
        auto pos = tmp.find(code[i]);
        if(pos != string::npos && pos == 0) {
            return 'A'+i;
        }
    }
    return '&';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        fill(arr,arr+MAX,'&');
        fill(dp,dp+MAX,0);
        cin>>str;
        if(cin.eof()) break;
        int size = str.size();
        for(int i=0;i<size;i++) {
            char ch = decode(i);
            if(ch != '&') {
                arr[i] = ch;
                dp[i] = code[ch-'A'].size();
            }
        }
        ans = "";
        int p = 0;
        bool flag = true;
        while(p < size) {
            if(arr[p] == '&') {
                flag = false;
                break;
            }
            ans+=arr[p];
            p+=dp[p];
        }
        if(flag) {
            cout<<ans<<"\n";
        }
        else {
            cout<<"could not be translated"<<"\n";
        }
    }
    return 0;
}