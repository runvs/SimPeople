#ifndef NAMEGENERATORHARDCODED_H_12345
#define NAMEGENERATORHARDCODED_H_12345
#include "../SimPeopleLibrary/INameGenerator.h"

namespace SimPeople
{
/// This implementation of the NameGenerator Interface has some hard coded names that will be chosen linar. 
/// If the names are depleted the list is started from the beginning with appending Numbers to the names
class NameGeneratorHardCoded :
	public INameGenerator
{
public:
	NameGeneratorHardCoded(void);
	~NameGeneratorHardCoded(void);
protected:
	/// this Method does the work for creating the names
	std::string DoGetName();

private:
	/// This variable is used for counting through the list
	unsigned int m_uiNameCounter;
};
}
#endif