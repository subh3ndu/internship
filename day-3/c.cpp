#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Date {
    int day, month, year;
};

struct Time {
    int hr, mn;
};

struct MyCustom {
    Date startDate, endDate;
    Time startTime, endTime;
    int sleepDur;
};

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

MyCustom toMyCustom(string a, string b, string c, string d, int e) {
    MyCustom mc;
    mc.startDate = toDate(a);
    mc.startTime = toTime(b);
    mc.endDate = toDate(c);
    mc.endTime = toTime(d);
    mc.sleepDur = e;
    return mc;
}

bool comparatorDate(Date &a, Date &b) {
    if(a.year == b.year)
        if(a.month == b.month)
            if(a.day == b.day)
                return false;
            else return a.day < b.day;
        else return a.month < b.month;
    else return a.year < b.year;
}

bool comparatorTime(Time &t1, Time &t2) {
    if(t1.hr == t2.hr) {
        if(t1.mn == t2.mn) {
            return false;
        } else return t1.mn < t2.mn;
    } else return t1.hr < t2.hr;
}

bool customCompare(const MyCustom &a, const MyCustom &b) {
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

int32_t main() {
    int n;
    cin >> n;
    vector<MyCustom> arr;
    for(int i = 0; i < n; i++) {
        string a, b, c, d;
        int e;
        cin >> a >> b >> c >> d >> e;
        arr.push_back(toMyCustom(a, b, c, d, e));
    }

    sort(arr.begin(), arr.end(), customCompare);

    vector<MyCustom> ans;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ans.push_back(arr[i]);
            continue;
        }

        auto prev = ans.back();
        auto curr = arr[i];

        // duplicate removed
        if(prev.startTime.hr == curr.startTime.hr and prev.startTime.mn == curr.startTime.mn) {
            continue;
        } else 
            ans.push_back(arr[i]);

        // 
        if(prev.endTime.hr < curr.startTime.hr or prev.endTime.mn < curr.startTime.mn) { 
            ans.push_back(curr);
            continue;
        } else if(prev.endTime.hr == curr.startTime.hr or prev.endTime.mn == curr.startTime.mn) { 

        }
    }

    for(auto x : ans) {
        cout << x.startDate.year << "-";
        cout << x.startDate.month << "-";
        cout << x.startDate.day << "  ";
        cout << x.startTime.hr << ":";
        cout << x.startTime.mn << "    ";

        cout << x.endDate.year << "-";
        cout << x.endDate.month << "-";
        cout << x.endDate.day << "  ";
        cout << x.endTime.hr << ":";
        cout << x.endTime.mn << "   ";
        cout << x.sleepDur << "\n";
    }

    return 0;
}
