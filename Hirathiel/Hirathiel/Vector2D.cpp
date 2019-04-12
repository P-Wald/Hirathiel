#include "Vector2D.hpp"

Vector2D::Vector2D(float x,float y):x(x),y(y) {

}

void Vector2D::addVector(Vector2D* vector) {
	this->x += vector->x;
	this->y += vector->y;
}

void Vector2D::subVector(Vector2D* vector) {
	this->addVector(new Vector2D(-vector->getX(),-vector->getY()));
}

