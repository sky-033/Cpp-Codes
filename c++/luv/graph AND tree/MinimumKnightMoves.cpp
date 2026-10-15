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

const lli INF=1e9+7;
lli vis[8][8];     // chess board in form of 2-D matrix
lli level[8][8];   // level of childs from source
lli getX(string s){
    return s[0]-'a';
}
lli getY(string s){
    return s[1]-'1';
}
void reset(){
    f(i,8){
        g(j,8){
            vis[i][j]=0;
            level[i][j]=INF;
        }
    }
}
bool isValid(lli x,lli y){
    return x>=0 && y>=0 && x<8 && y<8;
}
vp movements={{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
lli bfs(string source,string destination){
    lli sourceX=getX(source);
    lli sourceY=getY(source);
    lli destX=getX(destination);
    lli destY=getY(destination);
    queue<pair<lli,lli>> q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1;
    level[sourceX][sourceY]=0;
    while(!q.empty()){
        pair<lli,lli> v=q.front();       // coordinates of first element in the queue
        lli x=v.first,y=v.second;
        q.pop();
        for(auto movement:movements){              // define child's all 8 possibilities
            lli childX=x+movement.first;       
            lli childY=y+movement.second;
            if(isValid(childX,childY) && vis[childX][childY]==0){
                q.push({childX,childY});
                level[childX][childY]=level[x][y]+1;
                vis[childX][childY]=1;
            }
        }
        if(level[destX][destY]!=INF) break;   //destination's level is already marked so break the loop
    }
    return level[destX][destY];

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        reset();
        string s1,s2;
        cin>>s1>>s2;
        cout<<bfs(s1,s2)<<endl;
    }
    return 0;
}