#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(auto i: scoville)
        pq.push(i);
    
    while(pq.size() > 1){
        int a = pq.top();
        if( a >= K)
            return answer;
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b*2);
        
        answer++;
    }
    if(pq.size() == 1 && pq.top() < K)
        answer = -1;
    
    return answer;
}