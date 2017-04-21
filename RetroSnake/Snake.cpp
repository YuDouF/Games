#include "Snake.h"
#include "Square.h"
#include <iostream>
Snake::Snake(int x, int y, int length) : m_length(length), m_headY(y){
	m_headX = x > length ? x : length;
	if (m_headX < 0){
		m_headX = 0;
	}
	else if (m_headX > GAME_WIDTH){
		m_headX = GAME_WIDTH;
	}
	if (m_headY < 0){
		m_headY = 0;
	}
	else if (m_headY > GAME_HEIGHT){
		m_headY = GAME_HEIGHT;
	}
	for (int i = m_headX; i > m_headX - m_length; --i){
		Square* s = new Square(i, m_headY, 1, 0);
		m_sList.push_back(s);	
	}
	m_headDirect = RIGHT;
	m_tailDirect = RIGHT;
}
int Snake::GetHeadX(){
	return m_headX;
}
int Snake::GetHeadY(){
	return m_headY;
}
void Snake::SetHeadDirecte(Directe directe){
	m_headDirect = directe;
}
Directe Snake::GetHeadDirecte(){
	return m_headDirect;
}
Directe Snake::GetTailDirecte(){
	Square* last = m_sList.back();
	Square* l = m_sList.at(m_sList.size() - 2);
	if (l->GetX() == last->GetX()){
		if (l->GetY() > last->GetY()){
			return Directe(DOWN);
		}
		else{
			return Directe(UP);
		}
	}
	else{
		if (l->GetX() > last->GetX()){
			return Directe(RIGHT);
		}
		else{
			return Directe(LEFT);
		}
	}
}
void Snake::AddSquareToTail(){
	Square* last = m_sList.back();
	Square* l = m_sList.at(m_sList.size() - 2);
	int x, y;
	if (l->GetX() == last->GetX()){
		if (m_headDirect == UP){
			x = last->GetX();
			y = last->GetY() + 1;
		}
		else{
			x = last->GetX();
			y = last->GetY() - 1;
		}
	}
	else{
		if (m_headDirect == RIGHT){
			x = last->GetX() - 1;
			y = last->GetY();
		}
		else{
			x = last->GetX() + 1;
			y = last->GetY();		
		}
	}
	m_sList.push_back(new Square(x, y, 1, 0));
	m_length++;
}
void Snake::Move(){
	m_tailDirect = GetTailDirecte();
	Square *head = m_sList.front();
	Square *tail = m_sList.back();
	int x = 0;
	int y = 0;
	switch (m_headDirect){
	case UP:{
				x = head->GetX();
				y = head->GetY() - 1;
				m_headY -= 1;
				break;
	}
	case RIGHT:{
				   x = head->GetX() + 1;
				   y = head->GetY();
				   m_headX += 1;
				   break;
	}
	case DOWN:{
				  x = head->GetX();
				  y = head->GetY() + 1;
				  m_headY += 1;
				  break;
	}
	case LEFT:{
				  x = head->GetX() - 1 < 0 ? 0 : head->GetX() - 1;
				  y = head->GetY();
				  m_headX -= 1;
				  break;
	}
	}
	tail->SetX(x);
	tail->SetY(y);
	m_sList.push_front(tail);
	m_sList.pop_back();
}
std::deque<Square*>& Snake::GetList(){
	return m_sList;
}

void Snake::GetRange(int& leftX, int& rightX, int& topY, int& bottomY){
	leftX = GAME_WIDTH;
	topY = GAME_HEIGHT;
	rightX = bottomY = 0;
	for (std::deque<Square*>::iterator it = m_sList.begin(); it != m_sList.end();  ++it){
		int x = (*it)->GetX();
		int y = (*it)->GetY();
		if (leftX >= x){
			leftX = x;
		}
		if (rightX <= x){
			rightX = x;
		}
		if (topY >= y){
			topY = y;
		}
		if (bottomY <= y){
			bottomY = y;
		}
	}
}
void Snake::Clean(){
	Square *tail = m_sList.back();
	int x, y;
	switch (m_tailDirect){
	case UP:
		x = tail->GetX();
		y = tail->GetY() + 1;
		break;
	case RIGHT:
		x = tail->GetX() - 1; 
		y = tail->GetY();
		break;
	case DOWN:
		x = tail->GetX(); 
		y = tail->GetY() - 1;
		break;
	case LEFT:
		x = tail->GetX() + 1;
		y = tail->GetY();
		break;
	}
	CursorToPos(x, y);
	std::cout << " ";
}
bool Snake::IsCrash(){
	for (std::deque<Square*>::iterator it = m_sList.begin() + 1; it != m_sList.end(); ++it){
		if ((*it)->GetX() == m_headX && (*it)->GetY() == m_headY){
			return true;
		}
	}
	return false;
}
void Snake::Display(){
	Square* head = m_sList.front();
	CursorToPos(head->GetX(), head->GetY());
	std::cout << "*";
}
