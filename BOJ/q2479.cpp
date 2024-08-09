#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
string arr[1001];
int dist[1001];
int N,K,A,B;
string ans;
bool hamming(string a, string b) {
    int cnt = 0;
    for(int i=0;i<K;i++) {
        if(a[i] != b[i]) cnt++;
    }
    return cnt == 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    for(int i=1;i<N;i++) {
        for(int j=i+1;j<=N;j++) {
            if(hamming(arr[i],arr[j])) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    cin>>A>>B;
    queue<pair<int,string>> q;
    q.push({A,to_string(A)});
    dist[A] = 1;
    ans = "";
    while(!q.empty()) {
        int now = q.front().first;
        string path = q.front().second;
        q.pop();
        if(now == B) {
            ans = path;
            break;
        }
        for(auto next: v[now]) {
            if(!dist[next]) {
                dist[next] = dist[now]+1;
                q.push({next,path+" "+to_string(next)});
            }
        }
    }
    if(ans.size()) {
        cout<<ans<<"\n";
    }
    else {
        cout<<-1<<"\n";
    }
    return 0;
}