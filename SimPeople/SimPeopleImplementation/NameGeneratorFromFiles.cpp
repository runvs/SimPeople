#include "NameGeneratorFromFiles.h"

#include <iostream>
#include <fstream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/random/uniform_int.hpp>
#include<boost/random/variate_generator.hpp>
//#include <boost/filesystem/operations.hpp>
//#include <boost/filesystem.hpp>
//#include <boost/filesystem/fstream.hpp>

#include "../SimPeopleLibrary/SimPeopleExceptions.h"


namespace SimPeople
{

NameGeneratorFromFiles::NameGeneratorFromFiles(void)
{
}


NameGeneratorFromFiles::~NameGeneratorFromFiles(void)
{
}


void NameGeneratorFromFiles::LoadNamesFromFiles ( std::string strNameFilePath)
{
	//// convert to a Path
	//boost::filesystem::path t_pNameFilePath(strNameFilePath);
	//// check if the file exists
	//if (boost::filesystem::exists(t_pNameFilePath))
	//{
	//	// open a stream
	//	boost::filesystem::ifstream t_istrmNameFileStream(t_pNameFilePath);

	//	// loop over all lines and push the names into the vector
	//	for(std::string t_strName; std::getline(t_istrmNameFileStream, t_strName); )
 //       {
 //           std::cout << "Processed line " << t_strName << '\n';
	//		m_vecFirstNames.push_back(t_strName);
 //       }

	//	t_istrmNameFileStream.close();
	//}
	//else
	//{
	//	throw SimPeople::Exceptions::IOError();
	//}

	std::ifstream t_istrmNameFileStream(strNameFilePath);
	for(std::string t_strName; std::getline(t_istrmNameFileStream, t_strName); )
	{
		std::cout << "Processed line " << t_strName << '\n';
		if ( !boost::starts_with(t_strName, "#") && ! boost::starts_with(t_strName, "//") )
		{
			m_vecFirstNames.push_back(t_strName);
		}
	}

	if (m_vecFirstNames.size() == 0 )
	{
		throw SimPeople::Exceptions::IOError();
	}


}

std::string NameGeneratorFromFiles::DoGetName()
{
	std::string t_strReturn = "";

	size_t t_sLength = NameGeneratorFromFiles::m_vecFirstNames.size();
	
	size_t t_sChosen  = static_cast<size_t>(GetRandomInt(0, t_sLength));	// select a random

	t_strReturn = m_vecFirstNames.at(t_sChosen);

	return t_strReturn;
}

int NameGeneratorFromFiles::GetRandomInt(int min, int max)
{
    boost::uniform_int<> distribution(min, max);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > gen(gen, distribution);
    return gen();
}

}