#include <string>
#include <vector>

using namespace std;

int answer = 0;
int n;
int tar;

void dfs(vector<int> nums,int index, int total){
    if(index == n){
        if(total == tar){
            answer++;
        }
        return;
    }
    dfs(nums,index+1,total + nums[index]);
    dfs(nums,index+1,total - nums[index]);
    
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    tar = target;
    dfs(numbers,0,0);
    return answer;
}