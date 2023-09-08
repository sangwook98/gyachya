#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    // x=0 갯수알기
    // x=n 갯수알기
    
    //longest y 알기
    //lowest y 알기
    
    //그다음부터는 해당 y에서 시작
    int long_y = r2;
    int short_y = r1;
    
    for(int x=1; x<r2; x++){
        
        
        while(pow(x,2) + pow(long_y,2) > pow(r2,2)){
            long_y--;
        }
 
        while(short_y > 1 && pow(x,2) + pow(short_y-1,2) >= pow(r1,2)){
            short_y--;
        }    

        
        if(long_y >= short_y){
            answer += long_y - short_y +1;
            // printf("x long short %d %d %d\n",x,long_y,short_y);
            // printf("%d\n",answer);
        }
        
    }
    answer *=4;
    answer += 4*(r2-r1+1);
    
    return answer;
}