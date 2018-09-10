#ifndef GRADER_H
#define GRADER_H

#include <fstream>
#include <string>
#include <ctype.h>

#include "trigram.h"

class grader
{
	public:
		bool open_file(const char* file_name);
		bool close_file();

		void grade_file();
		int get_single_grade(char check);
		int get_total_grade();
	private:
		int check_A();
		int check_B();
		int check_C();
		int check_D();
		int check_E();
		int check_F();
		int check_G();
		bool is_punct(char c);
		bool is_cap(char c);
		void reset_file();
		std::string extract_trigram();
		std::string lowercase(std::string word);

		int grades[7];
		std::ifstream file;
};

#endif
