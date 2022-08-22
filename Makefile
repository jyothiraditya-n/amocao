# Amacao: A Mind of Order & Chaos
# Copyright (C) 2021-2022 Jyothiraditya Nellakra
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see <https://www.gnu.org/licenses/>.

HEADERS = $(wildcard src/*.h)
HEADERS += $(wildcard libClame/inc/*.h)

CFILES = $(shell find src/ -name "*.c")
OBJS = $(patsubst %.c,%.o,$(CFILES))
LIBS = libClame/libClame.a libScricon/libScricon.a

CC = gcc
AS = as
LD = ld

CPPFLAGS += -Wall -Wextra -Wpedantic -std=gnu17 -O3
CPPFLAGS += -I libClame/inc/ -I libScricon/inc/
CFLAGS += -std=gnu17 -O3 -s

LDLIBS += -L libClame/ -lClame -L libScricon/ -lScricon -lm -lpthread

DESTDIR ?= ~/.local/bin

files = $(wildcard amocao)
files += $(foreach obj,$(OBJS),$(wildcard $(obj)))

CLEAN = $(foreach file,$(files),rm $(file);)

$(DESTDIR) : 
	mkdir -p $(DESTDIR)/

$(OBJS) : %.o : %.c $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

libClame/libClame.a :
	+cd libClame; $(MAKE) libClame.a

libScricon/libScricon.a :
	+cd libScricon; $(MAKE) libScricon.a

amocao : $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) -o amocao $(LDLIBS)

.DEFAULT_GOAL = all
.PHONY : all clean global install remove

all : amocao

clean :
	cd libClame; $(MAKE) clean
	cd libScricon; $(MAKE) clean
	$(CLEAN)

global : install
	-sudo rm /bin/amocao
	sudo ln -s $(DESTDIR)/amocao /bin/amocao

install : $(DESTDIR)/ amocao script/bfc.sh
	cp amocao $(DESTDIR)/

remove :
	-rm $(DESTDIR)/amocao