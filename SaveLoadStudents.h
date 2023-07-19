#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <io.h>
#include "Student.h"

using namespace std;

class SaveLoadStudents {
public:
	static void load_students(string path, vector<Student>& students) {
		if (!is_exist(path)) {
			cout << "file not found!" << endl;
			return;
		}

		auto stream = fstream(path, ios_base::in);

		if (!stream.is_open()) {
			cout << "Oops, can't be opened" << endl;
			return;
		}

		auto delim = ';';
		string buffer;

		while (getline(stream, buffer)) {
			stringstream stream_line(buffer);
			string name;
			string s_age;
			string group;

			getline(stream_line, name, delim);
			getline(stream_line, s_age, delim);
			getline(stream_line, group, delim);

			Student stud{ name, stoi(s_age), group };
			students.push_back(stud);
			// or
			// students.push_back(Student{ name, stoi(s_age), group });
		}

		stream.close();
	}

	static void save_students(string path, vector<Student>& students, ios_base::openmode mode = ios_base::out) {
		if (!is_exist(path)) {
			cout << "file not found!" << endl;
			return;
		}

		auto stream = fstream(path, ios_base::out);

		if (!stream.is_open()) {
			cout << "Oops, can't be saved" << endl;
			return;
		}

		char delimeter{ ';' };
		for (auto& student : students) {
			stream << student.get_name() << delimeter <<
				student.get_age() << delimeter <<
				student.get_group() << endl;
		}

		stream.close();
	}

private:
	static bool is_exist(const string& path) {
		return _access(path.c_str(), 6) != -1;
	}
};
