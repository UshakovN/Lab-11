#pragma once
#include <cstdio>


class REPEAT_DEL
{
private:
	const char* error;

public:
	REPEAT_DEL(const char* str);
	void GetInfo() const;
};


class REPEAT_ADD
{
private:
	const char* error;

public:
	REPEAT_ADD(const char* str);
	void GetInfo() const;
};

class BAD_VALUE
{
private:
	const char* error;

public:
	BAD_VALUE(const char* str);
	void GetInfo() const;
};
