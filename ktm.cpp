#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);

class KTM
{
private:
    double stroke, crank_radius, connecting_rod_length, crank_angle, rpm, angular_velocity, n, v_piston, a_piston, w_connecting_rod, a_connecting_rod;

    double get_piston_velocity(double angular_velocity, double crank_radius, double crank_angle, double n)
    {
        double v_piston = angular_velocity * crank_radius * (sin((crank_angle * pi) / 180) + (sin((2 * crank_angle * pi) / 180) / (2 * n)));
        return v_piston;
    }

    double get_piston_acceleration(double angular_velocity, double crank_radius, double crank_angle, double n)
    {
        double a_piston = pow(angular_velocity, 2) * crank_radius * (cos((crank_angle * pi) / 180) + (cos((2 * crank_angle * pi) / 180) / (n)));
        return a_piston;
    }

    double get_angular_velocity_crod(double angular_velocity, double crank_angle, double n)
    {
        double w_connecting_rod = (angular_velocity * cos((crank_angle * pi) / 180)) / n;
        return w_connecting_rod;
    }

    double get_angular_acceleration_crod(double angular_velocity, double crank_angle, double n)
    {
        double a_connecting_rod = -(pow(angular_velocity, 2) * sin((crank_angle * pi) / 180)) / n;
        return a_connecting_rod;
    }

public:
    void solve()
    {

        cout << "INPUT THE FOLLOWING PARAMETERS." << endl
             << endl;
        cout << "1. Steam engine's stroke (m)." << endl;
        cin >> stroke;
        crank_radius = stroke / 2;
        cout << "2. Length of connecting rod (m)." << endl;
        cin >> connecting_rod_length;
        n = connecting_rod_length / crank_radius;
        cout << "3. Angle made by crank (deg)." << endl;
        cin >> crank_angle;
        cout << "3. Crank speed (rpm)." << endl;
        cin >> rpm;
        angular_velocity = (2 * pi * rpm) / 60;

        v_piston = get_piston_velocity(angular_velocity, crank_radius, crank_angle, n);
        a_piston = get_piston_acceleration(angular_velocity, crank_radius, crank_angle, n);
        w_connecting_rod = get_angular_velocity_crod(angular_velocity, crank_angle, n);
        a_connecting_rod = get_angular_acceleration_crod(angular_velocity, crank_angle, n);

        cout << endl;
        cout << "The following parameters are obtained." << endl;
        cout << "1. Velocity of piston = " << v_piston << " m/s" << endl;
        cout << "2. Acceleration of piston = " << a_piston << " m/s2" << endl;
        cout << "3. Angular velocity of connecting rod = " << w_connecting_rod << " rad/s" << endl;
        cout << "4. Angular acceleration of connecting rod = " << a_connecting_rod << " rad/s2" << endl;
        cout << endl;
    }
};

int main()
{
    system("cls");
    KTM solution;
    solution.solve();

    return 0;
}