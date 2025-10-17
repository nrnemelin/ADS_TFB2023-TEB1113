#include <iostream>
#include <string>

using namespace std;

struct Student {
	int id;
	string name;
	string email;
};

int main() {
	Student student [5];

	for (int i=0; i<5; i++) {
		cin>>student[i].id;
		cin>>student[i].name;
		cin>>student[i].email;
	}

	for (int i=0; i<5; i++) {
		cout<<"Student "<<i<<"details\n";
		cout<<"Name: "<<student[i].name<<"\n";
		cout<<"Email: "<<student[i].email<<"\n";
	}

	return 0;
}
