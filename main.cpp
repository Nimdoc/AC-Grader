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

	Grader.grade_file();

	std::cout << "Individual Grades:\n\n";

	for(int i = 0; i < 7; i++)
		std::cout << "Check " << (char)('A' + i) << ": " << Grader.get_single_grade('A' + i) << std::endl;

	std::cout << "\nTotal Grade: " << Grader.get_total_grade() << std::endl;

	Grader.close_file();
}
