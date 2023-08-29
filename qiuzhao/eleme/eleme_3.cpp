/*
@File  :eleme_3.cpp
@Author:dfc
@Date  :2023/8/29  10:36
@Desc  :
*/
#include "iostream"
#include "vector"
#include "cmath"
#include<iomanip>
using namespace std;

long double compute_distance(long double x1, long double y1, long double x2, long double y2)
{
    long double distance =  sqrtl((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
    return distance;
}

int main()
{
    long double x0=0, y0=0, x1=0, y1=2, x2=2, y2=0;
    cin>>x2>>y2>>x1>>y1>>x0>>y0;
    long double d= 1;
    cin>>d;
    long double d_01 = compute_distance(x0, y0,x1,y1);
    if (d_01<=d)
    {
        cout<<0<<endl;
        return 0;
    }
    long double m = (y2 - y1) / (x2 - x1);
    long double b = y1 - m * x1;
    long double A = -m;
    long double B = 1;
    long double C = -b;

    long double distance_0_to_line = abs(A * x0 + B * y0 + C) / sqrtl(A*A + B*B);
    long double distance_1_to_2 = compute_distance(x1,y1, x2,y2);
    if (distance_0_to_line<=d)
    {
        cout<<setprecision(10)<<compute_distance(x1,y1, x2,y2) * 2<<endl;
        return 0;
    }
    long double distance_1_to_line = sqrtl(d_01 * d_01 - distance_0_to_line * distance_0_to_line);

    long double distance_2_to_line = distance_1_to_2 - distance_1_to_line;
    long double distance_qie_to_line = distance_0_to_line - d;

    long double distance_qie_to_1 = sqrtl(distance_qie_to_line *distance_qie_to_line
                                    + distance_1_to_line *distance_1_to_line);
    long double distance_qie_to_2 = sqrtl(distance_qie_to_line * distance_qie_to_line +
                                            distance_2_to_line * distance_2_to_line );
    cout<<setprecision(10)<<distance_1_to_2 + distance_qie_to_1 + distance_qie_to_2<<endl;
    return 0;
}

