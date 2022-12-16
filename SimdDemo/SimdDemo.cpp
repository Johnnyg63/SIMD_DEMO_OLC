// O------------------------------------------------------------------------------O
// | Example "Hello World" Program (main.cpp)                                     |
// O------------------------------------------------------------------------------O

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

// Override base class with your custom functionality
class SIMDDEMO : public olc::PixelGameEngine
{
public:
	SIMDDEMO()
	{
		// Name your application
		sAppName = "SIMD INSTRUCTION SET DEMO";
	}

	/* Vars */
	int nMapWidth = 0;	// Map Width
	int nMapHeight = 0; // Map Height 

	/* End Vars */

	/* Sprites */
	olc::Sprite* sprMrIcey = nullptr;
	olc::Sprite* sprBackGround = nullptr;

	/* END Sprites*/

	/* Layers */

	int nLayerMessages = 1;			// Message Layer
	int nLayerPlayer = 2;			// Player layer
	int nLayerCircle = 3;			// Circle Layer
	int nLayerRect = 4;				// Rectangle Layer
	int nLayerTriange = 5;			// Triangle Layer
	int nLayerDrawSprite = 6;		// Draw Sprite Layer
	int nLayerDrawPartialSprite = 7;	// Draw Parital Sprite Layer
	int nLayerDrawMergeSprite = 8;	// Draw a Merge Sprite Layer
	int nLayerBackGround = 9;		// Background layer


	/* End Layers */



public:
	bool OnUserCreate() override
	{
		/*--- Sprites ---*/
		sprMrIcey = new olc::Sprite("./assets/images/runsmall.png");
		sprMrIcey->setInsturctionSet(sprMrIcey->getInsturctionSet());
		sprMrIcey->setStoreSubSprites(true);

		sprBackGround = new olc::Sprite("./assets/images/ExampleBG1.png");
		sprMrIcey->setInsturctionSet(sprMrIcey->getInsturctionSet());
		sprMrIcey->setStoreSubSprites(false);
		/*--- END Sprites ---*/


		/*--- Layers ---*/

		/*------- Level Messages 1 ------*/
		nLayerMessages = CreateLayer();
		SetDrawTarget(nLayerMessages);
		Clear_SIMD(olc::BLANK);
		EnableLayer(nLayerMessages, true);

		/*------- Level Player 2 ------*/
		nLayerPlayer = CreateLayer();
		SetDrawTarget(nLayerPlayer);
		Clear_SIMD(olc::BLANK);
		EnableLayer(nLayerPlayer, true);

		/*------- Level Cirle 3 ------*/
		nLayerCircle = CreateLayer();
		SetDrawTarget(nLayerCircle);
		Clear_SIMD(olc::BLANK);
		FillCircle_SIMD({ 50, 50 }, 25, olc::GREEN);
		EnableLayer(nLayerCircle, true);

		/*------- Level Rectangles 4 ------*/
		nLayerRect = CreateLayer();
		SetDrawTarget(nLayerRect);
		Clear_SIMD(olc::BLANK);
		FillRect_SIMD({ 25, 100 }, { 50, 50 }, olc::RED);
		EnableLayer(nLayerRect, true);

		/*------- Level Triangles 5 ------*/
		nLayerRect = CreateLayer();
		SetDrawTarget(nLayerRect);
		Clear_SIMD(olc::BLANK);
		FillTriangle_SIMD({ 50, 175 }, { 25, 225 }, { 75, 225 }, olc::YELLOW);
		EnableLayer(nLayerRect, true);


		/*------- Level Sprites 5 ------*/
		nLayerDrawSprite = CreateLayer();
		SetDrawTarget(nLayerDrawSprite);
		Clear_SIMD(olc::BLANK);
		DrawSprite_SIMD({ 100, 25 }, sprMrIcey, 1, olc::Sprite::NONE);
		DrawSprite_SIMD(100, 200, sprMrIcey, 1, olc::Sprite::HORIZ);
		DrawSprite_SIMD(100, 350, sprMrIcey, 1, olc::Sprite::VERT);
		EnableLayer(nLayerDrawSprite, true);

		/*------- Level Partial Sprites 6 ------*/
		nLayerDrawPartialSprite = CreateLayer();
		SetDrawTarget(nLayerDrawPartialSprite);
		Clear_SIMD(olc::BLANK);
		DrawPartialSprite_SIMD({ 300, 25 }, sprMrIcey, { 50, 50 }, { 80,80 }, 1, olc::Sprite::NONE);
		DrawPartialSprite_SIMD({ 300, 200 }, sprMrIcey, { 50, 50 }, { 80,80 }, 1, olc::Sprite::HORIZ);
		DrawPartialSprite_SIMD({ 300, 350 }, sprMrIcey, { 50, 50 }, { 80,80 }, 1, olc::Sprite::VERT);
		
		EnableLayer(nLayerDrawPartialSprite, true);

		/*------- Level Merge Sprites 7 ------*/
		nLayerDrawMergeSprite = CreateLayer();
		SetDrawTarget(nLayerDrawMergeSprite);
		Clear_SIMD(olc::BLANK);
	
		EnableLayer(nLayerDrawMergeSprite, true);

		/*------- Level Merge Sprites 7 ------*/
		nLayerBackGround = CreateLayer();
		SetDrawTarget(nLayerBackGround);
		Clear_SIMD(olc::BLUE);
		DrawSprite_SIMD({ 0,0 }, sprBackGround, 2, olc::Sprite::NONE);
		EnableLayer(nLayerBackGround, true);


		/*--- End Layers ---*/

		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		SetDrawTarget(nullptr);
		Clear_SIMD(olc::BLANK);

		// Create Messages
		SetDrawTarget(nLayerMessages);
		Clear_SIMD(olc::BLANK);

		// Draw the background
		//SetDrawTarget(nLayerBackGround);
		//Clear_SIMD(olc::BLUE);
		//DrawSprite_SIMD({ 0,0 }, sprBackGround, 2, olc::Sprite::NONE);




		return true;
	}
};

int main()
{
	SIMDDEMO simdemo;

	// Set size, and number if pixels
	// Play around with these setting as every game will be different
	// I would recommend  using resources to store these values
	// (Screen Width, Screen Height, Pixel Width, Pixel Height, Full Screen (true/False (Default)), 
	//	vertical sync (true/False (Default)), pixel cohesion (true/False (Default))
	if (simdemo.Construct(1280, 720, 1, 1, false, false, true))
	{
		simdemo.nMapWidth = 1280;
		simdemo.nMapHeight = 720;

		// lets get the show on the road
		simdemo.Start();
	}
	return 0;
}

