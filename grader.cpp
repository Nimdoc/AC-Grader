#include "grader.h"

bool grader::open_file(const char* file_name)
{
	file.open(file_name);

	if(!file)
	{
		return -1;
	}
	return 0;
}

bool grader::close_file()
{
	file.close();
}

int grader::get_grade()
{
	int total_score = 0;

	total_score += check_A();

	reset_file();

	total_score += check_B();

	return total_score; 
}

int grader::check_A()
{
	char c;
	int count;
	bool cap_found = false;
	int score = 0;

	while(!file.eof())
	{
		file.get(c);

		if(is_punct(c))
		{
			count = 0;
			cap_found = false;
			while((count < 3) && !cap_found && !file.eof())
			{
				file.get(c);
				if(is_cap(c))
				{
					score += 10;
					cap_found = true;
				}

				count++;
			}
			
			if(!cap_found && !file.eof())
				score -= 10;
			else if(file.eof())
				score += 20;
		}
	}
	return score;
}

int grader::check_B()
{
	std::string cur_trigram;
	trigram Trigram;

	int count = 0;

	while(!file.eof())
	{
		cur_trigram = extract_trigram();

		if(Trigram.is_trigram(lowercase(cur_trigram)))
			count++;
	}

	return (count * 3);
}

int grader::check_C()
{

}

int grader::check_D()
{

}

int grader::check_E()
{

}

int grader::check_F()
{

}

int grader::check_G()
{

}

void grader::reset_pos()
{

}

bool grader::is_punct(char c)
{
	return ((c == '.') || (c == '!') || (c == '?'));
}

bool grader::is_cap(char c)
{
	return ((c >= 65) && (c <= 90));
}

void grader::reset_file()
{
	file.clear();
	file.seekg(0, std::ios::beg);
}

std::string grader::extract_trigram()
{
	int count = 0;
	char c = '\n';

	std::string cur_trigram;

	while(!isalpha(c) && !file.eof())
		file.get(c);

	// Not gonna bust out anything complicated for checking 3 chars
	if(isalpha(c))
	{
		cur_trigram.push_back(c);
		file.get(c);
		if(isalpha(c))
		{
			cur_trigram.push_back(c);
			file.get(c);
			if(isalpha(c))
				cur_trigram.push_back(c);
		}
	}

	while(isalpha(c) && !file.eof())
		file.get(c);

	return cur_trigram;
}

std::string grader::lowercase(std::string word)
{
	std::string low_word;

	for(int i = 0; i < word.length(); i++)
		low_word.push_back(tolower(word[i]));

	return low_word;
}















