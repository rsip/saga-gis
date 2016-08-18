/**********************************************************
 * Version $Id: Flow_BRM.h 1921 2014-01-09 10:24:11Z oconrad $
 *********************************************************/

///////////////////////////////////////////////////////////
//                                                       //
//                         SAGA                          //
//                                                       //
//      System for Automated Geoscientific Analyses      //
//                                                       //
//                     Tool Library                      //
//                     ta_hydrology                      //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//                      Flow_BRM.h                       //
//                                                       //
//                 Copyright (C) 2003 by                 //
//                      Olaf Conrad                      //
//                                                       //
//-------------------------------------------------------//
//                                                       //
// This file is part of 'SAGA - System for Automated     //
// Geoscientific Analyses'. SAGA is free software; you   //
// can redistribute it and/or modify it under the terms  //
// of the GNU General Public License as published by the //
// Free Software Foundation; version 2 of the License.   //
//                                                       //
// SAGA is distributed in the hope that it will be       //
// useful, but WITHOUT ANY WARRANTY; without even the    //
// implied warranty of MERCHANTABILITY or FITNESS FOR A  //
// PARTICULAR PURPOSE. See the GNU General Public        //
// License for more details.                             //
//                                                       //
// You should have received a copy of the GNU General    //
// Public License along with this program; if not,       //
// write to the Free Software Foundation, Inc.,          //
// 51 Franklin Street, 5th Floor, Boston, MA 02110-1301, //
// USA.                                                  //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//    e-mail:     oconrad@saga-gis.org                   //
//                                                       //
//    contact:    Olaf Conrad                            //
//                Institute of Geography                 //
//                University of Goettingen               //
//                Goldschmidtstr. 5                      //
//                37077 Goettingen                       //
//                Germany                                //
//                                                       //
///////////////////////////////////////////////////////////

//---------------------------------------------------------


///////////////////////////////////////////////////////////
//														 //
//                                                       //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#ifndef HEADER_INCLUDED__Flow_BRM_H
#define HEADER_INCLUDED__Flow_BRM_H


///////////////////////////////////////////////////////////
//														 //
//                                                       //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
const int BRM_BitMtrx[][8]		=
{
	{	0, 0, 0, 0, 1, 1, 1, 1	},
	{	0, 0, 1, 1, 0, 0, 1, 1	},
	{	0, 1, 0, 1, 0, 1, 0, 1	}
};

//---------------------------------------------------------
const double BRM_g[][6][9][9]	=
{
	{
		{
			{0.345491,0.330817,0.308609,0.280762,0.250000,0.219238,0.191391,0.169183,0.154509,},
			{0.264419,0.258082,0.250888,0.238153,0.219238,0.196386,0.172987,0.152978,0.140142,},
			{0.187701,0.191733,0.200746,0.201406,0.191391,0.172987,0.149627,0.126499,0.112621,},
			{0.104968,0.129630,0.160199,0.172795,0.169183,0.152978,0.126499,0.092593,0.069122,},
			{0.000000,0.078549,0.109329,0.119501,0.118034,0.108228,0.090155,0.059574,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,}
		},
		{
			{0.345491,0.330817,0.308609,0.280762,0.250000,0.219238,0.191391,0.169183,0.154509,},
			{0.440699,0.416145,0.374720,0.327309,0.280762,0.238153,0.201406,0.172795,0.154740,},
			{0.563105,0.521569,0.448881,0.374720,0.308609,0.250888,0.200746,0.160199,0.136573,},
			{0.734773,0.648148,0.521569,0.416145,0.330817,0.258082,0.191733,0.129630,0.091137,},
			{1.000000,0.633284,0.450774,0.340339,0.263932,0.204204,0.150258,0.090469,0.000000,},
			{0.734773,0.648148,0.521569,0.416145,0.330817,0.258082,0.191733,0.129630,0.091137,},
			{0.563105,0.521569,0.448881,0.374720,0.308609,0.250888,0.200746,0.160199,0.136573,},
			{0.440699,0.416145,0.374720,0.327309,0.280762,0.238153,0.201406,0.172795,0.154740,},
			{0.345491,0.330817,0.308609,0.280762,0.250000,0.219238,0.191391,0.169183,0.154509,}
		},
		{
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.078549,0.109329,0.119501,0.118034,0.108228,0.090155,0.059574,0.000000,},
			{0.104968,0.129630,0.160199,0.172795,0.169183,0.152978,0.126499,0.092593,0.069122,},
			{0.187701,0.191733,0.200746,0.201406,0.191391,0.172987,0.149627,0.126499,0.112621,},
			{0.264419,0.258082,0.250888,0.238153,0.219238,0.196386,0.172987,0.152978,0.140142,},
			{0.345491,0.330817,0.308609,0.280762,0.250000,0.219238,0.191391,0.169183,0.154509,}
		},
		{
			{0.154509,0.169183,0.191391,0.219238,0.250000,0.280762,0.308609,0.330817,0.345491,},
			{0.140142,0.152978,0.172987,0.196386,0.219238,0.238153,0.250888,0.258082,0.264419,},
			{0.112621,0.126499,0.149627,0.172987,0.191391,0.201406,0.200746,0.191733,0.187701,},
			{0.069122,0.092593,0.126499,0.152978,0.169183,0.172795,0.160199,0.129630,0.104968,},
			{0.000000,0.059574,0.090155,0.108228,0.118034,0.119501,0.109329,0.078549,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,}
		},
		{
			{0.154509,0.169183,0.191391,0.219238,0.250000,0.280762,0.308609,0.330817,0.345491,},
			{0.154740,0.172795,0.201406,0.238153,0.280762,0.327309,0.374720,0.416145,0.440699,},
			{0.136573,0.160199,0.200746,0.250888,0.308609,0.374720,0.448881,0.521569,0.563105,},
			{0.091137,0.129630,0.191733,0.258082,0.330817,0.416145,0.521569,0.648148,0.734773,},
			{0.000000,0.090469,0.150258,0.204204,0.263932,0.340339,0.450774,0.633284,1.000000,},
			{0.091137,0.129630,0.191733,0.258082,0.330817,0.416145,0.521569,0.648148,0.734773,},
			{0.136573,0.160199,0.200746,0.250888,0.308609,0.374720,0.448881,0.521569,0.563105,},
			{0.154740,0.172795,0.201406,0.238153,0.280762,0.327309,0.374720,0.416145,0.440699,},
			{0.154509,0.169183,0.191391,0.219238,0.250000,0.280762,0.308609,0.330817,0.345491,}
		},
		{
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
			{0.000000,0.059574,0.090155,0.108228,0.118034,0.119501,0.109329,0.078549,0.000000,},
			{0.069122,0.092593,0.126499,0.152978,0.169183,0.172795,0.160199,0.129630,0.104968,},
			{0.112621,0.126499,0.149627,0.172987,0.191391,0.201406,0.200746,0.191733,0.187701,},
			{0.140142,0.152978,0.172987,0.196386,0.219238,0.238153,0.250888,0.258082,0.264419,},
			{0.154509,0.169183,0.191391,0.219238,0.250000,0.280762,0.308609,0.330817,0.345491,}
		}
	},
	{
		{
			{0.184954, 0.195678, 0.206211, 0.218885, 0.237326, 0.264926, 0.302961, 0.350137, 0.403465, },
			{0.187304, 0.205676, 0.224237, 0.244886, 0.270252, 0.302863, 0.344245, 0.394455, 0.452059, },
			{0.187375, 0.212801, 0.238204, 0.265388, 0.296596, 0.334049, 0.379489, 0.433875, 0.497181, },
			{0.187123, 0.218448, 0.249297, 0.281563, 0.317339, 0.358716, 0.407592, 0.465548, 0.533783, },
			{0.151145, 0.174340, 0.197249, 0.221815, 0.250000, 0.283866, 0.325671, 0.378026, 0.444182, },
			{0.186204, 0.217967, 0.249127, 0.281652, 0.317687, 0.359370, 0.408659, 0.467227, 0.536440, },
			{0.185979, 0.212089, 0.238006, 0.265632, 0.297289, 0.335277, 0.381436, 0.436861, 0.501737, },
			{0.185904, 0.205012, 0.224165, 0.245341, 0.271250, 0.304513, 0.346764, 0.398187, 0.457497, },
			{0.183850, 0.195258, 0.206368, 0.219565, 0.238548, 0.266808, 0.305723, 0.354090, 0.408980, }
		},
		{
			{0.407523, 0.450476, 0.487960, 0.514650, 0.525349, 0.517453, 0.492761, 0.456235, 0.413422, },
			{0.357530, 0.397162, 0.429535, 0.451236, 0.459496, 0.453069, 0.432803, 0.401272, 0.361916, },
			{0.313086, 0.351332, 0.380898, 0.399862, 0.406807, 0.401119, 0.383189, 0.354296, 0.316329, },
			{0.277300, 0.314518, 0.342082, 0.359218, 0.365322, 0.360114, 0.343738, 0.316699, 0.279720, },
			{0.201455, 0.223136, 0.238093, 0.246948, 0.250000, 0.247324, 0.238810, 0.224130, 0.202635, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, }
		},
		{
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.201455, 0.223136, 0.238093, 0.246948, 0.250000, 0.247324, 0.238810, 0.224130, 0.202635, },
			{0.275564, 0.313320, 0.341185, 0.358475, 0.364626, 0.359370, 0.342839, 0.315497, 0.277975, },
			{0.309928, 0.349057, 0.379149, 0.398390, 0.405421, 0.399645, 0.381436, 0.352013, 0.313152, },
			{0.353491, 0.394089, 0.427084, 0.449129, 0.457500, 0.450961, 0.430347, 0.398187, 0.357854, },
			{0.403100, 0.446932, 0.485032, 0.512085, 0.522904, 0.514889, 0.489833, 0.452683, 0.408980, }
		},
		{
			{0.407523, 0.353846, 0.305829, 0.266465, 0.237326, 0.217621, 0.204277, 0.193627, 0.183113, },
			{0.455166, 0.397162, 0.346228, 0.303878, 0.270252, 0.244068, 0.222952, 0.204274, 0.186025, },
			{0.499538, 0.435867, 0.380898, 0.334749, 0.296596, 0.264832, 0.237322, 0.211829, 0.186491, },
			{0.535577, 0.467034, 0.408621, 0.359218, 0.317339, 0.281170, 0.248670, 0.217753, 0.186496, },
			{0.445945, 0.379388, 0.326565, 0.284288, 0.250000, 0.221487, 0.196709, 0.173714, 0.150548, },
			{0.538232, 0.468713, 0.409688, 0.359872, 0.317687, 0.281259, 0.248501, 0.217276, 0.185584, },
			{0.504093, 0.438854, 0.382846, 0.335978, 0.297289, 0.265078, 0.237129, 0.211126, 0.185110, },
			{0.460605, 0.400899, 0.348751, 0.305529, 0.271250, 0.244525, 0.222889, 0.203625, 0.184649, },
			{0.413049, 0.357811, 0.308599, 0.268350, 0.238548, 0.218303, 0.204444, 0.193227, 0.182039, }
		},
		{
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, }
		},
		{
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, },
			{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, }
		}
	}
};


///////////////////////////////////////////////////////////
//														 //
//                                                       //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__Flow_BRM_H
