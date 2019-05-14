#pragma once
class MoBMetaData {
public:
	MoBMetaData(int x, int y, int w, int h, int critchance, float critMultiplier);
	~MoBMetaData();
	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; };
	void setW(int w) { this->w = w; };
	void setH(int h) { this->h = h; };
	void setCritChance(int critchance) { this->critchance = critchance; };
	void setCritMultiplier(float critMultiplier) { this->critMultiplier = critMultiplier; };

	int getX() { return this->x; };
	int getY() { return this->y; };
	int getW() { return this->w; };
	int getH() { return this->h; };
	int getCritChance() { return this->critchance; };
	float getCritMultiplier() { return this->critMultiplier; };

private:
	int x, y, w, h, critchance;
	float critMultiplier;
};