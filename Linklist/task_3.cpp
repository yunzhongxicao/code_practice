/*
@File  :task_3.cpp
@Author:dfc
@Date  :2023/2/12  15:38
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

bool PointinTriangle(vector<int>A, vector<int>B, vector<int>C, vector<int> P)
{
    // Vector3 v0 = C - A ;
    // Vector3 v1 = B - A ;
    // Vector3 v2 = P - A ;

    vector<int>v0 = {C[0]-A[0],C[1]-A[1]};
    vector<int>v1 = {B[0]-A[0],B[1]-A[1]};
    vector<int>v2 = {P[0]-A[0],P[1]-A[1]};


    float dot00 = v0[0] * v0[0]  + v0[1] * v0[1] ;
    float dot01 = v0[0] * v1[0] + v0[1] * v1[1] ;
    float dot02 = v0[0] * v2[0] + v0[1] * v2[1] ;
    float dot11 = v1[0] * v1[0] + v1[1] * v1[1] ;
    float dot12 = v1[0] * v2[0] + v1[1] * v2[1] ;

    float inverDeno = 1 / (dot00 * dot11 - dot01 * dot01) ;

    float u = (dot11 * dot02 - dot01 * dot12) * inverDeno ;
    if (u < 0 || u > 1) // if u out of range, return directly
    {
        return false ;
    }

    float v = (dot00 * dot12 - dot01 * dot02) * inverDeno ;
    if (v < 0 || v > 1) // if v out of range, return directly
    {
        return false ;
    }

    return u + v <= 1 ;
}

vector<int> solution(vector<int> &X, vector<int> &Y)
{
    vector<int> result;
    if (X.size()<3) return result;
    for (int i = 0; i < X.size(); ++i) {
        for (int j = i+1; j < X.size(); ++j) {
            for (int k = k+1; k <X.size() ; ++k) {
                double slope1 = double   (Y[i]-Y[j]) / (X[i] - X[j]);
                double slope2 = double   (Y[i]-Y[k]) / (X[i] - X[k]);
                if (slope1==slope2  )  continue;

            }
        }
    }
}