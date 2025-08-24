#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string* studentName;
    string* date;
    int score;

public:

    Exam(const string& name, const string& examDate, int s) : score(s) {
        studentName = new string(name);
        date = new string(examDate);
    }

    ~Exam() {
        delete studentName;
        delete date;
    }

    void setExamDetails(const string& name, const string& examDate, int s) {
        *studentName = name;
        *date = examDate;
        score = s;
    }

    void display() const {
        cout << "Student Name: " << *studentName << endl;
        cout << "Exam Date: " << *date << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam exam1("Alice", "2025-08-18", 95);
    cout << "Exam 1 details:" << endl;
    exam1.display();

    // shallow copy by default
    Exam exam2 = exam1;

    cout << "\nExam 2 details after shallow copy:" << endl;
    exam2.display();
    //This will also change exam1;
    exam2.setExamDetails("Bob", "2025-08-19", 88);

    cout << "\nAfter modifying exam2:" << endl;
    cout << "Exam 1 details:" << endl;
    exam1.display();  
    cout << "Exam 2 details:" << endl;
    exam2.display();

    return 0;
}
