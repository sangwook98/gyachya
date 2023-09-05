#include <string>
#include <vector>

using namespace std;
int n, target,answer;
vector<int> numbers;

void dfs(int index, int total){
    if(index == n){
        if(total == target)
            answer++;
        return;
    }
    
    dfs(index+1, total + numbers[index]);
    dfs(index+1, total - numbers[index]);
}

int solution(vector<int> numbers_, int target_) {
    target = target_;
    numbers = numbers_;
    n = numbers.size();
    dfs(0,0);
    return answer;
}