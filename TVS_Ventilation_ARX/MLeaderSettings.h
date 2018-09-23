#pragma once
#include "StdAfx.h"

class MLeaderSettings 
{
public:
	MLeaderSettings(void){
		instructionMessage=L"\
[L]-������ �3/�\r\n\
[V]-�������� �/�\r\n\
[D]-������ ��\r\n\
[P]-������ �������� P\r\n\
[BN]-��� ����� P\r\n\
[N]-��� ����\r\n\
[�������� ��������]-��������\r\n\ ��������� (��� ������)\r\n\
";
		pipeLeader =L"[D]";
		blockLeader = L"[���]-[������]";
	};
	virtual ~MLeaderSettings(void){};
	CString  instructionMessage;
	CString  pipeLeader;
	CString  blockLeader;
};