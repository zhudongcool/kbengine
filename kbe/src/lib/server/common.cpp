// Copyright 2008-2018 Yolo Technologies, Inc. All Rights Reserved. https://www.comblockengine.com


#include "common.h"
#include "server/serverconfig.h"

namespace KBEngine { 

//-------------------------------------------------------------------------------------
int32 secondsToTicks(float seconds, int lowerBound)
{
	return std::max(lowerBound, int(floorf(seconds * g_kbeSrvConfig.gameUpdateHertz() + 0.5f)));
}

//-------------------------------------------------------------------------------------
uint16 datatype2id(std::string datatype)
{
	std::transform(datatype.begin(), datatype.end(), datatype.begin(), toupper);	
	if (datatype == "STRING" || datatype == "STD::STRING")
		return 1;
	else if (datatype == "UINT8" || datatype == "BOOL" || datatype == "DATATYPE" || datatype == "CHAR" || datatype == "DETAIL_TYPE" ||
		datatype == "ENTITYCALL_CALL_TYPE")
		return 2;
	else if (datatype == "UINT16" || datatype == "UNSIGNED SHORT" || datatype == "SERVER_ERROR_CODE" || datatype == "ENTITY_TYPE" ||
		datatype == "ENTITY_PROPERTY_UID" || datatype == "ENTITY_METHOD_UID" || datatype == "ENTITY_SCRIPT_UID" || datatype == "DATATYPE_UID")
		return 3;
	else if (datatype == "UINT32" || datatype == "UINT" || datatype == "UNSIGNED INT" || datatype == "ARRAYSIZE" || datatype == "SPACE_ID" || datatype == "GAME_TIME" ||
		datatype == "TIMER_ID")
		return 4;
	else if (datatype == "UINT64" || datatype == "DBID" || datatype == "COMPONENT_ID")
		return 5;
	else if (datatype == "INT8" || datatype == "COMPONENT_ORDER")
		return 6;
	else if (datatype == "INT16" || datatype == "SHORT")
		return 7;
	else if (datatype == "INT32" || datatype == "INT" || datatype == "ENTITY_ID" || datatype == "CALLBACK_ID" || datatype == "COMPONENT_TYPE")
		return 8;
	else if (datatype == "INT64")
		return 9;
	else if (datatype == "PYTHON" || datatype == "PY_DICT" || datatype == "PY_TUPLE" || datatype == "PY_LIST" || datatype == "ENTITYCALL")
		return 10;
	else if (datatype == "BLOB")
		return 11;
	else if (datatype == "UNICODE")
		return 12;
	else if (datatype == "FLOAT")
		return 13;
	else if (datatype == "DOUBLE")
		return 14;
	else if (datatype == "VECTOR2")
		return 15;
	else if (datatype == "VECTOR3")
		return 16;
	else if (datatype == "VECTOR4")
		return 17;
	else if (datatype == "FIXED_DICT")
		return 18;
	else if (datatype == "ARRAY")
		return 19;
	else if (datatype == "KBE_DATATYPE2ID_MAX")
		return KBE_DATATYPE2ID_MAX;

	return 0;
}

//-------------------------------------------------------------------------------------
std::string datatype2nativetype(std::string datatype)
{
	uint16 tid = datatype2id(datatype);
	return datatype2nativetype(tid);
}

//-------------------------------------------------------------------------------------
std::string datatype2nativetype(uint16 datatype)
{
	switch (datatype)
	{
	case 1:
		return "STRING";
		break;
	case 2:
		return "UINT8";
		break;
	case 3:
		return "UINT16";
		break;
	case 4:
		return "UINT32";
		break;
	case 5:
		return "UINT64";
		break;
	case 6:
		return "INT8";
		break;
	case 7:
		return "INT16";
		break;
	case 8:
		return "INT32";
		break;
	case 9:
		return "INT64";
		break;
	case 10:
		return "PYTHON";
		break;
	case 11:
		return "BLOB";
		break;
	case 12:
		return "UNICODE";
		break;
	case 13:
		return "FLOAT";
		break;
	case 14:
		return "DOUBLE";
		break;
	case 15:
		return "VECTOR2";
		break;
	case 16:
		return "VECTOR3";
		break;
	case 17:
		return "VECTOR4";
		break;
	case 18:
		return "FIXED_DICT";
		break;
	case 19:
		return "ARRAY";
		break;
	default:
		break;
	};

	return "";
}

//-------------------------------------------------------------------------------------
}
