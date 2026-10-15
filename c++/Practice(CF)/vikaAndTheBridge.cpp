#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll c(n);
        vll pos[k+1];
        f(i,n){
            cin>>c[i];
            pos[c[i]].push_back(i+1);
        }
        // ff(1,k+1,1){
        //     fa(pos[i]) cout<<it<<" ";
        //     cout<<endl;
        // }
        lli mini=1e9;
        ff(1,k+1,1){
            lli maxi1=-1,maxi2=-1;
            sor(pos[i]);
            lli size=pos[i].size();
            if(size==0) continue;
            maxi1=max(pos[i][0]-1,n-pos[i][size-1]);
            for(lli j=0;j<size-1;j++){
                maxi1=max(maxi1,pos[i][j+1]-pos[i][j]-1);
            }
            lli ct=0;
            if(pos[i][0]-1==maxi1) ct++;
            else maxi2=pos[i][0]-1;
            if(n-pos[i][size-1]==maxi1 && ct>=1) maxi2=maxi1;
            else if(n-pos[i][size-1]==maxi1 && ct==0) ct++;
            else{
                maxi2=max(maxi2,n-pos[i][size-1]);
            }
            for(lli j=0;j<size-1;j++){
                if(pos[i][j+1]-pos[i][j]-1!=maxi1) maxi2=max(maxi2,pos[i][j+1]-pos[i][j]-1);
                else if(pos[i][j+1]-pos[i][j]-1==maxi1 && ct>=1) maxi2=maxi1;
                else if(pos[i][j+1]-pos[i][j]-1==maxi1 && ct==0) ct++;
            }
            lli val=max(maxi1/2,maxi2);
            mini=min(mini,val);
        }
        cout<<mini<<endl;
    }
    return 0;
}