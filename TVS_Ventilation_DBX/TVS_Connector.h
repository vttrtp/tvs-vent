#pragma once
#include "StdAfx.h"
#define notConnected 0
#define CdirectConnection 1
#define CsideConnection 2
class TVS_Entity;
#ifdef TVS_VENTILATION_DBX_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
//----- Note: we don't use __declspec(dllimport) here, because of the
//----- "local vtable" problem with msvc. If you use __declspec(dllimport),
//----- then, when a client dll does a new on the class, the object's
//----- vtable pointer points to a vtable allocated in that client
//----- dll. If the client dll then passes the object to another dll,
//----- and the client dll is then unloaded, the vtable becomes invalid
//----- and any virtual calls on the object will access invalid memory.
//-----
//----- By not using __declspec(dllimport), we guarantee that the
//----- vtable is allocated in the server dll during the ctor and the
//----- client dll does not overwrite the vtable pointer after calling
//----- the ctor. And, since we expect the server dll to remain in
//----- memory indefinitely, there is no problem with vtables unexpectedly
//----- going away.
#define DLLIMPEXP
#endif



class DLLIMPEXP TVS_Connector
{
public:

	TVS_Connector(void);
	~TVS_Connector(void);
	Int8 cTypeCurrent;
	Int8 cTypeAnother;
	AcGePoint3d point;
	AcDbObjectId connectionID;
	void write(AcDbDwgFiler *pFiler) const;
	void read(AcDbDwgFiler *pFiler, const int version);

	
	
};

