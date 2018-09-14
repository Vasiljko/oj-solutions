/*

  for all nodes that are on path from s to t, we need to pick 1 or 2 nodes such that du[first] + dv[second] is minimum where second can
  be equal to first
  
  we can find minimums with dp because new graph is DAG

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N =1e5+5;
const ll INF = 1e18;

int n,m,T;
bool vis[N];
ll du[N],dv[N],ds[N],dt[N],d1[N],d2[N],dp[N],ans;
vector<pair<int,ll> >v[2*N];
priority_queue<pair<ll,int> >pq;
multiset<ll>su,sv;

void Dijkstra(ll *d,int s){
    for(int i=1;i<=N;i++)d[i]=INF;
    d[s]=0;
    pq.push({-d[s],s});

    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();

        for(auto e:v[cur.second]){
            if(d[cur.second]+e.second<d[e.first]){
                d[e.first]=d[cur.second]+e.second;
                pq.push({-d[e.first],e.first});
            }
        }
    }
}

ll dfs(int s,int dir){
    if(vis[s])return dp[s];
    vis[s]=true;
    dp[s]=du[s];
    for(auto e:v[s]){
        if(dir==0){//go from s to t
            if(ds[s]+e.second+dt[e.first]==ds[T]){
                dp[s]=min(dp[s],dfs(e.first,dir));
            }
        }else{
            if(dt[s]+e.second+ds[e.first]==ds[T]){
                dp[s]=min(dp[s],dfs(e.first,dir));
            }
        }
    }
    ans=min(ans,dp[s]+dv[s]);
    return dp[s];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int s,t,a,b,x,y,z;

    cin>>n>>m;
    cin>>s>>t;
    cin>>a>>b;

    T=t;

    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }

    Dijkstra(du,a);
    Dijkstra(dv,b);
    Dijkstra(ds,s);
    Dijkstra(dt,t);

    ans=du[b];

    memset(vis,false,sizeof(vis));
    dfs(s,0);
    memset(vis,0,sizeof(vis));
    dfs(t,1);

    cout<<ans;
    return 0;
}
