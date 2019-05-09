#pragma once
#include "CombatAction.hpp"
#include "Poison.hpp"
#include "Cripple.hpp"
#include "FlatDmg.hpp"

class HiddenDagger :public CombatAction {
public:
	HiddenDagger(int x, int y, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer);
	~HiddenDagger();

	void applyEffects(MoB* applicant) override;
	void addEffects() override;
};