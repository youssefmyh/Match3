#include "FillCommand.h"
void FillCommand::execute()
{
	fill();

}

void FillCommand::fill(){

	
	for (size_t i = GAME_MAX_CELLS; i < mlevelColors.size(); i++)
	{

		if (mlevelColors[i] == -1) {

			mlevelColors[i] = rand() % 5;

			jewelers[i] = std::move(std::make_shared<JewelryItem>(mlevelColors[i] + 1, 0, 0, 35, 35));

		}

	}


	mCompleted = true;

}

bool FillCommand::isFinished()
{
	return mCompleted;
}
