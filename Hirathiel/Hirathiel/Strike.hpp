#pragma once
#include "CombatAction.hpp"
#include "FlatDmg.hpp"
#include "Bleed.hpp"
#include "Knockback.hpp"

class Strike :public CombatAction {
public:
	Strike(int x, int y, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer,int critchance,float crit,int xpos,int ypos);
	~Strike();

	void applyEffects(MoB* applicant) override;
	void addEffects() override;

private:
	int xpos,ypos;
};