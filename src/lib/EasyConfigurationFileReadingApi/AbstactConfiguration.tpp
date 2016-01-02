//
// Created by joseph on 31/12/15.
//

#include "AbstactConfiguration.h"

template<class T>
void AbstactConfiguration<T>::loadConfiguration(T* subClass, char commentCharacter)
{
	std::ifstream confFile(configFilePath, std::ios::in);
	if(!confFile)
	{
		std::cerr << "Can't open \"" << configFilePath << "\" : " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		std::string line;
		int numLine = 0;
		while(getline(confFile, line))
		{
			numLine++;
			if(line[0] != commentCharacter)
			{
				for(auto & dtf : directiveToFunction)
				{
					size_t pos = line.find(dtf.getDirective());
					if(pos == 0)
					{
						try
						{
							dtf.callSetter(subClass, line.substr(pos + dtf.getDirective().length() + 1));
						}
						catch(const std::exception& exception)
						{
							std::cerr << "Incorrect value for directive " << dtf.getDirective() << " line " << numLine << ". Default value will be used.\t";
							std::cerr << "Exeption message is: " << exception.what() << std::endl;
						}
						break;
					}
				}
			}
		}
	}
}