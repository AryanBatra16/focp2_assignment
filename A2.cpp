#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Course {
    string code;
    string title;
    int credits;
    string description;
public:
    Course() : code(""), title(""), credits(0), description("") {}
    Course(string c, string t, int cr, string d) : code(c), title(t), credits(cr), description(d) {}
    
    void course_details() {
        cout << "Course Code: " << code << "\nTitle: " << title
             << "\nCredits: " << credits << "\nDescription: " << description << endl;
    }
};

class Department {
    string dept_name;
    string location;
    string budget;
public:
    Department() : dept_name(""), location(""), budget("") {}
    Department(string d, string l, string b) : dept_name(d), location(l), budget(b) {}
    
    void department_details() {
        cout << "Department: " << dept_name << "\nLocation: " << location
             << "\nBudget: " << budget << endl;
    }
};

class Person {
protected:
    string per_name;
    int age;
    string id;
    string contact_info;
public:
    Person() : per_name(""), age(0), id(""), contact_info("") {}
    Person(string n, int a, string i, string c) : per_name(n), age(a), id(i), contact_info(c) {}
    
    virtual void displayDetails() {
        cout << "\nPersonal Details:\nName: " << per_name 
             << "\nAge: " << age << "\nID: " << id 
             << "\nContact: " << contact_info << endl;
    }
    
    virtual float calculatePayment() { return 0.0f; }
    
    void setContactInfo(string c) { if(!c.empty()) contact_info = c; }
    void setAge(int a) { if(a > 0) age = a; }
};

class Professor : public Person {
    string department;
    string specialization;
    string hire_date;
public:
    Professor() : Person(), department(""), specialization(""), hire_date("") {}
    Professor(string n, int a, string i, string c, string d, string s, string h)
        : Person(n, a, i, c), department(d), specialization(s), hire_date(h) {}
    
    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << department << "\nSpecialization: " << specialization
             << "\nHire Date: " << hire_date << endl;
    }
    
    float calculatePayment() override { return 85000.0f; }
};

class Student : public Person {
    string enroll_date;
    string program;
    float gpa;
public:
    Student() : Person(), enroll_date(""), program(""), gpa(0.0f) {}
    Student(string n, int a, string i, string c, string e, string p, float g)
        : Person(n, a, i, c), enroll_date(e), program(p), gpa(g) {}
    
    void displayDetails() override {
        Person::displayDetails();
        cout << "Enrollment: " << enroll_date << "\nProgram: " << program
             << "\nGPA: " << gpa << endl;
    }
    
    float calculatePayment() override { return 12000.0f; }
};

class GradeBook {
    vector<pair<string, float>> grades;
public:
    void addGrade(string id, float grade) {
        if(grade >= 0.0f && grade <= 100.0f)
            grades.emplace_back(id, grade);
    }
    
    void showResults() {
        float total = 0.0f;
        for(auto& [id, grade] : grades) total += grade;
        cout << "\nGrade Statistics:\nAverage: " << total/grades.size();
        
        auto max = *max_element(grades.begin(), grades.end(), 
            [](auto& a, auto& b) { return a.second < b.second; });
        cout << "\nHighest: " << max.second << " (ID: " << max.first << ")";
        
        cout << "\nNeeds Improvement:";
        for(auto& [id, grade] : grades)
            if(grade < 40.0f) cout << "\n- " << id << ": " << grade;
        cout << endl;
    }
};

class EnrollmentManager {
    vector<pair<string, string>> enrollments;
public:
    void enroll(string sId, string cCode) {
        enrollments.emplace_back(sId, cCode);
    }
    
    void showEnrollments() {
        cout << "\nCurrent Enrollments:";
        for(auto& [id, code] : enrollments)
            cout << "\nStudent " << id << " in " << code;
        cout << "\nTotal: " << enrollments.size() << endl;
    }
};

int main() {
    Student s1("Alex Johnson", 20, "S1001", "555-1234", 
              "2023-09-01", "Computer Science", 3.8f);
    Professor p1("Dr. Smith", 45, "P2001", "555-4321", 
                "CS", "AI", "2015-06-15");
    
    Course cs101("CS101", "Intro to Programming", 4, 
               "Basic programming concepts");
    Department csDept("Computer Science", "Building A", "10M");
    
    GradeBook grades;
    grades.addGrade("S1001", 88.5f);
    grades.addGrade("S1002", 35.0f);
    
    EnrollmentManager enrollments;
    enrollments.enroll("S1001", "CS101");
    enrollments.enroll("S1002", "CS101");

    cout << "=== University System Demo ===";
    s1.displayDetails();
    p1.displayDetails();
    cs101.course_details();
    csDept.department_details();
    grades.showResults();
    enrollments.showEnrollments();
    
    cout << "\nPayment Information:\nStudent: $" << s1.calculatePayment()
         << "\nProfessor: $" << p1.calculatePayment() << endl;

    return 0;
}