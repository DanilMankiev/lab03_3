#pragma once
#include"stdafx.h"
class Vector;
class Shape {
	static int count;
	static list<Shape*> shapes;
public:
	Shape();
	~Shape();

	virtual void Move(Vector& v) = 0;
	virtual void Out() = 0;
	virtual double Area() = 0;

	static int GetCount();
	static list<Shape*>& GetShapes();
	static void PrintCount();
};