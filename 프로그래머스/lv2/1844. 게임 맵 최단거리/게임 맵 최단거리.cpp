#include<vector>
#include<queue>
using namespace std;
#define INF 20001

int dis[101][101];
int n,m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int valid(int nx,int ny){
    return 0<=nx && nx <=n-1 && 0<= ny && ny <=m-1;
}

void bfs(vector<vector<int> > &maps){
    queue<pair<int,int>> q;
    q.push({0,0});
    dis[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(valid(nx,ny) && maps[nx][ny] && dis[nx][ny] > dis[x][y] +1){
                dis[nx][ny] = dis[x][y] +1 ;
                q.push({nx,ny});
                if(nx == n-1 && ny == m-1)
                    return;
            }
            
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n= maps.size(), m =maps[0].size();
    for(int i = 0;i<n;i++)
        fill_n(dis[i],m,INF);
    
    bfs(maps);
    
    answer = dis[n-1][m-1] == INF ? -1 : dis[n-1][m-1];
    
    return answer;
}