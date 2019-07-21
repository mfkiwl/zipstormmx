////////////////////////////////////////////////////////////////////////////////
//
// Filename:	./regdefs.h
//
// Project:	ZipSTORM-MX, an iCE40 ZipCPU demonstration project
//
// DO NOT EDIT THIS FILE!
// Computer Generated: This file is computer generated by AUTOFPGA. DO NOT EDIT.
// DO NOT EDIT THIS FILE!
//
// CmdLine:	autofpga autofpga -d -o . clock50.txt global.txt dlyarbiter.txt version.txt buserr.txt pic.txt pwrcount.txt spio.txt hbconsole.txt bkram.txt spixpress.txt zipbones.txt mem_all.txt mem_flash_bkram.txt mem_bkram_only.txt mem_sdram_bkram.txt
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019, Gisselquist Technology, LLC
//
// This program is free software (firmware): you can redistribute it and/or
// modify it under the terms of  the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
// target there if the PDF file isn't present.)  If not, see
// <http://www.gnu.org/licenses/> for a copy.
//
// License:	GPL, v3, as defined and found on www.gnu.org,
//		http://www.gnu.org/licenses/gpl.html
//
//
////////////////////////////////////////////////////////////////////////////////
//
//
#ifndef	REGDEFS_H
#define	REGDEFS_H


//
// The @REGDEFS.H.INCLUDE tag
//
// @REGDEFS.H.INCLUDE for masters
// @REGDEFS.H.INCLUDE for peripherals
// And finally any master REGDEFS.H.INCLUDE tags
// End of definitions from REGDEFS.H.INCLUDE


//
// Register address definitions, from @REGS.#d
//
// FLASH erase/program configuration registers
#define	R_FLASHCFG      	0x00010000	// 00010000, wbregs names: FLASHCFG
// The bus timer
#define	R_BUSTIMER      	0x00020000	// 00020000, wbregs names: BUSTIMER
// The bus timer
#define	R_BUSTIMER      	0x00020000	// 00020000, wbregs names: BUSTIMER
// The watchdog timer
#define	R_WATCHDOG      	0x00020004	// 00020004, wbregs names: WATCHDOG
// The watchdog timer
#define	R_WATCHDOG      	0x00020004	// 00020004, wbregs names: WATCHDOG
// CONSOLE registers
#define	R_CONSOLE_FIFO  	0x00030004	// 00030000, wbregs names: UFIFO
#define	R_CONSOLE_UARTRX	0x00030008	// 00030000, wbregs names: RX
#define	R_CONSOLE_UARTTX	0x0003000c	// 00030000, wbregs names: TX
#define	R_BUILDTIME     	0x00040000	// 00040000, wbregs names: BUILDTIME
#define	R_BUILDTIME     	0x00040000	// 00040000, wbregs names: BUILDTIME
#define	R_BUSERR        	0x00040004	// 00040004, wbregs names: BUSERR
#define	R_BUSERR        	0x00040004	// 00040004, wbregs names: BUSERR
#define	R_PIC           	0x00040008	// 00040008, wbregs names: PIC
#define	R_PIC           	0x00040008	// 00040008, wbregs names: PIC
#define	R_PWRCOUNT      	0x0004000c	// 0004000c, wbregs names: PWRCOUNT
#define	R_PWRCOUNT      	0x0004000c	// 0004000c, wbregs names: PWRCOUNT
#define	R_SPIO          	0x00040010	// 00040010, wbregs names: SPIO
#define	R_SPIO          	0x00040010	// 00040010, wbregs names: SPIO
#define	R_VERSION       	0x00040014	// 00040014, wbregs names: VERSION
#define	R_VERSION       	0x00040014	// 00040014, wbregs names: VERSION
#define	R_BKRAM         	0x00050000	// 00050000, wbregs names: RAM
#define	R_FLASH         	0x00080000	// 00080000, wbregs names: FLASH
#define	R_ZIPCTRL       	0x00100000	// 00100000, wbregs names: CPU
#define	R_ZIPDATA       	0x00100004	// 00100000, wbregs names: CPUD


//
// The @REGDEFS.H.DEFNS tag
//
// @REGDEFS.H.DEFNS for masters
#define	CLKFREQHZ	50000000
#define	R_ZIPCTRL	0x00100000
#define	R_ZIPDATA	0x00100004
#define	BAUDRATE	1000000
// @REGDEFS.H.DEFNS for peripherals
#define	BKRAMBASE	0x00050000
#define	BKRAMLEN	0x00002000
#define	FLASHBASE	0x00080000
#define	FLASHLEN	0x00080000
#define	FLASHLGLEN	19
// @REGDEFS.H.DEFNS at the top level
// End of definitions from REGDEFS.H.DEFNS
//
// The @REGDEFS.H.INSERT tag
//
// @REGDEFS.H.INSERT for masters

#define	CPU_GO		0x0000
#define	CPU_RESET	0x0040
#define	CPU_INT		0x0080
#define	CPU_STEP	0x0100
#define	CPU_STALL	0x0200
#define	CPU_HALT	0x0400
#define	CPU_CLRCACHE	0x0800
#define	CPU_sR0		0x0000
#define	CPU_sSP		0x000d
#define	CPU_sCC		0x000e
#define	CPU_sPC		0x000f
#define	CPU_uR0		0x0010
#define	CPU_uSP		0x001d
#define	CPU_uCC		0x001e
#define	CPU_uPC		0x001f

#define	RESET_ADDRESS	0x00080000


// @REGDEFS.H.INSERT for peripherals

// Flash memory constants
#define	SZPAGEB		256
#define	PGLENB		256
#define	SZPAGEW		64
#define	PGLENW		64
#define	NPAGES		256
#define	SECTORSZB	(NPAGES * SZPAGEB)	// In bytes, not words!!
#define	SECTORSZW	(NPAGES * SZPAGEW)	// In words
#define	NSECTORS	64
#define	SECTOROF(A)	((A) & (-1<<16))
#define	SUBSECTOROF(A)	((A) & (-1<<12))
#define	PAGEOF(A)	((A) & (-1<<8))

// @REGDEFS.H.INSERT from the top level
typedef	struct {
	unsigned	m_addr;
	const char	*m_name;
} REGNAME;

extern	const	REGNAME	*bregs;
extern	const	int	NREGS;
// #define	NREGS	(sizeof(bregs)/sizeof(bregs[0]))

extern	unsigned	addrdecode(const char *v);
extern	const	char *addrname(const unsigned v);
// End of definitions from REGDEFS.H.INSERT


#endif	// REGDEFS_H
