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

// Filename    : OB_PROJ.H
// Description : header file for Projectile

#ifdef _OB_PROJ_H_
#error "Multiple inclusion of OB_PROJ.h"
#endif
#define _OB_PROJ_H_

#include <OBULLET.h>

#pragma pack(1)
class Projectile : public Bullet
{
public:
	float z_coff;			// height = z_coff * (cur_step) * (total_step - cur_step)
	Sprite	act_bullet;
	Sprite	bullet_shadow;

public:
	Projectile();
	~Projectile();
	void	init(char parentType, short parentRecno, short targetXLoc, short targetYLoc, char targetMobileType); // virtual function from obullet.h
	void	deinit();
	char	display_layer();
	void	draw();

	int	write_derived_file(File *);
	int	read_derived_file(File *);

	//-------------- multiplayer checking codes ---------------//
	virtual	UCHAR crc8();
	virtual	void	clear_ptr();
};
#pragma pack()
