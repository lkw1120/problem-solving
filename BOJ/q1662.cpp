#include<bits/stdc++.h>
using namespace std;
const int MAX = 50;
int check[MAX] = {0};
stack<int> s;
string S;
int ans;
int solve(int left, int right) {
    int result = 0;
    for(int i=left;i<right;i++) {
        if(S[i] == '(') {
            int m = S[i-1]-'0';
            result+=m*solve(i+1,check[i])-1;
            i = check[i];
            continue;
        }
        result++;
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>S;
    for(int i=0;i<S.size();i++) {
        if(S[i] == '(') {
            s.push(i);
        }
        if(S[i] == ')') {
            check[s.top()] = i;
            s.pop();
        }
    }
    ans = solve(0,S.size());
    cout<<ans<<"\n";
    return 0;
}