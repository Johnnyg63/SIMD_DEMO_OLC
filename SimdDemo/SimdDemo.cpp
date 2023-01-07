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

	/* Vectors */
	std::vector<std::string> vecMessages;
	/* END Vectors*/

	/* Vars */
	int nMapWidth = 0;	// Map Width
	int nMapHeight = 0; // Map Height 
	olc::Sprite::SIMD_INSTRUCTON_OPTION nCurrentSIMDOption;

	int nFlipFaceCount = 0;
	bool bTottleFace = false;

	/* End Vars */

	/* Sprites */
	olc::Sprite* sprMrIcey = nullptr;
	olc::Sprite* sprMrIceyVERT = nullptr;
	olc::Sprite* sprMrIceyScale = nullptr;
	olc::Sprite* sprMrSmiley = nullptr;
	olc::Sprite* sprSpriteSheet = nullptr;
	olc::Sprite* sprSpriteSheetVERT = nullptr;
	olc::Sprite* sprBody3D = nullptr;
	olc::Sprite* sprFace1 = nullptr;
	olc::Sprite* sprFace2 = nullptr;
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
		sprMrIcey->setInsturctionSet(olc::Sprite::SIMD_AVX);
		sprMrIceyVERT = sprMrIcey->Duplicate_SIMD(olc::Sprite::VERT);
		sprMrIcey->setStoreSubSprites(true);
		
		nCurrentSIMDOption = sprMrIcey->getInsturctionSet();

		sprMrSmiley = new olc::Sprite("./assets/images/CubeEnemuHaHaHa.png");
		sprMrSmiley->setInsturctionSet(sprMrSmiley->getInsturctionSet());
		sprMrSmiley->setStoreSubSprites(true);

		sprSpriteSheet = new olc::Sprite("./assets/images/SpriteSheet.png");
		sprSpriteSheet->setInsturctionSet(sprSpriteSheet->getInsturctionSet());
		sprSpriteSheetVERT = sprSpriteSheet->Duplicate_SIMD({ 250, 0 }, { 100,150 });
		sprSpriteSheetVERT = sprSpriteSheetVERT->Duplicate_SIMD(olc::Sprite::VERT);
		sprSpriteSheet->setStoreSubSprites(true);
		sprSpriteSheetVERT->setStoreSubSprites(true);
		


		sprBody3D = new olc::Sprite("./assets/images/Body3D.png");
		sprBody3D->setInsturctionSet(sprBody3D->getInsturctionSet());
		sprBody3D->setStoreSubSprites(true);


		// Note we took the instruction set from the sprBody3D, we will be merging these later
		sprFace1 = new olc::Sprite("./assets/images/Face1.png");
		sprFace1->setInsturctionSet(sprBody3D->getInsturctionSet());
		sprFace1->setStoreSubSprites(sprBody3D->getStoreSubSprites());

		sprFace2 = new olc::Sprite("./assets/images/Face2.png");
		sprFace2->setInsturctionSet(sprBody3D->getInsturctionSet());
		sprFace2->setStoreSubSprites(sprBody3D->getStoreSubSprites());

		sprBackGround = new olc::Sprite("./assets/images/ExampleBG1.png");
		sprMrIcey->setInsturctionSet(sprMrIcey->getInsturctionSet());
		sprMrIcey->setStoreSubSprites(true);
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
		FillCircle_SIMD({ 50, 110 }, 25, olc::GREEN);
		EnableLayer(nLayerCircle, true);

		/*------- Level Rectangles 4 ------*/
		nLayerRect = CreateLayer();
		SetDrawTarget(nLayerRect);
		Clear_SIMD(olc::BLANK);
		FillRect_SIMD({ 25, 160 }, { 50, 50 }, olc::RED);
		EnableLayer(nLayerRect, true);

		/*------- Level Triangles 5 ------*/
		nLayerRect = CreateLayer();
		SetDrawTarget(nLayerRect);
		Clear_SIMD(olc::BLANK);
		FillTriangle_SIMD({ 50, 235 }, { 25, 285 }, { 75, 285 }, olc::YELLOW);
		EnableLayer(nLayerRect, true);


		/*------- Level Sprites 5 ------*/
		nLayerDrawSprite = CreateLayer();
		SetDrawTarget(nLayerDrawSprite);
		Clear_SIMD(olc::BLANK);
		EnableLayer(nLayerDrawSprite, true);

		/*------- Level Partial Sprites 6 ------*/
		nLayerDrawPartialSprite = CreateLayer();
		SetDrawTarget(nLayerDrawPartialSprite);
		Clear_SIMD(olc::BLANK);
		
		
		EnableLayer(nLayerDrawPartialSprite, true);

		/*------- Level Merge Sprites 7 ------*/
		nLayerDrawMergeSprite = CreateLayer();
		SetDrawTarget(nLayerDrawMergeSprite);
			
		Clear_SIMD(olc::BLANK);
				
		EnableLayer(nLayerDrawMergeSprite, true);

		/*------- Level Merge Sprites 7 ------*/
		nLayerBackGround = CreateLayer();
		SetDrawTarget(nLayerBackGround);
		Clear_SIMD(olc::WHITE);
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

		// Clear the nLayerMessages
		SetDrawTarget(nLayerMessages);
		Clear_SIMD(olc::BLANK);
		vecMessages.clear();
		vecMessages.push_back("Press E to Enable/Disable Store Sub Spites, Press S to Enable/Disable SIMD");

		//
		SetDrawTarget(nLayerDrawSprite);
		Clear_SIMD(olc::BLANK);

		//
		SetDrawTarget(nLayerDrawPartialSprite);
		Clear_SIMD(olc::BLANK);

		// merge!!
		SetDrawTarget(nLayerDrawMergeSprite);
		Clear_SIMD(olc::BLANK);

		if (bTottleFace)
		{
			/*DrawMergeSprite({ 100, 500 }, sprFace1, { 10, 40 }, sprBody3D, olc::BLANK, 1, olc::Sprite::NONE);
			DrawMergeSprite_SIMD({ 300, 500 }, sprFace1, { 10, 40 }, sprBody3D, olc::BLANK, 1, olc::Sprite::NONE);*/


			DrawMergeSprite_SIMD({ 800, 400 }, sprFace1, { 10, 40 }, sprBody3D);
			DrawMergeSprite_SIMD({ 1000, 400 }, sprFace1, { 10, 40 }, sprBody3D, olc::BLANK, 2, olc::Sprite::VERT);
			DrawSprite_SIMD({ 100, 50 }, sprMrIcey, 1, olc::Sprite::NONE);
			DrawSprite_SIMD(100, 200, sprMrIcey, 1, olc::Sprite::HORIZ);
			DrawSprite_SIMD(100, 350, sprMrIceyVERT, 1, olc::Sprite::NONE);
			DrawSprite_SIMD({ 500, 50 }, sprMrIcey, 2, olc::Sprite::NONE);		
			DrawSprite_SIMD({ 500, 400 }, sprMrIcey, 2, olc::Sprite::HORIZ);
			DrawPartialSprite_SIMD({ 750, 100 }, sprSpriteSheet, { 0, 0 }, { 150,150 }, 1, olc::Sprite::NONE);
			DrawPartialSprite_SIMD({ 900, 100 }, sprSpriteSheet, { 150, 0 }, { 100,150 }, 1, olc::Sprite::HORIZ);
			DrawPartialSprite_SIMD({ 1000, 120 }, sprSpriteSheet, { 250, 0 }, { 100,150 }, 1, olc::Sprite::VERT);
			
		}
		else
		{
			/*DrawMergeSprite({ 100, 500 }, sprFace2, { 10, 40 }, sprBody3D, olc::BLANK, 1, olc::Sprite::NONE);
			DrawMergeSprite_SIMD({ 300, 500 }, sprFace2, { 10, 40 }, sprBody3D, olc::BLANK, 1, olc::Sprite::NONE);*/

			DrawMergeSprite_SIMD({ 800, 400 }, sprFace2, { 10, 40 }, sprBody3D);
			DrawMergeSprite_SIMD({ 1000, 400 }, sprFace2, { 10, 40 }, sprBody3D, olc::BLANK, 2, olc::Sprite::VERT);
			DrawSprite_SIMD({ 100, 50 }, sprMrIcey, 1, olc::Sprite::HORIZ);
			DrawSprite_SIMD(100, 200, sprMrIcey, 1, olc::Sprite::NONE);
			DrawSprite_SIMD(100, 350, sprMrIceyVERT, 1, olc::Sprite::HORIZ);
			DrawSprite_SIMD({ 500, 50 }, sprMrIcey, 2, olc::Sprite::HORIZ);
			DrawSprite_SIMD({ 500, 400 }, sprMrIcey, 2, olc::Sprite::NONE);
			DrawPartialSprite_SIMD({ 750, 100 }, sprSpriteSheet, { 0, 0 }, { 150,150 }, 1, olc::Sprite::HORIZ);
			DrawPartialSprite_SIMD({ 900, 100 }, sprSpriteSheet, { 150, 0 }, { 100,150 }, 1, olc::Sprite::NONE);
			DrawSprite_SIMD({ 1000, 120 }, sprSpriteSheetVERT, 1, olc::Sprite::HORIZ);
						
		}
		nFlipFaceCount++;
		if (nFlipFaceCount > 200)
		{
			bTottleFace = !bTottleFace;
			nFlipFaceCount = 0;
		}


		if (GetKey(olc::Key::E).bPressed)
		{
			if (sprMrIcey->getStoreSubSprites())
			{
				sprMrIcey->setStoreSubSprites(false);
				sprBackGround->setStoreSubSprites(false);
				sprFace1->setStoreSubSprites(false);
				sprFace2->setStoreSubSprites(false);
				sprBody3D->setStoreSubSprites(false);
			}
			else
			{
				sprMrIcey->setStoreSubSprites(true);
				sprBackGround->setStoreSubSprites(true);
				sprFace1->setStoreSubSprites(true);
				sprFace2->setStoreSubSprites(true);
				sprBody3D->setStoreSubSprites(true);
				
			}
		}

		if (GetKey(olc::Key::S).bPressed)
		{
			if (sprMrIcey->getInsturctionSet() == sprMrIcey->SIMD_NONE)
			{
				sprMrIcey->setInsturctionSet(nCurrentSIMDOption);
				sprBackGround->setInsturctionSet(nCurrentSIMDOption);
				sprFace1->setInsturctionSet(nCurrentSIMDOption);
				sprFace2->setInsturctionSet(nCurrentSIMDOption);
				sprBody3D->setInsturctionSet(nCurrentSIMDOption);
				
			}
			else
			{

				sprMrIcey->setInsturctionSet(sprMrIcey->SIMD_NONE);
				sprBackGround->setInsturctionSet(sprMrIcey->SIMD_NONE);
				sprFace1->setInsturctionSet(sprMrIcey->SIMD_NONE);
				sprFace2->setInsturctionSet(sprMrIcey->SIMD_NONE);
				sprBody3D->setInsturctionSet(sprMrIcey->SIMD_NONE);

				
			}
		}


		// Draw Messages
		SetDrawTarget(nLayerMessages);
		Clear_SIMD(olc::BLANK);

		if (sprMrIcey->getStoreSubSprites())
		{
			vecMessages.push_back("Store Sub Sprites ENABLED");
		}
		else
		{
			vecMessages.push_back("Store Sub Sprites DISABLED");
		}

		if (sprMrIcey->getInsturctionSet() == sprMrIcey->SIMD_NONE)
		{
			vecMessages.push_back("SIMD DISABLED");
		}
		else
		{
			vecMessages.push_back("SIMD ENABLED");
		}

		int nStep = 20;
		for (auto& s : vecMessages)
		{
			DrawString(20, nStep, s);
			nStep += 20;
		}

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

