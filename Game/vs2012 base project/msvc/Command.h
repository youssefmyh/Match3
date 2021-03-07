#pragma once
//  Created by Youssef Hanna.
//  Copyright © 2021. All rights reserved.
//
/**
* Command Interface 
*/
enum CommandsType {
	SWAP,
	DELETE,
	FILL
};

class Command
{
	
public:
	virtual void execute() = 0; // must be overrided for each command
	virtual bool isFinished() = 0; // to determine if the command is finished to move on with the next one

};

