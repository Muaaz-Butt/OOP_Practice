#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String {
private:
	char* data;
	int size;
	int getLength(const char* c);
	void mySwap(char* a, char* b);
public:
	String();
	String(const char c);
	String(const char* c);
	String(const String& c);
	~String();
	void input();
	void shrink();
	char& at(int index);
	bool isEmpty() const;
	int getLength() const;
	void display() const;
	int find(const String& substr, int start = 0)const;
	void insertString(int index, const String& subStr);
	void remove(int index, int count = 1);
	void reSize(int s);
	void makeUpper();
	void makeLower();
	void reverse();
	int compare(const String& s2) const;
	bool isAlpha(int index)const;
	void trimLeft();
	void trimRight();
	void trim();
	String concatenate(const String& obj);
	void copyString(char* destination, char* source);
	String operator+(const String& str);
	String operator-(const String& str);
	String operator=(const String& str);
	bool operator==(const String& str);
	bool operator>(const String& str);
	bool operator<(const String& str);
	char& operator[](int index);
	const char* getData() const;
	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);
};
#endif STRING_H
