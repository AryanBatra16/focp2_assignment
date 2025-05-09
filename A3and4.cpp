#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 100;
// PERSON CLASS AND CONSTUCTORS
class Person
{
    string per_name;
    int age;
    string id;
    string contact_info;

public:
    Person();
    Person(string per_name, int age, string id, string contact_info);
    // Getters
    string getName() { return per_name; }
    int getAge() { return age; }
    string getID() { return id; }
    string getContactInfo() { return contact_info; }

    // Setters with validation
    void setName(string name)
    {
        if (!name.empty())
            per_name = name;
    }
    void setAge(int a)
    {
        if (a > 0 && a < 120)
            age = a;
    }
    void setID(string i);
    void setContactInfo(int c);

    virtual void displayDetails()
    {
        cout << "Name : " << per_name << endl;
        cout << "Age : " << age << endl;
        cout << "ID : " << id << endl;
        cout << "Contact Info. : " << contact_info << endl;
    }
    virtual float calculatePayment() { return 0.0; }
};
Person::Person() : per_name(" "), age(0), id(" "), contact_info("0") {}

Person::Person(string per_name, int age, string id, string contact_info) : per_name(per_name), age(age), id(id), contact_info(contact_info) {}

// STUDENT CLASS AND CONSTRUCTORS AND GETTER
class Student : public Person
{
    string enroll_date;
    string program;
    float gpa;

public:
    static int stu_count;
    Student();
    Student(string per_name, int age, string id, string contact_info, string enroll_date, string program, float gpa);
    string getEnrollDate() { return enroll_date; }
    string getProgram() { return program; }
    float getGPA() { return gpa; }

    void setEnrollDate(string ed)
    {
        if (!ed.empty())
            enroll_date = ed;
    }
    void setProgram(string p)
    {
        if (!p.empty())
            program = p;
    }
    void setGPA(float g)
    {
        if (g >= 0.0 && g <= 4.0)
            gpa = g;
    }

    void displayDetails() override
    {
        Person::displayDetails();
        cout << "Enrollment Date : " << enroll_date << endl;
        cout << "Program : " << program << endl;
        cout << "GPA : " << gpa << endl;
    }
    float calculatePayment() override { return 10000.0f; }
};
int Student::stu_count = 0;

Student::Student() : Person(), enroll_date(""), program(""), gpa(0.0f) {}

Student::Student(string per_name, int age, string id, string contact_info, string enroll_date, string program, float gpa) : Person(per_name, age, id, contact_info), enroll_date(enroll_date), program(program), gpa(gpa) {}

class UndergraduateStudent : public Student
{
private:
    int major;
    int minor;
    int expectedGraduationDate;

public:
    UndergraduateStudent() : Student()
    {
        this->major = 0;
        this->minor = 0;
        this->expectedGraduationDate = 0;
    }

    UndergraduateStudent(string per_name, int age, string id, string contact_info, string enroll_date, string program, float gpa, int major, int minor, int expectedGraduationDate) : Student(per_name, age, id, contact_info, enroll_date, program, gpa)
    {
        this->major = major;
        this->minor = minor;
        this->expectedGraduationDate = expectedGraduationDate;
    }
    void setMajor(int m)
    {
        if (m >= 0)
            major = m;
    }
    void setMinor(int m)
    {
        if (m >= 0)
            minor = m;
    }
    void setExpectedGraduationDate(int e)
    {
        if (e > 0)
            expectedGraduationDate = e;
    }

    int getMajor() { return major; }
    int getMinor() { return minor; }
    int getExpectedGraduationDate() { return expectedGraduationDate; }

    void displayDetails() override
    {
        Student::displayDetails();
        cout << "Major : " << major << endl;
        cout << "Minor : " << minor << endl;
        cout << "Expected Graduation Date : " << expectedGraduationDate << endl;
    }
};
class GraduateStudent : public Student
{
private:
    string researchTopic;
    string advisor;
    string thesisTitle;

public:
    GraduateStudent() : Student()
    {
        this->researchTopic = "-";
        this->advisor = "-";
        this->thesisTitle = "-";
    }
    GraduateStudent(string per_name, int age, string id, string contact_info, string enroll_date, string program, float gpa, string reasearchTopic, string advisor, string thesisTitle) : Student(per_name, age, id, contact_info, enroll_date, program, gpa)
    {
        this->researchTopic = reasearchTopic;
        this->advisor = advisor;
        this->thesisTitle = thesisTitle;
    }
    void setresearchTopic(string r)
    {
        if (!r.empty())
            researchTopic = r;
    }
    void setadvisor(string a)
    {
        if (!a.empty())
            advisor = a;
    }
    void setthesisTitle(string t)
    {
        if (!t.empty())
            thesisTitle = t;
    }

    void displayDetails() override
    {
        Student::displayDetails();
        cout << "Research Topic : " << researchTopic << endl;
        cout << "Advisor " << advisor << endl;
        cout << "Thesis Title : " << thesisTitle << endl;
    }
};

// PROFESSOR CLASS AND CONSTRUCTORS AND GETTER
class Professor : public Person
{
    string dept_name;
    string specialization;
    string hire_date;

public:
    Professor();
    Professor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date);
    string getDeptName() { return dept_name; }
    string getSpecialization() { return specialization; }
    string getHireDate() { return hire_date; }

    void setDeptName(string d)
    {
        if (!d.empty())
            dept_name = d;
    }
    void setSpecialization(string s)
    {
        if (!s.empty())
            specialization = s;
    }
    void setHireDate(string h)
    {
        if (!h.empty())
            hire_date = h;
    }

    void displayDetails() override
    {
        Person::displayDetails();
        cout << "Department : " << dept_name << endl;
        cout << "Specialization : " << specialization << endl;
        cout << "Hire Date : " << hire_date << endl;
    }
    float calculatePayment() override { return 50000.0f; }
};
Professor::Professor() : Person(), dept_name(""), specialization(""), hire_date("") {}
Professor::Professor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date) : Person(per_name, age, id, contact_info), dept_name(dept_name), specialization(specialization), hire_date(hire_date) {}

// Assistant Professor class inheriting from Professor
class AssistantProfessor : public Professor
{
    int probation_years;
    string research_area;

public:
    AssistantProfessor();
    AssistantProfessor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date, int probation_years, string research_area);

    void displayDetails() override
    {
        Professor::displayDetails();
        cout << "Probation Years : " << probation_years << endl;
        cout << "Research Area : " << research_area << endl;
    }

    float calculatePayment() override
    {
        return Professor::calculatePayment() + 5000.0f; // small increment
    }
};

AssistantProfessor::AssistantProfessor() : Professor(), probation_years(0), research_area("") {}
AssistantProfessor::AssistantProfessor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date, int probation_years, string research_area) : Professor(per_name, age, id, contact_info, dept_name, specialization, hire_date), probation_years(probation_years), research_area(research_area) {}

// Associate Professor class inheriting from Professor
class AssociateProfessor : public Professor
{
    int publications;
    string domain;

public:
    AssociateProfessor();
    AssociateProfessor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date, int publications, string domain);

    void displayDetails() override
    {
        Professor::displayDetails();
        cout << "Publications : " << publications << endl;
        cout << "Domain : " << domain << endl;
    }

    float calculatePayment() override
    {
        return Professor::calculatePayment() + 10000.0f + (publications * 200);
    }
};

AssociateProfessor::AssociateProfessor() : Professor(), publications(0), domain("") {}
AssociateProfessor::AssociateProfessor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date, int publications, string domain) : Professor(per_name, age, id, contact_info, dept_name, specialization, hire_date), publications(publications), domain(domain) {}

// Full Professor class inheriting from Professor
class FullProfessor : public Professor
{
    int years_of_experience;
    float admin_allowance;

public:
    FullProfessor();
    FullProfessor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date, int years_of_experience, float admin_allowance);

    void displayDetails() override
    {
        Professor::displayDetails();
        cout << "Years of Experience : " << years_of_experience << endl;
        cout << "Admin Allowance : " << admin_allowance << endl;
    }

    float calculatePayment() override
    {
        return Professor::calculatePayment() + 20000.0f + admin_allowance;
    }
};

FullProfessor::FullProfessor() : Professor(), years_of_experience(0), admin_allowance(0.0f) {}
FullProfessor::FullProfessor(string per_name, int age, string id, string contact_info, string dept_name, string specialization, string hire_date, int years_of_experience, float admin_allowance) : Professor(per_name, age, id, contact_info, dept_name, specialization, hire_date), years_of_experience(years_of_experience), admin_allowance(admin_allowance) {}

// COURSE CLASS AND CONSTRUCTORS AND GETTER
class Course
{
    string code;
    string title;
    int credits;
    string description;

public:
    Course() : code(""), title(""), credits(0), description("") {}

    Course(string c, string t, int cr, string desc)
        : code(c), title(t), credits(cr), description(desc) {}

    void course_details()
    {
        cout << "Course code : " << code << endl;
        cout << "Course name : " << title << endl;
        cout << "Credits : " << credits << endl;
        cout << "Description : " << description << endl;
    }
};
// DEPARTMENT CLASS AND CONSTRUCTORS AND GETTER
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
        cout << "Department Name : " << dept_name << endl;
        cout << "Location : " << location << endl;
        cout << "Budget : " << budget << endl;
    }
};

class GradeBook : public Student
{
private:
    vector<string> studentIDs;
    vector<float> grades;

public:
    void addGrade(Student &s, float grade);

    float calculateAverageGrade()
    {
        if (grades.empty())
            return 0.0f;
        float total = 0.0f;
        for (float g : grades)
            total += g;
        return total / grades.size();
    }

    float getHighestGrade()
    {
        if (grades.empty())
            return 0.0f;
        return *max_element(grades.begin(), grades.end());
    }

    void getFailingStudents()
    {
        cout << "Failing Students (Grade < 40):" << endl;
        for (size_t i = 0; i < grades.size(); ++i)
        {
            if (grades[i] < 40.0f)
                cout << "Student ID: " << studentIDs[i] << ", Grade: " << grades[i] << endl;
        }
    }

    void displayDetails() override
    {
        cout << "GradeBook Details:" << endl;
        cout << "Total Students: " << studentIDs.size() << endl;
        cout << "Average Grade: " << calculateAverageGrade() << endl;
        cout << "Highest Grade: " << getHighestGrade() << endl;
        getFailingStudents();
    }
};

// ENROLLMENT MANAGER CLASS
class EnrollmentManager : public Student
{
private:
    vector<string> studentIDs;
    vector<string> courseCodes;

public:
    void enrollPerson(Student &s, const string &courseCode);

    void dropPerson(Student &s, const string &courseCode)
    {
        for (size_t i = 0; i < studentIDs.size(); ++i)
        {
            if (studentIDs[i] == s.getID() && courseCodes[i] == courseCode)
            {
                studentIDs.erase(studentIDs.begin() + i);
                courseCodes.erase(courseCodes.begin() + i);
                break;
            }
        }
    }

    int getEnrollmentCount(const string &courseCode)
    {
        int count = 0;
        for (const string &c : courseCodes)
        {
            if (c == courseCode)
                count++;
        }
        return count;
    }

    void displayDetails() override
    {
        cout << "Enrollment Details:" << endl;
        for (size_t i = 0; i < studentIDs.size(); ++i)
        {
            cout << "Student ID: " << studentIDs[i] << ", Course: " << courseCodes[i] << endl;
        }
        cout << "Total Enrollments: " << studentIDs.size() << endl;
    }
};
void UGstudentDeatils(string studentNumber)
{
    string per_name;
    int age;
    string id;
    string contact_info;
    string enroll_date;
    string program;
    float gpa;
    int major;
    int minor;
    int expectedGraduationDate;
    cout << "Undergraduate Student Details" << endl;
    cout << "Name : ";
    cin >> per_name;
    cout << "Age : ";
    cin >> age;
    cout << "ID : ";
    cin >> id;
    cout << "Contact Info : ";
    cin >> contact_info;
    cout << "Enrollment Date : ";
    cin >> enroll_date;
    cout << "Program : ";
    cin >> program;
    cout << "GPA : ";
    cin >> gpa;
    cout << "Major : ";
    cin >> major;
    cout << "Minor: ";
    cin >> minor;
    cout << "Expected Graduation Date";
    cin >> expectedGraduationDate;
    cout << endl;
    UndergraduateStudent student(per_name, age, id, contact_info, enroll_date, program, gpa, major, minor, expectedGraduationDate);
    student.displayDetails();
    GradeBook gb;
    gb.addGrade(student, gpa); // Adding grade to GradeBook
    EnrollmentManager em;
    em.enrollPerson(student, program); // Enrolling student in a course
    cout << endl;
}

void GstudentDeatils(string studentNumber)
{
    string per_name;
    int age;
    string id;
    string contact_info;
    string enroll_date;
    string program;
    float gpa;
    string researchTopic;
    string advisor;
    string thesisTitle;
    int expectedGraduationDate;
    cout << "Undergraduate Student Details" << endl;
    cout << "Name : ";
    cin >> per_name;
    cout << "Age : ";
    cin >> age;
    cout << "ID : ";
    cin >> id;
    cout << "Contact Info : ";
    cin >> contact_info;
    cout << "Enrollment Date : ";
    cin >> enroll_date;
    cout << "Program : ";
    cin >> program;
    cout << "GPA : ";
    cin >> gpa;
    cout << "Research Topic : ";
    cin >> researchTopic;
    cout << "Advisor : ";
    cin >> advisor;
    cout << "Thesis Tilte : ";
    cin >> thesisTitle;
    GraduateStudent student(per_name, age, id, contact_info, enroll_date, program, gpa, researchTopic, advisor, thesisTitle);
    student.displayDetails();
    cout << endl;
}

// Base exception class
class UniversitySystemException : public exception
{
protected:
    string message;

public:
    UniversitySystemException(const string &msg) : message(msg) {}
    virtual const char *what() const noexcept override
    {
        return message.c_str();
    }
};

// Enrollment-related exception
class EnrollmentException : public UniversitySystemException
{
public:
    EnrollmentException(const string &msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

// Grade-related exception
class GradeException : public UniversitySystemException
{
public:
    GradeException(const string &msg) : UniversitySystemException("Grade Error: " + msg) {}
};

// Payment-related exception
class PaymentException : public UniversitySystemException
{
public:
    PaymentException(const string &msg) : UniversitySystemException("Payment Error: " + msg) {}
};

// Other custom exceptions
class InvalidIDException : public UniversitySystemException
{
public:
    InvalidIDException(const string &msg) : UniversitySystemException("Invalid ID Error: " + msg) {}
};

class InvalidContactException : public UniversitySystemException
{
public:
    InvalidContactException(const string &msg) : UniversitySystemException("Invalid Contact Info Error: " + msg) {}
};
void EnrollmentManager::enrollPerson(Student &s, const string &courseCode)
{
    if (studentIDs.size() >= MAX)
    {
        throw EnrollmentException("Cannot enroll, course is full.");
    }
    studentIDs.push_back(s.getID());
    courseCodes.push_back(courseCode);
}
void GradeBook::addGrade(Student &s, float grade)
{
    if (grade < 0.0 || grade > 100.0)
    {
        throw GradeException("Invalid grade value.");
    }
    studentIDs.push_back(s.getID());
    grades.push_back(grade);
}
void Person::setID(string i)
{
    if (i.empty())
    {
        throw InvalidIDException("ID cannot be empty.");
    }
    id = i;
}

void Person::setContactInfo(int c)
{
    if (c <= 0)
    {
        throw InvalidContactException("Contact information must be a positive number.");
    }
    contact_info = to_string(c);
}
class UniversitySystem
{
private:
    vector<Department> departments;
    vector<Course> courses;
    vector<Student *> students;
    vector<Professor *> professors;

public:
    void addDepartment(const Department &dept)
    {
        departments.push_back(dept);
    }

    void addCourse(const Course &course)
    {
        courses.push_back(course);
    }

    void addStudent(Student *student)
    {
        students.push_back(student);
    }

    void addProfessor(Professor *professor)
    {
        professors.push_back(professor);
    }

    void generateReports()
    {
        // Logic to generate reports
    }
};

int main()
{
    UndergraduateStudent s1("Alex Johnson", 20, "S1001", "555-1234",
                            "2023-09-01", "Computer Science", 3.8f, 101, 201, 2025);
    FullProfessor p1("Dr. Smith", 45, "P2001", "555-4321",
                     "Computer Science", "Artificial Intelligence", "2015-06-15", 15, 5000.0f);

    Course cs101("CS101", "Intro to Programming", 4,
                 "Basic programming concepts");
    Department csDept("Computer Science", "Building A", "10M");

    GradeBook grades;
    grades.addGrade(s1, 88.5f);
    grades.addGrade(s1, 92.0f);

    EnrollmentManager enrollments;
    enrollments.enrollPerson(s1, "CS101");
    enrollments.enrollPerson(s1, "MATH101");

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
    grades.displayDetails();

    cout << "\n6. Enrollment Status\n";
    cout << "---------------------\n";
    enrollments.displayDetails();

    cout << "\n7. Financial Overview\n";
    cout << "----------------------\n";
    cout << "Student Fees\t: $" << s1.calculatePayment() << endl;
    cout << "Faculty Salary\t: $" << p1.calculatePayment() << endl;

    UniversitySystem us;
    try
    {
        us.addDepartment(csDept);
        us.addCourse(cs101);
        us.addStudent(new UndergraduateStudent(s1));
        us.addProfessor(new FullProfessor(p1));

        GraduateStudent gs("Emily Chen", 25, "S1002", "555-5678",
                           "2023-09-01", "Computer Engineering", 3.9f,
                           "Machine Learning", "Dr. Wilson", "Advanced AI Systems");
        us.addStudent(new GraduateStudent(gs));

        cout << "\n8. Graduate Student Profile\n";
        cout << "---------------------------\n";
        gs.displayDetails();
    }
    catch (const UniversitySystemException &e)
    {
        cerr << "System Error: " << e.what() << endl;
    }

    return 0;
}