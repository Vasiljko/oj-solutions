/*
    just consider contiguous block of elements such that there are k+1 or less distinct elements. Then, for each of these
    contigous subsequences you have to find maximum number of elements of same kind
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 1e5+5;

int a[N];
int n,k,ans;
map<int,int>cnt;

struct cmp{
    bool operator () (const int &lhs,const int &rhs){
        return lhs>rhs;
    }
};

multiset<int,cmp>s;

int main()
{
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    fin>>n>>k;
    for(int i=1;i<=n;i++)fin>>a[i];
    int j=1;
    int d=0;
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]==0){
            d++;
        }

        if(cnt[a[i]])s.erase(s.find(cnt[a[i]]));
        cnt[a[i]]++;
        s.insert(cnt[a[i]]);

        if(d<=k+1){
            ans=max(ans,*(s.begin()));
        }else{
            while(j<=i){
                s.erase(s.find(cnt[a[j]]));
                cnt[a[j]]--;
                if(cnt[a[j]])s.insert(cnt[a[j]]);
                if(cnt[a[j]]==0)d--;
                j++;
                if(d<=k+1)break;
            }
            ans=max(ans,*(s.begin()));
        }
    }

    fout<<ans;
    return 0;
}
