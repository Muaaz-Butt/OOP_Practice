#include <iostream>

using namespace std;

class Student {
private:
	char* name;
	int rollNo;
	float cgpa;
public:
	Student() {

	}

	Student(char* name, int rollNo) {
		int nameLength = strlen(name);
		this->name = new char[nameLength + 1];
		int i = 0;
		for (i = 0; i < nameLength; i++) {
			this->name[i] = name[i];
		}
		this->name[i] = '\0';
		this->rollNo = rollNo;
		this->cgpa = -1;
	}

	Student(char* name, int rollNo, float cgpa) {
		int nameLength = strlen(name);
		this->name = new char[nameLength + 1];
		int i = 0;
		while (i < nameLength) {
			this->name[i] = name[i];
			i++;
		}
		this->name[i] = '\0';
		this->rollNo = rollNo;
		this->cgpa = cgpa;
	}

	Student(const Student& st1) {

		int nameLength = strlen(st1.name);
		this->name = new char[nameLength + 1];
		int i = 0;
		for (i = 0; i < nameLength; i++) {
			this->name[i] = st1.name[i];
		}
		this->name[i] = '\0';
		this->rollNo = st1.rollNo;
		this->cgpa = st1.cgpa;
	}

	char* getName() const {
		return name;
	}

	int getRollNo() const {
		return rollNo;
	}

	float getCgpa() const {
		return cgpa;
	}

	void setName(char* name) {
		if (this->name) {
			delete[]name;
		}
		int nameLength = strlen(name);
		this->name = new char[nameLength + 1];
		int i = 0;
		for (i = 0; i < nameLength; i++) {
			this->name[i] = name[i];
		}
		this->name[i] = '\0';
	}

	void setRollNo(int rollNo) {
		this->rollNo = rollNo;
	}

	void setCgpa(float cgpa) {
		this->cgpa = cgpa;
	}

	void display() {
		cout << "Name: " << name << endl;
		cout << "Roll Number: " << rollNo << endl;
		cout << "CGPA: " << cgpa << endl;
	}
	~Student() {
		cout << "Destructor is called" << endl;
	}
};
int main() {
	char nameOfStudent1[6] = "Muaaz";
	Student st1(nameOfStudent1, 123);
	st1.display();
	char nameOfStudent2[7] = "Zayyad";
	Student st2(nameOfStudent2, 123, 3.7);
	Student st3(st2);
	st2.display();
	st3.display();
	Student st4;
	char nameofStudent4[7] = "Hammad";
	st4.setName(nameofStudent4);
	st4.setCgpa(3.9);
	st4.setRollNo(543);
	st4.display();
}