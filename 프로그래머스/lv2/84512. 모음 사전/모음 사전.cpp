#include <string>
#include <vector>

using namespace std;
string target = "";
string aeiou ="AEIOU";
int cnt = -1;
int answer;

void dfs(string word){
    cnt++;
    if(word == target){
        answer = cnt;
        return;
    }
        
    
    if(word.size() == 5)
        return;
    
    for(int i = 0;i<5;i++){
        dfs(word+aeiou[i]);
    }
}


int solution(string word) {
    target = word;
    dfs("");
    return answer;
}