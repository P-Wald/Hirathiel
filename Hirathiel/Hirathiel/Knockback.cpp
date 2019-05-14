#include "Knockback.hpp"
#include <math.h>
#include "MoB.hpp"

Knockback::Knockback(int distance,int xorig,int yorig):Effect((0.3),(1)){
	this->next = nullptr;
	this->prev = nullptr;
	this->distance = distance;
	this->timer = new CTimer();
	this->timer->update();
	this->knockback = nullptr;
	this->xorig = xorig;
	this->yorig = yorig;
}

Knockback::~Knockback() {
	delete this->timer;
	delete this->knockback;
}

void Knockback::copy(Effect* effect) {
	Knockback* copy = dynamic_cast<Knockback*>(effect);
	if (copy) {
		this->xorig = copy->getx();
		this->yorig = copy->gety();
		this->distance = copy->getDistance();
	}
	copy = nullptr; delete copy;
	this->next = nullptr;
	this->prev = nullptr;
}

void Knockback::apply(Object* applicant) {
	MoB* applicantcpy = dynamic_cast<MoB*>(applicant);
	if (this->firstick) {
		this->speed = applicantcpy->getSpeed();
		applicantcpy->setSpeed(0);
		this->firstick = false;
	}
	if (!knockback) {
		float xVec = applicant->getX()- this->xorig;
		float yVec = applicant->getY() - this->yorig;
		this->knockback = new Vector2D(xVec, yVec);
		float xVecPos = xVec;
		float yVecPos = yVec;
		if (xVec < 0) { xVecPos *= -1; }
		if (yVec < 0) { yVecPos *= -1; }
		float length = sqrt((xVecPos*xVecPos)+(yVecPos*yVecPos));
		float trim;

		if (distance > 0) {
			trim = this->distance/length;
		}
		else {
			trim = 1;
		}

		this->knockback->scalar(trim);
	}


	if (this->timing <= 0) {
		this->ticks--;
		applicantcpy->setSpeed(applicantcpy->getSpeed() + this->speed);
	}

	Vector2D* moveVec = new Vector2D(this->knockback->getX(),this->knockback->getY());
	moveVec->scalar(this->timer->getElapsed()*3);
	applicantcpy->move(moveVec);

	
	this->timing -= this->timer->getElapsed();
	this->timer->update();
	applicantcpy = nullptr; delete applicantcpy;
}
