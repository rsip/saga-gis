/**********************************************************
 * Version $Id$
 *********************************************************/
/*******************************************************************************
    InvertNoData.cpp
    Copyright (C) Victor Olaya
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, 5th Floor, Boston, MA 02110-1301, USA
*******************************************************************************/ 

#include "Grid_InvertNoData.h"

CInvertNoData::CInvertNoData(void){

	Parameters.Set_Name(_TL("Invert Data/No-Data"));
	Parameters.Set_Description(_TW("(c) 2005 Victor Olaya."));

	Parameters.Add_Grid(NULL, 
						"INPUT",
						_TL("Grid"), 						
						_TL(""), 
						PARAMETER_INPUT);
	
	Parameters.Add_Grid(NULL, 
						"OUTPUT",
						_TL("Result"), 						
						_TL(""), 
						PARAMETER_OUTPUT);
}//constructor


CInvertNoData::~CInvertNoData(void)
{}

bool CInvertNoData::On_Execute(void){
	
	int x,y;
	
	CSG_Grid* pInput = Parameters("INPUT")->asGrid(); 
	CSG_Grid* pOutput = Parameters("OUTPUT")->asGrid(); 
	pOutput->Set_NoData_Value_Range(-9999,0);
				
	for(y=0; y<Get_NY() && Set_Progress(y); y++){		
		for(x=0; x<Get_NX(); x++){
			if (pInput->is_NoData(x,y)){
				pOutput->Set_Value(x, y, 1.0);
			}//if
			else{
				pOutput->Set_Value(x, y, -9999.0);
			}//else
		}//if
	}//for

	return true;

}//method