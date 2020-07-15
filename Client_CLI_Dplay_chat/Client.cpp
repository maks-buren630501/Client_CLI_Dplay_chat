#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"





HRESULT WINAPI clientWork(PVOID pvUserContext, DWORD dwMessageId, PVOID pMsgBuffer)
{
	FMessage *mes;
	if (((mes = (FMessage*)pvUserContext)) == NULL)
		return E_FAIL;
	switch (dwMessageId)
	{
	case DPN_MSGID_CONNECT_COMPLETE:
		mes->fl = 2;
		break;
	case DPN_MSGID_RECEIVE:
		DPNMSG_RECEIVE* pReceive = (DPNMSG_RECEIVE*)pMsgBuffer;
		SMessage *message = (SMessage*)pReceive->pReceiveData;
		
		strcpy(mes->data,message->data);
		strcpy(mes->name,message->name);
		mes->fl = 1;

		break;

	}
	return E_FAIL;
}

Client::Client(string ipAdderss, int port, string userName, string sessionName, FMessage *mes)
{
	mes_ = mes;
	DPN_PLAYER_INFO descriptorPlayer_;
	DPN_APPLICATION_DESC descriptorSession_;
	CoInitialize(NULL);
	WCHAR wszSessionName[256];
	WCHAR wszPassword[256];
	WCHAR wszIpAddress[256];
	WCHAR wszPlayerName[256];
	result_ = CoCreateInstance(CLSID_DirectPlay8Client, NULL, CLSCTX_INPROC, IID_IDirectPlay8Client, (LPVOID *)& client_);
	result_ = client_->Initialize(mes, clientWork, NULL);

	IDirectPlay8Address *addressClient;
	result_ = CoCreateInstance(CLSID_DirectPlay8Address, NULL, CLSCTX_INPROC, IID_IDirectPlay8Address, (LPVOID *)&addressClient);
	DWORD portClient = 8000;
	result_ = addressClient->AddComponent(DPNA_KEY_PORT, &portClient, sizeof(DWORD), DPNA_DATATYPE_DWORD);
	result_ = addressClient->SetSP(&CLSID_DP8SP_TCPIP);

	IDirectPlay8Address *addressServer;
	result_ = CoCreateInstance(CLSID_DirectPlay8Address, NULL, CLSCTX_INPROC, IID_IDirectPlay8Address, (LPVOID *)&addressServer);
	result_ = addressServer->SetSP(&CLSID_DP8SP_TCPIP);
	DWORD portServer = port;
	result_ = addressServer->AddComponent(DPNA_KEY_PORT, &portServer, sizeof(DWORD), DPNA_DATATYPE_DWORD);
	mbstowcs(wszIpAddress, ipAdderss.c_str(), ipAdderss.length() + 1);
	result_ = addressServer->AddComponent(DPNA_KEY_HOSTNAME, wszIpAddress, (wcslen(wszIpAddress) + 1) * sizeof(WCHAR), DPNA_DATATYPE_STRING);
	
	ZeroMemory(&descriptorPlayer_, sizeof(DPN_PLAYER_INFO));
	descriptorPlayer_.dwSize = sizeof(DPN_PLAYER_INFO);
	descriptorPlayer_.dwInfoFlags = DPNINFO_NAME | DPNINFO_DATA;
	mbstowcs(wszPlayerName, userName.c_str(), userName.length() + 1);
	descriptorPlayer_.pwszName = wszPlayerName;

	client_->SetClientInfo(&descriptorPlayer_, NULL, NULL, DPNSETCLIENTINFO_SYNC);

	ZeroMemory(&descriptorSession_, sizeof(DPN_APPLICATION_DESC));
	descriptorSession_.dwSize = sizeof(DPN_APPLICATION_DESC);
	mbstowcs(wszSessionName, sessionName.c_str(), sessionName.length() + 1);
	descriptorSession_.pwszSessionName = wszSessionName;
	descriptorSession_.dwFlags = DPNSESSION_CLIENT_SERVER;

	result_ = client_->Connect(&descriptorSession_, addressServer, addressClient, NULL, NULL, NULL, 0, NULL, NULL, DPNCONNECT_SYNC);

	addressClient->Release();
	addressServer->Release();
	ZeroMemory(&descriptorPlayer_, sizeof(DPN_PLAYER_INFO));
	ZeroMemory(&descriptorSession_, sizeof(DPN_APPLICATION_DESC));
}



Client::~Client()
{
	
	client_->Release();
}







void Client::sendMessage(string user, string message)
{
	SMessage messageToSend;
	
	strcpy(messageToSend.name, user.c_str());
	strcpy(messageToSend.data, message.c_str());

	DPN_BUFFER_DESC descriptorSend;
	descriptorSend.dwBufferSize = sizeof(messageToSend);
	descriptorSend.pBufferData = (BYTE*)&messageToSend;

	DPNHANDLE g_hSendTo;

	result_ = client_->Send(&descriptorSend, 1, 0, NULL, NULL, DPNSEND_SYNC);
}
