#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool visited[10001];
string answer_str = "a";

void dfs(vector<vector<string>> &tickets,string path,int depth ){
    if(depth == tickets.size()){
        if(path<answer_str){
            answer_str = path;
        }
        return;
    }
    string cur = path.substr(path.size()-3,3);
    for(int i= 0;i<tickets.size();i++){
        if(cur == tickets[i][0] && !visited[i]){
            visited[i]= true;
            dfs(tickets,path+tickets[i][1],depth+1);
            visited[i]=false;
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    dfs(tickets,"ICN",0);
    for(int i = 0;i<answer_str.size();i+=3){
        answer.push_back(answer_str.substr(i,3));
    }
    
        
    return answer;
}