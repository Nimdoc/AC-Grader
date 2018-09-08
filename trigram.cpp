#include "trigram.h"

/*
PRE: None 
POST: None

Checks to see if 'phrase' is in the trigram table returns true or false respectively.
*/
bool trigram::is_trigram(std::string phrase)
{
	int result;

	result = search(phrase, 0, table_size - 1);

	if(result >= 0)
		return true;
	else
		return false;
}

/*
PRE: None 
POST: None

Does a binary search on trigram_table for 'phrase'. Returns the array location if found, otherwise returns -1
*/
int trigram::search(std::string phrase, int l, int r)
{
	int comp = 0;

	if(r >= l)
	{
		int mid = l + (r - l) / 2;

		comp = phrase.compare(trigram_table[mid]);

		if(comp == 0)
			return mid;

		if(comp < 0)
			return search(phrase, l, mid-1);

		if(comp > 0)
			return search(phrase, mid+1, r);
	}

	return -1;
}
