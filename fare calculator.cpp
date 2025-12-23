#include <iostream>
#include <fstream>
using namespace std;
class Taxi {
private:
    float distance;
    float fare;
public:
    Taxi(float d = 0) {
        distance = d;
        fare = distance * 15;
    }
    Taxi operator + (Taxi t) {
        Taxi temp;
        temp.distance = distance + t.distance;
        temp.fare = fare + t.fare;
        return temp;
    }
    void logFare() {
        ofstream file("farelog.txt", ios::app);
        file << "Distance: " << distance
             << " km | Fare: " << fare << " Rs" << endl;
        file.close();
    }
    void display() {
        cout << "Total Distance: " << distance << " km" << endl;
        cout << "Total Fare: " << fare << " Rs" << endl;
    }
};
int main() {
    float d1, d2;
	cout << "Enter distance 1 (km): ";
    cin >> d1;
	cout << "Enter distance 2 (km): ";
    cin >> d2;
	Taxi t1(d1), t2(d2);
    Taxi total = t1 + t2;
	total.display();
    total.logFare();
	cout << "Fare logged successfully!" << endl;
	return 0;
}
