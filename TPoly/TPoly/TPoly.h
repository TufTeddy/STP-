#pragma once

#include <string>
#include <list>

class TPoly
{
public:
	class TMember
	{
	private:
		int fact;

		int exp;

	public:
		explicit TMember(int k = 0, int n = 0);

		int getExp() const;

		int getFactor() const;

		void setExp(int n);

		void setFactor(int k);

		bool operator==(const TMember &sec);

		TMember differentiate();

		double calculate(double a);

		std::string toString();
	};

	explicit TPoly(int k = 0, int n = 0);

	int getExp();

	int getFactor(int exp);

	void clear();

	TPoly operator+(const TMember &elem);

	TPoly operator+(const TPoly &sec);

	TPoly operator-(const TMember &elem);

	TPoly operator-(const TPoly &sec);

	TPoly operator*(const TMember &elem);

	TPoly operator*(const TPoly &sec);

	TPoly operator-();

	bool operator==(const TPoly &sec);

	TPoly differentiate();

	double calculate(double a);

	TMember &elemAt(int idx);

	TPoly &operator=(const TPoly &sec) = default;

private:
	std::list<TMember> polynom;
};

