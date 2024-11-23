#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Student {
    int id;
    string name;
    int attendance;
    double grade;
};


class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(int id, const string& name) {
        Student newStudent = {id, name, 0, 0.0};
        students.push_back(newStudent);
        cout << "Student " << name << " added successfully.\n";
    }

    void updateAttendance(int id, int days) {
        for (auto& student : students) {
            if (student.id == id) {
                student.attendance += days;
                cout << "Attendance updated for " << student.name << ".\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }
    void updateGrade(int id, double grade) {
        for (auto& student : students) {
            if (student.id == id) {
                student.grade = grade;
                cout << "Grade updated for " << student.name << ".\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    void displayStudents() {
        cout << "\nStudent List:\n";
        cout << "ID\tName\t\tAttendance\tGrade\n";
        for (const auto& student : students) {
            cout << student.id << "\t" << student.name << "\t\t" << student.attendance << "\t\t" << student.grade << "\n";
        }
    }
};

int main() {
    StudentManagementSystem sms;

    int choice;
    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Update Attendance\n";
        cout << "3. Update Grade\n";
        cout << "4. Display Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);
            sms.addStudent(id, name);
        } else if (choice == 2) {
            int id, days;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Attendance Days to Add: ";
            cin >> days;
            sms.updateAttendance(id, days);
        } else if (choice == 3) {
            int id;
            double grade;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Grade: ";
            cin >> grade;
            sms.updateGrade(id, grade);
        } else if (choice == 4) {
            sms.displayStudents();
        } else if (choice == 5) {
            cout << "Exiting the system. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}