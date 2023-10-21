#include <string>
#include <vector>
#include <math.h>

using namespace std;

//start 10:11

int human[1002];
float arr[3] = {2.0/1,3.0/2,4.0/3};

long long solution(vector<int> weights) {
    long long answer = 0;
    
    for(int i=0;i<weights.size();i++){
        human[weights[i]]++;
    }

    
    for(int i=100;i<=1000;i++){
        if(human[i] ==0)
            continue;
        
        answer += ((long long)human[i] *(human[i]-1))/2;
        // printf("now answer %d %lld\n",i,answer);
        for(int j=0;j<3;j++){
            if(i*arr[j] == floor(i*arr[j]) && floor(i*arr[j]) <=1000){
                // printf("%d %d\n",i,int(i*arr[j]));
                answer += (long long)human[i] * human[(int)(i*arr[j])];
            }
        }
    
    
    }
    
    
    
    
    return answer;
}