#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long timeToInt(string time) {
    int hs = stoi(time.substr(0, 2)) * 60 * 60;
    int ms = stoi(time.substr(3, 2)) * 60;
    int s = stoi(time.substr(6, 2));
    return hs + ms + s;
}

string intToTime(long long num) {
    string st = "";
    int h = num / 3600;
    num %= 3600;
    int m = num / 60;
    int s = num % 60;
    
    if (h < 10) st += "0";
    st += to_string(h) + ":";
    if (m < 10) st += "0";
    st += to_string(m) + ":";
    if (s < 10) st += "0";
    st += to_string(s);
    
    return st;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    long long play_duration = timeToInt(play_time);
    long long adv_duration = timeToInt(adv_time);
    
    // 시청자 타임라인 배열 생성 (초 단위)
    vector<long long> timeline(play_duration + 1, 0);
    
    // 로그에서 시작과 종료 시간에 맞게 배열 업데이트
    for (auto log : logs) {
        long long start_time = timeToInt(log.substr(0, 8));
        long long end_time = timeToInt(log.substr(9, 8));
        timeline[start_time]++;
        timeline[end_time]--;
    }
    
    // 시청 인원 누적
    for (int i = 1; i <= play_duration; i++) {
        timeline[i] += timeline[i - 1];
    }
    
    // 시청 시간 누적
    for (int i = 1; i <= play_duration; i++) {
        timeline[i] += timeline[i - 1];
    }
    
    // 광고 구간에서 최대 누적 시청 시간 찾기
    long long max_view = timeline[adv_duration - 1];
    long long max_time = 0;
    
    for (int i = adv_duration; i <= play_duration; i++) {
        long long current_view = timeline[i] - timeline[i - adv_duration];
        if (current_view > max_view) {
            max_view = current_view;
            max_time = i - adv_duration + 1;
        }
    }
    
    // 가장 시청 시간이 많은 구간의 시작 시간을 반환
    return intToTime(max_time);
}
