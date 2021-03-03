#pragma once
//  Created by Youssef Hanna.
//  Copyright © 2021. All rights reserved.
//
/**
* Command Interface 
*/
class Command
{
	enum Commands {
		SWAP,
		DELETE,
		FILL
	};


	virtual void Execute() = 0; // must be overrided for each command
	virtual bool IsFinished() = 0; // to determine if the command is finished to move on with the next one

};

