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

//Filename    :: ODYNARR.H
//Description :: Dynamic Array Object

#ifdef _ODYNARR_H_
#error "Multiple inclusion of ODYNARR.h"
#endif
#define _ODYNARR_H_

#include <string.h>


//--------- Define constant ------------//

#define DEF_DYNARRAY_BLOCK_SIZE 30	// default allocation block size (no. of unities each block has) 

//---------- Define sort types --------//

enum { SORT_INT=1,
		 SORT_SHORT,
		 SORT_CHAR,
		 SORT_CHAR_PTR,
		 SORT_CHAR_STR };

class File;

//-------- BEGIN OF CLASS DynArrary ---------//

#pragma pack(1)
class DynArray
{
public :

   int  ele_num;            // the size of the whole array
   int  block_num;          // the number of element of each block
   int  cur_pos;            // current position
   int  last_ele;           // last element position ( the array is not fully used )
   int  ele_size;           // the size of each element

   int  sort_offset;
   char sort_type;

   char* body_buf;	    // cur_pos and last_ele are start from 1 (not 0)

   //----------------------------------------------//

public :

   DynArray(int,int=DEF_DYNARRAY_BLOCK_SIZE);
   ~DynArray();

   void  resize(int);

   void  linkin(void*);
	void  linkin_unique(void*);
	void  linkout(int= -1);
   void  update(void*, int= -1);
   void  insert(void*);
	void  insert_at(int,void*);
	void  add_blank(int);

   void  init_sort(int,char);
	void  linkin_sort_scan_from_bottom(void*);
// void  resort(int);

   void* get();
   void* get(int);
   void* get_ptr() const;
   void* get_ptr(int) const;
	void  read(void*);

   int   check_pos();

   void  push(void*);
   void  pop(void* =0);

   void  start();
   void  end();
   int   fwd();
   int   bkwd();

   void  jump(int);
   void  go(int);
   int   recno();
   int   size() const;

   int   is_start();
   int   is_end();

   int   scan_whole(void*);
   int   scan(void*,int,char,int=0);
   int   compare(void*,int,char);

   void  quick_sort( int(*cmpFun)(const void*, const void*) );

   void  clean_up(int* =0);
   void  free_ptr(void*,int*);
	void  zap(int resizeFlag=1);

   int   write_file(File*);    // Write current dynamic array to file
   int   read_file(File*);     // Read dynamic array from file
};
#pragma pack()

//--------- END OF CLASS DynArray ---------//


