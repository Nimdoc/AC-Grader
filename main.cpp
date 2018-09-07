#include <iostream>

#include "grader.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "USAGE: grader.out [FILENAME]" << std::endl;
		return 0;
	}

	grader Grader;

	if(Grader.open_file(argv[1]) == -1)
	{
		std::cout << "File could not be opened." << std::endl;
		return 0;
	}

	std::cout << "Score: " << Grader.get_grade() << std::endl;
}
