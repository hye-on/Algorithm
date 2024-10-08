#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<long long,long long>> t; // i~i+1구간까지 중접된 개수, 시각
priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

long long timeToInt(string time) {
    int hs = stoi(time.substr(0,2)) * 60 * 60;
    int ms = stoi(time.substr(3,2)) * 60;
    int s  = stoi(time.substr(6,2));
    return hs + ms + s;
}

string intToTime(long long num) {
    string st = "";
    int h = num / 3600;
    num %= 3600;
    int m = num / 60;
    int s = num % 60;
    
    if (h <= 9)
        st += '0';
    st += to_string(h);
    st += ":";
    if (m <= 9)
        st += '0';
    st += to_string(m);
    st += ":";
    if (s <= 9)
        st += '0';
    st += to_string(s);
    
    return st;
}

void insertAfterInt(string s) {
    string startTime = s.substr(0,8);
    string endTime = s.substr(9,8);
    pq.push({timeToInt(startTime), 0}); //0이면 시작 시각
    pq.push({timeToInt(endTime), 1});  //1이면 끝 시각
}

string solution(string play_time, string adv_time, vector<string> logs) {
    long long playTimeInt = timeToInt(play_time);
    long long duration = timeToInt(adv_time);

    if (logs.empty() || duration >= playTimeInt) {
        return "00:00:00";
    }

    for (auto lo : logs) {
        insertAfterInt(lo);
    }
    
    vector<long long> totalTime(playTimeInt + 1, 0);
    
    while (!pq.empty()) {
        long long time = pq.top().first;
        int type = pq.top().second;
        pq.pop();
     
        if (type == 0) { // 시작 시간
            totalTime[time]++;
        } else { // 종료 시간
            totalTime[time]--;
        }
    }
    
    // 누적 합 계산
    for (int i = 1; i <= playTimeInt; i++) {
        totalTime[i] += totalTime[i-1];
    }
    
    // 구간 합 계산
    // i까지의 합 
    for (int i = 1; i <= playTimeInt; i++) {
        totalTime[i] += totalTime[i-1];
    }
    
    long long maxTime = totalTime[duration - 1];
    long long ansInt = 0;
    
    for (long long i = duration; i < playTimeInt; i++) {
        //i까지의 합 - j까지의 합 = j-i구간 합
        long long currentTime = totalTime[i] - totalTime[i - duration];
        if (currentTime > maxTime) {
            maxTime = currentTime;
            ansInt = i - duration + 1;
        }
    }

    return intToTime(ansInt);
}