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
const lli N=1e3+10;
const lli INF=1e9+7; 
lli n,m;
lli val[N][N];
lli vis[N][N];
lli level[N][N];

vp movements={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool isValid(lli i,lli j){
    return i>=0 && j>=0 && i<n && j<m;
}
lli bfs(){
    lli maxi=-1,ans=0;
    f(i,n){
        g(j,n){
           maxi=max(maxi,val[i][j]); 
        }
    }
    queue<pair<lli,lli>> q;
    f(i,n){
        g(j,n){
           if(val[i][j]==maxi){
            q.push({i,j});
            vis[i][j]=1;
            level[i][j]=0;
           }
        }
    }
    while(!q.empty()){
        auto cur_v=q.front();
        lli cur_x=cur_v.first;
        lli cur_y=cur_v.second;
        q.pop();
        for(auto &movement:movements){
            lli child_x=cur_x+movement.first;
            lli child_y=cur_y+movement.second;
            if(isValid(child_x,child_y) && vis[child_x][child_y]==0){
                q.push({child_x,child_y});
                vis[child_x][child_y]=1;
                level[child_x][child_y]=level[cur_x][cur_y]+1;
                ans=max(ans,level[child_x][child_y]);
            }
        }
    }
    return ans;
}
void reset(){
    f(i,n){
        g(j,n){
            vis[i][j]=0;
            level[i][j]=INF;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        reset();
        cin>>n>>m;
        f(i,n){
            g(j,m){
                cin>>val[i][j];
            }
        }
        cout<<bfs()<<endl;

    }
    return 0;
}