#include <string>
#include <vector>

using namespace std;

int answer = 0;
int tar;

void dfs(vector<int> &nums,int index, int total){
    if(index == nums.size()){
        if(total == tar){
            answer++;
        }
        return;
    }
    dfs(nums,index+1,total + nums[index]);
    dfs(nums,index+1,total - nums[index]);
    
}

int solution(vector<int> numbers, int target) {
    tar = target;
    dfs(numbers,0,0);
    return answer;
}