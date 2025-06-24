#include<bits/stdc++.h>
using namespace std;
string str;
int N,ans;
int find(char ch) {
    queue<char> q;
    q.push(ch);
    for(int i=0;i<N;i++) {
        if(q.back() == 'R' && str[i] == 'S') {
            q.push(str[i]);
        }
        else if(q.back() == 'P' && str[i] == 'R') {
            q.push(str[i]);
        }
        else if(q.back() == 'S' && str[i] == 'P') {
            q.push(str[i]);
        }
    }
    q.pop();
    while(!q.empty()) {
        if(q.back() == 'R' && q.front() != 'S') {
            q.pop();
        }
        else if(q.back() == 'P' && q.front() != 'R') {
            q.pop();
        }
        else if(q.back() == 'S' && q.front() != 'P') {
            q.pop();
        }
        else {
            break;
        }
    }
    return N-q.size();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>str;
    ans = min({find('R'),find('S'),find('P')});
    cout<<ans<<"\n";
    return 0;
}