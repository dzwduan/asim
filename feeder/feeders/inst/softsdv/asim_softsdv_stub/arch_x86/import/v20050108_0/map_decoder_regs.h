/*
 * Copyright (C) 2005-2006 Intel Corporation
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */

/*
 * Map the Falcon decoder's x86 register names (the enumeration
 * IA_Decoder_Operand_Name) to CPUAPI strings.
 *
 *  NOTE: This file is generated by mapregs.pl reading the
 *        decoder header files automatically.  Do not edit.
 */

#ifndef _DECODER_TO_CPUAPI_REGS_
#define _DECODER_TO_CPUAPI_REGS_

#include "cpuapi_arch_ia32.h"

#ifdef __cplusplus
extern "C"
{
#endif

char * const decoderRegsToCPUAPI[176]
#ifdef INIT_DECODER_TO_CPUAPI_REGS_VALUES
    = {
    0,                             /* IA_DECODER_NO_REG         */
    CPUAPI_IA32_EAX,               /* IA_DECODER_REG_EAX        */
    CPUAPI_IA32_ECX,               /* IA_DECODER_REG_ECX        */
    CPUAPI_IA32_EDX,               /* IA_DECODER_REG_EDX        */
    CPUAPI_IA32_EBX,               /* IA_DECODER_REG_EBX        */
    CPUAPI_IA32_ESP,               /* IA_DECODER_REG_ESP        */
    CPUAPI_IA32_EBP,               /* IA_DECODER_REG_EBP        */
    CPUAPI_IA32_ESI,               /* IA_DECODER_REG_ESI        */
    CPUAPI_IA32_EDI,               /* IA_DECODER_REG_EDI        */
    CPUAPI_IA32_R8D,               /* IA_DECODER_REG_R8D        */
    CPUAPI_IA32_R9D,               /* IA_DECODER_REG_R9D        */
    CPUAPI_IA32_R10D,              /* IA_DECODER_REG_R10D       */
    CPUAPI_IA32_R11D,              /* IA_DECODER_REG_R11D       */
    CPUAPI_IA32_R12D,              /* IA_DECODER_REG_R12D       */
    CPUAPI_IA32_R13D,              /* IA_DECODER_REG_R13D       */
    CPUAPI_IA32_R14D,              /* IA_DECODER_REG_R14D       */
    CPUAPI_IA32_R15D,              /* IA_DECODER_REG_R15D       */
    CPUAPI_IA32_ES_SEL,            /* IA_DECODER_REG_ES         */
    CPUAPI_IA32_CS_SEL,            /* IA_DECODER_REG_CS         */
    CPUAPI_IA32_SS_SEL,            /* IA_DECODER_REG_SS         */
    CPUAPI_IA32_DS_SEL,            /* IA_DECODER_REG_DS         */
    CPUAPI_IA32_FS_SEL,            /* IA_DECODER_REG_FS         */
    CPUAPI_IA32_GS_SEL,            /* IA_DECODER_REG_GS         */
    CPUAPI_IA32_EFLAGS,            /* IA_DECODER_REG_EFLAGS     */
    CPUAPI_IA32_DR0,               /* IA_DECODER_REG_DR0        */
    CPUAPI_IA32_DR1,               /* IA_DECODER_REG_DR1        */
    CPUAPI_IA32_DR2,               /* IA_DECODER_REG_DR2        */
    CPUAPI_IA32_DR3,               /* IA_DECODER_REG_DR3        */
    CPUAPI_IA32_DR4,               /* IA_DECODER_REG_DR4        */
    CPUAPI_IA32_DR5,               /* IA_DECODER_REG_DR5        */
    CPUAPI_IA32_DR6,               /* IA_DECODER_REG_DR6        */
    CPUAPI_IA32_DR7,               /* IA_DECODER_REG_DR7        */
    CPUAPI_IA32_CR0,               /* IA_DECODER_REG_CR0        */
    CPUAPI_IA32_CR1,               /* IA_DECODER_REG_CR1        */
    CPUAPI_IA32_CR2,               /* IA_DECODER_REG_CR2        */
    CPUAPI_IA32_CR3,               /* IA_DECODER_REG_CR3        */
    CPUAPI_IA32_CR4,               /* IA_DECODER_REG_CR4        */
    0,                             /*                           */
    0,                             /*                           */
    0,                             /*                           */
    CPUAPI_IA32_CR8,               /* IA_DECODER_REG_CR8        */
    0,                             /* IA_DECODER_REG_TSSR       */
    0,                             /* IA_DECODER_REG_LDTR       */
    0,                             /* IA_DECODER_REG_ESR_BASE   */
    0,                             /* IA_DECODER_REG_ESR_LIMIT  */
    0,                             /* IA_DECODER_REG_CSR_BASE   */
    0,                             /* IA_DECODER_REG_CSR_LIMIT  */
    0,                             /* IA_DECODER_REG_SSR_BASE   */
    0,                             /* IA_DECODER_REG_SSR_LIMIT  */
    0,                             /* IA_DECODER_REG_DSR_BASE   */
    0,                             /* IA_DECODER_REG_DSR_LIMIT  */
    0,                             /* IA_DECODER_REG_FSR_BASE   */
    0,                             /* IA_DECODER_REG_FSR_LIMIT  */
    0,                             /* IA_DECODER_REG_GSR_BASE   */
    0,                             /* IA_DECODER_REG_GSR_LIMIT  */
    0,                             /* IA_DECODER_REG_TSSR_BASE  */
    0,                             /* IA_DECODER_REG_TSSR_LIMIT */
    0,                             /* IA_DECODER_REG_LDTR_BASE  */
    0,                             /* IA_DECODER_REG_LDTR_LIMIT */
    CPUAPI_IA32_GDTR_BASE,         /* IA_DECODER_REG_GDTR_BASE  */
    CPUAPI_IA32_GDTR_LIMIT,        /* IA_DECODER_REG_GDTR_LIMIT */
    CPUAPI_IA32_IDTR_BASE,         /* IA_DECODER_REG_IDTR_BASE  */
    CPUAPI_IA32_IDTR_LIMIT,        /* IA_DECODER_REG_IDTR_LIMIT */
    CPUAPI_IA32_TR_SEL,            /* IA_DECODER_REG_TR         */
    0,                             /* IA_DECODER_REG_TR3        */
    0,                             /* IA_DECODER_REG_TR4        */
    0,                             /* IA_DECODER_REG_TR5        */
    0,                             /* IA_DECODER_REG_TR6        */
    0,                             /* IA_DECODER_REG_TR7        */
    CPUAPI_IA32_AX,                /* IA_DECODER_REG_AX         */
    CPUAPI_IA32_CX,                /* IA_DECODER_REG_CX         */
    CPUAPI_IA32_DX,                /* IA_DECODER_REG_DX         */
    CPUAPI_IA32_BX,                /* IA_DECODER_REG_BX         */
    CPUAPI_IA32_SP,                /* IA_DECODER_REG_SP         */
    CPUAPI_IA32_BP,                /* IA_DECODER_REG_BP         */
    CPUAPI_IA32_SI,                /* IA_DECODER_REG_SI         */
    CPUAPI_IA32_DI,                /* IA_DECODER_REG_DI         */
    CPUAPI_IA32_R8W,               /* IA_DECODER_REG_R8W        */
    CPUAPI_IA32_R9W,               /* IA_DECODER_REG_R9W        */
    CPUAPI_IA32_R10W,              /* IA_DECODER_REG_R10W       */
    CPUAPI_IA32_R11W,              /* IA_DECODER_REG_R11W       */
    CPUAPI_IA32_R12W,              /* IA_DECODER_REG_R12W       */
    CPUAPI_IA32_R13W,              /* IA_DECODER_REG_R13W       */
    CPUAPI_IA32_R14W,              /* IA_DECODER_REG_R14W       */
    CPUAPI_IA32_R15W,              /* IA_DECODER_REG_R15W       */
    CPUAPI_IA32_AL,                /* IA_DECODER_REG_AL         */
    CPUAPI_IA32_CL,                /* IA_DECODER_REG_CL         */
    CPUAPI_IA32_DL,                /* IA_DECODER_REG_DL         */
    CPUAPI_IA32_BL,                /* IA_DECODER_REG_BL         */
    CPUAPI_IA32_AH,                /* IA_DECODER_REG_AH         */
    CPUAPI_IA32_CH,                /* IA_DECODER_REG_CH         */
    CPUAPI_IA32_DH,                /* IA_DECODER_REG_DH         */
    CPUAPI_IA32_BH,                /* IA_DECODER_REG_BH         */
    CPUAPI_IA32_R8B,               /* IA_DECODER_REG_R8B        */
    CPUAPI_IA32_R9B,               /* IA_DECODER_REG_R9B        */
    CPUAPI_IA32_R10B,              /* IA_DECODER_REG_R10B       */
    CPUAPI_IA32_R11B,              /* IA_DECODER_REG_R11B       */
    CPUAPI_IA32_R12B,              /* IA_DECODER_REG_R12B       */
    CPUAPI_IA32_R13B,              /* IA_DECODER_REG_R13B       */
    CPUAPI_IA32_R14B,              /* IA_DECODER_REG_R14B       */
    CPUAPI_IA32_R15B,              /* IA_DECODER_REG_R15B       */
    CPUAPI_IA32_FR0,               /* IA_DECODER_REG_ST0        */
    CPUAPI_IA32_FR1,               /* IA_DECODER_REG_ST1        */
    CPUAPI_IA32_FR2,               /* IA_DECODER_REG_ST2        */
    CPUAPI_IA32_FR3,               /* IA_DECODER_REG_ST3        */
    CPUAPI_IA32_FR4,               /* IA_DECODER_REG_ST4        */
    CPUAPI_IA32_FR5,               /* IA_DECODER_REG_ST5        */
    CPUAPI_IA32_FR6,               /* IA_DECODER_REG_ST6        */
    CPUAPI_IA32_FR7,               /* IA_DECODER_REG_ST7        */
    CPUAPI_IA32_FR0,               /* IA_DECODER_REG_MM0        */
    CPUAPI_IA32_FR1,               /* IA_DECODER_REG_MM1        */
    CPUAPI_IA32_FR2,               /* IA_DECODER_REG_MM2        */
    CPUAPI_IA32_FR3,               /* IA_DECODER_REG_MM3        */
    CPUAPI_IA32_FR4,               /* IA_DECODER_REG_MM4        */
    CPUAPI_IA32_FR5,               /* IA_DECODER_REG_MM5        */
    CPUAPI_IA32_FR6,               /* IA_DECODER_REG_MM6        */
    CPUAPI_IA32_FR7,               /* IA_DECODER_REG_MM7        */
    CPUAPI_IA32_XMM0,              /* IA_DECODER_REG_XMM0       */
    CPUAPI_IA32_XMM1,              /* IA_DECODER_REG_XMM1       */
    CPUAPI_IA32_XMM2,              /* IA_DECODER_REG_XMM2       */
    CPUAPI_IA32_XMM3,              /* IA_DECODER_REG_XMM3       */
    CPUAPI_IA32_XMM4,              /* IA_DECODER_REG_XMM4       */
    CPUAPI_IA32_XMM5,              /* IA_DECODER_REG_XMM5       */
    CPUAPI_IA32_XMM6,              /* IA_DECODER_REG_XMM6       */
    CPUAPI_IA32_XMM7,              /* IA_DECODER_REG_XMM7       */
    CPUAPI_IA32_XMM8,              /* IA_DECODER_REG_XMM8       */
    CPUAPI_IA32_XMM9,              /* IA_DECODER_REG_XMM9       */
    CPUAPI_IA32_XMM10,             /* IA_DECODER_REG_XMM10      */
    CPUAPI_IA32_XMM11,             /* IA_DECODER_REG_XMM11      */
    CPUAPI_IA32_XMM12,             /* IA_DECODER_REG_XMM12      */
    CPUAPI_IA32_XMM13,             /* IA_DECODER_REG_XMM13      */
    CPUAPI_IA32_XMM14,             /* IA_DECODER_REG_XMM14      */
    CPUAPI_IA32_XMM15,             /* IA_DECODER_REG_XMM15      */
    CPUAPI_IA32_MXCSR,             /* IA_DECODER_REG_MXCSR      */
    CPUAPI_IA32_FCONTROL,          /* IA_DECODER_REG_FPCW       */
    CPUAPI_IA32_FSTATUS,           /* IA_DECODER_REG_FPSW       */
    CPUAPI_IA32_FTAG,              /* IA_DECODER_REG_FPTAG      */
    CPUAPI_IA32_FINST_OFFSET,      /* IA_DECODER_REG_FPIP_OFF   */
    CPUAPI_IA32_FINST_SEL,         /* IA_DECODER_REG_FPIP_SEL   */
    CPUAPI_IA32_FOPCODE,           /* IA_DECODER_REG_FPOPCODE   */
    CPUAPI_IA32_FDATA_OFFSET,      /* IA_DECODER_REG_FPDP_OFF   */
    CPUAPI_IA32_FDATA_SEL,         /* IA_DECODER_REG_FPDP_SEL   */
    CPUAPI_IA32_EIP,               /* IA_DECODER_REG_EIP        */
    CPUAPI_IA32_SPL,               /* IA_DECODER_REG_SPL        */
    CPUAPI_IA32_BPL,               /* IA_DECODER_REG_BPL        */
    CPUAPI_IA32_SIL,               /* IA_DECODER_REG_SIL        */
    CPUAPI_IA32_DIL,               /* IA_DECODER_REG_DIL        */
    CPUAPI_IA32_RAX,               /* IA_DECODER_REG_RAX        */
    CPUAPI_IA32_RCX,               /* IA_DECODER_REG_RCX        */
    CPUAPI_IA32_RDX,               /* IA_DECODER_REG_RDX        */
    CPUAPI_IA32_RBX,               /* IA_DECODER_REG_RBX        */
    CPUAPI_IA32_RSP,               /* IA_DECODER_REG_RSP        */
    CPUAPI_IA32_RBP,               /* IA_DECODER_REG_RBP        */
    CPUAPI_IA32_RSI,               /* IA_DECODER_REG_RSI        */
    CPUAPI_IA32_RDI,               /* IA_DECODER_REG_RDI        */
    CPUAPI_IA32_R8,                /* IA_DECODER_REG_R8         */
    CPUAPI_IA32_R9,                /* IA_DECODER_REG_R9         */
    CPUAPI_IA32_R10,               /* IA_DECODER_REG_R10        */
    CPUAPI_IA32_R11,               /* IA_DECODER_REG_R11        */
    CPUAPI_IA32_R12,               /* IA_DECODER_REG_R12        */
    CPUAPI_IA32_R13,               /* IA_DECODER_REG_R13        */
    CPUAPI_IA32_R14,               /* IA_DECODER_REG_R14        */
    CPUAPI_IA32_R15,               /* IA_DECODER_REG_R15        */
    CPUAPI_IA32_RIP,               /* IA_DECODER_REG_RIP        */
    0,                             /* IA_DECODER_REG_LAST       */
    0,                             /* IA_DECODER_FPST_ALL       */
    0,                             /* IA_DECODER_IREG32_ALL     */
    0,                             /* IA_DECODER_IREG16_ALL     */
    0,                             /* IA_DECODER_IREG64_ALL     */
    0,                             /* IA_DECODER_MEM_REF        */
    0,                             /* IA_DECODER_MEM8           */
    0,                             /* IA_DECODER_MEM16          */
    0,                             /* IA_DECODER_MEM32          */
    0,                             /* IA_DECODER_MEM64          */
    0,                             /* IA_DECODER_MEM80          */
    0                              /* IA_DECODER_MEM128         */
}
#endif /* INIT_DECODER_TO_CPUAPI_REGS_VALUES */
;

#ifdef __cplusplus
}
#endif

#endif /* _DECODER_TO_CPUAPI_REGS_ */
