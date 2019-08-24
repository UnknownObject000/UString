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
	std::string str;								//存储用变量
	std::string WTS(const std::wstring & wstr);		//wstring转string
	std::wstring STW(const std::string & str);		//string转wstring
	std::string SUBSTR(int start, int stop);		//取子串
	bool ISDEC(char c);								//判断是否为合法十进制数字串
	bool ISHEX(char c);								//判断是否为合法十六进制数字串
	int tint(char c);								//字符转数字
	void swap(int &var1, int &var2);				//交换两数
public:
	//构造与析构

	UString();										//默认无参构造函数
	UString(const UString &ustr);					//UString复制构造
	UString(std::string s);							//从string构造
	UString(std::wstring ws);						//从wstring构造
	UString(char* cs);								//从C字符串构造
	UString(const char* ccs);						//从C字符串构造2
	UString(wchar_t* ws);							//从UNICODE下的C字符串构造
	UString(const wchar_t* cws);					//从UNICODE下的C字符串构造2
	UString(const char chr);						//从普通字符构造
	UString(const wchar_t wch);						//从UNICODE字符构造
	~UString();										//析构
	//字符串转换

	std::string std_str();							//转换为string
	const char* c_str();							//转换为C字符串
	char* c_str_nc();								//转换为非常量C字符串
	std::wstring w_str();							//转换为wstring
	const wchar_t* wc_str();						//转换为UNICODE下C字符串
	wchar_t* w_str_nc();							//转换为UNICODE下非常量C字符串
	char bit_c(int bit);							//取某一位字符，相当于[bit]
	wchar_t bit_w(int bit);							//以UNICODE格式取某一位字符
	//字符串信息

	int length();									//获取字串长度
	//字符串操作

	int find(char c);								//在串中寻找一个字符并返回它的位置
	int find(wchar_t wc);							//在串中寻找一个UNICODE字符并返回它的位置
	int find(std::string s);						//在串中寻找一个string子串并返回位置
	int find(std::wstring ws);						//在串中寻找一个wstring子串并返回位置
	std::string substr(int start, int stop);		//取出从start到stop的子串并以string类型返回
	std::wstring substr_w(int start, int stop);		//取出从start到stop的子串并以wstring类型返回
	bool erase(int poi);							//删除poi处的字符
	bool erase(int start, int stop);				//删除从start到stop的所有字符
	void format(std::string cmd, ...);				//格式化字符串
	void Random(int bits, UString STRUCT);			//生成一个随机字符串
	void Go_away_0x();								//去除十六进制数字串开头的“0x”
	int to_int_dec();								//转换为int（按十进制转换）
	int to_int_hex();								//转换为int（按十六进制转换）
	long long to_int_dec_ll();						//转换为long long（按十进制转换）
	long long to_int_hex_ll();						//转换为long long（按十六进制转换）
	double to_double();								//转换为double
	//运算符
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