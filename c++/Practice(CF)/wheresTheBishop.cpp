#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<char>> board(8);
        map<pair<int,int>,int> mp;
        for(int i=0;i<8;i++){
            board[i].resize(8);
            for(int j=0;j<8;j++){
                cin>>board[i][j];
            }
        }
        int r=0,c=0;
        for(int i=1;i<8;i++){
            for(int j=1;j<8;j++){
                if(board[i][j]=='#'){
                    if(board[i-1][j-1]=='#' && board[i-1][j+1]=='#' && board[i+1][j-1]=='#'
                    && board[i+1][j+1]=='#'){
                        r=i+1;
                        c=j+1;
                    }
                }
            } 
        }
        cout<<r<<" "<<c<<endl;
    }
    return 0;
}