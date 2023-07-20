#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[8];
int answer;
int n;
vector<vector<int>> dungeons;

void dfs(int life,int ans){
 
    answer = max(answer,ans);

    for(int i = 0;i<n;i++){
        if(!visited[i]){
            if(dungeons[i][0] > life)
                continue;
            visited[i] = true;
            dfs(life-dungeons[i][1],ans+1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons_) {
    dungeons = dungeons_;
    n = dungeons.size();
    dfs(k,0);
    return answer;
}