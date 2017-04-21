#include "Square.h"
Square::Square(int width, int height) : m_width(width), m_height(height){
	m_X = m_Y = 0;
}
Square::Square(int X, int Y, int width, int height) : m_X(X), m_Y(Y), m_width(width), m_height(height){}
Square::Square(const Square& s){
	m_height = s.m_height;
	m_width = s.m_width;
	m_X = s.m_X;
	m_Y = s.m_Y;
}
int Square::GetWidth(){
	return m_width;
}
int Square::GetHeight(){
	return m_height;
}
int Square::GetX(){
	return m_X;
}
void Square::SetX(int X){
	m_X = X;
}
int Square::GetY(){
	return m_Y;
}
void Square::SetY(int Y){
	m_Y = Y;
}