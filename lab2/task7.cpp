#include <iostream>
using namespace std;

class Company {
private:
    int departments;           
    int *empCount;             
    int **salaries;            

public:
  
    Company(int d) {
        departments = d;
        empCount = new int[departments];   
        salaries = new int*[departments];  
    }

   
    void inputSalaries() {
        for (int i = 0; i < departments; i++) {
            cout << "Enter number of employees in department " << i + 1 << ": ";
            cin >> empCount[i];

            salaries[i] = new int[empCount[i]];  

            cout << "Enter salaries of employees in department " << i + 1 << ":\n";
            for (int j = 0; j < empCount[i]; j++) {
                cin >> salaries[i][j];
            }
        }
    }

    void highestSalaryPerDept() {
        cout << "\nHighest salary in each department:\n";
        for (int i = 0; i < departments; i++) {
            int maxSalary = INT_MIN;
            for (int j = 0; j < empCount[i]; j++) {
                if (salaries[i][j] > maxSalary) {
                    maxSalary = salaries[i][j];
                }
            }
            cout << "Department " << i + 1 << ": " << maxSalary << endl;
        }
    }

    void departmentWithMaxAvgSalary() {
        double maxAvg = -1;
        int deptIndex = -1;

        for (int i = 0; i < departments; i++) {
            int sum = 0;
            for (int j = 0; j < empCount[i]; j++) {
                sum += salaries[i][j];
            }
            double avg = (double)sum / empCount[i];
            if (avg > maxAvg) {
                maxAvg = avg;
                deptIndex = i;
            }
        }

        cout << "\nDepartment " << deptIndex + 1 
             << " has the maximum average salary: " << maxAvg << endl;
    }

    ~Company() {
        for (int i = 0; i < departments; i++) {
            delete[] salaries[i];   
        }
        delete[] salaries;   
        delete[] empCount;   
    }
};

int main() {
    int n;
    cout << "Enter number of departments: ";
    cin >> n;

    Company c(n);
    c.inputSalaries();
    c.highestSalaryPerDept();
    c.departmentWithMaxAvgSalary();

    return 0;
}
