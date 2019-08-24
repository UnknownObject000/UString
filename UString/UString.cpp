#include "pch.h"

#include "UString.h"

std::string UString::WTS(const std::wstring & wstr)
{
	std::string ret;
	try {
		std::wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
		ret = wcv.to_bytes(wstr);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

std::wstring UString::STW(const std::string & str)
{
	std::wstring ret;
	try {
		std::wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
		ret = wcv.from_bytes(str);
	}
	catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

std::string UString::SUBSTR(int start, int stop)
{
	if (start > stop)
	{
		return "null";
	}
	if ((stop - start) > length())
	{
		return "overload";
	}
	char* tmp = new char[length()];
	for (int i = start; i <= stop; i++)
	{
		tmp[i - start] = str[i];
	}
	std::string ret = std::string(tmp);
	delete[] tmp;
	return ret;
}

bool UString::ISDEC(char c)
{
	if (c >= '0'&& c <= '9')
		return true;
	else return false;
}

bool UString::ISHEX(char c)
{
	if (ISDEC(c))
		return true;
	else
	{
		if (c >= 'A'&& c <= 'F')
			return true;
		else if (c >= 'a'&& c <= 'f')
			return true;
		else return false;
	}
}

int UString::tint(char c)
{
	if (ISDEC(c))
		return (c - '0');
	else
	{
		if (c == 'A' || c == 'a')
			return 10;
		if (c == 'B' || c == 'b')
			return 11;
		if (c == 'C' || c == 'c')
			return 12;
		if (c == 'D' || c == 'd')
			return 13;
		if (c == 'E' || c == 'e')
			return 14;
		if (c == 'F' || c == 'f')
			return 15;
	}
}

void UString::swap(int &var1, int &var2)
{
	int tmp = var1;
	var1 = var2;
	var2 = tmp;
	return;
}

//build & unbuild
UString::UString()
{
	str = "";
}

UString::UString(const UString &ustr)
{
	str = ustr.str;
}

UString::UString(std::string s)
{
	str = s;
}

UString::UString(std::wstring ws)
{
	str = WTS(ws);
}

UString::UString(char* cs)
{
	str = std::string(cs);
}

UString::UString(const char* ccs)
{
	str = std::string(ccs);
}

UString::UString(wchar_t* ws)
{
	str = WTS(std::wstring(ws));
}

UString::UString(const wchar_t* cws)
{
	str = WTS(std::wstring(cws));
}

UString::UString(const char chr)
{
	char cg[2];
	cg[0] = chr;
	cg[1] = '\0';
	str = std::string(cg);
}

UString::UString(const wchar_t wch)
{
	wchar_t wg[2];
	wg[0] = wch;
	wg[1] = L'\0';
	str = WTS(std::wstring(wg));
}

UString::~UString()
{
	str.~basic_string();
}

//string etc...
std::string UString::std_str()
{
	return str;
}

const char* UString::c_str()
{
	return str.c_str();
}

char* UString::c_str_nc()
{
	const char* cstr = str.c_str();
	char* ncstr = new char[str.length()];
	for (int i = 0; i < str.length(); i++)
	{
		ncstr[i] = cstr[i];
	}
	char* ret = ncstr;
	delete[] ncstr;
	return ret;
}

std::wstring UString::w_str()
{
	return STW(str);
}

const wchar_t* UString::wc_str()
{
	return STW(str).c_str();
}

wchar_t* UString::w_str_nc()
{
	const wchar_t* cstr = STW(str).c_str();
	wchar_t* ncstr = new wchar_t[str.length()];
	for (int i = 0; i < str.length(); i++)
	{
		ncstr[i] = cstr[i];
	}
	wchar_t* ret = ncstr;
	delete[] ncstr;
	return ret;
}

char UString::bit_c(int bit)
{
	if (bit >= length())
	{
		throw("UString: Out of range");
		return 0;
	}
	return str[bit];
}

wchar_t UString::bit_w(int bit)
{
	if (bit >= length())
	{
		throw("UString: Out of range");
		return 0;
	}
	std::wstring wstr;
	wstr = STW(str);
	return wstr[bit];
}

//info
int UString::length()
{
	return str.length();
}

//opt
int UString::find(char c)
{
	for (int i = 0; i < length(); i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

int UString::find(wchar_t wc)
{
	std::wstring tmp = STW(str);
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == wc)
		{
			return i;
		}
	}
	return -1;
}

int UString::find(std::string s)
{
	if (length() < s.length())
		return -1;
	for (int i = 0; i < length(); i++)
	{
		if ((i + s.length()) > length())
		{
			return -1;
		}
		if (SUBSTR(i, i + s.length()) == s)
		{
			return i;
		}
	}
	return -1;
}

int UString::find(std::wstring ws)
{
	std::string s;
	s = WTS(ws);
	return find(s);
}

std::string UString::substr(int start, int stop)
{
	return SUBSTR(start, stop);
}

std::wstring UString::substr_w(int start, int stop)
{
	return STW(SUBSTR(start, stop));
}

bool UString::erase(int poi)
{
	std::string tmp;
	if (poi >= length()) return false;
	for (int i = 0; i < poi; i++)
	{
		tmp[i] = str[i];
	}
	for (int i = poi + 1; i < length(); i++)
	{
		tmp[i - 1] = str[i];
	}
	str = tmp;
	return true;
}

bool UString::erase(int start, int stop)
{
	std::string tmp;
	if (start >= length()) return false;
	if (stop >= length()) return false;
	if (start > stop) swap(start, stop);
	for (int i = 0; i < start; i++)
	{
		tmp[i] = str[i];
	}
	for (int i = stop + 1; i < length(); i++)
	{
		tmp[i - (stop - start + 1)] = str[i];
	}
	str = tmp;
	return true;
}

void UString::format(std::string cmd, ...)
{
	char* cstr;
	va_list vl;
	int cnt = 0;
	for (int i = 0; i < cmd.length(); i++)
	{
		if (i != (cmd.length() - 1))
		{
			if ((cmd[i] == '%') && (cmd[i + 1] != '%'))
			{
				cnt++;
			}
		}
	}
	va_start(vl, cnt);
	sprintf(cstr, cmd.c_str(), vl);
	va_end(vl);
	str = std::string(cstr);
	delete[] cstr;
	return;
}

void UString::Random(int bits, UString STRUCT)
{
	int seed;
	UString ustr;
	seed = time(nullptr);
	for (int i = 0; i < bits; i++)
	{
		srand(seed);
		seed = (rand() % STRUCT.length());
		ustr += STRUCT.bit_c(seed);
	}
	if (ustr.length() == bits)
		str = ustr.std_str();
	else
		throw("UString: Unknown libary error");
	return;
}

void UString::Go_away_0x()
{
	if ((str[0] == '0') && (str[1] == 'x'))
	{
		erase(0, 1);
	}
}

int UString::to_int_dec()
{
	int ret = 0;
	for (int i = 0; i < length(); i++)
	{
		if (!ISDEC(str[i]))
			return INF;
	}
	int len = length();
	for (int i = 0; i < len; i++)
	{
		ret = ret + (tint(str[i]) * (len - i - 1) * 10);
	}
	return ret;
}

int UString::to_int_hex()
{
	int ret = 0;
	for (int i = 0; i < length(); i++)
	{
		if (!ISHEX(str[i]))
			return INF;
	}
	int len = length();
	for (int i = 0; i < len; i++)
	{
		ret = ret + (tint(str[i]) * (len - i - 1) * 16);
	}
	return ret;
}

long long UString::to_int_dec_ll()
{
	long long ret = 0;
	for (int i = 0; i < length(); i++)
	{
		if (!ISDEC(str[i]))
			return INF;
	}
	int len = length();
	for (int i = 0; i < len; i++)
	{
		ret = ret + (tint(str[i]) * (len - i - 1) * 10);
	}
	return ret;
}

long long UString::to_int_hex_ll()
{
	long long ret = 0;
	for (int i = 0; i < length(); i++)
	{
		if (!ISHEX(str[i]))
			return INF;
	}
	int len = length();
	for (int i = 0; i < len; i++)
	{
		ret = ret + (tint(str[i]) * (len - i - 1) * 16);
	}
	return ret;
}

double UString::to_double()
{
	double ret = 0.00;
	ret = atof(str.c_str());
	return ret;
}

//operation
//+
UString UString::operator+(const UString &ustr)
{
	str = str + ustr.str;
	return UString(str);
}

UString UString::operator+(const std::string &sstr)
{
	str = str + sstr;
	return UString(str);
}

UString UString::operator+(const std::wstring &wstr)
{
	str = str + WTS(wstr);
	return UString(str);
}

UString UString::operator+(const char* &cstr)
{
	str = str + std::string(cstr);
	return UString(str);
}

UString UString::operator+(const wchar_t* &wcstr)
{
	str = str + WTS(std::wstring(wcstr));
	return UString(str);
}

UString UString::operator+(const char &chr)
{
	str = str + UString(chr).std_str();
	return UString(str);
}

UString UString::operator+(const wchar_t &wch)
{
	str = str + UString(wch).std_str();
	return UString(str);
}

//+=
void UString::operator+=(const UString &ustr)
{
	str = str + ustr.str;
	return;
}

void UString::operator+=(const std::string &sstr)
{
	str = str + sstr;
	return;
}

void UString::operator+=(const std::wstring &wstr)
{
	str = str + WTS(wstr);
	return;
}

void UString::operator+=(const char* &cstr)
{
	str = str + std::string(cstr);
	return;
}

void UString::operator+=(const wchar_t* &wcstr)
{
	str = str + WTS(std::wstring(wcstr));
	return;
}

void UString::operator+=(const char &chr)
{
	std::string tmp = UString(chr).std_str();
	str += tmp;
	return;
}

void UString::operator+=(const wchar_t &wch)
{
	std::string tmp = WTS(std::wstring(UString(wch).w_str()));
	str += tmp;
	return;
}

//=
void UString::operator=(const UString &ustr)
{
	str = ustr.str;
	return;
}

void UString::operator=(const std::string &sstr)
{
	str = sstr;
	return;
}

void UString::operator=(const std::wstring &wstr)
{
	str = WTS(wstr);
	return;
}

void UString::operator=(const char* &cstr)
{
	str = std::string(cstr);
	return;
}

void UString::operator=(const wchar_t* &wcstr)
{
	str = WTS(std::wstring(wcstr));
	return;
}

void UString::operator=(const char & chr)
{
	str = UString(chr).std_str();
	return;
}

void UString::operator=(const wchar_t & wch)
{
	str = UString(wch).std_str();
	return;
}

//==
bool UString::operator==(const UString &ustr)
{
	if (str == ustr.str)
		return true;
	else return false;
}

bool UString::operator==(const std::string &sstr)
{
	if (str == sstr)
		return true;
	else return false;
}

bool UString::operator==(const std::wstring &wstr)
{
	if (str == WTS(wstr))
		return true;
	else return false;
}

bool UString::operator==(const char* &cstr)
{
	if (str == std::string(cstr))
		return true;
	else return false;
}

bool UString::operator==(const wchar_t* &wcstr)
{
	if (str == WTS(std::wstring(wcstr)))
		return true;
	else return false;
}

//<<
std::ostream &operator<< (std::ostream& ostr, UString& ustr)
{
	ostr << ustr.std_str();
	return ostr;
}

//>>
std::istream &operator>> (std::istream& istr, UString& ustr)
{
	std::string tmp;
	istr >> tmp;
	ustr = tmp;
	return istr;
}