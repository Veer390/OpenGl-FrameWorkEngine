#pragma once
/*Actor Is The Basic Class That Can Always Be Drawn On The Screen Any Class Which Wishes To Be Drwn On The Screen Must Be Inherited FRom THe Actor Class*/
//Note - Actor Does Not Contain Input Class For It To Recieve Input...

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Logger.h"
#include "Texture.h"
#include "rectangle.h"
#include "Animation.h"


class Actor
{
protected:
	std::string Name;
	vector Location = {0,0};
	std::vector<Texture*> ActorTextureArray; /*Note - All Textures are loaded into the renderer by default Only Renderer is allowed
											 To Draw On The Screen*/

	std::vector<int> RendererTextureArray;/*Note - All Textures are loaded into the renderer by default Only Renderer is allowed
											 To Draw On The Screen*/

	std::vector<Animation> Animations_Actor;

	int PlayRate = 1;//Default PlayRate = 1 Plays Normally At The Refresh Rate Of The Display...
public:
	//Flags 
	bool ShouldIRenderOnScreen = true;

protected:
	void SetAnimationPlayRate(int PlayRate); //Higher PlayRate is Faster Animation
	
protected:
	//Animations Centric Functions
	void SetAnimations(std::vector<Animation> Animations);//Clears All Existing Animations And Places New Ones In its Place
	void SetAnimations_Append(std::vector<Animation> Animations);//Appends The Existing Vector With New Animations
	void SetAnimation(Animation NewAnimation);

	std::vector<std::string> GetAnimationsAssociatedWithActor();//Gets The Names Of All Animations Associated With This Actor

protected:
	//Texture Centric Functions
	void LoadTexture(int RendrerTextureValue);
};