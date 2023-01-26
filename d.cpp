#include <algorithm>
#include<bits/stdc++.h>
#include <ctime>
#include <mutex>
#include <ratio>
using namespace std;

typedef long long ll;

// A. Apple Watch Problem

struct Date {
    int day, month, year;
};

struct Time {
    int hr, mn;
};

struct MyType {
    Date startDate, endDate;
    Time startTime, endTime; 
    int sleepDur;
};

bool dateGreater(const Date &a, const Date &b) {
    if(a.year == b.year) {
        if(a.month == b.month) {
            if(a.day == b.day) {
                return false;
            } else return a.day > b.day;
        } else return a.month > b.month;
    } else return a.year > b.year;
}

bool dateLesser(const Date &a, const Date &b) {
    if(a.year == b.year) {
        if(a.month == b.month) {
            if(a.day == b.day) {
                return false;
            } else return a.day < b.day;
        } else return a.month < b.month;
    } else return a.year < b.year;
}

bool dateEquals(const Date &a, const Date &b) {
    if(a.year == b.year and a.month == b.month and a.day == b.day) 
        return true;
    else  
        return false;
}

bool timeGreater(const Time &a, const Time &b) {
    if(a.hr == b.hr)  {
        if(a.mn == b.mn) {
            return false;
        } else return a.mn > b.mn;
    } else return a.hr > b.hr;
}

bool timeLesser(const Time &a, const Time &b) {
    if(a.hr == b.hr)  {
        if(a.mn == b.mn) {
            return false;
        } else return a.mn < b.mn;
    } else return a.hr < b.hr;
}

bool timeEquals(const Time &a, const Time &b) {
    if(a.hr == b.hr and a.mn == b.mn)
        return true;
    else 
        return false;
}

bool comparator(const MyType &a, const MyType &b) {
    if(a.startDate.year == b.startDate.year) {
        if(a.startDate.month == b.startDate.month) {
            if(a.startDate.day == b.startDate.day) {
                if(a.endDate.year == b.endDate.year) {
                    if(a.endDate.month == b.endDate.month) {
                        if(a.endDate.day == b.endDate.day) {
                            if(a.endTime.hr == b.endTime.hr) {
                                if(a.endTime.mn == b.endTime.mn) {
                                    if(a.startTime.hr == b.startTime.hr) {
                                        if(a.startTime.mn == b.startTime.mn) {
                                            return false;
                                        } else return a.startTime.hr < b.startTime.hr;
                                    } else return a.startTime.hr < b.startTime.hr;
                                } else return a.endTime.mn < b.endTime.mn;
                            } else return a.endTime.hr < b.endTime.hr;
                        } else return a.endDate.day < b.endDate.day;
                    } else return a.endDate.month < b.endDate.month;
                } else return a.endDate.year < b.endDate.year;
            } else return a.startDate.day < b.startDate.day;
        } else return a.startDate.month < b.startDate.month;
    } else return a.startDate.year < b.startDate.year;
}

int toMonth(string s) {
    if(s == "Jan") {
        return 0;
    } else if(s == "Feb") {
        return 1;
    } else if(s == "Mar") {
        return 2;
    } else if(s == "Apr") {
        return 3;
    } else if(s == "May") {
        return 4;
    } else if(s == "Jun") {
        return 5;
    } else if(s == "Jul") {
        return 6;
    } else if(s == "Aug") {
        return 7;
    } else if(s == "Sep") {
        return 8;
    } else if(s == "Oct") {
        return 9;
    } else if(s == "Nov") {
        return 10;
    } else if(s == "Dec") {
        return 11;
    }

    return -1;
}

int toMin(const Time &t) {
    int ans = 0;
    ans += (t.hr * 60) + t.mn;
    return ans;
}

Date toDate(string s) {
    Date t;
    string str = "";
    int cnt = 0;
    for(auto c : s) {
        if(c == '-') {
            cnt++;
            if(cnt == 1) {
                t.day = stoi(str);
                str = "";
            } else {
                t.month = toMonth(str);
                str = "";
            }
        } else {
            str += c;
        }
    }
    t.year = stoi(str);
    return t;
}

Time toTime(string s) {
    Time t;
    string str;
    for(auto c : s) {
        if(c == ':') {
            t.hr = stoi(str);
            str = "";
        } else {
            str += c;
        }
    }
    t.mn = stoi(str);
    return t;
}

MyType toMyType(string a, string b, string c, string d, int e) {
    MyType m;
    m.startDate = toDate(a);
    m.startTime = toTime(b);
    m.endDate = toDate(c);
    m.endTime = toTime(d);
    m.sleepDur = e;
    return m;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<MyType> arr;
    for(int i = 0; i < n; i++) {
        string a, b, c, d;
        int e;
        cin >> a >> b >> c >> d >> e;
        arr.push_back(toMyType(a, b, c, d, e));
    }

    // sort MyType
    sort(arr.begin(), arr.end(), comparator);

    vector<MyType> ans;
    for(int i = 0; i < (int)arr.size(); i++) {
        if(i == 0) {
            ans.push_back(arr[i]);
            continue;
        }

        auto prev = ans.back();
        auto curr = arr[i];

        // Remove Duplicates
        if(dateEquals(prev.startDate, curr.startDate)) {
            if(timeEquals(prev.startTime, curr.startTime)) {
                if(dateEquals(prev.endDate, curr.endDate)) {
                    if(timeEquals(prev.endTime, curr.endTime))
                        continue;
                } else ans.push_back(arr[i]);
            } else ans.push_back(arr[i]);
        } else ans.push_back(arr[i]);
    }

    vector<MyType> merged;
    for(int i = 0; i < (int)ans.size(); i++) {
        if(i == 0) {
            merged.push_back(ans[i]);
            continue;
        }

        auto prev = merged.back();
        auto curr = ans[i];

        if(dateEquals(prev.endDate, curr.startDate) and timeEquals(prev.endTime, curr.startTime)) {
            MyType t;
            t.startDate = prev.startDate;
            t.startTime = prev.startTime;
            t.endDate = curr.endDate;
            t.endTime = curr.endTime;
            t.sleepDur = prev.sleepDur + curr.sleepDur;
            merged.pop_back();
            merged.push_back(t);
        } else merged.push_back(ans[i]);
    }

    vector<MyType> finalAns;
    reverse(merged.begin(), merged.end());
    for(int i = 0; i < (int)merged.size(); i++) {
        if(i == 0) {
            finalAns.push_back(merged[i]);
            continue;
        }

        auto prev = finalAns.back();
        auto curr = merged[i];
        if(dateEquals(prev.startDate, curr.startDate) and dateEquals(prev.endDate, curr.endDate)) {
            if(timeGreater(curr.startTime, prev.startTime) and timeLesser(curr.endTime, prev.endTime)) {
                continue;
            }

            if(timeGreater(curr.startTime, prev.endTime) or timeLesser(curr.endTime, prev.startTime)) {
                finalAns.push_back(merged[i]);
                continue;
            }  

            if(timeLesser(curr.startTime, prev.startTime) and timeGreater(curr.endTime, prev.endTime)) {
                finalAns.pop_back();
                finalAns.push_back(merged[i]);
                continue;
            }  

            if(timeLesser(curr.startTime, prev.startTime) and timeLesser(curr.endTime, prev.endTime) and timeGreater(curr.endTime, prev.startTime)) {
                MyType t;
                t.startDate = curr.startDate;
                t.startTime = curr.startTime;
                t.endDate = prev.endDate;
                t.endTime = prev.endTime;
                /* t.sleepDur = prev.sleepDur + (toMin(prev.startTime) - toMin(curr.startTime)); */
                t.sleepDur = toMin(t.endTime) - toMin(t.startTime);
                finalAns.pop_back();
                finalAns.push_back(t);
                continue;
            }  

            if(timeGreater(curr.endTime, prev.endTime) and timeGreater(curr.startTime, prev.startTime) and timeLesser(curr.startTime, prev.endTime)) { 
                MyType t;
                t.startDate = prev.startDate;
                t.startTime = prev.startTime;
                t.endDate = curr.endDate;
                t.endTime = curr.endTime;
                /* t.sleepDur = prev.sleepDur + (toMin(curr.endTime) - toMin(prev.endTime)); */
                t.sleepDur = toMin(t.endTime) - toMin(t.startTime);
                finalAns.pop_back();
                finalAns.push_back(t);
                continue;
            }

            finalAns.push_back(merged[i]);
        } else finalAns.push_back(merged[i]);
    }

    reverse(finalAns.begin(), finalAns.end());

    long long totalSleep = 0;
    for(auto x : finalAns) {
        cout << x.startDate.day << "-";
        cout << x.startDate.month << "-";
        cout << x.startDate.year << " ";

        cout << x.startTime.hr << ":";
        cout << x.startTime.mn << " ";

        cout << x.endDate.day << "-";
        cout << x.endDate.month << "-";
        cout << x.endDate.year << " ";

        cout << x.endTime.hr << ":";
        cout << x.endTime.mn << " ";
        cout << x.sleepDur << "\n";
        totalSleep += x.sleepDur;
    }

    cout << "Total Sleep: " << totalSleep / 60 << " hrs " << totalSleep % 60 << " mns";

    return 0;
}
