#include <time.h>
#include <GL/glut.h> 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include "SOIL.h"
#pragma once

#define rad(x) (PI*(x))/180.0
#define PI 3.1415926535898

using namespace std;

class Point {
private:
public:
	int x, y, z;
	Point(){};
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class Grid {
private:
public:
	Point a, b, c;
	Grid(Point a, Point b, Point c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

class Object {
private:
public:
	Object() {};
	~Object() {};
	virtual void Draw()=0;
};

class Cube : public Object {
private:
public:
	Cube() {};
	~Cube() {};
	void Draw();
};

class Cone : public Object {
private:
public:
	Cone() {};
	~Cone() {};
	void Draw();
};

class Circle : public Object {
private:
public:
	Circle() {};
	~Circle() {};
	void Draw();
};

class Sphere : public Object {
private:
public:
	Sphere() {};
	~Sphere() {};
	void Draw();
};

class Torus : public Object {
private:
public:
	Torus() {};
	~Torus() {};
	void Draw();
};

class Cylinder : public Object {
private:
public:
	Cylinder() {};
	~Cylinder() {};
	void Draw();
};

class Paraboloid : public Object {
private:
public:
	Paraboloid() {};
	~Paraboloid() {};
	void Draw();
};

class Hyperboloid : public Object {
private:
public:
	Hyperboloid() {};
	~Hyperboloid() {};
	void Draw();
};

