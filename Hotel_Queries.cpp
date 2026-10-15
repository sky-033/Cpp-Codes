#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void build(lli node,lli st,lli en,vll &diff,vll &seg ){
    if(st==en){
        seg[node]=diff[st];
        return;
    }
    lli mid=(st+en)/2;
    build(2*node+1,st,mid,diff,seg);
    build(2*node+2,mid+1,en,diff,seg);
    seg[node]=max(seg[2*node+1],seg[2*node+2]);
}
 
lli query(lli node,lli st,lli en,lli l,lli r,vll &seg){
    if(r<st || en<l) return 0;
    if(l<=st && r>=en) return seg[node];
    lli mid=(en+st)/2;
    lli left=query(2*node+1,st,mid,l,r,seg);
    lli right=query(2*node+2,mid+1,en,l,r,seg);
    return  max(left,right);
}


void update(lli node,lli st,lli en,lli idx,lli val,vll &seg) {
    if(st== en) seg[node]-=val;
    else{
        lli mid=(st+en)/2;
        if(idx<=mid) update(2*node+1,st,mid,idx,val,seg);
        else update(2*node+2,mid+1,en,idx,val,seg);
        seg[node]=max(seg[2*node+1],seg[2*node+2]);
    }
}

lli find_first(lli node,lli st,lli en,lli val,vll &seg){
    if(seg[node]<val) return -1;
    if(st==en) return st;

    lli mid=(st+en)/2;
    if (seg[2*node+1]>=val)
        return find_first(2*node+1,st,mid,val,seg);
    else
        return find_first(2*node+2,mid+1,en,val,seg);
}

void solve(){
    lli n,m;
    cin>>n>>m;
    vll h(n);
    f(i,n) cin>>h[i];
    vll seg(4*n);
    build(0,0,n-1,h,seg);
    f(i,m){
        lli r;
        cin>>r;
        lli indx=find_first(0,0,n-1,r,seg);
        if(indx==-1) cout<<0<<" ";
        else{
            update(0,0,n-1,indx,r,seg);
            cout<<indx+1<<" ";
        }
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}