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

#include <stdint.h>

#include "block.h"

AOb_class_t AOb_class(AOb_t b) {
	return b & 0b00000111;
}

void AOb_set_class(AOb_t *b, AOb_class_t c) {
	*b &= 0b11111000;
	*b |= c;
}

AOb_type_t uint8_type(AOb_t b) {
	return (b & 0b11111000) >> 3;
}

void AOb_set_type(AOb_t *b, AOb_type_t t) {
	*b &= 0b00000111;
	*b |= t << 3;
}