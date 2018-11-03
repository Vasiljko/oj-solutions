#include <bits/stdc++.h>
using namespace std;

void solve(int N);
int query(int s, int t);
void answer(int i, int a);


int a[5000];
bool vis[5000];

void solve(int n) {
    int diff=n-1;
    int ind;
    int lo=1;
    int hi=n;

    while(lo<=hi){
        int mid=(lo+hi)>>1;
        if(query(mid,n)==diff){
            lo=mid+1;
        }else{
            ind=mid-1;
            hi=mid-1;
        }
    }

    a[ind]=1;
    a[ind+1]=1+query(ind,ind+1);
    if(ind>1){
        a[ind-1]=1+query(ind-1,ind);
        vis[a[ind-1]]=true;
    }
    vis[a[ind]]=true;
    vis[a[ind+1]]=true;

    for(int i=ind+2;i<=n;i++){
        int q=query(i-1,i);

        if(vis[a[i-1]+q]){
            a[i]=a[i-1]-q;
            continue;
        }else if(vis[a[i-1]-q]){
            a[i]=a[i-1]+q;
            continue;
        }

        int p=query(i-2,i);

        int val=a[i-1]+q;
        if(max(val,max(a[i-1],a[i-2]))-min(val,min(a[i-1],a[i-2]))==p){
            a[i]=val;
        }else{
            a[i]=a[i-1]-q;
        }
        vis[a[i]]=true;
    }

    if(ind>1){
        for(int i=ind-2;i>=1;i--){
            int q=query(i,i+1);

            if(vis[a[i+1]+q]){
                a[i]=a[i+1]-q;
                continue;
            }else if(vis[a[i+1]-q]){
                a[i]=a[i+1]+q;
                continue;
            }

            int p=query(i,i+2);

            int val=a[i+1]+q;
            if(max(val,max(a[i+1],a[i+2]))-min(val,min(a[i+1],a[i+2]))==p){
                a[i]=val;
            }else{
                a[i]=a[i+1]-q;
            }
            vis[a[i]]=true;
        }
    }
    for(int i=1;i<=n;i++)answer(i,a[i]);
}
