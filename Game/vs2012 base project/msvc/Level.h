#pragma once
class Level {

	virtual void load() = 0;
	virtual void end()  = 0;
	virtual void won()  = 0;
};