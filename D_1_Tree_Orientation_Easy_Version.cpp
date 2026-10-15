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

void solve(){
    lli n;
    cin>>n;
    vvll graph(n,vll (n));
    f(i,n){
        string s;
        cin>>s;
        f(j,n){
            if(s[j]=='1') graph[i][j]=1;
            else graph[i][j]=0;
        }
    }
    // debug(graph);
    f(i,n){
        f(j,n){
            if(i==j && graph[i][j]==0){
                cout<<"No"<<endl;
                return;
            }
            if(i!=j && graph[i][j] && graph[j][i]){
                cout<<"No"<<endl;
                return;
            }
        }
    }

    f(i,n){
        f(j,n){
            f(k,n){
                if(i!=j && j!=k){
                    if(graph[i][j] && graph[j][k] && !graph[i][k]){
                        cout<<"No"<<endl;
                        return;
                    }
                }
            }
        }
    }

    vp edges;

    f(i,n){
        f(j,n){
            if(i!=j && graph[i][j]){
                bool req=true;
                f(k,n){
                    if(k!=i && k!=j && graph[i][k] && graph[k][j]){
                        req=false;
                        break;
                    }
                }
                if(req) edges.push_back({i+1,j+1});
            }
        }
    }

    //debug(edges);

    if(edges.size()!=n-1){
        no;
        return;
    }

    vvll g(n);
    fa(edges){
        g[it.first-1].push_back(it.second-1);
    }
    vvll undirected_g(n);
    fa(edges) {
        undirected_g[it.first - 1].push_back(it.second - 1);
        undirected_g[it.second - 1].push_back(it.first - 1);
    }

    vll visited_undirected(n, 0);
    queue<lli> q_conn;
    q_conn.push(0);
    visited_undirected[0] = 1;
    lli connected_count = 0;

    while (!q_conn.empty()) {
        lli u = q_conn.front();
        q_conn.pop();
        connected_count++;
        for (auto &v : undirected_g[u]) {
            if (!visited_undirected[v]) {
                visited_undirected[v] = 1;
                q_conn.push(v);
            }
        }
    }

    if (connected_count != n) {
        no;
        return;
    }
    f(i,n){
        vll visited(n,0);
        queue<lli> q;
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            lli node=q.front();
            q.pop();
            fa(g[node]){
                if(visited[it]) continue;
                q.push(it);
                visited[it]=1;
            }
        }
        f(j,n){
            if(visited[j]!=graph[i][j]){
                no;
                return;
            }
        }
    }

    vll reach(n,0);
    fa(edges){
        reach[it.first-1]=1;
        reach[it.second-1]=1;
    }
    f(i,n){
        if(!reach[i]){
            no;
            return;
        }
    }
    yes;
    fa(edges) cout<<it.first<<" "<<it.second<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}