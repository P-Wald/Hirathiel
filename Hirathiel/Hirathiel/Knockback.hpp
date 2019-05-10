#pragma once
#include "Effect.hpp"
#include "Vector2D.hpp"

class Knockback :public Effect {
public:
	Knockback(int distance, int xorig, int yorig);
	~Knockback();
	int getDistance() { return this->distance; };
	int getx() { return this->xorig; };
	int gety() { return this->yorig; };
	void apply(MoB* applicant) override;
	void copy(Effect* effect);

private:
	bool firstick = true;
	int speed;
	int xorig;
	int yorig;
	int distance;
	CTimer* timer;
	Vector2D* knockback;

};