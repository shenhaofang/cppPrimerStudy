    //
    //  main.cpp
    //  primer_study
    //
    //  Created by 申皓方 on 2021/10/15.
    //

#include <cstring>
#include <iostream>
#include <vector>
#include <initializer_list>

#include "sale_data.h"
#include "fact.hpp"

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
        cout << vi[i] + vi[i+1] << endl;
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

void test360(){
    cout << "\n-------------------\n\ttest 3.6\n"
    << "-------------------" << endl;
    int ia[][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    for (const auto &row : ia){
        for (const auto item : row){
            cout << item << " ";
        }
    }
    
    cout << "\n-------------------" << endl;
    for (size_t rowNum = 0; rowNum < end(ia) - begin(ia); ++rowNum){
        for (decltype(end(ia[rowNum]) - begin(ia[rowNum])) colNum = 0; colNum < end(ia[rowNum]) - begin(ia[rowNum]); ++colNum){
            if (rowNum > 0 || colNum > 0){
                cout << " ";
            }
            cout << ia[rowNum][colNum];
        }
    }
    
    cout << "\n-------------------" << endl;
    for (int *p = *ia; p != end(*(end(ia)-1)); ++p){
        if (p != *ia){
            cout << " ";
        }else{
            cout << p << "|" << ia << "|" << *ia << endl;
        }
        cout << *p;
    }
    cout << endl;
}

vector<int> doubleOdd(vector<int> originInts){
    for (auto itr = originInts.begin(); itr < originInts.end(); ++itr){
        if (*itr % 2){
            *itr = 2**itr;
        }
    }
    return originInts;
}

void test470(){
    cout << "\n-------------------\n\ttest 4.7\n"
    << "-------------------" << endl;
    vector<int> a = {1, 3, 4, 5, 6, 7, 9}, b = doubleOdd(a);
    printIntVector(a);
    cout << "-------------------" << endl;
    printIntVector(b);
}
void test4113(){
    cout << "\n-------------------\n\ttest 4.11.3\n"
    << "-------------------" << endl;
    char c = 'c';
    int i; double d; const string *ps; char *pc = &c; void *pv;
    // pv = static_cast<void*>(ps); 是不行的，必须先const_cast去掉ps的cosnt属性
    pv = static_cast<void*>(const_cast<string*>(ps));
    i = static_cast<int>(*pc);
    cout << "i:" << i << endl;
}

void test541(){
    cout << "\n-------------------\n\ttest 5.4.1\n"
    << "-------------------" << endl;
    string currentInput, lastInput, maxRepeatInput;
    int repeatCnt = 1, maxRepeatCnt = 1;
    
    while(cin>>currentInput){
        if (currentInput == lastInput){
            ++repeatCnt;
        }else{
            if (repeatCnt > maxRepeatCnt) {
                maxRepeatCnt = repeatCnt;
                maxRepeatInput = lastInput;
            }
            repeatCnt = 1;
            lastInput = currentInput;
        }
    }
    
    if (repeatCnt == 1){
        cout<<"no word repeat!"<< endl;
        return;
    }
    
    if (repeatCnt > maxRepeatCnt){
        maxRepeatCnt = repeatCnt;
        maxRepeatInput = currentInput;
    }
    cout << "max repeat word is " << maxRepeatInput << ", repeat " << maxRepeatCnt << " times" << endl;
}

void test552(){
    cout << "\n-------------------\n\ttest 5.5.2\n"
    << "-------------------" << endl;
    
    string lastInput, currentInput;
    while (cin >> currentInput){
        if (currentInput[0] < 'A' || currentInput[0] > 'Z'){
            continue;
        }
        if (lastInput == currentInput) {
            break;
        }
        lastInput = currentInput;
        currentInput = "";
    }
    
    if (currentInput == lastInput){
        cout << "repeat word: " << currentInput << endl;
    }else{
        cout << "no repeat words"<< endl;
    }
}

void test563(){
    cout << "\n-------------------\n\ttest 5.6.3\n"
    << "-------------------" << endl;
    int a, b;
    char tryAgain;
    while (true){
        try{
            cout << "enter two int number for a and b to get val of a/b:" << endl;
            cin >> a >> b;
            if (b == 0){
                throw std::runtime_error("0 can not be divisor");
            }
            cout << "a/b = " << a/b << endl;
            return;
        }catch(std::runtime_error err){
            cout << err.what() << endl;
            cout << "try again?(y/n)" << endl;
            cin >> tryAgain;
            if (!tryAgain || tryAgain == 'n'){
                break;
            }
        }
    }
}

void test610(){
    cout << "\n-------------------\n\ttest 6.1\n"
    << "-------------------" << endl;
    try{
        int a;
        cin >> a;
        cout << "abs(" << a << ") = " << abs(a) << endl;
        cout << "fact(" << a << ") = " << fact(a) << endl;
    }catch(std::runtime_error err){
        cout << err.what() << endl;
    }
}

void exchangeValue(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void test621(){
    cout << "\n-------------------\n\ttest 6.2.1\n"
    << "-------------------" << endl;
    int a = 10, b = 100;
    cout << "exchange the value of a("<<a<<"), b("<<b<<")" << endl;
    exchangeValue(&a, &b);
    cout << "a: " << a << ", b: " << b << endl;
}

bool hasUpperChar(const string& s){
    for (auto itr = s.cbegin(); itr != s.cend(); ++itr){
        if (*itr >= 'A' && *itr <= 'Z'){
            return true;
        }
    }
    return false;
}

void toLower(string& s){
    for (auto itr = s.begin(); itr != s.end(); ++itr){
        if (*itr >= 'A' && *itr <= 'Z'){
            *itr = tolower(*itr);
        }
    }
}

void test623(){
    cout << "\n-------------------\n\ttest 6.2.3\n"
    << "-------------------" << endl;
    string a = "Shen Haofang is a good boy!";
    if (hasUpperChar(a)){
        cout << "string a is \"" << a << "\", has upper char" << endl;
        toLower(a);
        cout << "after toLower(), it change to \"" << a << "\"" << endl;
    }
    if (!hasUpperChar("shenhaofang")){
        cout << "string \"shenhaofang\" has no upper char" << endl;
    }
}

void swapIntPointer(int * &a, int * &b){
    int * c = a;
    a = b;
    b = c;
}

void test624(){
    cout << "\n-------------------\n\ttest 6.2.4\n"
    << "-------------------" << endl;
    int a = 1;
    int b = 2;
    int *ai = &a;
    int *bi = &b;
    cout << "before swap: ai("<< ai << "):" << *ai << ", bi("<< bi << "):" << *bi << endl;
    swapIntPointer(ai, bi);
    cout << "after swap: ai("<< ai << "):" << *ai << ", bi("<< bi << "):" << *bi << endl;
}

int sumInt(std::initializer_list<int> initList){
    int res = 0;
    for (const int * it = initList.begin(); it != initList.end(); ++it){
        res += *it;
    }
    return res;
}

void test626(){
    cout << "\n-------------------\n\ttest 6.2.6\n"
    << "-------------------" << endl;
    cout << "sum of 1,2,3,5,6,8,10 is " << sumInt({1,2,3,5,6,8,10}) << endl;
}

int main(int argc, char * args[]) {
    string argStr;
    for (int i = 1; i < argc; ++i){
        if (i > 1){
            argStr.push_back(',');
            argStr.push_back(' ');
        }
        for (char * c = args[i]; *c != '\0'; ++c){
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
    int * const cai = &i;
    // int * const cai = &ci; ❌cai没有底层const，&ci有底层const，不能用来初始化cai
    const int * cbi = &r;
    const int * const cci = cai; // cai只有顶层const没有底层const，但是cci有底层const，无论cai有没有底层const都可以用来初始化cci
    
    *cai = 2;
    // *cbi = 2 ❌，cbi指向const常量（底层const）不能改其指向变量的值
    // cai = cbi ❌，cai本身是const（顶层const）常量不能改
    cbi = cai;
    // cci = cai; ❌，cci有顶层const，不能改
    // cci = cbi; ❌，cci有顶层const，不能改
    // *cci = *cai; ❌，cci也有底层const，不能改
    
    cout << *cai << "(" << cai << "), " << *cbi << "(" << cbi << "), " << *cci << "(" << cci << ")" << endl;
    
    cout << "-------------------" << endl;
    
    int x1[10];
    int *p = x1;
    cout << sizeof(p) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
    cout << sizeof(x1)/sizeof(*p) << endl;
    
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
    return 0;
}
