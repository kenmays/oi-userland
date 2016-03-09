/*
 * Copyright (c) 2015, 2016, Oracle and/or its affiliates. All rights reserved.
 */

/*
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef	_PSIF_HW_CSR_H
#define	_PSIF_HW_CSR_H
#ifdef __cplusplus
extern "C" {
#endif

#include "psif_api.h"

/* The psif base address setup access ids */
enum psif_csr_map {
	PSIF_CSR_ADDR_BASE_ADDR_ATSP                 = 0x5248,
	PSIF_CSR_ADDR_BASE_ADDR_AH                   = 0x55948,
	PSIF_CSR_ADDR_BASE_ADDR_QP	             = 0x55960,
	PSIF_CSR_ADDR_BASE_ADDR_SQ_CMPL              = 0x59d68,
	PSIF_CSR_ADDR_BASE_ADDR_KEY                  = 0x59d80,
	PSIF_CSR_ADDR_BASE_ADDR_RQSP                 = 0x59e08,
	PSIF_CSR_ADDR_BASE_ADDR_RQ_SW                = 0x59e20,
	PSIF_CSR_ADDR_BASE_ADDR_RQ_HW                = 0x59e38,
	PSIF_CSR_ADDR_BASE_ADDR_SQ_SW                = 0xc4548,
	PSIF_CSR_ADDR_BASE_ADDR_SQ_HW                = 0xc4560,
	PSIF_CSR_ADDR_BASE_ADDR_SQ_RING              = 0xc4d18,
	PSIF_CSR_ADDR_BASE_ADDR_SQ_RSPQ              = 0xc4f68,
	PSIF_CSR_ADDR_BASE_ADDR_SQ_TVL               = 0xc5388,
	PSIF_CSR_ADDR_BASE_ADDR_CQ_SW                = 0xcd7a0,
	PSIF_CSR_ADDR_BASE_ADDR_CQ_HW                = 0xcd7b8,
    PSIF_CSR_ADDR_END                            = 0xce9f0
}; /* enum psif_csr_map */

/* The psif base address setup access ids as offset in a struct */
/* *** DEPRECATED DATA TYPE *** */
struct psif_csr_be {
	__be64 ingenting_01[((0x5248) / sizeof(__be64))];
	/* HW:TSU_HOST_QP_BASE_ADDR_0 -> struct base_addr_atsp [165 bits] */
	__be64 base_addr_atsp[3];	 /* Offset   0x5248 */
	/* HW:TSU_QPS_AHA_BASE_ADDR_0 -> struct base_addr_ah [165 bits] */
	__be64 ingenting_03[((0x55948 - 0x5248) / sizeof(__be64)) - 3];
	__be64 base_addr_ah[3];	 /* Offset  0x55948 */
	/* HW:TSU_QPS_QP_BASE_ADDR_0 -> struct base_addr_qp [165 bits] */
	__be64 ingenting_04[((0x55960 - 0x55948) / sizeof(__be64)) - 3];
	__be64 base_addr_qp[3];	 /* Offset  0x55960 */
	/* HW:TSU_CMPL_SQ_BASE_ADDR_0 -> struct base_addr_sq_cmpl [165 bits] */
	__be64 ingenting_05[((0x59d68 - 0x55960) / sizeof(__be64)) - 3];
	__be64 base_addr_sq_cmpl[3];	 /* Offset  0x59d68 */
	/* HW:TSU_VAL_KEY_BASE_ADDR_0 -> struct base_addr_key [165 bits] */
	__be64 ingenting_06[((0x59d80 - 0x59d68) / sizeof(__be64)) - 3];
	__be64 base_addr_key[3];	 /* Offset  0x59d80 */
	/* HW:TSU_RQH_QP_BASE_ADDR_0 -> struct base_addr_rqsp [165 bits] */
	__be64 ingenting_07[((0x59e08 - 0x59d80) / sizeof(__be64)) - 3];
	__be64 base_addr_rqsp[3];	 /* Offset  0x59e08 */
	/* HW:TSU_DSCR_RQ_BASE_ADDR_SW_0 -> struct base_addr_rq_sw [165 bits] */
	__be64 ingenting_08[((0x59e20 - 0x59e08) / sizeof(__be64)) - 3];
	__be64 base_addr_rq_sw[3];	 /* Offset  0x59e20 */
	/* HW:TSU_DSCR_RQ_BASE_ADDR_HW_0 -> struct base_addr_rq_hw [165 bits] */
	__be64 ingenting_09[((0x59e38 - 0x59e20) / sizeof(__be64)) - 3];
	__be64 base_addr_rq_hw[3];	 /* Offset  0x59e38 */
	/* HW:TSU_IBPR_P1_EOIB_MAC1 SW:ibpr_p1_eoib_mac1
	 * -> struct psif_csr_ibpr_p1_eoib_mac1 [64 bits] */
	__be64 ingenting_10[((0xbfcb8 - 0x59e38) / sizeof(__be64)) - 1];
	__be64 ibpr_p1_eoib_mac1;	 /* Offset  0xbfcb8 */
	/* HW:TSU_IBPR_P1_EOIB_MAC2 SW:ibpr_p1_eoib_mac2
	 * -> struct psif_csr_ibpr_p1_eoib_mac2 [64 bits] */
	__be64 ingenting_11[((0xbfcc0 - 0xbfcb8) / sizeof(__be64)) - 1];
	__be64 ibpr_p1_eoib_mac2;	 /* Offset  0xbfcc0 */
	/* HW:TSU_IBPR_P2_EOIB_MAC1 SW:ibpr_p2_eoib_mac1
	 * -> struct psif_csr_ibpr_p2_eoib_mac1 [64 bits] */
	__be64 ingenting_12[((0xbfcc8 - 0xbfcc0) / sizeof(__be64)) - 1];
	__be64 ibpr_p2_eoib_mac1;	 /* Offset  0xbfcc8 */
	/* HW:TSU_IBPR_P2_EOIB_MAC2 SW:ibpr_p2_eoib_mac2
	 * -> struct psif_csr_ibpr_p2_eoib_mac2 [64 bits] */
	__be64 ingenting_13[((0xbfcd0 - 0xbfcc8) / sizeof(__be64)) - 1];
	__be64 ibpr_p2_eoib_mac2;	 /* Offset  0xbfcd0 */
	/* HW:TSU_SQS_SQ_BASE_ADDR_SW_0 -> struct base_addr_sq_sw [165 bits] */
	__be64 ingenting_14[((0xc4548 - 0xbfcd0) / sizeof(__be64)) - 3];
	__be64 base_addr_sq_sw[3];	 /* Offset  0xc4548 */
	/* HW:TSU_SQS_SQ_BASE_ADDR_HW_0 -> struct base_addr_sq_hw [165 bits] */
	__be64 ingenting_15[((0xc4560 - 0xc4548) / sizeof(__be64)) - 3];
	__be64 base_addr_sq_hw[3];	 /* Offset  0xc4560 */
	/* HW:TSU_SQS_PIO_RING_BASE_ADDR_0 -> struct base_addr_sq_ring [165 bits] */
	__be64 ingenting_16[((0xc4d18 - 0xc4560) / sizeof(__be64)) - 3];
	__be64 base_addr_sq_ring[3];	 /* Offset  0xc4d18 */
	/* HW:TSU_SQS_RSPQ_BASE_ADDR_0 -> struct base_addr_sq_rspq [165 bits] */
	__be64 ingenting_17[((0xc4f68 - 0xc4d18) / sizeof(__be64)) - 3];
	__be64 base_addr_sq_rspq[3];	 /* Offset  0xc4f68 */
	/* HW:TSU_SQS_RSPQ_TVL_BASE_ADDR_0 -> struct base_addr_sq_tvl [165 bits] */
	__be64 ingenting_18[((0xc5388 - 0xc4f68) / sizeof(__be64)) - 3];
	__be64 base_addr_sq_tvl[3];	 /* Offset  0xc5388 */
	/* HW:TSU_CBLD_CQ_BASE_ADDR_SW_0 -> struct base_addr_cq_sw [165 bits] */
	__be64 ingenting_19[((0xcd7a0 - 0xc5388) / sizeof(__be64)) - 3];
	__be64 base_addr_cq_sw[3];	 /* Offset  0xcd7a0 */
	/* HW:TSU_CBLD_CQ_BASE_ADDR_HW_0 -> struct base_addr_cq_hw [165 bits] */
	__be64 ingenting_20[((0xcd7b8 - 0xcd7a0) / sizeof(__be64)) - 3];
	__be64 base_addr_cq_hw[3];	 /* Offset  0xcd7b8 */
	__be64 ingenting_21[((0xce9f0 - 0xcd7b8) / sizeof(__be64)) - 3];
}; /* struct psif_csr_be [6770560 bits] */

#ifdef __cplusplus
}
#endif
#endif	/* _PSIF_HW_CSR_H */
