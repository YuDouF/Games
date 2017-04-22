#include "Point.h"
Point::Point(int x, int y) : m_x(x), m_y(y){
}
Point::~Point(){
}
void Point::SetX(int x){
	m_x = x;
}
int Point::GetX(){
	return m_x;
}
void Point::SetY(int y){
	m_y = y;
}
int Point::GetY(){
	return m_y;
}