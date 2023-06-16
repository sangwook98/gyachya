#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int student[100001];
int indegree[100001];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {   // 입력
        int N; cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> student[i];
            indegree[student[i]]++;
        }
        // 위상정렬 -> 사이클을 이루는 원소는 항상 indegree > 0이므로 큐에 들어갈 수 없음.
        int ans = 0;
        queue<int> Q;
        for (int i = 1; i <= N; i++)
        {
            if (indegree[i] == 0)
                Q.push(i);
        }
        while (!Q.empty())
        {
            int cur = Q.front(); Q.pop();
            if (--indegree[student[cur]] == 0)
                Q.push(student[cur]);
            ans++;
        }
        cout << ans << '\n';
        // TC 초기화
        memset(student, 0, sizeof(student));
        memset(indegree, 0, sizeof(indegree));
    }
    return 0;
}