#include <iostream>
//#define _SELECT
//��������ѡ�����ݣ��뽫�˺�_SELECT����ǰ��ע�ͷ���ɾ��
#include <cstring>
#ifndef _SELECT
#include <string>
#include <sstream>
#endif
using namespace std;

class MyString {
private:
    char* data; // �ַ�������
    int Length; // �ַ�������

public:
    static const int npos = -1; // �����ʾδ�ҵ�λ�õĳ���

    // ���캯��
    MyString();
    MyString(const char* str);
    MyString(int n, char c);
    MyString(const char* str, int pos, int len);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;

    // ��������
    ~MyString();

    // ��ֵ�����
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    MyString& operator=(const char* str);
    MyString& operator=(char c);

    // �ַ�����ֵ����
    MyString& assign(const MyString& other);
    MyString& assign(const MyString& other, int pos, int len);
    MyString& assign(int n, char c);
    MyString& assign(const char* str, int pos, int len);

    // ��ȡ�ַ�������
    int length() const;
    int size() const;

    // �ַ������Ӻ���
    MyString& append(const MyString& other);
    MyString& append(const MyString& other, int pos, int len);
    MyString& append(int n, char c);
    MyString& append(const char* str, int pos, int len);

    // �Ƚ������
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;

    // ��ȡ�Ӵ�����
    MyString substr(int pos, int len) const;
    MyString substr(int pos) const;

    // ���������ַ������������
    void swap(MyString& other);

    // �����Ӵ����ַ�
    int find(char c, int pos = 0) const;
    int find(const char* str, int pos = 0) const;
    int find(const MyString& other, int pos = 0) const;
    int find_first_of(const char* str, int pos = 0) const;
    int find_last_of(char c) const;
    int find_first_not_of(const char* str, int pos = 0) const;

    // �滻�Ӵ�
    MyString& replace(size_t pos, size_t len, const char* str, size_t str_pos, size_t str_len);
    MyString& replace(size_t pos, size_t len, size_t n, char c);
    MyString& replace(size_t pos, size_t len, const char* str);

    // ɾ���Ӵ�
    MyString& erase(int pos, int len);
    MyString& erase(int pos);

    // �����ַ���
    MyString& insert(int pos, const char* str);
    MyString& insert(int pos, const MyString& other);
    MyString& insert(int pos, int n, char c);

    // ���������������
    friend ostream& operator<<(ostream& os, const MyString& str);
};

// Ĭ�Ϲ��캯������ʼ�����ַ���
MyString::MyString() : data(nullptr), Length(0) {}

// ʹ��C�ַ�������MyString����
MyString::MyString(const char* str) {
    Length = strlen(str);
    data = new char[Length + 1];
    strcpy(data, str);
}

// ����һ����n���ַ�c��ɵ�MyString����
MyString::MyString(int n, char c) {
    Length = n;
    data = new char[Length + 1];
    memset(data, c, Length);
    data[Length] = '\0';
}

// ��C�ַ�����ָ��λ�ÿ�ʼ����MyString����
MyString::MyString(const char* str, int pos, int len) {
    Length = len;
    data = new char[Length + 1];
    strncpy(data, str + pos, len);
    data[Length] = '\0';
}

// �������캯�������
MyString::MyString(const MyString& other) {
    Length = other.Length;
    data = new char[Length + 1];
    strcpy(data, other.data);
}

// �ƶ����캯����ת����Դ����Ȩ
MyString::MyString(MyString&& other) noexcept : data(other.data), Length(other.Length) {
    other.data = nullptr;
    other.Length = 0;
}

// �����������ͷŶ�̬������ڴ�
MyString::~MyString() {
    delete[] data;
}

// ������ֵ����������
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        Length = other.Length;
        data = new char[Length + 1];
        strcpy(data, other.data);
    }
    return *this;
}

// �ƶ���ֵ�������ת����Դ����Ȩ
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

// ʹ��C�ַ�����ֵ
MyString& MyString::operator=(const char* str) {
    delete[] data;
    Length = strlen(str);
    data = new char[Length + 1];
    strcpy(data, str);
    return *this;
}

// ʹ�õ����ַ���ֵ
MyString& MyString::operator=(char c) {
    delete[] data;
    Length = 1;
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
    return *this;
}

// ������ֵ
MyString& MyString::assign(const MyString& other) {
    return *this = other;
}

// ��ָ��λ�úͳ��ȿ�����ֵ
MyString& MyString::assign(const MyString& other, int pos, int len) {
    if (pos >= other.Length) {
        return *this;
    }
    int n = min(len, other.Length - pos);
    return *this = MyString(other.data + pos, 0, n);
}

// ʹ��ָ���ַ��ͳ��ȸ�ֵ
MyString& MyString::assign(int n, char c) {
    return *this = MyString(n, c);
}

// ��C�ַ�����ָ��λ�úͳ��ȸ�ֵ
MyString& MyString::assign(const char* str, int pos, int len) {
    int n = min(len, (int)strlen(str) - pos);
    return *this = MyString(str + pos, 0, n);
}

// ��ȡ�ַ�������
int MyString::length() const {
    return Length;
}

// ��ȡ�ַ������ȣ���length��ͬ��
int MyString::size() const {
    return Length;
}

// ������һ��MyString����
MyString& MyString::append(const MyString& other) {
    return append(other.data, 0, other.Length);
}

// ��ָ��λ�úͳ���������һ��MyString����
MyString& MyString::append(const MyString& other, int pos, int len) {
    return append(other.data, pos, len);
}

// ����n���ַ�c
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

// ��C�ַ�����ָ��λ�úͳ�������
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

// ��ȡָ��λ�úͳ��ȵ��Ӵ�
MyString MyString::substr(int pos, int len) const {
    if (pos >= Length) return MyString();
    int n = min(len, Length - pos);
    MyString s1(data, pos, n);
    return s1;
}

// ��ȡ��ָ��λ�ÿ�ʼ���Ӵ�
MyString MyString::substr(int pos) const {
    if (pos >= Length) return MyString();
    int n = Length - pos;
    MyString s1(data, pos, n);
    return s1;
}

// ��������MyString���������
void MyString::swap(MyString& other) {
    std::swap(data, other.data);
    std::swap(Length, other.Length);
}

// �����ַ�c�״γ��ֵ�λ�ã���posλ�ÿ�ʼ����
int MyString::find(char c, int pos) const {
    if (pos >= Length) return npos;
    for (int i = pos; i < Length; ++i) {
        if (data[i] == c) return i;
    }
    return npos;
}

// ����C�ַ����״γ��ֵ�λ�ã���posλ�ÿ�ʼ����
int MyString::find(const char* str, int pos) const {
    int str_len = strlen(str);
    if (pos >= Length || str_len == 0) return npos;
    for (int i = pos; i <= Length - str_len; ++i) {
        if (strncmp(data + i, str, str_len) == 0) return i;
    }
    return npos;
}

// ����MyString�����״γ��ֵ�λ�ã���posλ�ÿ�ʼ����
int MyString::find(const MyString& other, int pos) const {
    return find(other.data, pos);
}

// ����C�ַ����������ַ��״γ��ֵ�λ�ã���posλ�ÿ�ʼ����
int MyString::find_first_of(const char* str, int pos) const {
    if (pos >= Length) return npos;
    for (int i = pos; i < Length; ++i) {
        if (strchr(str, data[i])) return i;
    }
    return npos;
}

// �����ַ�c���һ�γ��ֵ�λ��
int MyString::find_last_of(char c) const {
    for (int i = Length - 1; i >= 0; --i) {
        if (data[i] == c) return i;
    }
    return npos;
}

// ���Ҳ���C�ַ����еĵ�һ���ַ���λ�ã���posλ�ÿ�ʼ����
int MyString::find_first_not_of(const char* str, int pos) const {
    if (pos >= Length) return npos;
    for (int i = pos; i < Length; ++i) {
        if (!strchr(str, data[i])) return i;
    }
    return npos;
}

// �滻��posλ�ÿ�ʼ������Ϊlen���Ӵ�Ϊstr�д�str_pos��ʼ������Ϊstr_len���Ӵ�
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

// �滻��posλ�ÿ�ʼ������Ϊlen���Ӵ�Ϊn���ַ�c
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

// �滻��posλ�ÿ�ʼ������Ϊlen���Ӵ�Ϊstr
MyString& MyString::replace(size_t pos, size_t len, const char* str) {
    return replace(pos, len, str, 0, strlen(str));
}

// ɾ����posλ�ÿ�ʼ������Ϊlen���Ӵ�
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

// ɾ����posλ�ÿ�ʼ���Ӵ�
MyString& MyString::erase(int pos) {
    return erase(pos, Length - pos);
}

// ��posλ�ò���C�ַ���
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

// ��posλ�ò���MyString����
MyString& MyString::insert(int pos, const MyString& other) {
    return insert(pos, other.data);
}

// ��posλ�ò���n���ַ�c
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

// ��������������أ����ڴ�ӡMyString����
ostream& operator<<(ostream& os, const MyString& str) {
    if (str.data != nullptr) {
        os << str.data;
    }
    return os;
}


//����ʱ��ע�͵�����һ�����

int main()
{

    {  //����1
        MyString s1;  // si = ""
        MyString s2("Hello");  // s2 = "Hello"
        MyString s3(4, 'K');  // s3 = "KKKK"
        MyString s4("12345", 1, 3);  //s4 = "234"���� "12345" �Ĵ��±� 1 ��ʼ������Ϊ 3 ���Ӵ�
        cout<<s1<<s2<<s3<<s4 ;
    }
    {  //����2
        {
            MyString s1,s2;
            s1 = "Hello";  // s1 = "Hello"
            s2 = 'K';  // s2 = "K��
            cout<<s1<<s2 ;
        }
        {
            MyString s1("12345"), s2,s3;
            s3.assign(s1);  // s3 = s1
            cout<<s3;
            s2.assign(s1, 1, 2);  // s2 = "23"���� s1 ���Ӵ�(1, 2)
            cout<<s2;
            s2.assign(4, 'K');  // s2 = "KKKK"
            cout<<s2;
            s2.assign("abcde", 2, 3);  // s2 = "cde"���� "abcde" ���Ӵ�(2, 3)
            cout<<s2 ;
        }
    }
    {  //����3
        MyString s1("12345"), s2;
        cout << s1.length() << s2.size() ;
    }
    {//����4
        MyString s1("123"), s2("abc");
        s1.append(s2);  // s1 = "123abc"
        cout<<s1;
        s1.append(s2, 1, 2);  // s1 = "123abcbc"
        cout<<s1;
        s1.append(3, 'K');  // s1 = "123abcbcKKK"
        cout<<s1;
        s1.append("ABCDE", 2, 3);  // s1 = "123abcbcKKKCDE"����� "ABCDE" ���Ӵ�(2, 3)
        cout<<s1 ;
    }
    {   //����5
        MyString s1("hello"), s2("hello, world");
        cout<<(s1>s2)<<(s1<s2)<<(s1>=s2)<<(s1<=s2)<<(s1==s2)<<(s1!=s2) ;
    }
    {   //����6
        MyString s1 = "this is ok";
        MyString s2 = s1.substr(2, 4);  // s2 = "is i"
        cout<<s1<<s2;
        s2 = s1.substr(2);  // s2 = "is is ok"
        cout<<s2 ;
    }
    {   //����7
        MyString s1("West"), s2("East");
        cout<<s1<<s2;
        s1.swap(s2);  // s1 = "East"��s2 = "West"
        cout<<s1<<s2 ;
    }
    {   //����8
        MyString s1("Source Code");
        int n;
        if ((n = s1.find('u')) != MyString::npos) //���� u ���ֵ�λ��
            cout << "1) " << n << "," << s1.substr(n)  ;
        //��� l)2,urce Code
        if ((n = s1.find("Source", 3)) == MyString::npos)//���±�3��ʼ����"Source"���Ҳ���
            cout << "2) " << "Not Found"  ;  //��� 2) Not Found
        if ((n = s1.find("Co")) != MyString::npos) //�����Ӵ�"Co"�����ҵ�������"Co"��λ��
            cout << "3) " << n << ", " << s1.substr(n)  ;
        //��� 3) 7, Code
        if ((n = s1.find_first_of("ceo")) != MyString::npos)//���ҵ�һ�γ��ֻ� 'c'��'e'��'o'��λ��
            cout << "4) " << n << ", " << s1.substr(n) ;
        //��� 4) l, ource Code
        if ((n = s1.find_last_of('e')) != MyString::npos)//�������һ�� 'e' ��λ��
            cout << "5) " << n << ", " << s1.substr(n)  ;
        //��� 5) 10, e
        if ((n = s1.find_first_not_of("eou", 1)) != MyString::npos) //���±�1��ʼ���ҵ�һ�γ��ַ� 'e'��'o' �� 'u' �ַ���λ��
            cout << "6) " << n << ", " << s1.substr(n) ;
        //��� 6) 3, rce Code
    }
    {   //����9
        MyString s1("Real Steel");
        cout<<s1;
        s1.replace(1, 3, "123456", 2, 4);  //�� "123456" ���Ӵ�(2,4) �滻 s1 ���Ӵ�(1,3)
        cout << s1 ;  //��� R3456 Steel
        MyString s2("Harry Potter");
        cout<<s2;
        s2.replace(2, 3, 5, '0');  //�� 5 �� '0' �滻�Ӵ�(2,3)
        cout << s2  ;  //��� HaOOOOO Potter
        int n = s2.find("00000");  //�����Ӵ� "00000" ��λ�ã�n=2
        cout<<n;   //���2
        s2.replace(n, 5, "XXX");  //���Ӵ�(n,5)�滻Ϊ"XXX"
        cout << s2  ;  //��� HaXXX Potter
    }
    { //����10
        MyString s1("Real Steel");
        cout<<s1;
        s1.erase(1, 3);  //ɾ���Ӵ�(1, 3)���˺� s1 = "R Steel"
        cout<<s1;
        s1.erase(5);  //ɾ���±�5�������������ַ����˺� s1 = "R Ste"
        cout<<s1 ;
    }
    { //����11
        MyString s1("Limitless"), s2("00");
        cout<<s1<<s2;
        s1.insert(2, "123");  //���±� 2 �������ַ���"123"��s1 = "Li123mitless"
        cout<<s1;
        s1.insert(3, s2);  //���±� 2 ������ s2 , s1 = "Li10023mitless"
        cout<<s1;
        s1.insert(3, 5, 'X');  //���±� 3 ������ 5 �� 'X'��s1 = "Li1XXXXX0023mitless"
        cout<<s1;
    }
    {   //����12  ѡ������
#ifndef _SELECT
        //û�����ѡ��������ʹ��string���istringstream�����
        string src("Avatar 123 5.2 Titanic K");
        istringstream istrStream(src); //����src��istrStream����ϵ
        string s1, s2;
        int n;  double d;  char c;
        istrStream >> s1 >> n >> d >> s2 >> c; //��src�����ݵ������������ж�ȡ
        ostringstream ostrStream;
        ostrStream << s1  << s2   << n   << d   << c ;
        cout << ostrStream.str()<<endl;
#else
        //������ѡ��������ʹ��MyString���iMyStringstream�����
        MyString src("Avatar 123 5.2 Titanic K");
        iMyStringstream istrStream(src); //����src��istrStream����ϵ
        MyString s1, s2;
        int n;  double d;  char c;
        istrStream >> s1 >> n >> d >> s2 >> c; //��src�����ݵ������������ж�ȡ
        oMyStringstream ostrStream;
        ostrStream << s1  << s2   << n   << d   << c ;
        cout << ostrStream.str()<<endl;
#endif // _SELECT
    }
    return  0;
}
