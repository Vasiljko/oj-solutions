#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 210;

int dp[N][N];
int n,m;
string s[N];

int Get(int y1,int x1,int y2,int x2){
    return dp[y2][x2]-dp[y2][x1-1]-dp[y1-1][x2]+dp[y1-1][x1-1];
}

int main()
{
    ifstream fin("fortmoo.in");
    ofstream fout("fortmoo.out");

    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>s[i];
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            if(s[i][j-1]=='X')dp[i][j]++;
        }
    }

    int ans=-1;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            int row=-1;

            for(int k=1;k<=n;k++){
                bool ok = (Get(k,i,k,j)==0);

                if(ok)ans=max(ans,j-i+1);
                if(ok&&row>=1)ans=max(ans,(k-row+1)*(j-i+1));
                if(ok&&row==-1)row=k;
                if(Get(k,i,k,i)==1||Get(k,j,k,j)==1)row=-1;
            }
        }
    }

    fout<<ans;
    return 0;
}
