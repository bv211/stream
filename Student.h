#pragma once
#include <iostream>

using namespace std;

class Student {
	string _name;
	int _age;
	string _group;

public:

	Student(const string& name, int age, const string& group)
		: _name(name), _age(age), _group(group) {}

	const string& get_name() const {
		return _name;
	}

	const int get_age() const {
		return _age;
	}

	const string& get_group() const {
		return _group;
	}

	Student& set_name(const string name) {
		_name = name.empty() ? "none" : name;

		return *this;
	}

	Student& set_age(int age) {
		_age = age < 0 ? 0 : age;

		return *this;
	}

	Student& set_group(const string group) {
		_group = group.empty() ? "none" : group;

		return *this;
	}

	friend ostream& operator<< (ostream& out, const Student& stud) {
		out << "Name: " << stud._name << endl
			<< "Age: " << stud._age << endl
			<< "Group: " << stud._group;

		return out;
	}
};
