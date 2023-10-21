#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//start 10:17

//정렬해서 높은순으로
//근무태도 그룹별로 

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
            if(a.first+a.second != b.first+b.second) return a.first+a.second<b.first+b.second;
            if(a.first != b.first) return a.first < b.first;
            if(a.second != b.second) return a.second < b.second;
    };
};

bool compare1(vector<int> a,vector<int> b){
    if(a[0] != b[0]) return a[0]>b[0];
    if(a[1] != b[1]) return a[1]>b[1];
    
    return a[1]>b[1];
}


int solution(vector<vector<int>> scores) {
    //완호 혼자만 있다면
    if(scores.size()==1)
        return 1;
    
    pair<int,int> wanho = {scores[0][0],scores[0][1]};

    sort(scores.begin(),scores.end(),compare1);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>,compare> pq;
    
    // for(auto i:scores)
    //     printf("%d %d\n",i[0],i[1]);
    
    int a = -1,b=-1,c=-1;
    for(int i=0;i<scores.size();i++){
        if(a != scores[i][0]){
            a= scores[i][0];
            b= max(b,c);
            c = scores[i][1];
        }
        if(scores[i][1] < b){
            if(scores[i][0] == wanho.first && scores[i][1] == wanho.second)
                return -1;
        }else{
            pq.push({scores[i][0],scores[i][1]});
        }
    }
    
    
    int prev = pq.top().first + pq.top().second, level = 1, cnt = 1;
    pq.pop();
    while(!pq.empty()){
        int a = pq.top().first,b = pq.top().second;
        //printf("a,b,level,cnt %d %d %d %d\n",a,b,level,cnt);

        
        pq.pop();
        if(prev == a+b){
            cnt++;
        }else{
            prev = a+b;
            level += cnt;
            cnt = 1;
        }
        
        if(a == wanho.first && b==wanho.second)
            return level;
    }
    
 
    
    return 1;
}