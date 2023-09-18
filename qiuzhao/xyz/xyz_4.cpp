/*
@File  :xyz_4.cpp
@Author:dfc
@Date  :2023/9/3  22:43
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

std::vector<Vector> interpolate(const std::vector<Vector>& points, const std::vector<double>& samples)
{
    vector<double> length;
    int length=(int)points.size();
    Vector my_v;
    int maxLength=0;
    for(int i=1;i<length;i++){
        my_v=points[i]-points[i-1];
        length.push_back(my_v.norm());
        maxLength+=my_v.norm();
    }
    std::vector<Vector> res;
    for(double s:samples){
        if(s<0) {
            res.push_back(points[0]);
            std::cout<<points[0]<<std::endl;
            continue;
        }
        else if(s>maxLength){
            res.push_back(points[length-1]);
            std::cout<<points[length    -1]<<std::endl;
            continue;
        }
        else{
            for(int i=1;i<length;i++){
                if(s<=length[i-1]){//该点位于i i+1两点之间
                    Vector cur=points[i-1]+(points[i]-points[i-1])*(s/length[i-1]);
                    res.push_back(cur);
                    std::cout<<cur<<std::endl;
                    break;
                }
                else{
                    s-=length[i-1];
                }
            }
        }
    }
    return res;
}

