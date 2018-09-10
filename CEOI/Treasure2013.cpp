#include "treasure.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 105;

int a[N][N];

int sum(int i,int j){return a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];}

void findTreasure(int N){
    int m=N/2;

    for(int i=N;i>=1;i--){
        for(int j=N;j>=1;j--){
            if(i<=m&&j<=m){
                a[i][j]=a[N][j]+a[i][N]-a[N][N]+countTreasure(i+1,j+1,N,N);
            }else if(i<=m&&j>m){
                a[i][j]=a[N][j]-countTreasure(i+1,1,N,j);
            }else if(i>m&&j<=m){
                a[i][j]=a[i][N]-countTreasure(1,j+1,i,N);
            }else{//i>m && j>m
                a[i][j]=countTreasure(1,1,i,j);
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(sum(i,j)==1)Report(i,j);
        }
    }
}

