#pragma once
#include<string>
#include<map>
#include<iostream>
#include<vector>
using namespace std;

string timeInWords(int h, int m) {
	string time;

	vector<string> InWord = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven",
		"twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one",
		"twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight",	"twenty nine" };
	
	if (m == 0)
	{
		time = InWord[h] + " o' clock";
	}


	else if (m == 15)
	{
		time = "quarter past " + InWord[h];
	}

	else if (m < 30)
	{
		if(m == 1)
			time = InWord[m] + " minute past " + InWord[h];
		else
			time = InWord[m] + " minutes past " + InWord[h];
	}

	else if (m == 30)
	{
		time = "half past " + InWord[h];
	}

	else if (m > 30)
	{
		if (h < 12)
			h += 1;
		else
			h = 1;
		m = 60 - m;

		if (m != 15)
		{
			if (m != 1)
				time = InWord[m] + " minutes to " + InWord[h];
			else
				time = InWord[m] + " minute to " + InWord[h];
		}
		else
			time = "quarter to " + InWord[h];
	}

	return time;
}