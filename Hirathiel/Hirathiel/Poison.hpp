#include "Effect.hpp"

class Poison :public Effect {
public:
	Poison(int time);
	~Poison();
	void copy(Effect* effect);
	void apply(MoB* applicant);

private:
	int dmg;
	CTimer* poisonTimer;
};