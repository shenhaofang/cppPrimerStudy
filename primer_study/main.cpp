    //
    //  main.cpp
    //  primer_study
    //
    //  Created by 申皓方 on 2021/10/15.
    //

#include <cstring>
#include <initializer_list>
#include <iostream>
#include <vector>

#include "fact.hpp"
#include "sale_data.h"
#include "sale_data_map.h"
#include "Person.hpp"
#include "screen.hpp"
#include "window_mgr.hpp"

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

void test253() {
    cout << "\n-------------------\n\ttest 2.5.3\n"
    << "-------------------" << endl;
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
        // a: 4; b: 4; c: 4; d: 4;
    cout << "a:" << a << ", b:" << b << ", c:" << c << ", d:" << d << endl;
    
    auto x = a;
    decltype(a) y = a;
    ++x;
    ++y;
        // x: 5; y: 5; a: 4
    cout << "x:" << x << ", y:" << y << ", a:" << a << endl;
    
    auto m = d;
    decltype(d) n = d;
    ++m;
    ++n;
        // m: 5; n: 5; a: 5; d: 5
    cout << "m:" << m << ", n:" << n << ", a:" << a << ", d:" << d << endl;
}

void test322() {
    cout << "\n-------------------\n\ttest 3.2.2\n"
    << "-------------------" << endl;
    string line, line1;
        //    while (getline(cin, line)) {
        //        cout << line << endl;
        //    }
        //    while (cin >> line) {
        //        cout << line << endl;
        //    }
    cin >> line >> line1;
    if (line > line1) {
        cout << "bigger: " << line << endl;
    } else {
        cout << "bigger: " << line1 << endl;
    }
        //    if (strlen("line") > strlen("line1")) {
    if (line.size() > line1.size()) {
        cout << "longger: " << line << endl;
    } else {
        cout << "longger: " << line1 << endl;
    }
    string res;
    while (cin >> line) {
        res += " " + line;
    }
    cout << "res: " << res << endl;
}

string test3_6(string str) {
        //    for (auto &c :str ) {
        //    for (decltype(str.size()) i = 0; i < str.size(); ++i) {
        //    for (char &c :str ) {
    string::size_type i = 0;
    while (i < str.size()) {
            //        c = 'X';
        str[i] = 'X';
        ++i;
    }
    
    return str;
}

string test3_10(string str) {
    string res;
    for (auto &c : str) {
        if (!ispunct(c)) {
            res += c;
        }
    }
    return res;
}

void test323() {
    cout << "\n-------------------\n\ttest 3.2.3\n"
    << "-------------------" << endl;
    string tStr = "hello, world!";
    cout << test3_6(tStr) << endl;
    cout << test3_10(tStr) << endl;
}

void test2() {
    vector<char> vi;
    for (char c : "hello world!") {
        vi.push_back(c);
    }
        //    for(char c : vi){
        //        vi.push_back(c);
        //        cout << c;
        //    }
        //    cout << endl;
    vector<char> vj = {'a', 'i'};
    if (vj > vi) {
        cout << "vj > vi" << endl;
    } else if (vj < vi) {
        cout << "vi < vj" << endl;
    }
    
    for (char c : vi) {
        cout << c;
    }
    cout << endl;
}

void test332() {
    cout << "\n-------------------\n\ttest 3.3.2\n"
    << "-------------------" << endl;
        //    int ipt;
        //    vector<int> vi;
        //    while (cin >> ipt) {
        //        vi.push_back(ipt);
        //    }
        //    for (auto item : vi) {
        //        cout << item;
        //    }
        //    cout << endl;
    
    string sipt;
    vector<string> vs;
    while (cin >> sipt) {
        vs.push_back(sipt);
    }
    for (auto item : vs) {
        cout << item;
    }
    cout << endl;
}

void test3_1_7() {
    vector<string> vs;
    for (string sipt; cin >> sipt;) {
        vs.push_back(sipt);
    }
    for (auto &item : vs) {
        for (char &c : item) {
            c = toupper(c);
        }
    }
    for (auto item : vs) {
        cout << item << endl;
    }
}

void test3_2_0() {
    vector<int> vi;
    int ipt;
    while (cin >> ipt) {
        vi.push_back(ipt);
    }
    cout << "\n-------" << endl;
    for (decltype(vi.size()) i = 0; i < vi.size() - 1; ++i) {
        cout << vi[i] + vi[i + 1] << endl;
    }
    cout << "-------" << endl;
    for (decltype(vi.size()) i = 0; i <= vi.size() / 2; ++i) {
        if ((i + 1) * 2 - vi.size() == 2) {
            break;
        } else if ((i + 1) * 2 - vi.size() == 1) {
            cout << vi[i] << endl;
        } else {
            cout << vi[i] + vi[vi.size() - 1 - i] << endl;
        }
    }
}

void test333() {
    cout << "\n-------------------\n\ttest 3.3.3\n"
    << "-------------------" << endl;
        //    test3_1_7();
    test3_2_0();
}

string firstSectionUpper(vector<string> text) {
    string res;
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        for (auto cit = it->begin(); cit != it->end(); ++cit) {
            res.push_back(toupper(*cit));
        }
    }
    return res;
}

void test3_2_2() {
    vector<string> text = {"i love u.", " ", "you are my life", "",
        "can you see me?"};
    cout << firstSectionUpper(text) << endl;
}

void test3_2_3() {
    vector<int> ivct = {2, 3, 6, 1, 5, 3, 4, 9, 10, 8};
    
    for (auto it = ivct.begin(); it != ivct.end(); ++it) {
        *it = (*it) * 2;
    }
    
    for (auto it = ivct.cbegin(); it != ivct.cend(); ++it) {
        if (it != ivct.cbegin()) {
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;
}

void test341() {
    cout << "\n-------------------\n\ttest 3.4.1\n"
    << "-------------------" << endl;
    test3_2_2();
    test3_2_3();
}

void test3_2_4() {
    vector<int> iptv;
    int ipt;
    while (cin >> ipt) {
        iptv.push_back(ipt);
    }
    cout << endl;
    for (auto it = iptv.cbegin(); it != iptv.cend() - 1;) {
        cout << *it + (*++it) << endl;
    }
    cout << "---------" << endl;
    
    for (auto itb = iptv.cbegin(), ite = iptv.cend() - 1; itb <= ite;) {
        if (itb == ite) {
            cout << *(itb++) << endl;
        } else {
            cout << *(itb++) + *(ite--) << endl;
        }
    }
}

void printIntArr(int *a, size_t length) {
    cout << "{" << endl;
    for (auto idx = 0; idx < length; ++idx) {
        if (idx > 0) {
            cout << ", " << endl;
        }
        cout << "\t" << idx << ": " << a[idx];
    }
    cout << endl << "}" << endl;
}

void printIntVector(vector<int> v) {
    cout << "{" << endl;
    for (vector<int>::const_iterator itr = v.cbegin(); itr != v.cend(); ++itr) {
        if (itr != v.cbegin()) {
            cout << ", " << endl;
        }
        cout << "\t" << itr - v.cbegin() << ": " << *itr;
    }
    cout << endl << "}" << endl;
}

void test352() {
    cout << "\n-------------------\n\ttest 3.5.2\n"
    << "-------------------" << endl;
    int a[10]{};
    size_t c = 0;
    for (int &i : a) {
        i += c;
        ++c;
    }
    printIntArr(a, 10);
    
    cout << "-------------------" << endl;
    int b[10] = {};
    size_t idx = 0;
    for (auto item : a) {
        b[idx] = item;
        ++idx;
    }
    printIntArr(b, 10);
    
    cout << "-------------------" << endl;
    vector<int> v;
    for (size_t idx = 0; idx < 10; ++idx) {
        v.push_back(a[idx]);
    }
    printIntVector(v);
}

void test342() {
    cout << "\n-------------------\n\ttest 3.4.2\n"
    << "-------------------" << endl;
    test3_2_4();
}

bool compareIntArr(int *a, int *b, size_t alen, size_t blen) {
    if (alen != blen) {
        return false;
    }
    for (auto i = 0; i < alen; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool compareIntVector(vector<int> v1, vector<int> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
        //    for(auto idx = 0; idx < v2.size(); ++idx){
        //        if (v1[idx] != v2[idx]){
        //            return false;
        //        }
        //    }
    for (auto itr1 = v1.cbegin(), itr2 = v2.cbegin();
         itr1 != v1.cend() && itr2 != v2.cend(); ++itr1, ++itr2) {
        if (*itr1 != *itr2) {
            return false;
        }
    }
    return true;
}

void test3_35() {
    int a[] = {1, 2, 4, 5, 6, 7, 8};
    printIntArr(a, end(a) - begin(a));
    
    cout << "-------------------" << endl;
    for (int *ptr = a; ptr < end(a); ++ptr) {
        *ptr = 0;
    }
    printIntArr(a, end(a) - begin(a));
    
    cout << "-------------------" << endl;
    int b[] = {1, 2, 4, 5, 6, 7, 8};
    int c[] = {1, 2, 4, 5, 6, 7, 8};
    int d[] = {1, 2, 4, 5, 9, 7, 8};
    cout << "b == c : "
    << compareIntArr(b, c, end(b) - begin(b), end(c) - begin(c)) << endl;
    cout << "b == d : "
    << compareIntArr(b, d, end(b) - begin(b), end(d) - begin(d)) << endl;
    
    cout << "-------------------" << endl;
    vector<int> va, vb, vc;
    for (int *ib = b, *ic = c, *id = d; ib < end(b); ++ib, ++ic, ++id) {
        va.push_back(*ib);
        vb.push_back(*ic);
        vc.push_back(*id);
    }
    cout << "va == vb : " << compareIntVector(va, vb) << endl;
    cout << "va == vc : " << compareIntVector(va, vc) << endl;
}

void test353() {
    cout << "\n-------------------\n\ttest 3.5.3\n"
    << "-------------------" << endl;
    test3_35();
}

void test354() {
    cout << "\n-------------------\n\ttest 3.5.4\n"
    << "-------------------" << endl;
    string s1 = "hello world", s2 = "hello world", s3 = "hello work";
    cout << "s1 == s2 : " << (s1 == s2) << endl;
    cout << "s1 == s3 : " << (s1 == s3) << endl;
    
    cout << "-------------------" << endl;
    char c1[] = "hello world", c2[] = "hello world", c3[] = "hello work";
    cout << "c1 == c2 : " << (std::strcmp(c1, c2) == 0) << endl;
    cout << "c1 == c3 : " << (std::strcmp(c1, c3) == 0) << endl;
    
    cout << "-------------------" << endl;
    char cCombine[std::cend(c1) - std::cbegin(c1) + std::cend(c3) -
                  std::cbegin(c3) + 1];
    strcpy(cCombine, c1);
    strcat(cCombine, " ");
    strcat(cCombine, c3);
    cout << "c1 + c3 = \"" << cCombine << "\"" << endl;
}

void test355() {
    cout << "\n-------------------\n\ttest 3.5.5\n"
    << "-------------------" << endl;
    int a[10] = {5, 2, 0, 1, 0, 8, 2, 3, 1, 0};
    vector<int> va(begin(a), end(a));
    printIntVector(va);
    
    cout << "-------------------" << endl;
    int b[va.size()];
    int *i = b;
    for (int item : va) {
            // error: cannot increament value of int b[va.size()]
            //        *b = item;
            //        ++b;
        *i = item;
        ++i;
    }
        //    error: No matching function for call end/begin
        //    printIntArr(b, end(b) - begin(b));
    printIntArr(b, va.size());
}

void test360() {
    cout << "\n-------------------\n\ttest 3.6\n"
    << "-------------------" << endl;
    int ia[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    for (const auto &row : ia) {
        for (const auto item : row) {
            cout << item << " ";
        }
    }
    
    cout << "\n-------------------" << endl;
    for (size_t rowNum = 0; rowNum < end(ia) - begin(ia); ++rowNum) {
        for (decltype(end(ia[rowNum]) - begin(ia[rowNum])) colNum = 0;
             colNum < end(ia[rowNum]) - begin(ia[rowNum]); ++colNum) {
            if (rowNum > 0 || colNum > 0) {
                cout << " ";
            }
            cout << ia[rowNum][colNum];
        }
    }
    
    cout << "\n-------------------" << endl;
    for (int *p = *ia; p != end(*(end(ia) - 1)); ++p) {
        if (p != *ia) {
            cout << " ";
        } else {
            cout << p << "|" << ia << "|" << *ia << endl;
        }
        cout << *p;
    }
    cout << endl;
}

vector<int> doubleOdd(vector<int> originInts) {
    for (auto itr = originInts.begin(); itr < originInts.end(); ++itr) {
        if (*itr % 2) {
            *itr = 2 * *itr;
        }
    }
    return originInts;
}

void test470() {
    cout << "\n-------------------\n\ttest 4.7\n"
    << "-------------------" << endl;
    vector<int> a = {1, 3, 4, 5, 6, 7, 9}, b = doubleOdd(a);
    printIntVector(a);
    cout << "-------------------" << endl;
    printIntVector(b);
}
void test4113() {
    cout << "\n-------------------\n\ttest 4.11.3\n"
    << "-------------------" << endl;
    char c = 'c';
    int i;
    double d;
    const string *ps;
    char *pc = &c;
    void *pv;
        // pv = static_cast<void*>(ps); 是不行的，必须先const_cast去掉ps的cosnt属性
    pv = static_cast<void *>(const_cast<string *>(ps));
    i = static_cast<int>(*pc);
    cout << "i:" << i << endl;
}

void test541() {
    cout << "\n-------------------\n\ttest 5.4.1\n"
    << "-------------------" << endl;
    string currentInput, lastInput, maxRepeatInput;
    int repeatCnt = 1, maxRepeatCnt = 1;
    
    while (cin >> currentInput) {
        if (currentInput == lastInput) {
            ++repeatCnt;
        } else {
            if (repeatCnt > maxRepeatCnt) {
                maxRepeatCnt = repeatCnt;
                maxRepeatInput = lastInput;
            }
            repeatCnt = 1;
            lastInput = currentInput;
        }
    }
    
    if (repeatCnt == 1) {
        cout << "no word repeat!" << endl;
        return;
    }
    
    if (repeatCnt > maxRepeatCnt) {
        maxRepeatCnt = repeatCnt;
        maxRepeatInput = currentInput;
    }
    cout << "max repeat word is " << maxRepeatInput << ", repeat "
    << maxRepeatCnt << " times" << endl;
}

void test552() {
    cout << "\n-------------------\n\ttest 5.5.2\n"
    << "-------------------" << endl;
    
    string lastInput, currentInput;
    while (cin >> currentInput) {
        if (currentInput[0] < 'A' || currentInput[0] > 'Z') {
            continue;
        }
        if (lastInput == currentInput) {
            break;
        }
        lastInput = currentInput;
        currentInput = "";
    }
    
    if (currentInput == lastInput) {
        cout << "repeat word: " << currentInput << endl;
    } else {
        cout << "no repeat words" << endl;
    }
}

void test563() {
    cout << "\n-------------------\n\ttest 5.6.3\n"
    << "-------------------" << endl;
    int a, b;
    char tryAgain;
    while (true) {
        try {
            cout << "enter two int number for a and b to get val of a/b:"
            << endl;
            cin >> a >> b;
            if (b == 0) {
                throw std::runtime_error("0 can not be divisor");
            }
            cout << "a/b = " << a / b << endl;
            return;
        } catch (std::runtime_error err) {
            cout << err.what() << endl;
            cout << "try again?(y/n)" << endl;
            cin >> tryAgain;
            if (!tryAgain || tryAgain == 'n') {
                break;
            }
        }
    }
}

void test610() {
    cout << "\n-------------------\n\ttest 6.1\n"
    << "-------------------" << endl;
    try {
        int a;
        cin >> a;
        cout << "abs(" << a << ") = " << abs(a) << endl;
        cout << "fact(" << a << ") = " << fact(a) << endl;
    } catch (std::runtime_error err) {
        cout << err.what() << endl;
    }
}

void exchangeValue(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void test621() {
    cout << "\n-------------------\n\ttest 6.2.1\n"
    << "-------------------" << endl;
    int a = 10, b = 100;
    cout << "exchange the value of a(" << a << "), b(" << b << ")" << endl;
    exchangeValue(&a, &b);
    cout << "a: " << a << ", b: " << b << endl;
}

bool hasUpperChar(const string &s) {
    for (auto itr = s.cbegin(); itr != s.cend(); ++itr) {
        if (*itr >= 'A' && *itr <= 'Z') {
            return true;
        }
    }
    return false;
}

void toLower(string &s) {
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        if (*itr >= 'A' && *itr <= 'Z') {
            *itr = tolower(*itr);
        }
    }
}

void test623() {
    cout << "\n-------------------\n\ttest 6.2.3\n"
    << "-------------------" << endl;
    string a = "Shen Haofang is a good boy!";
    if (hasUpperChar(a)) {
        cout << "string a is \"" << a << "\", has upper char" << endl;
        toLower(a);
        cout << "after toLower(), it change to \"" << a << "\"" << endl;
    }
    if (!hasUpperChar("shenhaofang")) {
        cout << "string \"shenhaofang\" has no upper char" << endl;
    }
}

void swapIntPointer(int *&a, int *&b) {
    int *c = a;
    a = b;
    b = c;
}

void test624() {
    cout << "\n-------------------\n\ttest 6.2.4\n"
    << "-------------------" << endl;
    int a = 1;
    int b = 2;
    int *ai = &a;
    int *bi = &b;
    cout << "before swap: ai(" << ai << "):" << *ai << ", bi(" << bi
    << "):" << *bi << endl;
    swapIntPointer(ai, bi);
    cout << "after swap: ai(" << ai << "):" << *ai << ", bi(" << bi
    << "):" << *bi << endl;
}

int sumInt(std::initializer_list<int> initList) {
    int res = 0;
    for (const int *it = initList.begin(); it != initList.end(); ++it) {
        res += *it;
    }
    return res;
}

void test626() {
    cout << "\n-------------------\n\ttest 6.2.6\n"
    << "-------------------" << endl;
    cout << "sum of 1,2,3,5,6,8,10 is " << sumInt({1, 2, 3, 5, 6, 8, 10})
    << endl;
}

string (&fillAndReturnStrArr(string (&strsToFill)[10]))[10] {
    for (size_t idx = 0; idx < 10; ++idx) {
        strsToFill[idx] = std::to_string(idx);
    }
    return strsToFill;
}

using strArr = string[10];

strArr &fillAndReturnStrArr2(strArr &strsToFill) {
    for (size_t idx = 0; idx < 10; ++idx) {
        strsToFill[idx] = std::to_string(idx);
    }
    return strsToFill;
}

auto fillAndReturnStrArr3(string (&strsToFill)[10]) -> string (&)[10] {
    for (size_t idx = 0; idx < 10; ++idx) {
        strsToFill[idx] = std::to_string(idx);
    }
    return strsToFill;
}

string strs[10] = {};
decltype(strs) &fillAndReturnStrArr4(string (&strToFill)[10]) {
    for (size_t idx = 0; idx < 10; ++idx) {
        strToFill[idx] = std::to_string(idx);
    }
    return strToFill;
}

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrPtr(int i) { return (i % 2) ? odd : even; }

void test633() {
    cout << "\n-------------------\n\ttest 6.3.3\n"
    << "-------------------" << endl;
    string strToFill[10] = {};
        //    auto res = fillAndReturnStrArr(strToFill);
        //    auto res = fillAndReturnStrArr2(strToFill);
        //    auto res = fillAndReturnStrArr3(strToFill);
    auto res = fillAndReturnStrArr4(strToFill);
    cout << "strToFill :" << endl;
    for (size_t idx = 0; idx < 10; ++idx) {
        cout << "strToFill[" << idx << "]: " << strToFill[idx] << endl;
        cout << "res[" << idx << "]: " << res[idx] << endl;
    }
    
    auto oddR = arrPtr(1);
    auto evenR = arrPtr(2);
    for (size_t idx = 0; idx < 5; ++idx) {
        cout << "oddR[" << idx << "]: " << oddR[idx] << endl;
        cout << "evenR[" << idx << "]: " << evenR[idx] << endl;
    }
}

string make_plural(size_t ctr, const string &word,
                   const string &endding = "s") {
    return (ctr > 0) ? word + endding : word;
}

void test651() {
    cout << "\n-------------------\n\ttest 6.5.1\n"
    << "-------------------" << endl;
    cout << make_plural(2, "success", "es") << endl;
    cout << make_plural(2, "failure") << endl;
}

void printStrVectorRecursively(const vector<string> &sv,
                               vector<string>::const_iterator itr) {
#ifndef NDEBUG
    cout << sv.size() << endl;
#endif
    if (itr == sv.cend()) {
        return;
    }
    cout << *itr << endl;
    printStrVectorRecursively(sv, itr + 1);
}

void test653() {
    cout << "\n-------------------\n\ttest 6.5.3\n"
    << "-------------------" << endl;
    vector<string> testVector = {"I", "love", "U", "!"};
    printStrVectorRecursively(testVector, testVector.cbegin());
}

int reLoadFunc(int a, int b = 5) { return a + b; }

int reloadFunc(int a) { return ++a; }

int CalTwoNum(int n, int m);
int Plus(int n, int m) { return n + m; }
int Minus(int n, int m) { return n - m; }
int Multiple(int n, int m) { return n * m; }
int Divide(int n, int m) {
    if (m == 0) {
        throw std::runtime_error("num can not be divided by 0!");
    }
    return n / m;
}

void test654() {
    cout << "\n-------------------\n\ttest 6.5.4\n"
    << "-------------------" << endl;
    vector<decltype(CalTwoNum) *> calTwoNumFuncs;
    calTwoNumFuncs = {Plus, Minus, Multiple, Divide};
    int n = 2, m = 3;
    try {
        for (auto f : calTwoNumFuncs) {
            cout << f(n, m) << endl;
        }
    } catch (std::runtime_error err) {
        cout << err.what() << endl;
    }
}

bool printSaleDataMap(const std::string &key, const SalesData &item){
    cout << "key: " << key << endl;
    printSaleData(cout, item);
    return true;
}

void testFreeAndDel(SalesDataKV ** valAssigned){
    for (size_t i = 0; i < 5; ++i) {
        delete *(valAssigned+i);
        *(valAssigned+i) = nullptr;
    }
    free(valAssigned);
}

void InputTips(std::ostream &outStream){
    outStream << "please input bookNo, unitsSold, revenue one by one:" << std::endl;
}

void test711() {
    cout << "\n-------------------\n\ttest 7.1.1\n"
    << "-------------------" << endl;
    
    SalesDataKV **valArr = (SalesDataKV **)malloc(5*sizeof(SalesDataKV *));
    for (size_t i = 0; i < 5; ++i){
        SalesDataKV *val = new SalesDataKV;
        cout << (valArr+i) << ":" << val << endl;
        *(valArr+i) = val;
    }
    cout << "-------------------" << endl;
    SalesDataKV ** valAssigned = valArr;
    valArr = (SalesDataKV **)malloc(5*sizeof(SalesDataKV *));
    for (size_t i = 0; i < 5; ++i){
        *(valArr+i) = nullptr;
    }
    for (size_t i = 0; i < 5; ++i) {
        cout << (valAssigned+i) << ":" << *(valAssigned+i) << endl;
    }
//    for (size_t i = 0; i < 5; ++i) {
//        delete *(valAssigned+i);
//        *(valAssigned+i) = nullptr;
//    }
//    free(valAssigned);
    
    testFreeAndDel(valAssigned);
    
    SalesDataMap map = SalesDataMap{};
    InputTips(cout);
//    201-1-x 10 100
//    201-2-x 12 180
//    202-5-x 5 50
//    202-5-x 10 90
//    201-1-x 100 1800
    for (SalesData item = SalesData{}; ReadSalesData(cin, item) && item.Isbin() != ""; SalesDataMapStore(&map, item.Isbin(), item)){
        auto getRes = SalesDataMapGet(&map, item.Isbin());
        if (getRes.Exist) {
            item = CombineSaleData(item, getRes.Val);
        }
        InputTips(cout);
    }
    SalesDataMapStore(&map, "test1", SalesData("test1", 1, 1));
    SalesDataMapStore(&map, "test2", SalesData("test2", 1, 2));
    SalesDataMapStore(&map, "test3", SalesData{"test3", 1, 3});
    SalesDataMapDelByKey(&map, "test2");
    ForeachSalesDataMap(&map, printSaleDataMap);
    FreeSaleDataMapVal(&map);
}

bool printSalesDataKV (const std::string &key, const SalesData &item){
    cout << "key: " << key << "; ";
    printSalesData(cout, item) << endl;
    return true;
}

void test712() {
    cout << "\n-------------------\n\ttest 7.1.2 ~ 7.1.3 (7.6~7.7)\n"
    << "-------------------" << endl;
    SalesDataMap map = SalesDataMap{};
    InputTips(cout);
    for (SalesData item = SalesData{}; readSalesData(cin, item) && item.Isbin() != ""; SalesDataMapStore(&map, item.Isbin(), item)){
        auto getRes = SalesDataMapGet(&map, item.Isbin());
        if (getRes.Exist) {
            item.Combine(getRes.Val);
        }
        InputTips(cout);
    }
    ForeachSalesDataMap(&map, printSalesDataKV);
    FreeSaleDataMapVal(&map);
    
    
}

void test7_10() {
    cout << "\n-------------------\n\ttest 7.1.3 (7.10)\n"
    << "-------------------" << endl;
    
    Person p;
    cout << "input person name and addr:" << endl;
    ReadPerson(cin, p);
    PrintPerson(cout, p) << endl;
}

struct SalesDataKVPrinter {
    static SalesData AddItem;
    SalesDataKVPrinter(double price, unsigned unitsSold){
        AddItem = SalesData("", price, unitsSold);
    }
    static bool PrintKVFunc(const std::string &key, const SalesData &item) {
        cout << "key: " << key << endl;
        cout << "\tbefore add\n\t";
        printSalesData(cout, item) << endl;
        auto sumRes = SalesData(key, AddItem.GetAvgPrice(), AddItem.GetUnitsSold());
        cout << "\tafter add: ";
        printSalesData(cout, sumRes) << endl;
        sumRes.Combine(item);
        cout << "\t";
        printSalesData(cout, sumRes) << endl;
        return true;
    }
};

SalesData SalesDataKVPrinter::AddItem = SalesData();

// auto addAndGenPrintKVFunc(double price, unsigned unitsSold) -> bool (*) (const std::string &key, const SalesData &item)
bool (*addAndGenPrintKVFunc(double price, unsigned unitsSold))(const std::string &key, const SalesData &item){
    auto printer = SalesDataKVPrinter(price, unitsSold);
    return printer.PrintKVFunc;
}

void test714(){
    cout << "\n-------------------\n\ttest 7.1.4\n"
    << "-------------------" << endl;
    
    //    201-1-x 10 10
    //    201-2-x 12 15
    //    202-5-x 100 2
    //    202-5-x 90 90
    //    201-1-x 8 100
    SalesDataMap map = SalesDataMap{};
    while(true){
        cout << "please input bookNo, price, unitsSold one by one:" << std::endl;
        SalesData item = SalesData(cin);
        if (item.Isbin() == "-" || cin.eof()) {
            break;
        }
        auto getRes = SalesDataMapGet(&map, item.Isbin());
        if (getRes.Exist) {
            item.Combine(getRes.Val);
        }
        SalesDataMapStore(&map, item.Isbin(), item);
    }
    ForeachSalesDataMap(&map, addAndGenPrintKVFunc(100, 10));
    FreeSaleDataMapVal(&map);
}

void test732(){
    cout << "\n-------------------\n\ttest 7.3.2\n"
    << "-------------------" << endl;
    Screen s(5, 5, 'x');
    Screen myScreen = s;
    myScreen.Move(4, 0).Set('#').Display(cout);
    cout << "\n";
    myScreen.Display(cout);
    cout << "\n";
    // 若move、set返回的是Screen而不是Screen &，则输出的第一行中有#，第二行中没有
}

// test 7.3.3
class Y;

class X {
    Y *y;
};

class Y {
    X x;
};

void test734(){
    cout << "\n-------------------\n\ttest 7.3.4\n"
    << "-------------------" << endl;
    WindowMgr windowMgr;
    windowMgr.AddScreen(Screen(5, 5, 'x'));
    auto &s = windowMgr.GetScreen(0);
    s.Display(cout);
    cout << endl;
    windowMgr.Clear(0);
    s.Display(cout);
    cout << endl;
}

void test752(){
    cout << "\n-------------------\n\ttest 7.5.2\n"
    << "-------------------" << endl;
    cout << "-------------------SalesData();-------------------" << endl;
    SalesData s = SalesData();
    cout << "-------------------SalesData(\"test\");-------------------" << endl;
    s = SalesData("test");
    cout << "-------------------SalesData(\"test\", 10, 20);-------------------" << endl;
    s = SalesData("test", 10, 20);
//    cout << "-------------------SalesData(cin);-------------------" << endl;
//    s = SalesData(cin);
}

class NoDefault{
private:
    int i;
public:
    NoDefault(int a): i(a){}
};

class C {
private:
    NoDefault s;
public:
    C():s(NoDefault(0)){}
};

int main(int argc, char *args[]) {
    string argStr;
    for (int i = 1; i < argc; ++i) {
        if (i > 1) {
            argStr.push_back(',');
            argStr.push_back(' ');
        }
        for (char *c = args[i]; *c != '\0'; ++c) {
            argStr.push_back(*c);
        }
    }
    cout << "args: " << argStr << endl;
    
    unsigned int a0 = 10, b0 = 30;
    std::cout << a0 - b0 << std::endl;  // 很大
    std::cout << b0 - a0 << std::endl;  // 20
    
    int x = 10, y = 30;
    std::cout << y - x << std::endl;     // 20
    std::cout << x - y << std::endl;     // -20
    std::cout << x - a0 << std::endl;    // 0
    std::cout << a0 - x << std::endl;    // 0
    std::cout << "2\tM\n" << std::endl;  // a
    
    double salary = 999.999, sal2 = 9999.23;
    std::cout << salary << "\n" << sal2 << std::endl;  // a
    
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto &g = ci;
    
    a = 42;
    b = 42;
    c = 42;
        //    d = 42;
        //    e = 42;
        //    g = 42;
    int *const cai = &i;
        // int * const cai = &ci;
        // ❌cai没有底层const，&ci有底层const，不能用来初始化cai
    const int *cbi = &r;
    const int *const cci =
    cai;  // cai只有顶层const没有底层const，但是cci有底层const，无论cai有没有底层const都可以用来初始化cci
    
    *cai = 2;
        // *cbi = 2 ❌，cbi指向const常量（底层const）不能改其指向变量的值
        // cai = cbi ❌，cai本身是const（顶层const）常量不能改
    cbi = cai;
        // cci = cai; ❌，cci有顶层const，不能改
        // cci = cbi; ❌，cci有顶层const，不能改
        // *cci = *cai; ❌，cci也有底层const，不能改
    
    cout << *cai << "(" << cai << "), " << *cbi << "(" << cbi << "), " << *cci
    << "(" << cci << ")" << endl;
    
    cout << "-------------------" << endl;
    
    int x1[10];
    int *p = x1;
    cout << sizeof(p) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    cout << sizeof(x1) / sizeof(*p) << endl;
    
        //    int pi = 3;
        //    switch (1.4){ // 必须为整形
        //        case 1.2: // 必须为整形常量
        //            std::cout<<"1.2"<<std::endl;
        //        case pi: // 必须为整形常量
        //            std::cout<< "pi" << std::endl;
        //        default:
        //            std::cout<< "default" << std::endl;
        //    }
    cout << "-------------------" << endl;
    
        //    test253();
        //    test322();
        //    test323();
        //    test332();
        //            test2();
        //    test333();
    test341();
        //    test342();
    test352();
    test353();
    test354();
    test355();
    test360();
    test470();
    test4113();
        //    test541();
        //    test552();
        //    test563();
        //    test610();
    test621();
    test623();
    test624();
    test626();
    test633();
    test651();
    test653();
    cout << reloadFunc(1) << endl;
    test654();
//    test711();
//    test712();
//    test7_10();
//    test714();
    test732();
    test734();
    test752();
    return 0;
}
