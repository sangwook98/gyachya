#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int n;

bool compare(vector<string> v1,vector<string> v2 ){
    return v1[1]<v2[1]; 
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    n = plans.size();
    sort(plans.begin(),plans.end(),compare);
    stack<pair<string,int>> stk;
    
    int time = stoi(plans[0][1].substr(0,2))*60 + stoi(plans[0][1].substr(3,2));
    stk.push({plans[0][0],stoi(plans[0][2])});
    int index = 1;
    
    while(!stk.empty() || index < n){
        time++;
        if(!stk.empty()){
            stk.top().second--;
            if(stk.top().second == 0){
                answer.push_back(stk.top().first);
                stk.pop();
            }
        }
        
        if( index < n){
            int tim=stoi(plans[index][1].substr(0,2))*60 + stoi(plans[index][1].substr(3,2));
            if(tim == time){
                stk.push({plans[index][0],stoi(plans[index][2])});
                index++;
            }
        }
    }
        
   
    
    // plans를 시간 순으로 정렬
    // 분단위로 for문 전개
    // 하다가 만거 스택에 저장.
    
    
    return answer;
}