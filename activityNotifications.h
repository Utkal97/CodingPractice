#pragma once
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int activityNotifications(vector<int> expenditure, int d) {
	if (expenditure.size() >= d)
		return 0;

	int count = 0;
	for (int i = d; i < expenditure.size(); i++) {

	}
	return count;
}
