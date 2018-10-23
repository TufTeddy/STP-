#ifndef FRACTION_H
#define FRACTION_H
//#define _CRT_SECURE_NO_WARNINGS

#pragma once

//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>


class Fraction
{

private:
	int numerator;
	int denominator;

public:
	Fraction()
	{
		numerator = 0;
		denominator = 0;
	}
	Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
	{}
	Fraction(std::string FractionString);

	~Fraction()
	{}
	int getNum();
	int getDen();
	std::string getNumString();
	std::string getFracString();
	std::string getDenString();
	void setNum(int num);
	void setDen(int den);
	void unary();
	int gcd(int a, int b);
	void reduction();
	Fraction operator = (const Fraction &firstFrac);

	bool convertStringToFraction(std::string FractionString);
	Fraction sum(Fraction, Fraction);
	Fraction multi(Fraction, Fraction);
	Fraction divide(Fraction, Fraction);
	Fraction subtract(Fraction, Fraction);
	Fraction square(Fraction);
	void reroll();
	Fraction copy(Fraction);


	/*
	friend Fraction operator + (const Fraction &firstFrac, const Fraction &secondFrac);
	friend Fraction operator + (Fraction &frac, int term);
	friend Fraction operator + (int term, Fraction &frac);
	friend Fraction operator - (Fraction &firstFrac, Fraction &secondFrac);
	friend Fraction operator - (Fraction &frac, int term);
	friend Fraction operator - (int term, Fraction &frac);
	friend Fraction operator * (Fraction &firstFrac, Fraction &secondFrac);
	friend Fraction operator * (Fraction &frac, int mul);
	friend Fraction operator * (int mul, Fraction &frac);
	friend Fraction operator / (Fraction &firstFrac, Fraction &secondFrac);
	friend Fraction operator / (Fraction &frac, int div);
	friend Fraction operator / (int div, Fraction &frac);
	*/

};

#endif FRACTION_H