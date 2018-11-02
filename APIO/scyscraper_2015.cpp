#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 3e4+5;
const ll INF = 2e9+1000;

int n,m,b[N],p[N];
int dist[N];
map<pair<int,int>,bool>exist;
vector<pair<int,int> >v[N];
priority_queue<pair<int,int>>pq;
set<int>S[N];

void Dijkstra(){
    for(int i=0;i<n;i++)dist[i]=INF;
    pq.push({0,b[0]});
    dist[b[0]]=0;

    while(!pq.empty()){
        int t=pq.top().second;
        int len=-pq.top().first;
        pq.pop();
        if(dist[t]<len)continue;
        for(auto e:v[t]){
            int to=e.first;
            ll w=e.second;

            if(dist[t]+w<dist[to]){
                dist[to]=w+dist[t];
                pq.push({-dist[to],to});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>b[i]>>p[i];
        S[b[i]].insert(p[i]);
    }

    for(int i=0;i<n;i++){
        for(auto e:S[i]){
            for(int j=i+e;j<n;j+=e){
                v[i].push_back({j,(j-i)/e});
                if(S[j].lower_bound(e)!=S[j].end()&&*S[j].lower_bound(e)==e)break;
            }
            for(int j=i-e;j>=0;j-=e){
                v[i].push_back({j,(i-j)/e});
                if(S[j].lower_bound(e)!=S[j].end()&&*S[j].lower_bound(e)==e)break;
            }
        }
    }
    Dijkstra();

    if(dist[b[1]]==INF)cout<<-1;
    else cout<<dist[b[1]];

    return 0;
}
