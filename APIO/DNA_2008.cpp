#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 5e4+5;

ll dp[N][5][15];
int n,k,a[N];
ll r;
string s;


ll solve(int pos,int last,int rest){
    if(rest<=0)return 0;
    if(pos==n+1)return 1;
    if(dp[pos][last][rest]!=-1)return dp[pos][last][rest];

    ll sol=0;

    int c;
    if(s[pos]=='A')c=1;
    else if(s[pos]=='C')c=2;
    else if(s[pos]=='G')c=3;
    else c=4;
    if(s[pos]!='N'){
        if(last>a[pos])sol=solve(pos+1,c,rest-1);
        else sol=solve(pos+1,c,rest);
    }
    else{
        for(int j=1;j<=4;j++){
            if(last>j){
                sol+=solve(pos+1,j,rest-1);
            }else{
                sol+=solve(pos+1,j,rest);
            }
        }
    }
    dp[pos][last][rest]=sol;

    return sol;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));

    cin>>n>>k>>r;
    cin>>s;
    s="A"+s;


    for(int i=0;i<=n;i++){
        if(s[i]!='N'){
            if(s[i]=='A')a[i]=1;
            else if(s[i]=='C')a[i]=2;
            else if(s[i]=='G')a[i]=3;
            else a[i]=4;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='N'){
            for(int j=1;j<=4;j++){
                if(a[i-1]>j){
                    ll val=solve(i+1,j,k-1);
                    if(val>=r){
                        a[i]=j;
                        break;
                    }else{//if letter is j then there is no solution
                        r-=val;
                    }
                }else{
                    ll val=solve(i+1,j,k);
                    if(val>=r){
                        a[i]=j;
                        break;
                    }else{
                        r-=val;
                    }
                }
            }
        }
        if(a[i-1]>a[i])k--;
    }

    for(int i=1;i<=n;i++){
        if(a[i]==1)cout<<'A';
        else if(a[i]==2)cout<<'C';
        else if(a[i]==3)cout<<'G';
        else cout<<'T';
    }

    return 0;
}
