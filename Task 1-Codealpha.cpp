#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	int numCourses;
	cout << "Enter the number of courses:";
	cin >> numCourses;
	
	vector<string> courseName(numCourses);
	vector<float> grade(numCourses);
	vector<int> creditHours(numCourses);
	float totalGradePoints = 0;
	int totalCredits = 0;
	
	// Input for each course
	for (int i = 0; i < numCourses; i++) {
		cout << "\nCourse"<< i + 1 << "Details:" << endl;
		cout << "Enter Course Name:";
		cin.ignore();
		getline(cin, courseName[i]);
		
		cout << "Enter Grade Point for" <<courseName[i] << "(e.g., 9.0 for A):";
		cin >> grade[i];
		
		cout << "Enter Credit Hours for" << courseName[i] << ":";
		cin >> creditHours[i];
		
		totalGradePoints += grade[i] * creditHours[i];
		totalCredits += creditHours[i];
		
	}
	
	float cgpa = totalGradePoints / totalCredits;
	
	// Display Result
	cout << "\n--- Result ---" << endl;
	cout << fixed << setprecision(2);
	for (int i = 0; i < numCourses; i++){
		cout << "Course: " << courseName[i]
		<<"| Grade:" << grade[i]
		<< "| Credits:" << creditHours[i] << endl;
	}
	
	cout << "----------"<<endl;
	cout << "Total Credits: " << totalCredits << endl;
	cout << "Final CGPA:" << cgpa << endl;
	
	return 0;
}
