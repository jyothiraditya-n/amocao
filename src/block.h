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

#ifndef AO_BLOCK_H
#define AO_BLOCK_H 1

typedef uint8_t AOb_t;
typedef uint8_t AOb_type_t;
typedef uint8_t AOb_class_t;
typedef uint8_t AOb_data_t;

extern uint8_t AOb_get_class(AOb_t b);
extern void AOb_set_class(AOb_t *b, uint8_t c);

#define AOB_FULL 0
#define AOB_STAIR 1
#define AOB_SLAB 2
#define AOB_OTHER 3
#define AOB_DOOR 4
#define AOB_TRAPDOOR 5
#define AOB_LADDER 6
#define AOB_LIQUID 7

extern uint8_t AOb_get_type(AOb_t b);
extern void AOb_set_type(AOb_t *b, uint8_t t);

#define AOB_AIR 0
#define AOB_STONE 1
#define AOB_COBBLE 2
#define AOB_DIRT 3
#define AOB_SAND 4
#define AOB_GRAVEL 5
#define AOB_CLAY 6
#define AOB_BRICK 7
#define AOB_OAK_LOG 8
#define AOB_OAK_PLANK 9
#define AOB_BIRCH_LOG 10
#define AOB_BIRCH_PLANK 11
#define AOB_LEAF 12
#define AOB_WATER 13
#define AOB_LAVA 14
#define AOB_GLASS 15
#define AOB_TORCH 16
#define AOB_COAL 17
#define AOB_IRON 18
#define AOB_GOLD 19
#define AOB_DIAMOND 20
#define AOB_WHITE_WOOL 21
#define AOB_BED_HEAD 22
#define AOB_BED_FOOT 23
#define AOB_ROSE 24
#define AOB_SUNFLOWER 25
#define AOB_CACTUS 26
#define AOB_DEADBUSH 27
#define AOB_VINES 28
#define AOB_RED_MUSHROOM 29
#define AOB_WHITE_MUSHROOM 30
#define AOB_MUSHROOM_STALK 31

#endif