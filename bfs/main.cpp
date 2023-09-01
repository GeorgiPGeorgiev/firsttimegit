#include <bits/stdc++.h>

using namespace std;
queue<pair<int,int> > q;
char table[2000][2000];
int tabletime[2000][2000];
int n,m,sx,sy,ex,ey;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>table[i][j];
            if(table[i][j]=='S'){
                sx=i;
                sy=j;
            }
            if(table[i][j]=='T'){
                ex=i;
                ey=j;
            }
        }
    }

    q.push({sx,sy});
    vector<pair<int,int> > dirs;
    dirs.push_back({1,0});
    dirs.push_back({0,1});
    dirs.push_back({-1,0});
    dirs.push_back({0,-1});

    while(q.size()){
        pair<int,int> u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=u.first+dirs[i].first;
            int y=u.second+dirs[i].second;

            if(x<0 || x>=n || y<0 || y>=m)continue;
            if(table[x][y]=='x')continue;
            if(table[x][y]=='*')continue;

            table[x][y]='*';
            tabletime[x][y]=tabletime[u.first][u.second]+1;
            q.push({x,y});
        }
    }
    cout<<tabletime[ex][ey]<<' '<<1;
    return 0;
}
