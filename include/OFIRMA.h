/*
 * Seven Kingdoms: Ancient Adversaries
 *
 * Copyright 1997,1998 Enlight Software Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//Filename    : OFIRMA.H
//Description : Object Firm Array

#ifdef _OFIRMA_H_
#error "Multiple inclusion of OFIRMA.h"
#endif
#define _OFIRMA_H_

#include <ODYNARRB.h>

//--------- Define class FirmArray ----------//

class Firm;

class FirmArray : public DynArrayB
{
public:
	int	 selected_recno;		// the firm current being selected

private:
	int    process_recno;

public:
   FirmArray();
   ~FirmArray();

	void  init();
   void  deinit();

	int 	build_firm(int xLoc, int yLoc, int nationRecno, int firmId, char* buildCode=NULL, short builderRecno=0);
	int   create_firm(int);
   void  del_firm(int);
   int   firm_class_size(int);

	int   process();
	void  next_day();
	void  next_month();
	void  next_year();

	void	draw_dot();
	//### begin alex 12/9 ###//
	void	draw_profile();
	//#### end alex 12/9 ####//
	void  skip(int);

	int   write_file(File*);
	int   read_file(File*);

	#ifdef DYNARRAY_DEBUG_ELEMENT_ACCESS
		Firm* operator()();             // reference to current Firm record
		Firm* operator[](int recNo);
	#else
		Firm* operator()()	    		{ return (Firm*) get_ptr(); }
		Firm* operator[](int recNo)   { return (Firm*) get_ptr(recNo); }
	#endif

	int   is_deleted(int recNo)    // whether the item is deleted or not
			{ return get_ptr(recNo) == NULL; }

};

//---------------------------------------------//

class  MLink;

extern MLink     firm_mlink;
extern FirmArray firm_array;

//---------------------------------------------//
