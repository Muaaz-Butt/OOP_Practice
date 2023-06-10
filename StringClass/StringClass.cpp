#include <iostream>
#include <cmath>
#include "String.h"

using namespace std;

int String::getLength(const char* c) {
	int count = 0,i=0;
	while (c[i] != '\0') {
		count++;
		i++;
	}
	return count;
}

String::String() {
	//cout << "String  default constructor is called\n";
	data = nullptr;
	size = 0;
}

String::String(char c) {
	//cout << "Parameterized construcot for strig class for char c\n";
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';
}

String::String(const char* c) {
	//cout << "Parameterize dconstructor is called for char* c\n";
	size = getLength(c) + 1;
	data = new char[size];
	int i = 0;
	while (c[i] != '\0') {
		data[i] = c[i];
		i++;
	}
	data[i] = '\0';
}

String :: ~String() {
	if (!data) {
		return;
	}
	//cout << "String Desrtructor is called\n";
	delete[] data;
	data = nullptr;
	size = 0;
}

void String::reSize(int s) {
	if (s <= 0) {
		this->~String();
		return;
	}
	char* p = new char[s];
	int i = 0;
	for (i = 0; i < (s > size ? size : s - 1); i++) {
		p[i] = data[i];
	}
	p[i] = '\0';
	this->~String();
	data = p;
	size = s;
}

void String :: shrink() {
	int length = getLength();
	if (length < size) {
		reSize(length);
	}
}

void String::input() {
	this->~String();
	reSize(2);
	int i = 0;
	do {
		if (i == size) {
			reSize(2 * size);
		}
		data[i] = cin.get();
		i++;
	} while (data[i - 1] != '\n');
	data[i] = '\0';
	shrink();
}

char& String::at(int index) {
	if (index<0 || index>size) {
		exit(0);
	}
	return data[index];
}

bool String::isEmpty() const {
	cout << "In is empty function\n";
	if (size == 0) {
		return true;
	}
	return false;
}

int String::getLength() const {
	int i = 0, count = 0;
	while (data[i] != '\0') {
		count++;
		i++;
	}
	return count;
}

void String :: display() const {
	cout << data << "\n";
}

int String::find(const String& subStr, int start)const {
	int length = subStr.getLength(),count=0;
	int j = 0;
	int i = start;
	while (data[i]) {
		if (data[i] == subStr.data[j]) {
			j++;
			if (j == length) {
				return i - (length - 1);
			}
		}
		else {
			j = 0;
		}
		i++;
	}	
	return -1;
}

void String::insertString(int index, const String& subStr) {
	int subStrLen = subStr.getLength(), dataLength = getLength(),
		totalLength = subStrLen + dataLength, tempTotalLength = totalLength;
	reSize(subStrLen + dataLength + 1);
	int i = totalLength, j = dataLength;
	data[totalLength] = '\0';
	while (i >= 0)
	{
		if (j == index)
		{
			int k = 0, tempIndex = index;
			while (k < subStrLen)
			{
				data[tempIndex] = subStr.data[k];
				k = k + 1;
				tempIndex = tempIndex + 1;
				i--;
			}
		}
		else
		{
			data[i - 1] = data[j - 1];
			j = j - 1;
			i--;
		}
	}
}

void String::remove(int index, int count) {
	int len = getLength();
	int i = index, temp = count + index;
	while (i < len) {
		data[index] = data[temp];
		index++;
		temp++;
		i++;
	}
	reSize(len - count + 1);
}

void  String::makeUpper() {
	int i = 0;
	while (data[i]) {
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - ('a' - 'A');
		}
		i++;
	}
}

void String::makeLower()
{
	int i = 0;
	while (data[i])
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
		i = i + 1;
	}
}

void String::copyString(char* destination, char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

int String::compare(const String& s2) const
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] > s2.data[i])
		{
			return 1;
		}
		else if (data[i] < s2.data[i])
		{
			return -1;
		}
		i = i + 1;
	}
	return 0;
}

void String::reverse() {
	int len = getLength();
	for (int i = 0; i < len / 2; i++) {
		mySwap(&data[i], &data[len - i - 1]);
	}
}

void String::mySwap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

bool String::isAlpha(int index)const {
	if (data[index] >= 'A' && data[index] <= 'Z') {
		return true;
	}
	else if (data[index] >= 'a' && data[index] <= 'z') {
		return true;
	}
	else {
		return false;
	}
}

String String::concatenate(const String& obj) {
	int lenOfData = getLength(), lenOfObjData = obj.getLength();
	int totalLength = lenOfData + lenOfObjData;
	reSize(totalLength + 1);
	int i = lenOfData,j=0;
	data[totalLength] = '\0';
	while (i < totalLength) {
		data[i] = obj.data[j];
		i++;
		j++;
	}
	return data;
}

void String::trimLeft()
{
	int i = 0, len = getLength();
	while (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
	{
		i++;
	}
	remove(0, i);
}
void String::trimRight()
{
	int i = getLength() - 1;
	if (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
	{
		while (i >= 0 && (data[i] == ' ' || data[i] == '\t' || data[i] == '\n'))
		{
			i--;
		}
		data[i + 2] = '\0';
		shrink();
	}

}
void String::trim()
{
	trimRight();
	trimLeft();
}

String String :: operator+(const String& str){
	int lenOfData = getLength(), lenOfStrData = str.getLength();
	int totalLength = lenOfData + lenOfStrData;
	reSize(totalLength + 1);
	int i = lenOfData, j = 0;
	data[totalLength] = '\0';
	while (i < totalLength) {
		data[i] = str.data[j];
		i++;
		j++;
	}
	return data;
}

String String::operator-(const String& str) {
	int dataLength = getLength();
	int strLength = str.getLength();
	int totalLength = dataLength - strLength;
	int i = 0;
	bool flag = true;
	while (flag&&i<strLength) {
		if (data[i] == str.data[i]) {
			i++;
		}
		else {
			flag = false;
		}
	}
	if (i != strLength) {
		reSize(totalLength + 1);
		data[totalLength] = '\0';
		return data;
	}
	else if (i == strLength) {
		String temp;
		int j = 0;
		temp.reSize(totalLength + 1);
		temp.data[totalLength] = '\0';
		while (data[i]) {
			temp.data[j] = data[i];
			i++;
			j++;
		}
		reSize(totalLength + 1);
		data[totalLength] = '\0';
		i = 0;
		while (temp.data[i]) {
			data[i] = temp.data[i];
			i++;
		}
		return data;
	}
}

bool String :: operator>(const String& str) {
	int i = 0;
	if (data[i] > str.data[i])
	{
		return true;
	}
	else {
		return false;
	}
}

bool String :: operator<(const String& str) {
	int i = 0;
	if (data[i] < str.data[i])
	{
		return true;
	}
	else {
		return false;
	}
}

bool String :: operator==(const String& str) {
	int i = 0;
	while (data[i]) {
		if (data[i] == str.data[i]) {
			i++;
		}
		else {
			return false;
		}
	}
	return true;
}

String String :: operator=(const String& str) {
	int len = str.getLength();
	reSize(len+1);
	int i = 0;
	data[len] = '\0';
	while (str.data[i]) {
		data[i] = str.data[i];
		i++;
	}
	return (data);
}

char& String :: operator[](int index) {
	int length = getLength();
	//cout << data[4];
	if (index < length) {
		return data[index];
	}
	else {
		cout << "Index out of bound\n";
		exit(0);
	}
}

const char* String::getData() const {
	return data;
}

ostream& operator<<(ostream& out, const String& str) {
	out << str.data;
	return out;
}

istream& operator>>(istream& in, String& str) {
	str.~String();
	str.reSize(2);
	int i = 0;
	do {
		if (i == str.size) {
			str.reSize(2 * str.size);
		}
		str.data[i] = in.get();
		i++;
	} while (str.data[i - 1] != '\n');
	str.data[i] = '\0';
	str.shrink();
	return in;
}