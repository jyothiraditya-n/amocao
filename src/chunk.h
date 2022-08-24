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

#include <stddef.h>
#include <stdint.h>

#include <sys/types.h>

#include "block.h"

#ifndef AO_CHUNK_H
#define AO_CHUNK_H 1

typedef struct AOc_s {
	struct AOc_s *front, *back;
	struct AOc_s *left, *right;
	struct AOc_s *top, *bottom;

	ssize_t x, y, z;

	AOb_t blocks[4096];
	AOb_data_t data[4096];

} AOc_t;

extern AOc_t *AOc_chunks;
extern ssize_t AOc_radius;

extern void AOc_init();
extern AOc_t *AOc_get(ssize_t x, ssize_t y, ssize_t z);

extern void AOc_read(AOc_t *chunk);
extern void AOc_save(AOc_t *chunk);

#endif