/*
  if current sum>=b[i] then take b[i]
  if not then find if there is b[j] in set of taken deals such that b[j]>b[i] and delete b[j] and insert b[i], this way you will
  have same number of accepted deals but more money
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 250000+10;

int n;
ll a[N],b[N],sum;

struct cmp{
    bool operator()(const pair<ll,int> &lhs,const pair<ll,int> &rhs) const{
        if(lhs.first!=rhs.first)return lhs.first>rhs.first;
        return lhs.second<rhs.second;
    }
};

set<pair<ll,int>,cmp>s;
vector<int>ans;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        sum+=a[i];
        cin>>b[i];
        if(sum>=b[i]){
            sum-=b[i];
            s.insert({b[i],i});
        }else{
            if(s.empty())continue;
            auto e=*(s.begin());
            if(b[e.second]>b[i]){
                sum+=b[e.second];
                sum-=b[i];
                s.erase(s.begin());
                s.insert({b[i],i});
            }
        }
    }

    cout<<(int)s.size()<<"\n";

    for(auto e:s)ans.push_back(e.second);
    sort(ans.begin(),ans.end());

    for(auto e:ans)cout<<e<<" ";

    return 0;
}
