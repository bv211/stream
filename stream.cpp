#include <iostream>
#include <Windows.h>
#include <vector>
#include "Student.h"
#include "SaveLoadStudents.h"

using namespace std;
using namespace Employee;
using namespace SaveLoad;

void print_students(vector<Student>& students) {
	for (auto& student : students) {
		cout << endl;
		cout << student << endl;
		cout << string(10, '-') << endl;
	}
}

Student create_student(const string& name, int age, const string& group) {
	return Student(name, age, group);
}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string path{ "file.txt" };
	vector<Student> students;

	SaveLoadStudents::load_students(path, students);
	cout << "--==after load==--" << endl;
	print_students(students);

	students[0]
		.set_name("hello")
		.set_age(12)
		.set_group("");

	students[1]
		.set_name("")
		.set_age(32)
		.set_group("ак228");

	SaveLoadStudents::save_students(path, students);
	cout << "\n--==after changed==--" << endl;
	print_students(students);
	// or append
	// SaveLoadStudents::save_students(path, _students, ios_base::app);

	return 0;
}