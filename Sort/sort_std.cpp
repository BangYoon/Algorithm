#include<iostream>
#include<algorithm> // sort 알고리즘 들어있음
#include<string> // '<<' 연산자 들어있음

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	//점수가 높은 순서로 정렬 ('<' 이거면 낮은 순서)
	bool operator <(Student &student) {
		return this->score > student.score;
	}
};

bool compare(int a, int b) {
	return a > b;
}

int main() {
	Student students[] = {
		Student("방", 97),
		Student("하", 92),
		Student("박", 87),
		Student("이", 90)
	};

	sort(students, students + 4); 
	for (int i = 0; i < 4; i++) {
		// printf("%s ", students[i].name);
		cout << students[i].name;
		cout << students[i].score << ' ';
	}
	return 0;
}
