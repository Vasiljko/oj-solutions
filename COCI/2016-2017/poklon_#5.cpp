#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 5e5+5;
const int SZ = 710;

struct Query{
    int l,r,ind;
    Query(int _l=0,int _r=0,int _ind=0){
        l=_l;r=_r;ind=_ind;
    }

    bool operator < (const Query &p)const {
        if(l/SZ!=p.l/SZ)return l/SZ<p.l/SZ;
        return r<p.r;
    }
};

int n,q,a[N],cnt[N],sol,ans[N];
Query b[N];
vector<int>c;

void Add(int ind){
    if(cnt[a[ind]]==1)sol++;
    else if(cnt[a[ind]]==2)sol--;
    cnt[a[ind]]++;
}

void Del(int ind){
    if(cnt[a[ind]]==3)sol++;
    else if(cnt[a[ind]]==2)sol--;
    cnt[a[ind]]--;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c.push_back(a[i]);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());

    for(int i=1;i<=n;i++){
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin()+1;
    }

    for(int i=1;i<=q;i++){
        cin>>b[i].l>>b[i].r;
        b[i].ind=i;
    }
    sort(b+1,b+1+q);
    int l=0,r=0;
    for(int i=1;i<=q;i++){
        while(l<b[i].l)Del(l++);
        while(l>b[i].l)Add(--l);
        while(r<b[i].r)Add(++r);
        while(r>b[i].r)Del(r--);

        ans[b[i].ind]=sol;
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
    return 0;
}
