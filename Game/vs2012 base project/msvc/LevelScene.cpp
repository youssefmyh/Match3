#include "LevelScene.h"


void LevelScene::Start() {
	mEngine.Start(*this);
}

void LevelScene::Update() {
	mEngine.Render(King::Engine::TEXTURE_GREEN, 650.0f, 100.0f);
	mEngine.Render(King::Engine::TEXTURE_RED, 100.0f, 450.0f);
	mEngine.Render(King::Engine::TEXTURE_BLUE, 650.0f, 450.0f);

	mEngine.Write("Green", 100.0f, 140.0f);
	mEngine.Write("Red", 100.0f, 490.0f);
	mEngine.Write("Blue", 650.0f, 490.0f);

	const char text[] = "This rotates at 5/PI Hz";
	mRotation += mEngine.GetLastFrameSeconds();
	mEngine.Write(text, mEngine.GetWidth() / 2.0f, mEngine.GetHeight() / 2.0f, mRotation * 2.5f);

	if (mEngine.GetMouseButtonDown()) {
		mYellowDiamondX = mEngine.GetMouseX();
		mYellowDiamondY = mEngine.GetMouseY();
	}
	mEngine.Render(King::Engine::TEXTURE_YELLOW, mYellowDiamondX, mYellowDiamondY);
	mEngine.Write("Click to", mYellowDiamondX, mYellowDiamondY + 0.0f);
	mEngine.Write("move me!", mYellowDiamondX, mYellowDiamondY + 70.0f);
}