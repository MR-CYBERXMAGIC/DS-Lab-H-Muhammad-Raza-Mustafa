#include <iostream>
using namespace std;

int main() {
    int students;

    cout << "Enter number of students: ";
    cin >> students;

    // Create jagged array (array of int pointers)
    int** marks = new int*[students];
    // This help us in safe traversal 
    int* courseCount = new int[students]; 

    
    for (int i = 0; i < students; i++) {
        cout << "Enter number of courses for student " << i + 1 << ": ";
        cin >> courseCount[i];
        marks[i] = new int[courseCount[i]];
    }

    for (int i = 0; i < students; i++) {
        cout << "\nEnter marks for Student " << i + 1 << " (" 
             << courseCount[i] << " courses):\n";
        for (int j = 0; j < courseCount[i]; j++) {
            cout << "  Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\nAverage Marks of Students:\n";
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < courseCount[i]; j++) {
            sum += marks[i][j];
        }
        double avg = (double)sum / courseCount[i];
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    
    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courseCount;

    return 0;
}
