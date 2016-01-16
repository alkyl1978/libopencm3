/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_EFM32_USART_H
#define LIBOPENCM3_EFM32_USART_H

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define USART_CTRL(base)		MMIO32((base) + 0x000)
#define USART_FRAME(base)		MMIO32((base) + 0x004)
#define USART_TRIGCTRL(base)		MMIO32((base) + 0x008)
#define USART_CMD(base)			MMIO32((base) + 0x00C)
#define USART_STATUS(base)		MMIO32((base) + 0x010)
#define USART_CLKDIV(base)		MMIO32((base) + 0x014)
#define USART_RXDATAX(base)		MMIO32((base) + 0x018)
#define USART_RXDATA(base)		MMIO32((base) + 0x01C)
#define USART_RXDOUBLEX(base)		MMIO32((base) + 0x020)
#define USART_RXDOUBLE(base)		MMIO32((base) + 0x024)
#define USART_RXDATAXP(base)		MMIO32((base) + 0x028)
#define USART_RXDOUBLEXP(base)		MMIO32((base) + 0x02C)
#define USART_TXDATAX(base)		MMIO32((base) + 0x030)
#define USART_TXDATA(base)		MMIO32((base) + 0x034)
#define USART_TXDOUBLEX(base)		MMIO32((base) + 0x038)
#define USART_TXDOUBLE(base)		MMIO32((base) + 0x03C)
#define USART_IF(base)			MMIO32((base) + 0x040)
#define USART_IFS(base)			MMIO32((base) + 0x044)
#define USART_IFC(base)			MMIO32((base) + 0x048)
#define USART_IEN(base)			MMIO32((base) + 0x04C)
#define USART_IRCTRL(base)		MMIO32((base) + 0x050)
#define USART_ROUTE(base)		MMIO32((base) + 0x054)
#define USART_INPUT(base)		MMIO32((base) + 0x058)
#define USART_I2SCTRL(base)		MMIO32((base) + 0x05C)

/* USART_CTRL */
#define USART_CTRL_SMSDELAY		(1 << 31)
#define USART_CTRL_MVDIS		(1 << 30)
#define USART_CTRL_AUTOTX		(1 << 29)
#define USART_CTRL_BYTESWAP		(1 << 28)

#define USART_CTRL_TXDELAY_SHIFT	(26)
#define USART_CTRL_TXDELAY_MASK		(0x3 << USART_CTRL_TXDELAY_SHIFT)
#define USART_CTRL_TXDELAY(v)		\
	(((v)  << USART_CTRL_TXDELAY_SHIFT) & USART_CTRL_TXDELAY_MASK)
#define USART_CTRL_TXDELAY_NONE		USART_CTRL_TXDELAY(0)
#define USART_CTRL_TXDELAY_SINGLE	USART_CTRL_TXDELAY(1)
#define USART_CTRL_TXDELAY_DOUBLE	USART_CTRL_TXDELAY(2)
#define USART_CTRL_TXDELAY_TRIPLE	USART_CTRL_TXDELAY(3)

#define USART_CTRL_SSSEARLY		(1 << 25)
#define USART_CTRL_ERRSTX		(1 << 24)
#define USART_CTRL_ERRSRX		(1 << 23)
#define USART_CTRL_ERRSDMA		(1 << 22)
#define USART_CTRL_BIT8DV		(1 << 21)
#define USART_CTRL_SKIPPERRF		(1 << 20)
#define USART_CTRL_SCRETRANS		(1 << 19)
#define USART_CTRL_SCMODE		(1 << 18)
#define USART_CTRL_AUTOTRI		(1 << 17)
#define USART_CTRL_AUTOCS		(1 << 16)
#define USART_CTRL_CSINV		(1 << 15)
#define USART_CTRL_TXINV		(1 << 14)
#define USART_CTRL_RXINV		(1 << 13)
#define USART_CTRL_TXBIL		(1 << 12)
#define USART_CTRL_CSMA			(1 << 11)
#define USART_CTRL_MSBF			(1 << 10)
#define USART_CTRL_CLKPHA		(1 << 9)
#define USART_CTRL_CLKPOL		(1 << 8)

#define USART_CTRL_OVS_SHIFT		(5)
#define USART_CTRL_OVS_MASK		(0x3 << USART_CTRL_OVS_SHIFT)
#define USART_CTRL_OVS(v)		\
	(((v)  << USART_CTRL_OVS_SHIFT) & USART_CTRL_OVS_MASK)
#define USART_CTRL_OVS_X16		USART_CTRL_OVS(0)
#define USART_CTRL_OVS_X8		USART_CTRL_OVS(1)
#define USART_CTRL_OVS_X6		USART_CTRL_OVS(2)
#define USART_CTRL_OVS_X4		USART_CTRL_OVS(3)

#define USART_CTRL_MPAB			(1 << 4)
#define USART_CTRL_MPM			(1 << 3)
#define USART_CTRL_CCEN			(1 << 2)
#define USART_CTRL_LOOPBK		(1 << 1)
#define USART_CTRL_SYNC			(1 << 0)

/* USART_FRAME */

#define USART_FRAME_STOPBITS_SHIFT	(12)
#define USART_FRAME_STOPBITS_MASK	(0x3 << USART_FRAME_STOPBITS_SHIFT)
#define USART_FRAME_STOPBITS(v)		\
	(((v)  << USART_FRAME_STOPBITS_SHIFT) & USART_FRAME_STOPBITS_MASK)
#define USART_FRAME_STOPBITS_HALF	USART_FRAME_STOPBITS(0)
#define USART_FRAME_STOPBITS_ONE	USART_FRAME_STOPBITS(1)
#define USART_FRAME_STOPBITS_ONEANDAHALF	USART_FRAME_STOPBITS(2)
#define USART_FRAME_STOPBITS_ONE_AND_A_HALF	\
	USART_FRAME_STOPBITS_ONEANDAHALF
#define USART_FRAME_STOPBITS_TWO	USART_FRAME_STOPBITS(3)

#define USART_FRAME_PARITY_SHIFT	(8)
#define USART_FRAME_PARITY_MASK		(0x3 << USART_FRAME_PARITY_SHIFT)
#define USART_FRAME_PARITY(v)		\
	(((v)  << USART_FRAME_PARITY_SHIFT) & USART_FRAME_PARITY_MASK)
#define USART_FRAME_PARITY_NONE		USART_FRAME_PARITY(0)
#define USART_FRAME_PARITY_EVEN		USART_FRAME_PARITY(2)
#define USART_FRAME_PARITY_ODD		USART_FRAME_PARITY(3)

#define USART_FRAME_DATABITS_SHIFT	(0)
#define USART_FRAME_DATABITS_MASK	(0xF << USART_FRAME_DATABITS_SHIFT)
#define USART_FRAME_DATABITS(v)		\
	(((v)  << USART_FRAME_DATABITS_SHIFT) & USART_FRAME_DATABITS_MASK)
#define USART_FRAME_DATABITS_FOUR	USART_FRAME_DATABITS(1)
#define USART_FRAME_DATABITS_FIVE	USART_FRAME_DATABITS(2)
#define USART_FRAME_DATABITS_SIX	USART_FRAME_DATABITS(3)
#define USART_FRAME_DATABITS_SEVEN	USART_FRAME_DATABITS(4)
#define USART_FRAME_DATABITS_EIGHT	USART_FRAME_DATABITS(5)
#define USART_FRAME_DATABITS_NINE	USART_FRAME_DATABITS(6)
#define USART_FRAME_DATABITS_TEN	USART_FRAME_DATABITS(7)
#define USART_FRAME_DATABITS_ELEVEN	USART_FRAME_DATABITS(8)
#define USART_FRAME_DATABITS_TWELVE	USART_FRAME_DATABITS(9)
#define USART_FRAME_DATABITS_THIRTEEN	USART_FRAME_DATABITS(10)
#define USART_FRAME_DATABITS_FOURTEEN	USART_FRAME_DATABITS(11)
#define USART_FRAME_DATABITS_FIFTEEN	USART_FRAME_DATABITS(12)
#define USART_FRAME_DATABITS_SIXTEEN	USART_FRAME_DATABITS(13)

/* USART_TRIGCTRL */
#define USART_TRIGCTRL_AUTOTXTEN	(1 << 6)
#define USART_TRIGCTRL_TXTEN		(1 << 5)
#define USART_TRIGCTRL_RXTEN		(1 << 4)

#define USART_TRIGCTRL_TSEL_SHIFT	(8)
#define USART_TRIGCTRL_TSEL_MASK	(0x3 << USART_TRIGCTRL_TSEL_SHIFT)
#define USART_TRIGCTRL_TSEL_PRSCHx(v)	\
	(((v) << USART_TRIGCTRL_TSEL_SHIFT) & USART_TRIGCTRL_TSEL_MASK)
#define USART_TRIGCTRL_TSEL_PRSCH0	USART_TRIGCTRL_TSEL_PRSCHx(0)
#define USART_TRIGCTRL_TSEL_PRSCH1	USART_TRIGCTRL_TSEL_PRSCHx(1)
#define USART_TRIGCTRL_TSEL_PRSCH2	USART_TRIGCTRL_TSEL_PRSCHx(2)
#define USART_TRIGCTRL_TSEL_PRSCH3	USART_TRIGCTRL_TSEL_PRSCHx(3)
#define USART_TRIGCTRL_TSEL_PRSCH4	USART_TRIGCTRL_TSEL_PRSCHx(4)
#define USART_TRIGCTRL_TSEL_PRSCH5	USART_TRIGCTRL_TSEL_PRSCHx(5)
#define USART_TRIGCTRL_TSEL_PRSCH6	USART_TRIGCTRL_TSEL_PRSCHx(6)
#define USART_TRIGCTRL_TSEL_PRSCH7	USART_TRIGCTRL_TSEL_PRSCHx(7)

/* USART_CMD */
#define USART_CMD_CLEARRX		(1 << 11)
#define USART_CMD_CLEARTX		(1 << 10)
#define USART_CMD_TXTRIDIS		(1 << 9)
#define USART_CMD_TXTRIEN		(1 << 8)
#define USART_CMD_RXBLOCKDIS		(1 << 7)
#define USART_CMD_RXBLOCKEN		(1 << 6)
#define USART_CMD_MASTERDIS		(1 << 5)
#define USART_CMD_MASTEREN		(1 << 4)
#define USART_CMD_TXDIS			(1 << 3)
#define USART_CMD_TXEN			(1 << 2)
#define USART_CMD_RXDIS			(1 << 1)
#define USART_CMD_RXEN			(1 << 0)

/* USART_STATUS */
#define USART_STATUS_RXFULLRIGHT	(1 << 12)
#define USART_STATUS_RXDATAVRIGHT	(1 << 11)
#define USART_STATUS_TXBSRIGHT		(1 << 10)
#define USART_STATUS_TXBDRIGHT		(1 << 9)
#define USART_STATUS_RXFULL		(1 << 8)
#define USART_STATUS_RXDATAV		(1 << 7)
#define USART_STATUS_TXBL		(1 << 6)
#define USART_STATUS_TXC		(1 << 5)
#define USART_STATUS_TXTRI		(1 << 4)
#define USART_STATUS_RXBLOCK		(1 << 3)
#define USART_STATUS_MASTER		(1 << 2)
#define USART_STATUS_TXENS		(1 << 1)
#define USART_STATUS_RXENS		(1 << 0)

/* USART_CLKDIV */
#define USART_CLKDIV_DIV_SHIFT		(6)
#define USART_CLKDIV_DIV_MASK		(0x7FFF << USART_CLKDIV_DIV_SHIFT)
#define USART_CLKDIV_DIV(v)		\
	(((v) << USART_CLKDIV_DIV_SHIFT) & USART_CLKDIV_DIV_MASK)

/* USART_RXDATAX */
#define USART_RXDATAX_FERR		(1 << 15)
#define USART_RXDATAX_PERR		(1 << 14)

#define USART_RXDATAX_RXDATA_SHIFT	(0)
#define USART_RXDATAX_RXDATA_MASK	(0x1FF << USART_RXDATAX_RXDATA_SHIFT)

/* USART_RXDOUBLEX */
#define USART_RXDOUBLEX_FERR1		(1 << 31)
#define USART_RXDOUBLEX_PERR1		(1 << 30)

#define USART_RXDOUBLEX_RXDATA1_SHIFT	(16)
#define USART_RXDOUBLEX_RXDATA1_MASK	\
	(0x1FF << USART_RXDOUBLEX_RXDATA1_SHIFT)

#define USART_RXDOUBLEX_FERR0		(1 << 15)
#define USART_RXDOUBLEX_PERR0		(1 << 14)

#define USART_RXDOUBLEX_RXDATA0_SHIFT	(0)
#define USART_RXDOUBLEX_RXDATA0_MASK	\
	(0x1FF << USART_RXDOUBLEX_RXDATA1_SHIFT)

/* USART_RXDOUBLE */
#define USART_RXDOUBLE_RXDATA1_SHIFT	(8)
#define USART_RXDOUBLE_RXDATA1_MASK	(0xFF << USART_RXDOUBLE_RXDATA1_SHIFT)

#define USART_RXDOUBLE_RXDATA0_SHIFT	(0)
#define USART_RXDOUBLE_RXDATA0_MASK	(0xFF << USART_RXDOUBLE_RXDATA0_SHIFT)

/* USART_RXDATAXP */
#define USART_RXDATAXP_FERRP		(1 << 15)
#define USART_RXDATAXP_PERRP		(1 << 14)

#define USART_RXDATAXP_RXDATAP_SHIFT	(0)
#define USART_RXDATAXP_RXDATAP_MASK	(0x1FF << USART_RXDATAXP_RXDATAP_SHIFT)

/* USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_FERR1		(1 << 31)
#define USART_RXDOUBLEXP_PERR1		(1 << 30)

#define USART_RXDOUBLEXP_RXDATA1_SHIFT	(16)
#define USART_RXDOUBLEXP_RXDATA1_MASK	\
	(0x1FF << USART_RXDOUBLEXP_RXDATA1_SHIFT)

#define USART_RXDOUBLEXP_FERR0		(1 << 15)
#define USART_RXDOUBLEXP_PERR0		(1 << 14)

#define USART_RXDOUBLEXP_RXDATA0_SHIFT	(0)
#define USART_RXDOUBLEXP_RXDATA0_MASK	\
	(0x1FF << USART_RXDOUBLEXP_RXDATA1_SHIFT)

/* USART_TXDATAX */
#define USART_TXDATAX_RXENAT		(1 << 15)
#define USART_TXDATAX_TXDISAT		(1 << 14)
#define USART_TXDATAX_TXBREAK		(1 << 13)
#define USART_TXDATAX_TXTRIAT		(1 << 12)
#define USART_TXDATAX_UBRXAT		(1 << 11)

#define USART_TXDATAX_TXDATAX_SHIFT	(0)
#define USART_TXDATAX_TXDATAX_MASK	(0x1FF << USART_TXDATAX_TXDATAX_SHIFT)

/* USART_TXDOUBLEX */
#define USART_TXDOUBLEX_RXENAT1		(1 << 31)
#define USART_TXDOUBLEX_TXDISAT1	(1 << 30)
#define USART_TXDOUBLEX_TXBREAK1	(1 << 29)
#define USART_TXDOUBLEX_TXTRIAT1	(1 << 28)
#define USART_TXDOUBLEX_UBRXAT1		(1 << 27)

#define USART_TXDOUBLEX_TXDATA1_SHIFT	(16)
#define USART_TXDOUBLEX_TXDATA1_MASK	\
	(0x1FF << USART_TXDOUBLEX_TXDATA1_SHIFT)

#define USART_TXDOUBLEX_RXENAT0		(1 << 15)
#define USART_TXDOUBLEX_TXDISAT0	(1 << 14)
#define USART_TXDOUBLEX_TXBREAK0	(1 << 13)
#define USART_TXDOUBLEX_TXTRIAT0	(1 << 12)
#define USART_TXDOUBLEX_UBRXAT0		(1 << 11)

#define USART_TXDOUBLEX_TXDATA0_SHIFT	(0)
#define USART_TXDOUBLEX_TXDATA0_MASK	\
	(0x1FF << USART_TXDOUBLEX_TXDATA0_SHIFT)

/* USART_TXDOUBLE */
#define USART_TXDOUBLE_TXDATA1_SHIFT	(8)
#define USART_TXDOUBLE_TXDATA1_MASK	(0xFF << USART_TXDOUBLE_TXDATA1_SHIFT)

#define USART_TXDOUBLE_TXDATA0_SHIFT	(0)
#define USART_TXDOUBLE_TXDATA0_MASK	(0xFF << USART_TXDOUBLE_TXDATA0_SHIFT)

/* USART_IF */
#define USART_IF_CCF			(1 << 12)
#define USART_IF_SSM			(1 << 11)
#define USART_IF_MPAF			(1 << 10)
#define USART_IF_FERR			(1 << 9)
#define USART_IF_PERR			(1 << 8)
#define USART_IF_TXUF			(1 << 7)
#define USART_IF_TXOF			(1 << 6)
#define USART_IF_RXUF			(1 << 5)
#define USART_IF_RXOF			(1 << 4)
#define USART_IF_RXFULL			(1 << 3)
#define USART_IF_RXDATAV		(1 << 2)
#define USART_IF_TXBL			(1 << 1)
#define USART_IF_TXC			(1 << 0)

/* USART_IFS */
#define USART_IFS_CCF			(1 << 12)
#define USART_IFS_SSM			(1 << 11)
#define USART_IFS_MPAF			(1 << 10)
#define USART_IFS_FERR			(1 << 9)
#define USART_IFS_PERR			(1 << 8)
#define USART_IFS_TXUF			(1 << 7)
#define USART_IFS_TXOF			(1 << 6)
#define USART_IFS_RXUF			(1 << 5)
#define USART_IFS_RXOF			(1 << 4)
#define USART_IFS_RXFULL		(1 << 3)
#define USART_IFS_RXDATAV		(1 << 2)
#define USART_IFS_TXBL			(1 << 1)
#define USART_IFS_TXC			(1 << 0)

/* USART_IFC */
#define USART_IFC_CCF			(1 << 12)
#define USART_IFC_SSM			(1 << 11)
#define USART_IFC_MPAF			(1 << 10)
#define USART_IFC_FERR			(1 << 9)
#define USART_IFC_PERR			(1 << 8)
#define USART_IFC_TXUF			(1 << 7)
#define USART_IFC_TXOF			(1 << 6)
#define USART_IFC_RXUF			(1 << 5)
#define USART_IFC_RXOF			(1 << 4)
#define USART_IFC_RXFULL		(1 << 3)
#define USART_IFC_RXDATAV		(1 << 2)
#define USART_IFC_TXBL			(1 << 1)
#define USART_IFC_TXC			(1 << 0)

/* USART_IEN */
#define USART_IEN_CCF			(1 << 12)
#define USART_IEN_SSM			(1 << 11)
#define USART_IEN_MPAF			(1 << 10)
#define USART_IEN_FERR			(1 << 9)
#define USART_IEN_PERR			(1 << 8)
#define USART_IEN_TXUF			(1 << 7)
#define USART_IEN_TXOF			(1 << 6)
#define USART_IEN_RXUF			(1 << 5)
#define USART_IEN_RXOF			(1 << 4)
#define USART_IEN_RXFULL		(1 << 3)
#define USART_IEN_RXDATAV		(1 << 2)
#define USART_IEN_TXBL			(1 << 1)
#define USART_IEN_TXC			(1 << 0)

/* USART_IRCTRL */
#define USART_IRCTRL_IRPRSEN		(1 << 7)

#define USART_IRCTRL_IRPRSSEL_SHIFT	(4)
#define USART_IRCTRL_IRPRSSEL_MASK	(0x7 << USART_IRCTRL_IRPRSSEL_SHIFT)
#define USART_IRCTRL_IRPRSSEL(v)	\
	(((v) << USART_IRCTRL_IRPRSSEL_SHIFT) & USART_IRCTRL_IRPRSSEL_MASK)
#define USART_IRCTRL_IRPRSSEL_PRSCHx(x)	USART_IRCTRL_IRPRSSEL(x)
#define USART_IRCTRL_IRPRSSEL_PRSCH0	USART_IRCTRL_IRPRSSEL_PRSCHx(0)
#define USART_IRCTRL_IRPRSSEL_PRSCH1	USART_IRCTRL_IRPRSSEL_PRSCHx(1)
#define USART_IRCTRL_IRPRSSEL_PRSCH2	USART_IRCTRL_IRPRSSEL_PRSCHx(2)
#define USART_IRCTRL_IRPRSSEL_PRSCH3	USART_IRCTRL_IRPRSSEL_PRSCHx(3)
#define USART_IRCTRL_IRPRSSEL_PRSCH4	USART_IRCTRL_IRPRSSEL_PRSCHx(4)
#define USART_IRCTRL_IRPRSSEL_PRSCH5	USART_IRCTRL_IRPRSSEL_PRSCHx(5)
#define USART_IRCTRL_IRPRSSEL_PRSCH6	USART_IRCTRL_IRPRSSEL_PRSCHx(6)
#define USART_IRCTRL_IRPRSSEL_PRSCH7	USART_IRCTRL_IRPRSSEL_PRSCHx(7)

#define USART_IRCTRL_IRFILT		(1 << 3)

#define USART_IRCTRL_IRPW_SHIFT		(1)
#define USART_IRCTRL_IRPW_MASK		(0x3 << USART_IRCTRL_IRPW_SHIFT)
#define USART_IRCTRL_IRPW(v)		\
	(((v) << USART_IRCTRL_IRPW_SHIFT) & USART_IRCTRL_IRPW_MASK)
#define USART_IRCTRL_IRPW_ONE		USART_IRCTRL_IRPW(0)
#define USART_IRCTRL_IRPW_TWO		USART_IRCTRL_IRPW(1)
#define USART_IRCTRL_IRPW_THREE		USART_IRCTRL_IRPW(2)
#define USART_IRCTRL_IRPW_FOUR		USART_IRCTRL_IRPW(3)

#define USART_IRCTRL_IREN		(1 << 0)

/* USART_ROUTE */
#define USART_ROUTE_LOCATION_SHIFT	(8)
#define USART_ROUTE_LOCATION_MASK	(0x7 << USART_ROUTE_LOCATION_SHIFT)
#define USART_ROUTE_LOCATION(v)		\
	(((v) << USART_ROUTE_LOCATION_SHIFT) & USART_ROUTE_LOCATION_MASK)
#define USART_ROUTE_LOCATION_LOCx(x)	USART_ROUTE_LOCATION(x)
#define USART_ROUTE_LOCATION_LOC0	USART_ROUTE_LOCATION_LOCx(0)
#define USART_ROUTE_LOCATION_LOC1	USART_ROUTE_LOCATION_LOCx(1)
#define USART_ROUTE_LOCATION_LOC2	USART_ROUTE_LOCATION_LOCx(2)
#define USART_ROUTE_LOCATION_LOC3	USART_ROUTE_LOCATION_LOCx(3)
#define USART_ROUTE_LOCATION_LOC4	USART_ROUTE_LOCATION_LOCx(4)
#define USART_ROUTE_LOCATION_LOC5	USART_ROUTE_LOCATION_LOCx(5)

#define USART_ROUTE_CLKPEN		(1 << 3)
#define USART_ROUTE_CSPEN		(1 << 2)
#define USART_ROUTE_TXPEN		(1 << 1)
#define USART_ROUTE_RXPEN		(1 << 0)

/* USART_INPUT */
#define USART_INPUT_RXPRS		(1 << 4)

#define USART_INPUT_RXPRSSEL_SHIFT	(0)
#define USART_INPUT_RXPRSSEL_MASK	(0xF << USART_INPUT_RXPRSSEL_SHIFT)
#define USART_INPUT_RXPRSSEL(v)	\
	(((v) << USART_INPUT_RXPRSSEL_SHIFT) & USART_INPUT_RXPRSSEL_MASK)
#define USART_INPUT_RXPRSSEL_PRSCHx(x)	USART_INPUT_RXPRSSEL(x)
#define USART_INPUT_RXPRSSEL_PRSCH0	USART_INPUT_RXPRSSEL_PRSCHx(0)
#define USART_INPUT_RXPRSSEL_PRSCH1	USART_INPUT_RXPRSSEL_PRSCHx(1)
#define USART_INPUT_RXPRSSEL_PRSCH2	USART_INPUT_RXPRSSEL_PRSCHx(2)
#define USART_INPUT_RXPRSSEL_PRSCH3	USART_INPUT_RXPRSSEL_PRSCHx(3)
#define USART_INPUT_RXPRSSEL_PRSCH4	USART_INPUT_RXPRSSEL_PRSCHx(4)
#define USART_INPUT_RXPRSSEL_PRSCH5	USART_INPUT_RXPRSSEL_PRSCHx(5)
#define USART_INPUT_RXPRSSEL_PRSCH6	USART_INPUT_RXPRSSEL_PRSCHx(6)
#define USART_INPUT_RXPRSSEL_PRSCH7	USART_INPUT_RXPRSSEL_PRSCHx(7)
#define USART_INPUT_RXPRSSEL_PRSCH8	USART_INPUT_RXPRSSEL_PRSCHx(8)
#define USART_INPUT_RXPRSSEL_PRSCH9	USART_INPUT_RXPRSSEL_PRSCHx(9)
#define USART_INPUT_RXPRSSEL_PRSCH10	USART_INPUT_RXPRSSEL_PRSCHx(10)
#define USART_INPUT_RXPRSSEL_PRSCH11	USART_INPUT_RXPRSSEL_PRSCHx(11)

/* USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_SHIFT	(8)
#define USART_I2SCTRL_FORMAT_MASK	(0x7 << USART_I2SCTRL_FORMAT_SHIFT)
#define USART_I2SCTRL_FORMAT(v)	\
	(((v) << USART_I2SCTRL_FORMAT_SHIFT) & USART_I2SCTRL_FORMAT_MASK)
#define USART_I2SCTRL_FORMAT_W32D32	USART_I2SCTRL_FORMAT(0)
#define USART_I2SCTRL_FORMAT_W32D24M	USART_I2SCTRL_FORMAT(1)
#define USART_I2SCTRL_FORMAT_W32D24	USART_I2SCTRL_FORMAT(2)
#define USART_I2SCTRL_FORMAT_W32D16	USART_I2SCTRL_FORMAT(3)
#define USART_I2SCTRL_FORMAT_W32D8	USART_I2SCTRL_FORMAT(4)
#define USART_I2SCTRL_FORMAT_W16D16	USART_I2SCTRL_FORMAT(5)
#define USART_I2SCTRL_FORMAT_W16D8	USART_I2SCTRL_FORMAT(6)
#define USART_I2SCTRL_FORMAT_W8D8	USART_I2SCTRL_FORMAT(7)

#define USART_I2SCTRL_DELAY		(1 << 4)
#define USART_I2SCTRL_DMASPLIT		(1 << 3)
#define USART_I2SCTRL_JUSTIFY		(1 << 2)
#define USART_I2SCTRL_MONO		(1 << 1)
#define USART_I2SCTRL_EN		(1 << 0)

/* USART0 */
#define USART0				USART0_BASE
#define USART0_CTRL			USART_CTRL(USART0)
#define USART0_FRAME			USART_FRAME(USART0)
#define USART0_TRIGCTRL			USART_TRIGCTRL(USART0)
#define USART0_CMD			USART_CMD(USART0)
#define USART0_STATUS			USART_STATUS(USART0)
#define USART0_CLKDIV			USART_CLKDIV(USART0)
#define USART0_RXDATAX			USART_RXDATAX(USART0)
#define USART0_RXDATA			USART_RXDATA(USART0)
#define USART0_RXDOUBLEX		USART_RXDOUBLEX(USART0)
#define USART0_RXDOUBLE			USART_RXDOUBLE(USART0)
#define USART0_RXDATAXP			USART_RXDATAXP(USART0)
#define USART0_RXDOUBLEXP		USART_RXDOUBLEXP(USART0)
#define USART0_TXDATAX			USART_TXDATAX(USART0)
#define USART0_TXDATA			USART_TXDATA(USART0)
#define USART0_TXDOUBLEX		USART_TXDOUBLEX(USART0)
#define USART0_TXDOUBLE			USART_TXDOUBLE(USART0)
#define USART0_IF			USART_IF(USART0)
#define USART0_IFS			USART_IFS(USART0)
#define USART0_IFC			USART_IFC(USART0)
#define USART0_IEN			USART_IEN(USART0)
#define USART0_IRCTRL			USART_IRCTRL(USART0)
#define USART0_ROUTE			USART_ROUTE(USART0)
#define USART0_INPUT			USART_INPUT(USART0)
#define USART0_I2SCTRL			USART_I2SCTRL(USART0)

/* USART1 */
#define USART1				USART1_BASE
#define USART1_CTRL			USART_CTRL(USART1)
#define USART1_FRAME			USART_FRAME(USART1)
#define USART1_TRIGCTRL			USART_TRIGCTRL(USART1)
#define USART1_CMD			USART_CMD(USART1)
#define USART1_STATUS			USART_STATUS(USART1)
#define USART1_CLKDIV			USART_CLKDIV(USART1)
#define USART1_RXDATAX			USART_RXDATAX(USART1)
#define USART1_RXDATA			USART_RXDATA(USART1)
#define USART1_RXDOUBLEX		USART_RXDOUBLEX(USART1)
#define USART1_RXDOUBLE			USART_RXDOUBLE(USART1)
#define USART1_RXDATAXP			USART_RXDATAXP(USART1)
#define USART1_RXDOUBLEXP		USART_RXDOUBLEXP(USART1)
#define USART1_TXDATAX			USART_TXDATAX(USART1)
#define USART1_TXDATA			USART_TXDATA(USART1)
#define USART1_TXDOUBLEX		USART_TXDOUBLEX(USART1)
#define USART1_TXDOUBLE			USART_TXDOUBLE(USART1)
#define USART1_IF			USART_IF(USART1)
#define USART1_IFS			USART_IFS(USART1)
#define USART1_IFC			USART_IFC(USART1)
#define USART1_IEN			USART_IEN(USART1)
#define USART1_IRCTRL			USART_IRCTRL(USART1)
#define USART1_ROUTE			USART_ROUTE(USART1)
#define USART1_INPUT			USART_INPUT(USART1)
#define USART1_I2SCTRL			USART_I2SCTRL(USART1)

/* USART2 */
#define USART2				USART2_BASE
#define USART2_CTRL			USART_CTRL(USART2)
#define USART2_FRAME			USART_FRAME(USART2)
#define USART2_TRIGCTRL			USART_TRIGCTRL(USART2)
#define USART2_CMD			USART_CMD(USART2)
#define USART2_STATUS			USART_STATUS(USART2)
#define USART2_CLKDIV			USART_CLKDIV(USART2)
#define USART2_RXDATAX			USART_RXDATAX(USART2)
#define USART2_RXDATA			USART_RXDATA(USART2)
#define USART2_RXDOUBLEX		USART_RXDOUBLEX(USART2)
#define USART2_RXDOUBLE			USART_RXDOUBLE(USART2)
#define USART2_RXDATAXP			USART_RXDATAXP(USART2)
#define USART2_RXDOUBLEXP		USART_RXDOUBLEXP(USART2)
#define USART2_TXDATAX			USART_TXDATAX(USART2)
#define USART2_TXDATA			USART_TXDATA(USART2)
#define USART2_TXDOUBLEX		USART_TXDOUBLEX(USART2)
#define USART2_TXDOUBLE			USART_TXDOUBLE(USART2)
#define USART2_IF			USART_IF(USART2)
#define USART2_IFS			USART_IFS(USART2)
#define USART2_IFC			USART_IFC(USART2)
#define USART2_IEN			USART_IEN(USART2)
#define USART2_IRCTRL			USART_IRCTRL(USART2)
#define USART2_ROUTE			USART_ROUTE(USART2)
#define USART2_INPUT			USART_INPUT(USART2)
#define USART2_I2SCTRL			USART_I2SCTRL(USART2)

#endif

