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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>

#include <LC_vars.h>
#include <LC_files.h>

#include "block.h"
#include "chunk.h"
#include "error.h"
#include "main.h"

AOc_t *AOc_chunks;
ssize_t AOc_radius = 4;

static ssize_t length = 9;
static size_t chunk_data_len = 4096;
static char filename[4096];

void AOc_init() {
	length = 2 * AOc_radius + 1;
	AOc_chunks = malloc(sizeof(AOc_t) * length * length * length);
	if(!AOc_chunks) AOe_report_err(AOE_UNKNOWN_ERROR);

	for(ssize_t i = -AOc_radius; i <= AOc_radius; i++)
		for(ssize_t j = -AOc_radius; j <= AOc_radius; j++)
		for(ssize_t k = -AOc_radius; k <= AOc_radius; k++)
	{
		AOc_t *chunk = AOc_get(i, j, k);

		if(i != -AOc_radius) chunk -> back = AOc_get(i - 1, j, k);
		if(i != AOc_radius) chunk -> front = AOc_get(i + 1, j, k);

		if(j != -AOc_radius) chunk -> left = AOc_get(i, j - 1, k);
		if(j != AOc_radius) chunk -> right = AOc_get(i, j + 1, k);

		if(k != -AOc_radius) chunk -> bottom = AOc_get(i, j, k - 1);
		if(k != AOc_radius) chunk -> top = AOc_get(i, j, k + 1);

		chunk -> x = i;
		chunk -> y = j;
		chunk -> z = k;
	}
}

AOc_t *AOc_get(ssize_t x, ssize_t y, ssize_t z) {
	x += AOc_radius - AO_chunk_x;
	y += AOc_radius - AO_chunk_y;
	z += AOc_radius - AO_chunk_z;

	return &AOc_chunks[x + y * length + z * length * length];
}

void AOc_read(AOc_t *chunk) {
	LCv_clear();

	LCv_t *var = LCv_new(); var -> id = "blocks";
	var -> data = chunk -> blocks; var -> len = &chunk_data_len;
	var -> min_len = var -> max_len = 4096;
	var -> size = sizeof(AOb_t);

	var = LCv_new(); var -> id = "data";
	var -> data = chunk -> data; var -> len = &chunk_data_len;
	var -> min_len = var -> max_len = 4096;
	var -> size = sizeof(AOb_data_t);

	size_t len = strlen(AO_worldfile);
	strncpy(filename, AO_worldfile, 4096);
	snprintf(filename + len, 4096 - len, "/chunk %zd, %zd, %zd",
		AO_chunk_x + chunk -> x, AO_chunk_y + chunk -> y,
		AO_chunk_z + chunk -> z);

	int ret = LCf_read(filename);

	switch(ret) {
	case LCF_FILEIO_ERR:
		AOe_report_err(AOE_UNKNOWN_ERROR);
		break;

	case LCF_BAD_FORMAT:
	case LCF_BAD_ARCH:
	case LCF_BAD_VAR:
	case LCF_BAD_LEN:
		AOe_report_err(AOE_CORRUPT_WORLD);
		break;

	case LCF_BAD_LCF_VER:
	case LCF_BAD_PROG_VER:
	case LCF_BAD_PROG_NAME:
		AOe_report_err(AOE_OUTDATED_WORLD);
	}
}

void AOc_save(AOc_t *chunk) {
	LCv_clear();

	LCv_t *var = LCv_new(); var -> id = "blocks";
	var -> data = chunk -> blocks; var -> len = &chunk_data_len;
	var -> min_len = var -> max_len = 4096;
	var -> size = sizeof(AOb_t);

	var = LCv_new(); var -> id = "data";
	var -> data = chunk -> data; var -> len = &chunk_data_len;
	var -> min_len = var -> max_len = 4096;
	var -> size = sizeof(AOb_data_t);

	size_t len = strlen(AO_worldfile);
	strncpy(filename, AO_worldfile, 4096);
	snprintf(filename + len, 4096 - len, "/chunk %zd, %zd, %zd",
		AO_chunk_x + chunk -> x, AO_chunk_y + chunk -> y,
		AO_chunk_z + chunk -> z);

	int ret = LCf_save(filename);
	if(ret == LCF_FILEIO_ERR) AOe_report_err(AOE_UNKNOWN_ERROR);
}