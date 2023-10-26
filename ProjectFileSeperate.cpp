#include <iostream>
#include <vector>
#include "Snack.h"
#include "Candy.h"
#include "Chocolate.h"
#include "Util.h"
#pragma once

using namespace std;

Snack::Snack(){
	count++; 
}
Snack::~Snack(){
	count--;
}
int Snack::get_count() {
	return count;
}

string Snack::get_name() {
	return name;
}
void Snack::set_last(string menu) {
	lastSnack = menu;
}
string Snack::get_last() {
	return lastSnack;
}
void Snack::show_info() {
	cout << "과자입니다~" << endl;
}

int Snack::count = 0;
string Snack::lastSnack = "";

Chocolate::Chocolate(string shape) {
	this->price = 1000;
	this->name = "초콜릿";
	this->maker = "롯데";
	this->shape = shape;
}

void Chocolate::show_info() {
	cout << shape << "모양 초콜릿" << endl;
	Snack::set_last("초콜릿");
}

Candy::Candy(string flavor) {
	this->price = 200;
	this->name = "사탕";
	this->maker = "농심";
	this->flavor = flavor;
}


void Candy::show_info() {
	cout << flavor << "맛 사탕" << endl;
	Snack::set_last("사탕");
}


int main() {
	int num, cNum = 0, chNum = 0;
	string inFlavor, inShape;
	std::vector<Snack*> snackBasket;

	while (1) {
		cout << "과자 바구니에 추가할 간식을 고르시오. (1:사탕, 2:초콜릿, 0:종료) : ";
		cin >> num;

		if (num == 0) {
			break;
		}
		else if (num == 1) {
			cout << "맛을 입력하세요 : ";
			cin >> inFlavor;
			snackBasket.push_back(new Candy(inFlavor));
			//Candy c = Candy(inFlavor);
			//snackBasket.push_back(&c);
		}
		else if (num == 2) {
			cout << "모양을 입력하세요 : ";
			cin >> inShape;
			snackBasket.push_back(new Chocolate(inShape));
		}
		else {
			cout << "0~2 사이의 숫자를 입력하세요. " << endl;
		}
	}
	cout << endl;
	cout << "과자 바구니에 담긴 간식의 개수는 " << snackBasket.size() << "개 입니다." << endl;
	cout << "과자 바구니에 담긴 간식 확인하기 !" << endl;
	for (Snack* snack : snackBasket) {
		Candy* pc = dynamic_cast<Candy*>(snack);
		if (pc) {
			pc->show_info();
			cNum++;
		}
		else {
			Chocolate* pch = dynamic_cast<Chocolate*>(snack);
			pch->show_info();
			chNum++;
		}
	}

	for (Snack* snack : snackBasket) {
		delete snack;
	}

	// 마지막 간식 종류 출력하기.
	cout << "마지막으로 추가한 간식의 종류는 " << Snack::get_last() << "입니다." << endl;
	cout << endl;
	cout << "----------- Util 함수 사용하기 -------------" << endl;
	cout << "간식 바구니에 들어있는 간식 개수 : " << Util::add(cNum, chNum) << endl;
}