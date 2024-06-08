#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y, N;
    cout << "Write your curent location via x, y coordinates. Also write the radius of the artifact zone.\n"
            " Separate said values either by pressing enter or spacebar.\n";
    cin >> x >> y >> N;
    double distanceFromEchoToCenter = sqrt(x*x + y*y);
    if(distanceFromEchoToCenter > N){
        cout << "Echo detector isn't reacting";
    } else {
        double proximityPercentage = (N / distanceFromEchoToCenter) * 100;
        if(proximityPercentage <= 20.0){
            cout << "Detector beeps lazily.";
        } else if(proximityPercentage>20.0 && proximityPercentage <= 50.0) {
            cout << "Detector is beeping with a second interval.";
        } else if(proximityPercentage>50.0 && proximityPercentage <= 90.0) {
            cout << "Detector is beeping quite fast!";
        } else {
            cout << "You are close! Detector is going crazy!";
        }
    }
    cout << endl;
    system("pause");
}
