#pragma once
#include"Structs.h"
#include"dplay8.h"
#include<string>
#include<iostream>



using std::string;




class Client
{
private:
	HRESULT result_;
	IDirectPlay8Client *client_;
	FMessage *mes_;
	
	
public:
	Client(string ipAdderss, int portServer,string userName,string sessionName, FMessage *mes);
	~Client();
	void setMes(FMessage *mes);

	
	
	

	void sendMessage(string user, string message);
};

