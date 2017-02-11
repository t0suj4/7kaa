/*
 * Seven Kingdoms: Ancient Adversaries
 *
 * Copyright 1997,1998 Enlight Software Ltd.
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

//Filename    : OMOUSE.H
//Description : Header file for Mouse Handling Object (OMOUSE.CPP)

#ifdef _OMOUSE_H_
#error "Multiple inclusion of OMOUSE.h"
#endif
#define _OMOUSE_H_

//------ Default settting ---------//

#define DEFAULT_DOUBLE_SPEED_THRESHOLD 8
#define DEFAULT_TRIPLE_SPEED_THRESHOLD 16

#if defined(USE_SDL)
#include <mouse_sdl.h>
#else
#error "A input backend must be specified."
#endif

extern Mouse mouse;
