#pragma once
#include <bits/stdc++.h>
using namespace std;

string encryption(string s) {
	string encrypted_msg = "", without_spaces = "";
	int i = 0, ltr_cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			ltr_cnt += 1;
			without_spaces += s[i];
		}
		i++;
	}
	i -= 1;
	float l = sqrt(ltr_cnt);
	int r = floor(l) , c = ceil(l);

	for (int col = 0; col < c; col++)
	{
		int ptr = col;
		while (ptr < ltr_cnt)
		{
			encrypted_msg += without_spaces[ptr];
			ptr += c;
		}
		encrypted_msg += " ";
	}
	return encrypted_msg;
}