#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
int city[MAX][MAX] ={0};
int node[MAX][MAX] = {0};
bool edge[MAX][MAX] = {false};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>city[i][j];
            node[i][j] = city[i][j];
        }
    }
    ans = 0;
    for(int j=0;j<N;j++) {
        for(int i=0;i<N;i++) {
            for(int k=0;k<N;k++) {
                if(i == j || j == k) continue;
                if(city[i][k] > city[i][j] + city[j][k]) {
                    ans = -1;
                }
                if(city[i][k] == city[i][j] + city[j][k]) {
                    node[i][k] = 0;
                }

            }
        }
    }
    if(!ans) {    
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(node[i][j]!=0 && !edge[i][j]) {
                    ans += node[i][j];
                    edge[i][j] = edge[j][i] = true;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}