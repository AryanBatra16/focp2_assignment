#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Course
{
    string code;
    string title;
    int credits;
    string description;

public:
    Course() : code(""), title(""), credits(0), description("") {}
    Course(string c, string t, int cr, string d)
        : code(c), title(t), credits(cr), description(d) {}

    void course_details()
    {
        cout << "Course Code: " << code << "\nTitle: " << title
             << "\nCredits: " << credits << "\nDescription: " << description << endl;
    }
};

class Department
{
    string dept_name;
    string location;
    string budget;

public:
    Department() : dept_name(""), location(""), budget("") {}
    Department(string d, string l, string b)
        : dept_name(d), location(l), budget(b) {}

    void department_details()
    {
        cout << "Department: " << dept_name << "\nLocation: " << location
             << "\nBudget: " << budget << endl;
    }
};

class Person
{
protected:
    string per_name;
    int age;
    string id;
    string contact_info;

public:
    Person() : per_name(""), age(0), id(""), contact_info("") {}
    Person(string n, int a, string i, string c)
        : per_name(n), age(a), id(i), contact_info(c) {}

    virtual void displayDetails()
    {
        cout << "\nPersonal Details:\nName: " << per_name
             << "\nAge: " << age << "\nID: " << id
             << "\nContact: " << contact_info << endl;
    }

    virtual float calculatePayment() { return 0.0f; }

    void setContactInfo(string c)
    {
        if (!c.empty())
            contact_info = c;
    }

    void setAge(int a)
    {
        if (a > 0)
            age = a;
    }
};

class Professor : public Person
{
    string department;
    string specialization;
    string hire_date;

public:
    Professor() : Person(), department(""), specialization(""), hire_date("") {}
    Professor(string n, int a, string i, string c, string d, string s, string h)
        : Person(n, a, i, c), department(d), specialization(s), hire_date(h) {}

    void displayDetails() override
    {
        Person::displayDetails();
        cout << "Department: " << department << "\nSpecialization: " << specialization
             << "\nHire Date: " << hire_date << endl;
    }

    float calculatePayment() override { return 85000.0f; }
};

class Student : public Person
{
    string enroll_date;
    string program;
    float gpa;

public:
    Student() : Person(), enroll_date(""), program(""), gpa(0.0f) {}
    Student(string n, int a, string i, string c, string e, string p, float g)
        : Person(n, a, i, c), enroll_date(e), program(p), gpa(g) {}

    void displayDetails() override
    {
        Person::displayDetails();
        cout << "Enrollment: " << enroll_date << "\nProgram: " << program
             << "\nGPA: " << gpa << endl;
    }

    float calculatePayment() override { return 12000.0f; }
};

class GradeBook
{
    vector<pair<string, float>> grades;

public:
    void addGrade(string id, float grade)
    {
        if (grade >= 0.0f && grade <= 100.0f)
            grades.push_back(make_pair(id, grade));
    }

    void showResults()
    {
        if (grades.empty())
        {
            cout << "\nNo grades available\n";
            return;
        }

        float total = 0.0f;
        for (auto &entry : grades)
            total += entry.second;
        cout << "\nGrade Statistics:\nAverage: " << total / grades.size();

        auto max = *max_element(grades.begin(), grades.end(),
                                [](const pair<string, float> &a, const pair<string, float> &b)
                                {
                                    return a.second < b.second;
                                });
        cout << "\nHighest: " << max.second << " (ID: " << max.first << ")";

        cout << "\nNeeds Improvement:";
        for (auto &entry : grades)
            if (entry.second < 40.0f)
                cout << "\n- " << entry.first << ": " << entry.second;
        cout << endl;
    }
};

class EnrollmentManager
{
    vector<pair<string, string>> enrollments;

public:
    void enroll(string sId, string cCode)
    {
        enrollments.push_back(make_pair(sId, cCode));
    }

    void showEnrollments()
    {
        cout << "\nCurrent Enrollments:";
        for (auto &entry : enrollments)
            cout << "\nStudent " << entry.first << " in " << entry.second;
        cout << "\nTotal: " << enrollments.size() << endl;
    }
};

int main()
{
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

    cout << "University Management System Report\n";
    cout << "===================================\n\n";

    cout << "1. Student Profile\n";
    cout << "-------------------\n";
    s1.displayDetails();

    cout << "\n2. Faculty Profile\n";
    cout << "-------------------\n";
    p1.displayDetails();

    cout << "\n3. Course Information\n";
    cout << "----------------------\n";
    cs101.course_details();

    cout << "\n4. Department Overview\n";
    cout << "-----------------------\n";
    csDept.department_details();

    cout << "\n5. Academic Performance\n";
    cout << "------------------------\n";
    grades.showResults();

    cout << "\n6. Enrollment Status\n";
    cout << "---------------------\n";
    enrollments.showEnrollments();

    cout << "\n7. Financial Overview\n";
    cout << "----------------------\n";
    cout << "Student Fees\t: $" << s1.calculatePayment() << endl;
    cout << "Faculty Salary\t: $" << p1.calculatePayment() << endl;

    return 0;
}