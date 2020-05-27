#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){

    static double ASpeed = 0.5;
    static double BSpeed = 6.0;

    double  A, B, H, M;
    cin >> A >> B >> H >> M;

    double angle = (BSpeed - ASpeed) * (60 * H + M);

    double length = sqrt(A * A + B * B - 2 * A * B * cos(2 * M_PI * angle / 360));

    cout << fixed << setprecision(20) << length << endl;
}