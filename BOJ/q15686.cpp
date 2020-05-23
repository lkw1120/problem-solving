#include<bits/stdc++.h>
using namespace std;
const int MAX = 51;
int matrix[MAX][MAX] = {0};
vector<pair<int,int>> chicken;
vector<pair<int,int>> city;
int N,M,ans;
void comb(int idx, int cnt, bool check[]) {
    if(cnt > M) return ;
    if(idx >= chicken.size()) {
        if(cnt == M) {
            int size = city.size();
            int dist[size] = {0};
            int x,y,d;
            for(int i=0;i<idx;i++) {
                if(!check[i]) continue;
                for(int j=0;j<size;j++) {
                    y = chicken[i].first;
                    x = chicken[i].second;
                    d = abs(y-city[j].first)+abs(x-city[j].second);
                    dist[j] = dist[j] == 0? d : min(dist[j],d);
                }
            }
            int sum = 0;
            for(int i=0;i<size;i++) {
                sum+=dist[i];
            }
            ans = ans == 0? sum : min(ans,sum);
        }
        return ;
    }
    check[idx] = false;
    comb(idx+1,cnt,check);
    check[idx] = true;
    comb(idx+1,cnt+1,check);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>matrix[i][j];
            if(matrix[i][j] == 1) {
                city.push_back({i,j});
            }
            if(matrix[i][j] == 2) {
                chicken.push_back({i,j});
            }
        }
    }
    ans = 0;
    int size = chicken.size();
    bool check[size] = {false};
    comb(0,0,check);
    cout<<ans<<"\n";
    return 0;
}