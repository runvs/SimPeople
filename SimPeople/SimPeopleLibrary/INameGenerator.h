#ifndef INAMEGENERATOR_H_12345
#define INAMEGENERATOR_H_12345

#include <string>

namespace SimPeople
{
class INameGenerator
{
public:
	INameGenerator(void);
	virtual ~INameGenerator(void);

	std::string GetName ();

protected:
	virtual std::string DoGetName() = 0;
};

}

#endif