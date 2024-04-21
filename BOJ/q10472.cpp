#include<bits/stdc++.h>
using namespace std;
set<string> st;
int dX[5] = {0,0,1,0,-1};
int dY[5] = {0,1,0,-1,0};
int P,ans;
int find(string str) {
    queue<string> q;
    q.push(str);
    st.insert(str);
    int cnt = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            string now = q.front();
            q.pop();
            if(now == ".........") {
                return cnt;
            }
            for(int i=0;i<9;i++) {
                string next = now;
                for(int j=0;j<5;j++) {
                    int dx = i/3+dX[j];
                    int dy = i%3+dY[j];
                    if(0 <= dx && dx < 3 && 0 <= dy && dy < 3) {
                        if(next[dx*3+dy] == '*') {
                            next[dx*3+dy] = '.';
                        }
                        else {
                            next[dx*3+dy] = '*';
                        }
                    }
                }
                if(!st.count(next)) {
                    q.push(next);
                    st.insert(next);
                }
            }
        }
        cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>P;
    while(P--) {
        st.clear();
        string str = "";
        for(int i=0;i<3;i++) {
            string tmp;
            cin>>tmp;
            str+=tmp;
        }
        ans = find(str);
        cout<<ans<<"\n";
    }
    return 0;
}