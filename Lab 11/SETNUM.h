#pragma once
#include <cstdio>

class SETNUM
{
private:
	int* x;
	int size;
	void Init(int z);
	int Element(int z) const;
	void AddSort(int k, int z);
	void DelSort(int k, int z);
	const int MAX = 1000;
	const int MIN = -1000;

public:
	SETNUM(); 
	SETNUM(int z); 
	SETNUM(const SETNUM& set, int z = 1000); 
	void Output() const;
	bool Contains(int z) const;
	void AddElement(int z = 0);
	void DeleteElement(int z = 0);
	explicit operator int() const; 
	~SETNUM(); 
	
	SETNUM& operator += (int z);
	SETNUM& operator -= (int z);
	SETNUM& operator = (const SETNUM& other);
	SETNUM operator + (const SETNUM& other) const;
	SETNUM operator - (const SETNUM& other) const;
	SETNUM operator * (const SETNUM& other) const;
	bool operator == (const SETNUM& other) const;
};
