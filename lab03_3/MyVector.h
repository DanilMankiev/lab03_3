#pragma once
class Rect;
#include"Shape.h"
class Vector : public Shape {
private:
	double x, y;	// ���������� ������� �� ���������
	friend class Rect;
public:
	//========== ��� ������������
	Vector(double c1, double c2);
	Vector();							// Default
	Vector(const Vector& tmp);

	//====== ��������������� �������� =====//
	Vector& operator= (const Vector& v);	// ����������
	Vector operator+(const Vector& v);
	Vector operator+(double d);
	double operator!();
	bool operator>(Vector& v);
	bool operator<(Vector& v);

	bool operator==(Vector& v);
	Vector operator*(double d);
	friend Vector operator*(double d, Vector& c);
	friend bool operator==(const Vector& v1, const Vector& v2);
	double operator*(Vector& v);

	virtual void Move(Vector& v);
	virtual double Area();
	virtual void Out();

};
bool operator==(const Vector& v1, Vector& v2);


