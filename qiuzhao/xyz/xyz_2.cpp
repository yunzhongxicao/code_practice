/*
@File  :xyz_2.cpp
@Author:dfc
@Date  :2023/9/3  21:12
@Desc  :
*/
// 可以引入的库和版本相关请参考 “环境说明”

#include <iostream>
#include <ostream>
#include <numeric>
#include <cmath>

// Functions you may find helpful
// - sqrt()

// A 3-D vector.
struct Vector3
{
    Vector3() : x(0), y(0), z(0)
    {}
    Vector3(double x_, double y_, double z_) :
            x(x_), y(y_), z(z_)
    {}

    // subtraction operator
    Vector3 operator-(const Vector3& rhs) const
    {
        return Vector3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
    }

    // plus operator
    Vector3 operator+(const Vector3& rhs) const
    {
        return Vector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
    }

    Vector3 Normalize()
    {
        double dis = sqrt(x*x + y*y +  z*z);
        return Vector3(this->x/dis, this->y/dis, this->z/dis);
    }

    // Dot product between two vectors.
    double operator*(const Vector3& rhs) const
    {
        return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
    }



    // print the vector.
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
    {
        os << "x: " << v.x << " y: " << v.y << " z: " << v.z << std::endl;
        return os;
    }
    double x, y, z;
};

// A ray is constructed from its origin and a direction.
struct Ray
{
    Ray(const Vector3& origin_, const Vector3& direction_)
            : origin(origin_),
              direction(direction_)
    {
        direction = direction.Normalize();
    }

    Vector3 origin, direction;

private:
    Ray()
    {}
};

// A sphere is constructed from "center" and "radius", where center is a 3-D vector,
// representing the center of the sphere.
struct Sphere
{
    Sphere(const Vector3& center_, double radius_)
            : center(center_),
              radius(radius_)
    {}

    Vector3 center;
    double radius;

private:
    Sphere()
    {}
};



// You are asked to implement the function ray_sphere_intersect:
// The function should return True if ray and sphere intersect, and set the distance accordingly, return false if ray and sphere do not intersect.
bool ray_sphere_intersect(const Ray& ray, const Sphere& sphere, double& distance)
{

    Vector3 oc = ray.origin - sphere.center;
    double a = ray.direction * ray.direction;
    double b = ray.direction * oc;
    double c = oc * oc - sphere.radius * sphere.radius;
    double disc = b * b - a * c;
    if (disc<0)
        return false;
    distance =  ( - b - sqrt(disc)) / a;
    return true;
}



