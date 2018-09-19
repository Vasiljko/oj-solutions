#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 105;

int n;
int a[N],b[N],aa[N],bb[N];
int x,y;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a[x]++;
        b[y]++;
        if(i==1){
            cout<<x+y<<"\n";
            continue;
        }
        int res=-1;
        int fi=1,se=100;
        for(int i=1;i<=100;i++)aa[i]=a[i],bb[i]=b[i];
        while(fi<=100&&se>=1){
            while(!aa[fi])fi++;
            while(!bb[se])se--;
            if(fi>100||se<1)break;
            res=max(res,fi+se);
            int mn=min(aa[fi],bb[se]);
            aa[fi]-=mn;
            bb[se]-=mn;
        }
        cout<<res<<"\n";
    }

    return 0;
}
