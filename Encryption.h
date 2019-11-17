#pragma once
#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
	string encrypted_msg = "";
	int i = 0, ltr_cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			ltr_cnt += 1;
		i++;
	}
	i -= 1;
	cout << ltr_cnt << endl;
	return encrypted_msg;
}