#pragma once

class Resolution {
public:
	Resolution(int w, int h) { this->w = w; this->h = h; };
	int getW() { return this->w; };
	int getH() { return this->h; };

private:
	int w, h;
};