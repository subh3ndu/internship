#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Apple Watch Problem

struct Date {
    int day, month, year;
};

struct Time {
    int hr, mn;
};

struct DateTime {
    Date date;
    Time time;
};

struct MyCustom {
    DateTime start, end;
    int sleepDur;
};

// Custom Comparators

bool compareDate(const Date &d1, const Date &d2) {
    if(d1.year > d2.year) 
        return true;
    if(d1.year == d2.year && d1.month > d2.month) 
        return true;
    if(d1.year == d2.year && d1.month == d2.month && d1.day > d2.day) 
        return true;

    return false;
}

bool compareTime(const Time &t1, const Time &t2) {
    if(t1.hr > t2.hr) 
        return true;
    if(t1.hr == t2.hr && t1.mn > t2.mn)
        return true;

    return false;
}

bool compareDateTime(const DateTime &dt1, const DateTime &dt2) {
    if(dt1.date.year > dt2.date.year) 
        return true;
    if(dt1.date.year == dt2.date.year && dt1.date.month > dt2.date.month)  
        return true;
    if(dt1.date.year == dt2.date.year && dt1.date.month == dt2.date.month && dt1.date.day > dt2.date.day) 
        return true;
    if(dt1.date.year == dt2.date.year && dt1.date.month == dt2.date.month && dt1.date.day == dt2.date.day && dt1.time.hr > dt2.time.hr) 
        return true;
    if(dt1.date.year == dt2.date.year && dt1.date.month == dt2.date.month && dt1.date.day == dt2.date.day && dt1.time.hr == dt2.time.hr && dt1.time.mn > dt2.time.mn) 
        return true;

    return false;
}

bool myCustomCompare(const MyCustom &a, const MyCustom &b) {
    /* if(a.start.date.year < b.start.date.year) */ 
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month < b.start.date.month) */
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day < b.start.date.day) */ 
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr < b.start.time.hr) */ 
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn < b.start.time.mn) */ 
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year < b.end.date.year) */ 
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month < b.end.date.month) */  
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month == b.end.date.month && a.end.date.day < b.end.date.day) */  
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month == b.end.date.month && a.end.date.day == b.end.date.day && a.end.time.hr < b.end.time.hr) */  
    /*     return true; */
    /* if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month == b.end.date.month && a.end.date.day == b.end.date.day && a.end.time.hr == b.end.time.hr && a.end.time.mn < b.end.time.mn) */  
    /*     return true; */
    
    if(a.start.date.year < b.start.date.year) 
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month < b.start.date.month)
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day < b.start.date.day) 
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr < b.start.time.hr) 
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn < b.start.time.mn) 
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year < b.end.date.year) 
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month < b.end.date.month)  
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month == b.end.date.month && a.end.date.day < b.end.date.day)  
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month == b.end.date.month && a.end.date.day == b.end.date.day && a.end.time.hr > b.end.time.hr)  
        return true;
    if(a.start.date.year == b.start.date.year && a.start.date.month == b.start.date.month && a.start.date.day == b.start.date.day && a.start.time.hr == b.start.time.hr && a.start.time.mn == b.start.time.mn && a.end.date.year == b.end.date.year && a.end.date.month == b.end.date.month && a.end.date.day == b.end.date.day && a.end.time.hr == b.end.time.hr && a.end.time.mn > b.end.time.mn)  
        return true;
    
    return false;
}

bool customCompare(const MyCustom &a, const MyCustom &b) {
    if(a.start.date.year == b.start.date.year) {
        if(a.start.date.month == b.start.date.month) {
            if(a.start.date.day == b.start.date.day) {
                if(a.end.date.year == b.end.date.year) {
                    if(a.end.date.month == b.end.date.month) {
                        if(a.end.date.day == b.end.date.day) {
                            if(a.end.time.hr == b.end.time.hr) {
                                if(a.end.time.mn == b.end.time.mn) {
                                    return false;
                                } else return a.end.time.mn < b.end.time.mn;
                            } else 
                                return a.end.time.hr < b.end.time.hr;
                        } else 
                            return a.end.date.day < b.end.date.day;
                    } else 
                        return a.end.date.month < b.end.date.month;
                } else 
                    return a.end.date.year < b.end.date.year;
            } else 
                return a.start.date.day < b.start.date.day;
        } else 
            return a.start.date.month < b.start.date.month;
    } else 
        return a.start.date.year < b.start.date.year;
}

// Converters

long long totalDays(const Date &d) {
    map<int, int> mp;
    mp[0] = 31;
    mp[1] = 59; // 31 + 28;
    mp[2] = 90; // 59 + 31
    mp[3] = 120; // 90 + 30
    mp[4] = 151; // 120 + 31
    mp[5] = 181; // 151 + 30
    mp[6] = 212; // 181 + 31
    mp[7] = 243; // 212 + 31
    mp[8] = 273; // 243 + 30
    mp[9] = 304; // 273 + 31
    mp[10] = 334; // 304 + 30

    long long ans = 0;
    ans += (d.year * 365);
    if(d.month != 0) 
        ans += mp[d.month-1];
    ans += d.day;

    return ans;
}

int totalMins(const Time &t) {
    long long ans = 0; 
    /* ans += totalDays(dt.date) * 24 * 60; */
    ans += (t.hr * 60) + t.mn;
    return ans;
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

int stringToYear(string s) {
    int a = stoi(s);
    if(a > 75) 
        return 1900 + a;
    else 
        return 2000 + a;
}

// Formatters

Date stringToDate(string s) {
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
    t.year = stringToYear(str);
    return t;
}

Time stringToTime(string s) {
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

DateTime stringToDateTime(string date, string time) {
    DateTime dt;
    dt.date = stringToDate(date);
    dt.time = stringToTime(time);
    return dt;
}

MyCustom stringToMyCustom(string startDate, string startTime, string endDate, string endTime, string sleepDur) {
    MyCustom t;
    t.start = stringToDateTime(startDate, startTime);
    t.end = stringToDateTime(endDate, endTime);
    t.sleepDur = stoi(sleepDur);
    return t;
}

// Main Function

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<MyCustom> arr;
    for(int i = 0; i < n; i++) {
        string a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        arr.push_back(stringToMyCustom(a, b, c, d, e));
    }

    sort(arr.begin(), arr.end(), customCompare);

    vector<MyCustom> ans;
    int l = 0, r = 0, a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ans.push_back(arr[i]);
            l = totalMins(arr[i].start.time);
            r = l + arr[i].sleepDur;
            continue;
        }

        a = totalMins(arr[i].start.time);
        b = a + arr[i].sleepDur;

        if(a == l) {
            if(b <= r) {
                continue;
            } else {
                ans.pop_back();
                ans.push_back(arr[i]);
                continue;
            }
        } else {
            if(b <= r) {
                continue;
            } else {
                ans.push_back(arr[i]);
                continue;
            }
        }

    }

    for(auto x : ans) {
        cout << x.start.date.day << "-";
        cout << x.start.date.month << "-";
        cout << x.start.date.year << " ";
        cout << x.start.time.hr << ":";
        cout << x.start.time.mn << " ";

        cout << x.end.date.day << "-";
        cout << x.end.date.month << "-";
        cout << x.end.date.year << " ";
        cout << x.end.time.hr << ":";
        cout << x.end.time.mn << " ";

        cout << x.sleepDur << '\n';
    }

    return 0;
}
