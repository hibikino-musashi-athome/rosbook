//==================================================
//ソケットサーバクラスのヘッダ
//
//author: Yutaro ISHIDA
//==================================================


#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//以下2行，必ずwindows.hより先に走らせること
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib")


using namespace std;


//==================================================
//パラメータ
//==================================================


//==================================================
//グローバル
//==================================================


//==================================================
//Socketクライアントクラス
//==================================================
class SocketServer
{
private:
	WSADATA wsa_data_;

	struct sockaddr_in sockaddr_in_server_;
	SOCKET socket_server_;

	struct sockaddr_in sockaddr_in_client_;
	SOCKET socket_client_;

	fd_set fds_;

	struct timeval tv_;


public:
	//==================================================
	//コンストラクタ
	//==================================================
	SocketServer(int port);


	//==================================================
	//デストラクタ
	//==================================================
	~SocketServer();


	//==================================================
	//接続する関数
	//==================================================
	bool open_socket(void);


	//==================================================
	//切断する関数
	//==================================================
	bool close_socket(void);


	//==================================================
	//送信する関数
	//==================================================
	bool snd(float snd_data[], size_t snd_data_size);


	//==================================================
	//受信する関数
	//==================================================
	bool rcv(float rcv_data[], size_t rcv_data_size);
};

