#pragma once
#include <iostream>

using namespace std;

class Snack {
protected:
	int price;
	string name;
	string maker;
	static int count;
	static string lastSnack;
public:
	Snack();
	virtual ~Snack();
	static int get_count();
	string get_name();
	static void set_last(string menu);
	static string get_last();
	virtual void show_info();
};
