/*
 * Seven Kingdoms: Ancient Adversaries
 *
 * Copyright 2010 Jesse Allen
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

//Filename    : asmfun.h
//Description : Header file for asm compilation

#ifdef _ASMFUN_H_
#error "Multiple inclusion of asmfun.h"
#endif
#define _ASMFUN_H_

#ifdef USE_ASM
#ifdef _MSC_VER
	#include <windows.h>
	#define IMGcall _stdcall
#else
	#define IMGcall __attribute__((stdcall))
#endif
#else
#define IMGcall
#endif

