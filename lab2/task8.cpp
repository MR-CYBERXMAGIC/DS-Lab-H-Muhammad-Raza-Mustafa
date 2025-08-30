#include <iostream>
using namespace std;

class Temperature {
private:
    int days, times;
    float **readings; 

public:
   
    Temperature(int d, int t) : days(d), times(t) {
        readings = new float*[days];
        for (int i = 0; i < days; i++) {
            readings[i] = new float[times];
        }
    }

    void inputReadings() {
        cout << "\nEnter temperature readings:\n";
        for (int i = 0; i < days; i++) {
            cout << "\nDay " << i + 1 << ":\n";
            for (int j = 0; j < times; j++) {
                cout << "  Time " << j + 1 << ": ";
                cin >> readings[i][j];
            }
        }
    }

    void dailyAverage() {
        cout << "\nDaily Average Temperatures:\n";
        for (int i = 0; i < days; i++) {
            float sum = 0;
            for (int j = 0; j < times; j++) {
                sum += readings[i][j];
            }
            float avg = sum / times;
            cout << "  Day " << i + 1 << ": " << avg << " C\n";
        }
    }

    void findHottestColdestDay() {
        int hottestDay = -1, coldestDay = -1;
        float maxAvg = INT_MIN;
        float minAvg = INT_MAX;

        for (int i = 0; i < days; i++) {
            float sum = 0;
            for (int j = 0; j < times; j++) {
                sum += readings[i][j];
            }
            float avg = sum / times;

            if (avg > maxAvg) {
                maxAvg = avg;
                hottestDay = i;
            }
            if (avg < minAvg) {
                minAvg = avg;
                coldestDay = i;
            }
        }

        cout << "\nHottest Day: Day " << hottestDay + 1 << " with average " << maxAvg << " C";
        cout << "\nColdest Day: Day " << coldestDay + 1 << " with average " << minAvg << " C\n";
    }

    ~Temperature() {
        for (int i = 0; i < days; i++) {
            delete[] readings[i];
        }
        delete[] readings;
    }
};

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of times per day: ";
    cin >> m;

    Temperature city(n, m);
    city.inputReadings();
    city.dailyAverage();
    city.findHottestColdestDay();

    return 0;
}
