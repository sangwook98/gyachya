#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] < b[1];
    
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),compare);
    
    int start= 30000;
    int end = -30000;
    int n = routes.size();
    
    for(int i =0;i<n;i++){
        start = max(start,routes[i][0]);
        end = min(end,routes[i][1]);
        if(start > end){
            answer++;
            start= routes[i][0];
            end = routes[i][1];
        }
    }
    
    return answer;
}