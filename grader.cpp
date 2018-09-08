#include "grader.h"

/*
PRE: None 
POST: File is open and at the beginning

Open a file. Returns -1 if opening is unsuccessful.
*/
bool grader::open_file(const char* file_name)
{
	file.open(file_name);

	if(!file)
	{
		return -1;
	}
	return 0;
}

/*
PRE: None
POST: Member file is closed

Closes member file
*/
bool grader::close_file()
{
	file.close();
}

/*
PRE: None 
POST: None

Returns the score of a 'letter' by going through various checks.
*/
int grader::get_grade()
{
	int total_score = 0;

	total_score += check_A();

	reset_file();

	total_score += check_B();

	reset_file();

	total_score += check_C();

	reset_file();
	
	total_score += check_D();

	reset_file();

	total_score += check_E();

	reset_file();

	total_score += check_F();

	reset_file();
	
	total_score += check_G();

	return total_score; 
}

/*
PRE: File member must be loaded and at the beginning of the file
POST: File member will be at EOF

For every punctuation mark, there must be a capital letter within 3 spaces. +10 for having the a capital after punctuation, -10 for not having a capital. Gives an additional +20 points for having punctuation at the end of the file.
*/
int grader::check_A()
{
	char c;
	int count;
	bool cap_found = false;
	int score = 0;

	while(!file.eof())
	{
		file.get(c);
		
		// Check for punctuation
		if(is_punct(c))
		{

			// Check for capital 3 characters after punctuation
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
			
			// Add result to score
			if(!cap_found && !file.eof())
				score -= 10;
			else if(file.eof())
				score += 20;
		}
	}
	return score;
}

/*
PRE: File member must be loaded and at the beginning of the file
POST: File member will be at EOF

Gets the first 3 letters from every word (if word is less than 3 letters, then get the entire word), then checks to see if those 3 letters are in the trigram table. Gives 3 points for every match in the trigram table.
*/
int grader::check_B()
{
	std::string cur_trigram;
	trigram Trigram;

	int count = 0;

	// Check trigrams until the end of the file and add them to the counter
	while(!file.eof())
	{
		cur_trigram = extract_trigram();

		if(Trigram.is_trigram(lowercase(cur_trigram)))
			count++;
	}

	return (count * 3);
}

/*
PRE: File member must be loaded and at the beginning of the file
POST: File member will be at EOF

Checks if the first nonspace character of the file is capitalized. If so it rewards +20 points, if not it gives -10 points.
*/
int grader::check_C()
{
	char c = ' ';

	// Remove any spaces at the start of the file
	while(c == ' ')
		file.get(c);

	if(is_cap(c))
		return 20;
	else
		return -10; 
}

/*
PRE: File member must be loaded and at the beginning of the file
POST: File member will be at EOF

Checks to see if a letter is repeated 3 times in a row. If so then it gives -50 points and stops checking.
*/
int grader::check_D()
{
	char cur_c = ' ';
	char prev_c = ' ';
	int count = 0;

	// Check until EOF or until 3 consecutive characters are found
	while(!file.eof() && count < 3)
	{
		file.get(cur_c);
		
		if((cur_c == prev_c))
			count++;
		else
			count = 0;

		prev_c = cur_c;
	}

	if(count >= 3)
		return -50;
	else
		return 0;
}

/*
PRE: File member must be loaded and at the beginning of the file
POST: File member will be at EOF

Check for the ratio of spaces to non-spaces.

if num_spaces * 100 / num_other < 20

or

If the letter is only spaces. 

Then check E gives -20 points, otherwise it gives +20
*/
int grader::check_E()
{
	int num_spaces = 0;
	int num_other = 0;

	int calc;

	char c;

	// Add each character to its category
	while(!file.eof())
	{
		file.get(c);

		if(c == ' ')
			num_spaces++;
		else
			num_other++;
	}

	// Calculate the ratio and give points accordingly 
	calc = (num_spaces * 100) / num_other;

	if((calc < 20) || (num_other == 0))
		return -20;
	else
		return 20;
}

/*
PRE: File member must be loaded and at the beginning of the file
POST: File member will be at EOF

If the letter has a space of 75 characters without punctuation then check F gives -150 points
*/
int grader::check_F()
{
	int letter_count = 0;
	bool run_on_sent = false;

	char c;

	// Counts amount of characters from start of file or last punctuation. 
	while(!file.eof() && !run_on_sent)
	{
		file.get(c);
		letter_count++;

		if(is_punct(c))
			letter_count = 0;
		if(letter_count >= 75)
			run_on_sent = true;
	}

	// If a group of 75 characters was found without punctuation give -150 points
	if(run_on_sent)
		return -150;
	else
		return 0;
}

/*
PRE: File member must be loaded and at the beginning of the file
POST: File member will be at EOF

Checks every group of 32 characters for a space. For every group of 32 characters that does not have a space check G gives -20 points
*/
int grader::check_G()
{
	char c;
	bool found_space = false;
	int c_count = 0;
	int g_count = 0;

	// Counts by groups of 32, checking every character for a space
	while(!file.eof())
	{
		file.get(c);
		c_count++;

		if(c == ' ')
			found_space = true;
		if(c_count >= 32)
		{
			if(!found_space)
				g_count++;

			c_count = 0;
			found_space = false;
		}
	}

	return -20 * g_count;
}

/*
PRE: None 
POST: None

Checks every group of 32 characters for a space. For every group of 32 characters that does not have a space check G gives -20 points
*/
bool grader::is_punct(char c)
{
	return ((c == '.') || (c == '!') || (c == '?'));
}

/*
PRE: None
POST: None

Checks to see if the character is a regular alphabetical letter
*/
bool grader::is_cap(char c)
{
	return ((c >= 65) && (c <= 90));
}

/*
PRE: None
POST: Member file is reset to the beginning of the file
*/
void grader::reset_file()
{
	file.clear();
	file.seekg(0, std::ios::beg);
}

/*
PRE: File is loaded.
POST: File is moved forward by a variable amount.

Searches for the next alphabetical character, then saves it and then next 2 (if there are 22) alphabetical characters and returns them.
*/
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

/*
PRE: None
POST: None

Converts a string to all lowercase and returns it
*/
std::string grader::lowercase(std::string word)
{
	std::string low_word;

	for(int i = 0; i < word.length(); i++)
		low_word.push_back(tolower(word[i]));

	return low_word;
}















