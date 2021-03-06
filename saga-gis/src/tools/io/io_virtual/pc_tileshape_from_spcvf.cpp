/**********************************************************
 * Version $Id$
 *********************************************************/

///////////////////////////////////////////////////////////
//                                                       //
//                         SAGA                          //
//                                                       //
//      System for Automated Geoscientific Analyses      //
//                                                       //
//                     Tool Library                      //
//                      io_virtual                       //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//              pc_tileshape_from_spcvf.cpp              //
//                                                       //
//                 Copyright (C) 2014 by                 //
//                    Volker Wichmann                    //
//                                                       //
//-------------------------------------------------------//
//                                                       //
// This file is part of 'SAGA - System for Automated     //
// Geoscientific Analyses'. SAGA is free software; you   //
// can redistribute it and/or modify it under the terms  //
// of the GNU General Public License as published by the //
// Free Software Foundation, either version 2 of the     //
// License, or (at your option) any later version.       //
//                                                       //
// SAGA is distributed in the hope that it will be       //
// useful, but WITHOUT ANY WARRANTY; without even the    //
// implied warranty of MERCHANTABILITY or FITNESS FOR A  //
// PARTICULAR PURPOSE. See the GNU General Public        //
// License for more details.                             //
//                                                       //
// You should have received a copy of the GNU General    //
// Public License along with this program; if not, see   //
// <http://www.gnu.org/licenses/>.                       //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//    e-mail:     wichmann@laserdata.at                  //
//                                                       //
//    contact:    LASERDATA GmbH                         //
//                Management and Analysis of             //
//                Laserscanning Data                     //
//                Technikerstr. 21a                      //
//                6020 Innsbruck                         //
//                Austria                                //
//                www.laserdata.at                       //
//                                                       //
///////////////////////////////////////////////////////////

//---------------------------------------------------------


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include "pc_tileshape_from_spcvf.h"


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
CPointCloud_Create_Tileshape_From_SPCVF::CPointCloud_Create_Tileshape_From_SPCVF(void)
{
	Set_Name		(_TL("Create Tileshape from Virtual Point Cloud"));

	Set_Author		(SG_T("V. Wichmann, LASERDATA GmbH (c) 2014"));

	Set_Description	(_TW(
		"The tool allows one to create a polygon shapefile with the "
		"bounding boxes of a virtual point cloud dataset. Additionally, "
		"the header information of the chosen virtual point cloud "
		"dataset is reported (since SPCVFDataset version 1.1).\n"
		"A virtual point cloud dataset is a simple XML format "
		"with the file extension .spcvf, which can be created "
		"with the 'Create Virtual Point Cloud Dataset' tool.\n\n"
	));


	//-----------------------------------------------------
	Parameters.Add_FilePath(
		NULL	, "FILENAME"		, _TL("Filename"),
		_TL("The full path and name of the .spcvf file"),
		CSG_String::Format(SG_T("%s|%s|%s|%s"),
			_TL("SAGA Point Cloud Virtual Format (*.spcvf)")	, SG_T("*.spcvf"),
			_TL("All Files")									, SG_T("*.*")
		)
 	);

	Parameters.Add_Shapes(
		NULL	, "TILE_SHP"		, _TL("Tileshape"),
		_TL("Polygon shapefile describing the bounding boxes of spcvf tiles."),
		PARAMETER_OUTPUT, SHAPE_TYPE_Polygon
	);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool CPointCloud_Create_Tileshape_From_SPCVF::On_Execute(void)
{
	CSG_String		sFileName;
	CSG_Shapes		*pShapes;

	CSG_MetaData	SPCVF;
	CSG_String		sPathSPCVF, sFilePath;
	int				iPoints;
	double			dBBoxXMin, dBBoxYMin, dBBoxXMax, dBBoxYMax, dZMin, dZMax;


	//-----------------------------------------------------
	sFileName	= Parameters("FILENAME")->asString();
	pShapes		= Parameters("TILE_SHP")->asShapes();
	

	//-----------------------------------------------------
	if( !SPCVF.Create(sFileName) || SPCVF.Get_Name().CmpNoCase(SG_T("SPCVFDataset")) )
	{
		SG_UI_Msg_Add_Error(_TL("Please provide a valid *.scpvf file!"));
		return( false );
	}


	//-----------------------------------------------------
	CSG_String	sMethodPaths;
	SPCVF.Get_Property(SG_T("Paths"), sMethodPaths);

	if( !sMethodPaths.CmpNoCase(SG_T("absolute")) )
	{
		sPathSPCVF = SG_T("");
	}
	else if( !sMethodPaths.CmpNoCase(SG_T("relative")) )
	{
		sPathSPCVF = SG_File_Get_Path(sFileName);
		sPathSPCVF.Replace(SG_T("\\"), SG_T("/"));
	}
	else
	{
		SG_UI_Msg_Add_Error(_TL("Encountered invalid path description in *.spcvf file!"));
		return( false );
	}


	//-----------------------------------------------------
	CSG_MetaData	*pSPCVFHeader = SPCVF.Get_Child(SG_T("Header"));

	if( pSPCVFHeader != NULL )	// i.e. we have a file version >= 1.1
	{
		int				iValue;
		double			dValue;
		CSG_String		sValue;
		CSG_Projection	projSPCVF;

		SG_UI_Msg_Add(SG_T(""), true);
		SG_UI_Msg_Add(_TL("Metadata from Header:"), true);

		pSPCVFHeader->Get_Child(SG_T("Datasets"))->Get_Property(SG_T("Count"), iValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("Total number of referenced datasets: %d"), iValue), true);

		pSPCVFHeader->Get_Child(SG_T("Points"))->Get_Property(SG_T("Count"), sValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("Total number of points: %s"), sValue.c_str()), true);

		pSPCVFHeader->Get_Child(SG_T("SRS"))->Get_Property(SG_T("Projection"), sValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("Spatial Reference System: %s"), sValue.c_str()), true);

		if( pSPCVFHeader->Get_Child(SG_T("SRS"))->Get_Property(SG_T("WKT"), sValue) )
			SG_UI_Msg_Add(CSG_String::Format(_TL("WKT: %s"), sValue.c_str()), true);

		pSPCVFHeader->Get_Child(SG_T("NoData"))->Get_Property(SG_T("Value"), dValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("NoData Value: %.6f"), dValue), true);

		SG_UI_Msg_Add(SG_T(""), true);
		SG_UI_Msg_Add(_TL("Overall Bounding Box:"), true);
		pSPCVFHeader->Get_Child(SG_T("BBox"))->Get_Property(SG_T("XMin"), dValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("XMin: %.6f"), dValue), true);
		pSPCVFHeader->Get_Child(SG_T("BBox"))->Get_Property(SG_T("YMin"), dValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("YMin: %.6f"), dValue), true);
		pSPCVFHeader->Get_Child(SG_T("BBox"))->Get_Property(SG_T("XMax"), dValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("XMax: %.6f"), dValue), true);
		pSPCVFHeader->Get_Child(SG_T("BBox"))->Get_Property(SG_T("YMax"), dValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("YMax: %.6f"), dValue), true);
		pSPCVFHeader->Get_Child(SG_T("ZStats"))->Get_Property(SG_T("ZMin"), dValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("ZMin: %.6f"), dValue), true);
		pSPCVFHeader->Get_Child(SG_T("ZStats"))->Get_Property(SG_T("ZMax"), dValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("ZMax: %.6f"), dValue), true);

		SG_UI_Msg_Add(SG_T(""), true);
		pSPCVFHeader->Get_Child(SG_T("Attributes"))->Get_Property(SG_T("Count"), iValue);
		SG_UI_Msg_Add(CSG_String::Format(_TL("Number of attribute fields: %d"), iValue), true);

		for (int iField=0; iField<iValue; iField++)
		{
			CSG_MetaData	*pField = pSPCVFHeader->Get_Child(SG_T("Attributes"))->Get_Child(CSG_String::Format(SG_T("Field_%d"), iField + 1));
			pField->Get_Property(SG_T("Name"), sValue);
			SG_UI_Msg_Add(CSG_String::Format(_TL("Field %d: Name=\"%s\" "), iField + 1, sValue.c_str()), true);
			pField->Get_Property(SG_T("Type"), sValue);
			SG_UI_Msg_Add(CSG_String::Format(_TL("Type=\"%s\""), sValue.c_str()), false);
		}
	}


	//-----------------------------------------------------
	pShapes->Destroy();

	pShapes->Add_Field(_TL("ID"),		SG_DATATYPE_Int);
	pShapes->Add_Field(_TL("Filepath"),	SG_DATATYPE_String);
	pShapes->Add_Field(_TL("File"),		SG_DATATYPE_String);
	pShapes->Add_Field(_TL("Points"),	SG_DATATYPE_Int);

	if( pSPCVFHeader != NULL )
	{
		pShapes->Add_Field(_TL("ZMin"),		SG_DATATYPE_Double);
		pShapes->Add_Field(_TL("ZMax"),		SG_DATATYPE_Double);
	}

	pShapes->Set_Name(CSG_String::Format(_TL("Tileshape_%s"), SG_File_Get_Name(sFileName, false).c_str()));


	//-----------------------------------------------------
	CSG_MetaData	*pDatasets = SPCVF.Get_Child(SG_T("Datasets"));

	for(int i=0; i<pDatasets->Get_Children_Count(); i++)
	{
		CSG_MetaData	*pDataset	= pDatasets->Get_Child(i);
		CSG_MetaData	*pBBox		= pDataset->Get_Child(SG_T("BBox"));

		pDataset->Get_Property(SG_T("File"), sFilePath);

		pDataset->Get_Property(SG_T("Points"), iPoints);

		pBBox->Get_Property(SG_T("XMin"), dBBoxXMin);
		pBBox->Get_Property(SG_T("YMin"), dBBoxYMin);
		pBBox->Get_Property(SG_T("XMax"), dBBoxXMax);
		pBBox->Get_Property(SG_T("YMax"), dBBoxYMax);

		//-----------------------------------------------------
		CSG_Shape	*pShape = pShapes->Add_Shape();

		pShape->Add_Point(dBBoxXMin, dBBoxYMin);
		pShape->Add_Point(dBBoxXMin, dBBoxYMax);
		pShape->Add_Point(dBBoxXMax, dBBoxYMax);
		pShape->Add_Point(dBBoxXMax, dBBoxYMin);

		pShape->Set_Value(0, i + 1);

		if( sPathSPCVF.Length() == 0 )	// absolute paths
		{
			pShape->Set_Value(1, sFilePath.BeforeLast('/'));
			pShape->Set_Value(2, sFilePath.AfterLast('/'));
		}
		else							// relative paths
		{
			pShape->Set_Value(1, sPathSPCVF);
			pShape->Set_Value(2, sFilePath);
		}

		pShape->Set_Value(3, iPoints);

		if( pSPCVFHeader != NULL )
		{
			pDataset->Get_Property(SG_T("ZMin"), dZMin);
			pDataset->Get_Property(SG_T("ZMax"), dZMax);

			pShape->Set_Value(4, dZMin);
			pShape->Set_Value(5, dZMax);
		}
	}


	//-----------------------------------------------------
	return( true );
}


//---------------------------------------------------------

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
