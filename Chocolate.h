#pragma once
#include <iostream>

class Chocolate : public Snack {
public:
	string shape;
public:
	Chocolate(string shape);
	void show_info();
};