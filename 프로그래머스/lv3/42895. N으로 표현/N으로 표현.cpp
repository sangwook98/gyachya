#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> dp[9];

int solution(int N, int number) {
    int answer = 0;
    if(N == number)
        return 1;
    dp[1].insert(N),dp[2].insert(N*11);
    dp[3].insert(N*111),dp[4].insert(N*1111);
    dp[5].insert(N*11111),dp[6].insert(N*111111);
    dp[7].insert(N*1111111), dp[8].insert(N*11111111);
    

    for(int i = 2;i<9;i++){
        for(int j = 1;j<i;j++){
            for(int k = 1;k<i;k++){
                if(j+k != i) continue;
                
                for(int a : dp[j]){
                    for(int b : dp[k]){
                        dp[i].insert(a+b);
                        dp[i].insert(a*b);
                        dp[i].insert(a-b);
                        if(b != 0)
                            dp[i].insert(a/b);
                    }
                }
            }
        }
        if(dp[i].count(number)){
            return i;
        }
            
    }
    return -1;
}