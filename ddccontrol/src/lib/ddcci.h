/*
    ddc/ci interface functions header
    Copyright(c) 2004 Oleg I. Vdovikin (oleg@cs.msu.su)
    Copyright(c) 2004 Nicolas Boichat (nicolas@boichat.ch)

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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef DDCCI_H
#define DDCCI_H

#include <time.h>
#include <sys/time.h>

#include "monitor_db.h"

struct monitor {
	int fd;
	unsigned int addr;
	unsigned char pnpid[8];
	unsigned char digital; /* 0 - digital, 1 - analog */
	struct timeval last;
	struct monitor_db* db;
};

/* Struct used to return control parameters read */
struct control_ret {
	unsigned char supported;
	unsigned short value;
	unsigned short maximum;
};

int ddcci_open(struct monitor* mon, const char* filename);
int ddcci_save(struct monitor* mon);
int ddcci_close(struct monitor* mon);

int ddcci_writectrl(struct monitor* mon, unsigned char ctrl, unsigned short value);
int ddcci_readctrl(struct monitor* mon, unsigned char ctrl, int force, struct control_ret* ctrl_ret);

int ddcci_caps(struct monitor* mon, unsigned char *buffer, unsigned int buflen);

/* verbosity level (0 - normal, 1 - encoded data, 2 - ddc/ci frames) */
extern int verbosity;

#endif //DDCCI_H