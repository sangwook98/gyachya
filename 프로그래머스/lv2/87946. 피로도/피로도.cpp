#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[8];
int answer;
int n;

void dfs(vector<vector<int>> &dungeons,int life,int ans, int count){
    if(count == n){
        answer = max(answer,ans);
    }
    
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            if(dungeons[i][0] <= life)
                dfs(dungeons,life-dungeons[i][1],ans+1,count+1 );
            else
                dfs(dungeons,life,ans,count+1 );
            visited[i] = false;
        }
    }
}
int compare(vector<int> a, vector<int> b){
    if(a[1]==b[1])
        return a[0] < b[0];
    return a[1]<b[1];
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    // sort(dungeons.begin(),dungeons.end(),compare);
    dfs(dungeons,k,0, 0);
    return answer;
}