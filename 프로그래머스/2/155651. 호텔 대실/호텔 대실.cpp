#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//start 10:10

//문제 풀이 생각
//시간을 string에서 int단위로 바꾸기
//방을 1000개 잡아서, 다 돌기
//1. 해당 첫 시간에 종료된거 있으면 꺼내기
//2. 빈 칸에 넣기(종료시간만)
int n;
pair<int,int> int_time[1001];
pair<int,int> rooms[1001];

int solution(vector<vector<string>> book_time) {
    n = book_time.size();
    for(int i=0;i<n;i++){
        string a = book_time[i][0], b =book_time[i][1];
        int time1 = stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
        int time2 = stoi(b.substr(0,2))*60 + stoi(b.substr(3,2));
        //룸 클리닝 10분 추가
        int_time[i] = {time1,time2+10};    
    }
    sort(int_time,int_time+n);
    int answer = 0;
    
    for(int i=0;i<n;i++){
        // printf("%d %d\n",int_time[i].first,int_time[i].second);
        int start = int_time[i].first, end = int_time[i].second;
        //룸에 있는지 체크, 퇴실시간이 현재타임보다 이르다면 퇴실시키기.
        for(int j=0;j<n;j++){
            if(rooms[j].second != 0 && rooms[j].second <= start){
                rooms[j] = {0,0};
            }
        }
        //룸에 넣기, 그리고 존재하는 사람 체크.
        int cnt = 0;
        bool tmp = true;
        for(int j=0;j<n;j++){
            if(rooms[j].second != 0){
                cnt++;
            }
            if(tmp && rooms[j].second == 0){
                cnt++,tmp=false;
                rooms[j] = {start,end};
            }
        }
        answer = max(answer,cnt);
        
    }
    
    
    
    
    

    return answer;
}