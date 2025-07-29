#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    int marks[3];  // for 3 subjects
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        cout << "Enter Roll Number: ";
        cin >> s.rollNo;
        cin.ignore();  // clear input buffer

        cout << "Enter Name: ";
        getline(cin, s.name);

        cout << "Enter marks for 3 subjects:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> s.marks[i];
        }

        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\nList of Students:\n";
        for (auto& s : students) {
            cout << "Roll No: " << s.rollNo << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Marks: ";
            for (int i = 0; i < 3; i++) {
                cout << s.marks[i] << " ";
            }
            cout << "\n\n";
        }
    }

    void searchByRollNo(int roll) {
        bool found = false;
        for (auto& s : students) {
            if (s.rollNo == roll) {
                cout << "\nStudent Found:\n";
                cout << "Name: " << s.name << "\n";
                cout << "Marks: ";
                for (int i = 0; i < 3; i++) {
                    cout << s.marks[i] << " ";
                }
                cout << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << roll << " not found.\n";
        }
    }

    void calculateAverageMarks() {
        if (students.empty()) {
            cout << "No students to calculate average.\n";
            return;
        }

        cout << "\nAverage Marks of Each Student:\n";
        for (auto& s : students) {
            float total = 0;
            for (int i = 0; i < 3; i++) {
                total += s.marks[i];
            }
            float avg = total / 3.0;
            cout << "Roll No: " << s.rollNo << ", Name: " << s.name << ", Average Marks: " << avg << "\n";
        }
    }

    void countStudents() {
        cout << "Total number of students: " << students.size() << "\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n----- Student Management Menu -----\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Calculate Average Marks\n";
        cout << "5. Count Total Students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3: {
                int roll;
                cout << "Enter roll number to search: ";
                cin >> roll;
                manager.searchByRollNo(roll);
                break;
            }
            case 4:
                manager.calculateAverageMarks();
                break;
            case 5:
                manager.countStudents();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
