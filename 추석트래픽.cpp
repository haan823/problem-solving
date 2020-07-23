#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> stot(string str, char delim) {
    vector<string> tmp;
    int prev = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == delim) {
            tmp.push_back(str.substr(prev, i - prev));
            prev = i + 1;
        }
    }
    if (str.size() != prev) {
        tmp.push_back(str.substr(prev, str.size() - prev));
    }
    return tmp;
}

int solution(vector<string> lines) {
    int answer = 0;

    // {시작, 완료} 기록
    vector<vector<double>> time;
    for (int i = 0; i < lines.size(); i++) {
        vector<string> tmp = stot(lines[i], ' ');
        vector<string> tstr = stot(tmp[1], ':');
        double s = stod(tstr[0]) * 3600 + stod(tstr[1]) * 60 + stod(tstr[2]);
        double t = stod(stot(tmp[2], 's')[0]);

        time.push_back({ s - t + 0.001, s });
    }

    for (int i = 0; i < time.size(); i++) {
        double start = time[i][1];
        double end = start + 0.999;

        int tmp = 0;
        for (int j = i; j < time.size(); j++) {
            if ((time[j][1] > start || abs(time[j][1] - start) <= 0.001) && (time[j][0] < end || abs(time[j][0] - end) <= 0.001)) {
                tmp++;
            }
        }
        if (answer < tmp) {
            answer = tmp;
        }
    }
    return answer;
}
