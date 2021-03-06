################################################################################
##
## Filename:	sw/host/Makefile
##
## Project:	ZipSTORM-MX, an iCE40 ZipCPU demonstration project
##
## Purpose:	
## Targets:	
##
## Creator:	Dan Gisselquist, Ph.D.
##		Gisselquist Technology, LLC
##
################################################################################
##
## Copyright (C) 2019, Gisselquist Technology, LLC
##
## This program is free software (firmware): you can redistribute it and/or
## modify it under the terms of the GNU General Public License as published
## by the Free Software Foundation, either version 3 of the License, or (at
## your option) any later version.
##
## This program is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
## FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
## for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
## target there if the PDF file isn't present.)  If not, see
## <http://www.gnu.org/licenses/> for a copy.
##
## License:	GPL, v3, as defined and found on www.gnu.org,
##		http://www.gnu.org/licenses/gpl.html
##
##
################################################################################
##
##
.PHONY: all
all:
PROGRAMS := wbregs flashid dumpflash zipload zipstate zipdbg netuart
#
SCOPES := sdramscope dbgscope spixscope
all: $(PROGRAMS) $(SCOPES)
CXX := g++
OBJDIR := obj-pc
BUSSRCS := hexbus.cpp llcomms.cpp regdefs.cpp byteswap.cpp
SCOPESRC:= spixscope.cpp dbgscope.cpp sdramscope.cpp
SOURCES := wbregs.cpp netuart.cpp flashid.cpp flashdrvr.cpp $(BUSSRCS) $(SCOPESRC)
HEADERS := llcomms.h port.h hexbus.h devbus.h
OBJECTS := $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(SOURCES)))
BUSOBJS := $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(BUSSRCS)))
CFLAGS := -g -Wall -I. -I../../rtl
LIBS :=
SUBMAKE := $(MAKE) --no-print-directory -C

%.o: $(OBJDIR)/%.o
$(OBJDIR)/%.o: %.cpp
	$(mk-objdir)
	$(CXX) $(CFLAGS) -c $< -o $@
$(OBJDIR)/%.o: %.c
	$(mk-objdir)
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJDIR)/ $(PROGRAMS) $(SCOPES) a.out

$(OBJDIR)/scopecls.o: scopecls.cpp scopecls.h

netuart: $(OBJDIR)/netuart.o
	$(CXX) $(CFLAGS) $^ -o $@
#
# Some simple programs that just depend upon the ability to talk to the FPGA,
# and little more. 
wbregs: $(OBJDIR)/wbregs.o $(BUSOBJS)
	$(CXX) $(CFLAGS) $^ $(LIBS) -o $@
dumpflash: $(OBJDIR)/dumpflash.o $(BUSOBJS)
	$(CXX) $(CFLAGS) $^ $(LIBS) -o $@
# flashid: $(OBJDIR)/flashid.o $(OBJDIR)/flashdrvr.o $(BUSOBJS)
#	$(CXX) $(CFLAGS) $^ $(LIBS) -o $@
divutb: $(OBJDIR)/divutb.o
	$(CXX) $(CFLAGS) $^ -o $@

#
# Programs that depend upon not just the bus objects, but the flash driver
# as well.
wbprogram: $(OBJDIR)/wbprogram.o $(OBJDIR)/flashdrvr.o $(BUSOBJS)
	$(CXX) -g $^ -o $@
flashid: $(OBJDIR)/flashid.o $(BUSOBJS)
	echo "Requires" $(OBJDIR)/flashid.o $(BUSOBJS)
	ls -l $(OBJDIR)/flashid.o $(BUSOBJS)
	$(CXX) -g $^ -o $@
zipstate: $(OBJDIR)/zipstate.o $(BUSOBJS)
	$(CXX) -g $^ -o $@
zipload:  $(OBJDIR)/zipload.o $(OBJDIR)/flashdrvr.o
zipload: $(BUSOBJS) $(OBJDIR)/zipelf.o
	$(CXX) -g $^ -lelf -o $@

## SCOPES
# These depend upon the scopecls.o, the bus objects, as well as their
# main file(s).
#
spixscope: $(OBJDIR)/spixscope.o $(OBJDIR)/scopecls.o $(BUSOBJS)
	$(CXX) -g $^ -o $@
dbgscope: $(OBJDIR)/dbgscope.o $(OBJDIR)/scopecls.o $(BUSOBJS)
	$(CXX) -g $^ -o $@
sdramscope: $(OBJDIR)/sdramscope.o $(OBJDIR)/scopecls.o $(BUSOBJS)
	$(CXX) -g $^ -o $@
#
#


#
DBGSRCS  := zopcodes.cpp twoc.cpp
DBGOBJS := $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(DBGSRCS)))
zipdbg: $(OBJDIR)/zipdbg.o $(BUSOBJS) $(DBGOBJS)
	$(CXX) -g $^ -lcurses -o $@
#
#

define	mk-objdir
	@bash -c "if [ ! -e $(OBJDIR) ]; then mkdir -p $(OBJDIR); fi"
endef

define	build-depends
	@echo "Building dependency file(s)"
	$(mk-objdir)
	$(CXX) $(CFLAGS) -MM $(SOURCES) > $(OBJDIR)/xdepends.txt
	@sed -e 's/^.*.o: /$(OBJDIR)\/&/' < $(OBJDIR)/xdepends.txt > $(OBJDIR)/depends.txt
	@rm $(OBJDIR)/xdepends.txt
endef

tags: $(SOURCES) $(HEADERS)
	@echo "Generating tags"
	@ctags $(SOURCES) $(HEADERS)

.PHONY: depends
depends: tags
	$(build-depends)

$(OBJDIR)/depends.txt: $(SOURCES) $(HEADERS)
	$(build-depends)

ifneq ($(MAKECMDGOALS),clean)
-include $(OBJDIR)/depends.txt
endif
