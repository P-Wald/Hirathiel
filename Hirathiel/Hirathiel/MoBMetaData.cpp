#include "MoBMetaData.hpp"

MoBMetaData::MoBMetaData(int x, int y, int w, int h, int critchance, float critMultiplier){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->critchance = critchance;
	this->critMultiplier = critMultiplier;
}

MoBMetaData::~MoBMetaData() {
};