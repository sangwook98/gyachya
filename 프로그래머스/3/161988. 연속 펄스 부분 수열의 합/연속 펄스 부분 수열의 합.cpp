#include <string>
#include <vector>

using namespace std;

//start 09:31

// 2 -3 -6 -1 3 1 2 -4
// -2 3 6 1 -3 -1 -2 4

// 2 -1 -7 -8 -5 -4 -2 -6
// -2 1 7 8 5 4 2 6

long long dp[500002];
long long dp2[500002];

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    // 1,-1,1,-1
    long long total = 0;
    for(int i=0;i<sequence.size();i++){
        if(i%2){
            dp[i+1] = dp[i]+sequence[i];        
            dp2[i+1] = dp2[i] -sequence[i];
        }
        else{
            dp[i+1] = dp[i]-sequence[i];
            dp2[i+1] = dp2[i] +sequence[i];
        }
    }
        
    // 1,-1,1,-1
    long long maxi = -50000000000;
    for(int i=sequence.size(); i>=0;i--){
        maxi = max(maxi, dp[i]);
        answer = max(answer, maxi-dp[i]);
    }
    // -1,1,-1,1
    maxi = -50000000000;
    for(int i=sequence.size(); i>=0;i--){
        maxi = max(maxi, dp2[i]);
        answer = max(answer, maxi-dp2[i]);
    }
    
    
    
    return answer;
}