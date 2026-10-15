#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,r,b;
        cin>>n>>r>>b;
        vector<char> v(n);
        f(i,n) v[i]='R';
        lli div1=n/(b+1);
        lli div2=n/(b+1);
        if(n%(b+1)!=0) div1++;
        lli c=n%(b+1)-1;
        lli l=0,h=div1-1,indx=-1;
        while(h<n-1){
            v[h]='B';
            if(c>0){
                h+=div1;
            }
            else{
                h+=div2;
            }
            c--;
        }
        f(i,n) cout<<v[i];
        cout<<endl;
    }
    return 0;
}