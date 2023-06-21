#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    int sum[100001]={};

    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        sum[i]=sum[i-1]+tmp;
    }

    for(int i=0;i<m;i++){
        int start, end;
        cin >> start >> end;
        cout << sum[end]-sum[start-1] << "\n";
    }
}