#include<bits/stdc++.h>
#include <utility>
using namespace std;

typedef long long ll;

// Problem: Apple Watch Problem

struct Time {
    string startTime, endTime, startDate, endDate;
    int sleepDur;
};

int strToInt(string s) {
    int ans = 0, cnt = 0;
    for(auto it = s.rbegin(); it != s.rend(); it++) {
        ans += (*it - '0') * pow(10, cnt);
        cnt++;
    }
    return ans;
}

int handleTime(string s) {
    int a = (s[0]-'0') * 10 + (s[1]-'0');
    int b = (s[3]-'0') * 10 + (s[4]-'0');
    int ans = a*60 + b;
    return ans;
}

string changeMonth(string s) {
    map<string, string> mon;
    mon["Jan"] = "01";
    mon["Feb"] = "02";
    mon["Mar"] = "03";
    mon["Apr"] = "04";
    mon["May"] = "05";
    mon["Jun"] = "06";
    mon["Jul"] = "07";
    mon["Aug"] = "08";
    mon["Sep"] = "09";
    mon["Oct"] = "10";
    mon["Nov"] = "11";
    mon["Dec"] = "12";

    string ans = "", str = "";
    int cnt = 0;
    string date, month, year;
    for(auto c : s) {
        if(c == '-') {
            cnt++;
            switch(cnt) {
                case 1 : date = str;
                         break;
                case 2 : month = str;
                         break;
            }
        } else {
            str += c;
        }
    }
    year = str;
    ans += date + '-' + mon[month] + '-' + year;
    return ans;
}

Time solve(string s) {
    Time t;
    string str = "";
    int cnt = 0;
    for(auto c : s) {
        if(c != '*') {
            str += c;
        } else {
            cnt++;
            switch(cnt) {
                case 1: 
                    t.startDate = str;
                    str = "";
                    break;
                case 2:
                    t.startTime = str;
                    str = "";
                    break;
                case 3:
                    t.endDate = str;
                    str = "";
                    break;
                case 4: 
                    t.endTime = str;
                    str = "";
                    break;
                case 5: 
                    t.sleepDur = strToInt(str);
                    str = "";
                    break;
            }
        }
    }
    return t;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int time = 0;
    set <string> st;
    for(int i = 0; i < n; i++) {
        string a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        string str = changeMonth(a) + '*' + b + '*' + changeMonth(c) + '*' + d + '*' + e + '*';
        st.insert(str);
    }

    vector<Time> data;
    for(auto x : st) {
        data.push_back(solve(x));
    }

    vector<Time> ans;
    for(int i = 0; i < n; i++) {
        string a = data[i].startTime;
        string b = data[i].endTime;
        ans.push_back(data[i]);
        for(int j = 0; j < n and i != j; j++) {
            if(data[j].startTime > a and data[j].endTime <= b) {
                continue;
            } else if(a == data[j].startTime and b < data[j].endTime){
                b = data[j].endTime;
                ans.pop_back();
                ans.push_back(data[j]);
            }
        }
    }

    for(auto x : ans) {
        cout << x.startDate << " ";
        cout << x.startTime << " ";
        cout << x.endDate << " ";
        cout << x.endTime << " ";
        cout << x.sleepDur << "\n";
    }

    return 0;
}
