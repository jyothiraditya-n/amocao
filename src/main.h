/* Amacao: A Mind of Order & Chaos
 * Copyright (C) 2022 Jyothiraditya Nellakra
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>. */

#include <sys/types.h>

#ifndef AO_MAIN_H
#define AO_MAIN_H 1

#define AO_VERSION 1
#define AO_SUBVERSION 0

extern char *AO_execfile;
extern char *AO_configfile;
extern char *AO_worldfile;

extern ssize_t AO_x, AO_y, AO_z;
extern ssize_t AO_chunk_x, AO_chunk_y, AO_chunk_z; 

#endif