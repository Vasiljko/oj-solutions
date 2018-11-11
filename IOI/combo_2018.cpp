#include "combo.h"
#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int n) {
    string f="AB";
    string s,a;
    int k=press(f);

    if(k==2){
        s="A";a="BXY";
    }else if(k==1){
        if(press("A")==1) s="A",a="BXY";
        else s="B",a="AXY";
    }else{
        if(press("X")==1) s="X",a="ABY";
        else s="Y",a="ABX";
    }

    for(int i=2;i<=n-1;i++){
        string p=s+a[0]+s+a[1]+a[0]+s+a[1]+a[1]+s+a[1]+a[2];

        int t=press(p);
        if(t==s.length()+1){
            s=s+a[0];
        }else if(t==s.length()+2){
            s=s+a[1];
        }else{
            s=s+a[2];
        }
    }

    if(n==1)return s;

    if(press(s+a[0])==s.length()+1)s=s+a[0];
    else if(press(s+a[1])==s.length()+1)s=s+a[1];
    else s=s+a[2];

    return s;
}
