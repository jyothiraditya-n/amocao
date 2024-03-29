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

#include "main.h"

char *AO_execfile;
char *AO_configfile;
char *AO_worldfile;

ssize_t AO_x, AO_y, AO_z;
ssize_t AO_chunk_x, AO_chunk_y, AO_chunk_z; 

int main(int argc, char **argv) {
        AO_execfile = argv[0];
        (void) argc;

        return 0;
}