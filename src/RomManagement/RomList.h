//
// Created by joseph on 15/11/15.
//

#ifndef MAMEUISEN_ROMLIST_H
#define MAMEUISEN_ROMLIST_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Rom.h"

class RomList
{
private:
	std::string name;
	std::vector<Rom*> romList;
	int lastViewedRomIndex = 1;

public:
	//Constructor
	RomList(const std::string& name="") : name(name), romList(0, nullptr)
	{}

	//Getters
	const std::string& getName() const
	{
		return name;
	}

	Rom* getRom(int romNumber) const//rom number begin at 1!
	{
		return romList[romNumber-1];
	}

	unsigned long getRomListSize() const
	{
		return romList.size();
	}

	//Member functions
	bool isEmpty()
	{
		return romList.empty();
	}

	void addRom(Rom* rom)
	{
		romList.push_back(rom);
	}

	int getLastViewedRomIndex() const
	{
		return lastViewedRomIndex;
	}

	void setLastViewedRomIndex(int lastViewedRomIndex)
	{
		RomList::lastViewedRomIndex = lastViewedRomIndex;
	}

	void sort()
	{
		std::sort(romList.begin(), romList.end(), &Rom::compareRom);
	}
};


#endif //MAMEUISEN_ROMLIST_H