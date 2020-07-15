#pragma once

#include"dplay8.h"
#include<iostream>

//using namespace std;

struct User
{
	DPNID id;
	std::string name;
};

struct SMessage
{
	DPNID id;
	char name[64];
	char data[256];
};

struct FMessage
{
	int fl;
	char data[256];
	char name[256];
};