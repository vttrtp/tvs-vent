#pragma once
#include "StdAfx.h"

class MLeaderSettings 
{
public:
	MLeaderSettings(void){
		instructionMessage=L"\
[L]-Расход м3/ч\r\n\
[V]-Скорость м/с\r\n\
[D]-Размер мм\r\n\
[P]-Потери давления P\r\n\
[BN]-Имя блока P\r\n\
[N]-Имя слоя\r\n\
[Название Атрибута]-Значение\r\n\ Аттрибута (Для блоков)\r\n\
";
		pipeLeader =L"[D]";
		blockLeader = L"[ТИП]-[РАЗМЕР]";
	};
	virtual ~MLeaderSettings(void){};
	CString  instructionMessage;
	CString  pipeLeader;
	CString  blockLeader;
};