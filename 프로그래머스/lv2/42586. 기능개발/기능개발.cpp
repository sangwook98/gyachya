#include <string>
#include <vector>
#include <math.h>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    

    for(int i = 0;i<n;i++){
        int t = 100 - progresses[i];
        progresses[i] = ceil((float)t/speeds[i]);
    }

    int stack = 1;
    int now = progresses[0];
    for(int i = 1;i<n;i++){
        if(now >= progresses[i]){
            stack++;
        }
        else{
            answer.push_back(stack);
            stack = 1;
            now = progresses[i];
        }
    }
    answer.push_back(stack);
    
    return answer;
}