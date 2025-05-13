#include <iostream>
//#define _SELECT
//如果完成了选做内容，请将此宏_SELECT定义前的注释符号删除
#include <cstring>
#ifndef _SELECT
#include <string>
#include <sstream>
#endif
using namespace std;

class MyString {
private:
    char* data; // 字符串数据
    int Length; // 字符串长度

public:
    static const int npos = -1; // 定义表示未找到位置的常量

    // 构造函数
    MyString();
    MyString(const char* str);
    MyString(int n, char c);
    MyString(const char* str, int pos, int len);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;

    // 析构函数
    ~MyString();

    // 赋值运算符
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    MyString& operator=(const char* str);
    MyString& operator=(char c);

    // 字符串赋值函数
    MyString& assign(const MyString& other);
    MyString& assign(const MyString& other, int pos, int len);
    MyString& assign(int n, char c);
    MyString& assign(const char* str, int pos, int len);

    // 获取字符串长度
    int length() const;
    int size() const;

    // 字符串连接函数
    MyString& append(const MyString& other);
    MyString& append(const MyString& other, int pos, int len);
    MyString& append(int n, char c);
    MyString& append(const char* str, int pos, int len);

    // 比较运算符
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;

    // 获取子串函数
    MyString substr(int pos, int len) const;
    MyString substr(int pos) const;

    // 交换两个字符串对象的内容
    void swap(MyString& other);

    // 查找子串和字符
    int find(char c, int pos = 0) const;
    int find(const char* str, int pos = 0) const;
    int find(const MyString& other, int pos = 0) const;
    int find_first_of(const char* str, int pos = 0) const;
    int find_last_of(char c) const;
    int find_first_not_of(const char* str, int pos = 0) const;

    // 替换子串
    MyString& replace(size_t pos, size_t len, const char* str, size_t str_pos, size_t str_len);
    MyString& replace(size_t pos, size_t len, size_t n, char c);
    MyString& replace(size_t pos, size_t len, const char* str);

    // 删除子串
    MyString& erase(int pos, int len);
    MyString& erase(int pos);

    // 插入字符串
    MyString& insert(int pos, const char* str);
    MyString& insert(int pos, const MyString& other);
    MyString& insert(int pos, int n, char c);

    // 输出流操作符重载
    friend ostream& operator<<(ostream& os, const MyString& str);
};

// 默认构造函数：初始化空字符串
MyString::MyString() : data(nullptr), Length(0) {}

// 使用C字符串构造MyString对象
MyString::MyString(const char* str) {
    Length = strlen(str);
    data = new char[Length + 1];
    strcpy(data, str);
}

// 构造一个由n个字符c组成的MyString对象
MyString::MyString(int n, char c) {
    Length = n;
    data = new char[Length + 1];
    memset(data, c, Length);
    data[Length] = '\0';
}

// 从C字符串的指定位置开始构造MyString对象
MyString::MyString(const char* str, int pos, int len) {
    Length = len;
    data = new char[Length + 1];
    strncpy(data, str + pos, len);
    data[Length] = '\0';
}

// 拷贝构造函数：深拷贝
MyString::MyString(const MyString& other) {
    Length = other.Length;
    data = new char[Length + 1];
    strcpy(data, other.data);
}

// 移动构造函数：转移资源所有权
MyString::MyString(MyString&& other) noexcept : data(other.data), Length(other.Length) {
    other.data = nullptr;
    other.Length = 0;
}

// 析构函数：释放动态分配的内存
MyString::~MyString() {
    delete[] data;
}

// 拷贝赋值运算符：深拷贝
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        Length = other.Length;
        data = new char[Length + 1];
        strcpy(data, other.data);
    }
    return *this;
}

// 移动赋值运算符：转移资源所有权
MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        Length = other.Length;
        other.data = nullptr;
        other.Length = 0;
    }
    return *this;
}

// 使用C字符串赋值
MyString& MyString::operator=(const char* str) {
    delete[] data;
    Length = strlen(str);
    data = new char[Length + 1];
    strcpy(data, str);
    return *this;
}

// 使用单个字符赋值
MyString& MyString::operator=(char c) {
    delete[] data;
    Length = 1;
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
    return *this;
}

// 拷贝赋值
MyString& MyString::assign(const MyString& other) {
    return *this = other;
}

// 从指定位置和长度拷贝赋值
MyString& MyString::assign(const MyString& other, int pos, int len) {
    if (pos >= other.Length) {
        return *this;
    }
    int n = min(len, other.Length - pos);
    return *this = MyString(other.data + pos, 0, n);
}

// 使用指定字符和长度赋值
MyString& MyString::assign(int n, char c) {
    return *this = MyString(n, c);
}

// 从C字符串的指定位置和长度赋值
MyString& MyString::assign(const char* str, int pos, int len) {
    int n = min(len, (int)strlen(str) - pos);
    return *this = MyString(str + pos, 0, n);
}

// 获取字符串长度
int MyString::length() const {
    return Length;
}

// 获取字符串长度（与length相同）
int MyString::size() const {
    return Length;
}

// 连接另一个MyString对象
MyString& MyString::append(const MyString& other) {
    return append(other.data, 0, other.Length);
}

// 从指定位置和长度连接另一个MyString对象
MyString& MyString::append(const MyString& other, int pos, int len) {
    return append(other.data, pos, len);
}

// 连接n个字符c
MyString& MyString::append(int n, char c) {
    char* new_data = new char[Length + n + 1];
    strcpy(new_data, data);
    memset(new_data + Length, c, n);
    new_data[Length + n] = '\0';
    delete[] data;
    data = new_data;
    Length += n;
    return *this;
}

// 从C字符串的指定位置和长度连接
MyString& MyString::append(const char* str, int pos, int len) {
    int str_len = strlen(str);
    if (pos > str_len) return *this;
    int n = min(len, str_len - pos);
    char* new_data = new char[Length + n + 1];
    strcpy(new_data, data);
    strncpy(new_data + Length, str + pos, n);
    new_data[Length + n] = '\0';
    delete[] data;
    data = new_data;
    Length += n;
    return *this;
}

// 获取指定位置和长度的子串
MyString MyString::substr(int pos, int len) const {
    if (pos >= Length) return MyString();
    int n = min(len, Length - pos);
    MyString s1(data, pos, n);
    return s1;
}

// 获取从指定位置开始的子串
MyString MyString::substr(int pos) const {
    if (pos >= Length) return MyString();
    int n = Length - pos;
    MyString s1(data, pos, n);
    return s1;
}

// 交换两个MyString对象的内容
void MyString::swap(MyString& other) {
    std::swap(data, other.data);
    std::swap(Length, other.Length);
}

// 查找字符c首次出现的位置，从pos位置开始查找
int MyString::find(char c, int pos) const {
    if (pos >= Length) return npos;
    for (int i = pos; i < Length; ++i) {
        if (data[i] == c) return i;
    }
    return npos;
}

// 查找C字符串首次出现的位置，从pos位置开始查找
int MyString::find(const char* str, int pos) const {
    int str_len = strlen(str);
    if (pos >= Length || str_len == 0) return npos;
    for (int i = pos; i <= Length - str_len; ++i) {
        if (strncmp(data + i, str, str_len) == 0) return i;
    }
    return npos;
}

// 查找MyString对象首次出现的位置，从pos位置开始查找
int MyString::find(const MyString& other, int pos) const {
    return find(other.data, pos);
}

// 查找C字符串中任意字符首次出现的位置，从pos位置开始查找
int MyString::find_first_of(const char* str, int pos) const {
    if (pos >= Length) return npos;
    for (int i = pos; i < Length; ++i) {
        if (strchr(str, data[i])) return i;
    }
    return npos;
}

// 查找字符c最后一次出现的位置
int MyString::find_last_of(char c) const {
    for (int i = Length - 1; i >= 0; --i) {
        if (data[i] == c) return i;
    }
    return npos;
}

// 查找不在C字符串中的第一个字符的位置，从pos位置开始查找
int MyString::find_first_not_of(const char* str, int pos) const {
    if (pos >= Length) return npos;
    for (int i = pos; i < Length; ++i) {
        if (!strchr(str, data[i])) return i;
    }
    return npos;
}

// 替换从pos位置开始，长度为len的子串为str中从str_pos开始，长度为str_len的子串
MyString& MyString::replace(size_t pos, size_t len, const char* str, size_t str_pos, size_t str_len) {
    if (pos > Length) return *this;
    size_t end_pos = min(pos + len, (size_t)Length);
    size_t replace_len = end_pos - pos;
    size_t new_len = Length - replace_len + str_len;

    char* new_data = new char[new_len + 1];
    strncpy(new_data, data, pos);
    strncpy(new_data + pos, str + str_pos, str_len);
    strcpy(new_data + pos + str_len, data + end_pos);

    delete[] data;
    data = new_data;
    Length = new_len;
    return *this;
}

// 替换从pos位置开始，长度为len的子串为n个字符c
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c) {
    if (pos > Length) return *this;
    size_t end_pos = min(pos + len, (size_t)Length);
    size_t replace_len = end_pos - pos;
    size_t new_len = Length - replace_len + n;

    char* new_data = new char[new_len + 1];
    strncpy(new_data, data, pos);
    memset(new_data + pos, c, n);
    strcpy(new_data + pos + n, data + end_pos);

    delete[] data;
    data = new_data;
    Length = new_len;
    return *this;
}

// 替换从pos位置开始，长度为len的子串为str
MyString& MyString::replace(size_t pos, size_t len, const char* str) {
    return replace(pos, len, str, 0, strlen(str));
}

// 删除从pos位置开始，长度为len的子串
MyString& MyString::erase(int pos, int len) {
    if (pos >= Length) return *this;
    int end_pos = min(pos + len, Length);
    int erase_len = end_pos - pos;
    int new_len = Length - erase_len;

    char* new_data = new char[new_len + 1];
    strncpy(new_data, data, pos);
    strcpy(new_data + pos, data + end_pos);

    delete[] data;
    data = new_data;
    Length = new_len;
    return *this;
}

// 删除从pos位置开始的子串
MyString& MyString::erase(int pos) {
    return erase(pos, Length - pos);
}

// 在pos位置插入C字符串
MyString& MyString::insert(int pos, const char* str) {
    int str_len = strlen(str);
    if (pos > Length) return *this;

    char* new_data = new char[Length + str_len + 1];
    strncpy(new_data, data, pos);
    strcpy(new_data + pos, str);
    strcpy(new_data + pos + str_len, data + pos);

    delete[] data;
    data = new_data;
    Length += str_len;
    return *this;
}

// 在pos位置插入MyString对象
MyString& MyString::insert(int pos, const MyString& other) {
    return insert(pos, other.data);
}

// 在pos位置插入n个字符c
MyString& MyString::insert(int pos, int n, char c) {
    if (pos > Length) return *this;

    char* new_data = new char[Length + n + 1];
    strncpy(new_data, data, pos);
    memset(new_data + pos, c, n);
    strcpy(new_data + pos + n, data + pos);

    delete[] data;
    data = new_data;
    Length += n;
    return *this;
}

// 输出流操作符重载，用于打印MyString对象
ostream& operator<<(ostream& os, const MyString& str) {
    if (str.data != nullptr) {
        os << str.data;
    }
    return os;
}


//测试时请注释掉上面一行语句

int main()
{

    {  //测试1
        MyString s1;  // si = ""
        MyString s2("Hello");  // s2 = "Hello"
        MyString s3(4, 'K');  // s3 = "KKKK"
        MyString s4("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串
        cout<<s1<<s2<<s3<<s4 ;
    }
    {  //测试2
        {
            MyString s1,s2;
            s1 = "Hello";  // s1 = "Hello"
            s2 = 'K';  // s2 = "K”
            cout<<s1<<s2 ;
        }
        {
            MyString s1("12345"), s2,s3;
            s3.assign(s1);  // s3 = s1
            cout<<s3;
            s2.assign(s1, 1, 2);  // s2 = "23"，即 s1 的子串(1, 2)
            cout<<s2;
            s2.assign(4, 'K');  // s2 = "KKKK"
            cout<<s2;
            s2.assign("abcde", 2, 3);  // s2 = "cde"，即 "abcde" 的子串(2, 3)
            cout<<s2 ;
        }
    }
    {  //测试3
        MyString s1("12345"), s2;
        cout << s1.length() << s2.size() ;
    }
    {//测试4
        MyString s1("123"), s2("abc");
        s1.append(s2);  // s1 = "123abc"
        cout<<s1;
        s1.append(s2, 1, 2);  // s1 = "123abcbc"
        cout<<s1;
        s1.append(3, 'K');  // s1 = "123abcbcKKK"
        cout<<s1;
        s1.append("ABCDE", 2, 3);  // s1 = "123abcbcKKKCDE"，添加 "ABCDE" 的子串(2, 3)
        cout<<s1 ;
    }
    {   //测试5
        MyString s1("hello"), s2("hello, world");
        cout<<(s1>s2)<<(s1<s2)<<(s1>=s2)<<(s1<=s2)<<(s1==s2)<<(s1!=s2) ;
    }
    {   //测试6
        MyString s1 = "this is ok";
        MyString s2 = s1.substr(2, 4);  // s2 = "is i"
        cout<<s1<<s2;
        s2 = s1.substr(2);  // s2 = "is is ok"
        cout<<s2 ;
    }
    {   //测试7
        MyString s1("West"), s2("East");
        cout<<s1<<s2;
        s1.swap(s2);  // s1 = "East"，s2 = "West"
        cout<<s1<<s2 ;
    }
    {   //测试8
        MyString s1("Source Code");
        int n;
        if ((n = s1.find('u')) != MyString::npos) //查找 u 出现的位置
            cout << "1) " << n << "," << s1.substr(n)  ;
        //输出 l)2,urce Code
        if ((n = s1.find("Source", 3)) == MyString::npos)//从下标3开始查找"Source"，找不到
            cout << "2) " << "Not Found"  ;  //输出 2) Not Found
        if ((n = s1.find("Co")) != MyString::npos) //查找子串"Co"。能找到，返回"Co"的位置
            cout << "3) " << n << ", " << s1.substr(n)  ;
        //输出 3) 7, Code
        if ((n = s1.find_first_of("ceo")) != MyString::npos)//查找第一次出现或 'c'、'e'或'o'的位置
            cout << "4) " << n << ", " << s1.substr(n) ;
        //输出 4) l, ource Code
        if ((n = s1.find_last_of('e')) != MyString::npos)//查找最后一个 'e' 的位置
            cout << "5) " << n << ", " << s1.substr(n)  ;
        //输出 5) 10, e
        if ((n = s1.find_first_not_of("eou", 1)) != MyString::npos) //从下标1开始查找第一次出现非 'e'、'o' 或 'u' 字符的位置
            cout << "6) " << n << ", " << s1.substr(n) ;
        //输出 6) 3, rce Code
    }
    {   //测试9
        MyString s1("Real Steel");
        cout<<s1;
        s1.replace(1, 3, "123456", 2, 4);  //用 "123456" 的子串(2,4) 替换 s1 的子串(1,3)
        cout << s1 ;  //输出 R3456 Steel
        MyString s2("Harry Potter");
        cout<<s2;
        s2.replace(2, 3, 5, '0');  //用 5 个 '0' 替换子串(2,3)
        cout << s2  ;  //输出 HaOOOOO Potter
        int n = s2.find("00000");  //查找子串 "00000" 的位置，n=2
        cout<<n;   //输出2
        s2.replace(n, 5, "XXX");  //将子串(n,5)替换为"XXX"
        cout << s2  ;  //输出 HaXXX Potter
    }
    { //测试10
        MyString s1("Real Steel");
        cout<<s1;
        s1.erase(1, 3);  //删除子串(1, 3)，此后 s1 = "R Steel"
        cout<<s1;
        s1.erase(5);  //删除下标5及其后面的所有字符，此后 s1 = "R Ste"
        cout<<s1 ;
    }
    { //测试11
        MyString s1("Limitless"), s2("00");
        cout<<s1<<s2;
        s1.insert(2, "123");  //在下标 2 处插入字符串"123"，s1 = "Li123mitless"
        cout<<s1;
        s1.insert(3, s2);  //在下标 2 处插入 s2 , s1 = "Li10023mitless"
        cout<<s1;
        s1.insert(3, 5, 'X');  //在下标 3 处插入 5 个 'X'，s1 = "Li1XXXXX0023mitless"
        cout<<s1;
    }
    {   //测试12  选做部分
#ifndef _SELECT
        //没有完成选作部分则使用string类和istringstream类测试
        string src("Avatar 123 5.2 Titanic K");
        istringstream istrStream(src); //建立src到istrStream的联系
        string s1, s2;
        int n;  double d;  char c;
        istrStream >> s1 >> n >> d >> s2 >> c; //把src的内容当做输入流进行读取
        ostringstream ostrStream;
        ostrStream << s1  << s2   << n   << d   << c ;
        cout << ostrStream.str()<<endl;
#else
        //如果完成选作部分则使用MyString类和iMyStringstream类测试
        MyString src("Avatar 123 5.2 Titanic K");
        iMyStringstream istrStream(src); //建立src到istrStream的联系
        MyString s1, s2;
        int n;  double d;  char c;
        istrStream >> s1 >> n >> d >> s2 >> c; //把src的内容当做输入流进行读取
        oMyStringstream ostrStream;
        ostrStream << s1  << s2   << n   << d   << c ;
        cout << ostrStream.str()<<endl;
#endif // _SELECT
    }
    return  0;
}
