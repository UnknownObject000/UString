#pragma once

#include <iostream>
#include <stdarg.h>
#include <string.h>
#include <codecvt>
#include <string>
#include <time.h>

#define INF 0x7ffffff

class UString
{
private:
	std::string str;								//�洢�ñ���
	std::string WTS(const std::wstring & wstr);		//wstringתstring
	std::wstring STW(const std::string & str);		//stringתwstring
	std::string SUBSTR(int start, int stop);		//ȡ�Ӵ�
	bool ISDEC(char c);								//�ж��Ƿ�Ϊ�Ϸ�ʮ�������ִ�
	bool ISHEX(char c);								//�ж��Ƿ�Ϊ�Ϸ�ʮ���������ִ�
	int tint(char c);								//�ַ�ת����
	void swap(int &var1, int &var2);				//��������
public:
	//����������

	UString();										//Ĭ���޲ι��캯��
	UString(const UString &ustr);					//UString���ƹ���
	UString(std::string s);							//��string����
	UString(std::wstring ws);						//��wstring����
	UString(char* cs);								//��C�ַ�������
	UString(const char* ccs);						//��C�ַ�������2
	UString(wchar_t* ws);							//��UNICODE�µ�C�ַ�������
	UString(const wchar_t* cws);					//��UNICODE�µ�C�ַ�������2
	UString(const char chr);						//����ͨ�ַ�����
	UString(const wchar_t wch);						//��UNICODE�ַ�����
	~UString();										//����
	//�ַ���ת��

	std::string std_str();							//ת��Ϊstring
	const char* c_str();							//ת��ΪC�ַ���
	char* c_str_nc();								//ת��Ϊ�ǳ���C�ַ���
	std::wstring w_str();							//ת��Ϊwstring
	const wchar_t* wc_str();						//ת��ΪUNICODE��C�ַ���
	wchar_t* w_str_nc();							//ת��ΪUNICODE�·ǳ���C�ַ���
	char bit_c(int bit);							//ȡĳһλ�ַ����൱��[bit]
	wchar_t bit_w(int bit);							//��UNICODE��ʽȡĳһλ�ַ�
	//�ַ�����Ϣ

	int length();									//��ȡ�ִ�����
	//�ַ�������

	int find(char c);								//�ڴ���Ѱ��һ���ַ�����������λ��
	int find(wchar_t wc);							//�ڴ���Ѱ��һ��UNICODE�ַ�����������λ��
	int find(std::string s);						//�ڴ���Ѱ��һ��string�Ӵ�������λ��
	int find(std::wstring ws);						//�ڴ���Ѱ��һ��wstring�Ӵ�������λ��
	std::string substr(int start, int stop);		//ȡ����start��stop���Ӵ�����string���ͷ���
	std::wstring substr_w(int start, int stop);		//ȡ����start��stop���Ӵ�����wstring���ͷ���
	bool erase(int poi);							//ɾ��poi�����ַ�
	bool erase(int start, int stop);				//ɾ����start��stop�������ַ�
	void format(std::string cmd, ...);				//��ʽ���ַ���
	void Random(int bits, UString STRUCT);			//����һ������ַ���
	void Go_away_0x();								//ȥ��ʮ���������ִ���ͷ�ġ�0x��
	int to_int_dec();								//ת��Ϊint����ʮ����ת����
	int to_int_hex();								//ת��Ϊint����ʮ������ת����
	long long to_int_dec_ll();						//ת��Ϊlong long����ʮ����ת����
	long long to_int_hex_ll();						//ת��Ϊlong long����ʮ������ת����
	double to_double();								//ת��Ϊdouble
	//�����
	//+

	UString operator+(const UString &ustr);
	UString operator+(const std::string &sstr);
	UString operator+(const std::wstring &wstr);
	UString operator+(const char* &cstr);
	UString operator+(const wchar_t* &wcstr);
	UString operator+(const char &chr);
	UString operator+(const wchar_t &wch);
	//+=

	void operator+=(const UString &ustr);
	void operator+=(const std::string &sstr);
	void operator+=(const std::wstring &wstr);
	void operator+=(const char* &cstr);
	void operator+=(const wchar_t* &wcstr);
	void operator+=(const char &chr);
	void operator+=(const wchar_t &wch);
	//=

	void operator=(const UString &ustr);
	void operator=(const std::string &sstr);
	void operator=(const std::wstring &wstr);
	void operator=(const char* &cstr);
	void operator=(const wchar_t* &wcstr);
	void operator=(const char &chr);
	void operator=(const wchar_t &wch);
	//==

	bool operator==(const UString &ustr);
	bool operator==(const std::string &sstr);
	bool operator==(const std::wstring &wstr);
	bool operator==(const char* &cstr);
	bool operator==(const wchar_t* &wcstr);
};

//<<
std::ostream &operator<< (std::ostream& ostr, UString& ustr);
//>>
std::istream &operator>> (std::istream& istr, UString& ustr);