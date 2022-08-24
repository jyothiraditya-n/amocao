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

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "main.h"

void AOe_report_err(int errnum) {
	switch(errnum) {
	case AOE_CORRUPT_WORLD:
		fprintf(stderr, "%s: error: corrupt world file '%s'.\n",
			AO_execfile, AO_worldfile);
		exit(errnum);

	case AOE_OUTDATED_WORLD:
		fprintf(stderr, "%s: error: outdated world file format for "
			"file '%s'.\n", AO_execfile, AO_worldfile);
		exit(errnum);

	default:
		fprintf(stderr, "%s: error: unknown error\n", AO_execfile);
		perror("cstdlib");
		exit(errnum);
	}
}