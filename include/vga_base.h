/*
 * Seven Kingdoms: Ancient Adversaries
 *
 * Copyright 1997,1998 Enlight Software Ltd.
 * Copyright 2010,2015 Jesse Allen
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

//Filename    : vga_base.h
//Description : Defines the base vga class

#ifdef _VGA_BASE_H_
#error "Multiple inclusion of vga_base.h"
#endif
#define _VGA_BASE_H_

#include <COLOR.h>

//----------- define constants ----------//

#define VGA_WIDTH             800
#define VGA_HEIGHT            600
#define VGA_BPP                 8

#define MAX_BRIGHTNESS_ADJUST_DEGREE 10

//----------- Define constant -------------//

#define IF_LIGHT_BORDER_COLOR     V_WHITE
#define IF_DARK_BORDER_COLOR      V_BLACK
#define IF_UP_BRIGHTNESS_ADJUST   5
#define IF_DOWN_BRIGHTNESS_ADJUST 6

//-------- Define macro functions ---------//

#define get_bitmap_width(bitmapPtr)  (*(short*)bitmapPtr)
#define get_bitmap_height(bitmapPtr) (*((short*)bitmapPtr+1))

//-------- Define class Vga ----------------//
class VgaBuf;
class VgaBase
{
public:
	static VgaBuf* active_buf;
	static char    use_back_buf;
	static char    opaque_flag;

public:
	VgaBase() {};
	~VgaBase() {};
 
	virtual int    init() =0;
	virtual void   deinit() =0;

	virtual char   is_inited() =0;

	virtual int    set_custom_palette(char*) =0;
	virtual void   free_custom_palette() =0;
	virtual void   adjust_brightness(int changeValue) =0;

	void use_front();
	void use_back();

	virtual void handle_messages() =0;
	virtual void flag_redraw() =0;
	virtual int is_full_screen() =0;
	virtual int is_input_grabbed() =0;
	virtual void set_full_screen_mode(int mode) =0;
	virtual void set_window_grab(int mode) =0;
	virtual void flip() =0;
};

//--------------------------------------------//
