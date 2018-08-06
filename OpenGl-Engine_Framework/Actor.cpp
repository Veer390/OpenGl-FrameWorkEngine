#include "Actor.h"

void Actor::SetAnimationPlayRate(int PRate)
{
	PlayRate = PRate;
}

void Actor::SetAnimations(std::vector<Animation> Animations)
{
	Animations_Actor = Animations;
}

void Actor::SetAnimations_Append(std::vector<Animation> Animations)
{
	for (auto i : Animations)
	{
		Animations_Actor.push_back(i);
	}
}

void Actor::SetAnimation(Animation NewAnimation)
{
	Animations_Actor.push_back(NewAnimation);
}

std::vector<std::string> Actor::GetAnimationsAssociatedWithActor()
{
	std::vector<std::string> Temp;
	for (auto i : Animations_Actor)
	{
		Temp.push_back(i.GetName());
	}
	return Temp;
}
