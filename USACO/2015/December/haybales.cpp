#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e15+7;
const int N = 2e5+5;

int n,q;
ll lazy[4*N],a[N];
pair<ll,ll>tree[4*N];



void Push(int c,int ss,int se){
    if(lazy[c]){
        tree[c].first+=lazy[c]*(se-ss+1);
        tree[c].second+=lazy[c];
        if(ss!=se){
            lazy[c<<1]+=lazy[c];
            lazy[c<<1|1]+=lazy[c];
        }
        lazy[c]=0;
    }
}

void Build(int c,int ss,int se){
    if(ss==se){
        tree[c]={a[ss],a[ss]};
        return;
    }
    int mid=(ss+se)>>1;
    Build(c<<1,ss,mid);
    Build(c<<1|1,mid+1,se);
    tree[c].first=tree[c<<1].first+tree[c<<1|1].first;
    tree[c].second=min(tree[c<<1].second,tree[c<<1|1].second);
}

void Set(int c,int ss,int se,int qs,int qe,ll val){
    Push(c,ss,se);
    if(qe<ss||qs>se||ss>se)return;
    if(qs<=ss&&se<=qe){
        lazy[c]=val;
        Push(c,ss,se);
        return;
    }
    int mid=(ss+se)>>1;
    Set(c<<1,ss,mid,qs,qe,val);
    Set(c<<1|1,mid+1,se,qs,qe,val);
    tree[c].first=tree[c<<1].first+tree[c<<1|1].first;
    tree[c].second=min(tree[c<<1].second,tree[c<<1|1].second);
}

pair<ll,ll> Get(int c,int ss,int se,int qs,int qe){
    Push(c,ss,se);
    if(qe<ss||qs>se||ss>se)return {0LL,INF};
    if(qs<=ss&&se<=qe)return tree[c];

    int mid=(ss+se)>>1;
    pair<ll,ll> fi=Get(c<<1,ss,mid,qs,qe);
    pair<ll,ll> si=Get(c<<1|1,mid+1,se,qs,qe);

    return {fi.first+si.first,min(fi.second,si.second)};
}

int main()
{
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    fin>>n>>q;

    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    Build(1,1,n);

    while(q--){
        char c;
        int x,y;

        fin>>c>>x>>y;
        if(c=='M'){
            fout<<Get(1,1,n,x,y).second<<"\n";
        }else if(c=='P'){
            ll z;
            fin>>z;
            Set(1,1,n,x,y,z);
        }else{
            fout<<Get(1,1,n,x,y).first<<"\n";
        }
    }

    return 0;
}
