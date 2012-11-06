
#ifndef NAMEGENERATORFROMFILES_H_12345
#define NAMEGENERATORFROMFILES_H_12345

#include <string>
#include <vector>
#include <boost/random/mersenne_twister.hpp>
#include "../SimPeopleLibrary/INameGenerator.h"
namespace SimPeople
{

class NameGeneratorFromFiles :
	public SimPeople::INameGenerator
{
public:
	NameGeneratorFromFiles(void);
	~NameGeneratorFromFiles(void);

	void LoadNamesFromFiles ( std::string strNameFilePath = "names.txt");

protected:
	/// Implementation of the parents class method
	virtual std::string DoGetName();

private:
	std::vector<std::string> m_vecFirstNames;

	boost::random::mt19937 gen;		// rn generation must be encapsulated in a special object
	int GetRandomInt(int min, int max);

};

}
#endif