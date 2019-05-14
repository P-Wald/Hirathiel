#pragma once
#include "CombatAction.hpp"
#include "FlatDmg.hpp"
#include "Bleed.hpp"
#include "Knockback.hpp"
#include "MoBMetaData.hpp"

class Strike :public CombatAction {
public:
	Strike(MoBMetaData data, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer,int xpos,int ypos);
	~Strike();

	void applyEffects(MoB* applicant) override;
	void addEffects() override;
	void settarget(int x, int y);

private:
	int targetx, targety;
	int xpos,ypos;
};