/* { dg-do compile } */
/* { dg-options "-march=rv64gcv -mabi=lp64d --param=gpr2vr-cost=0" } */

#include "vx_binary.h"

#define T int16_t

DEF_VX_BINARY_CASE_0_WRAP(T, +, add)
DEF_VX_BINARY_CASE_0_WRAP(T, -, sub)
DEF_VX_BINARY_REVERSE_CASE_0_WRAP(T, -, rsub);
DEF_VX_BINARY_CASE_0_WRAP(T, &, and)
DEF_VX_BINARY_CASE_0_WRAP(T, |, or)
DEF_VX_BINARY_CASE_0_WRAP(T, ^, xor)
DEF_VX_BINARY_CASE_0_WRAP(T, *, mul)
DEF_VX_BINARY_CASE_0_WRAP(T, /, div)
DEF_VX_BINARY_CASE_0_WRAP(T, %, rem)

/* { dg-final { scan-assembler-times {vadd.vx} 1 } } */
/* { dg-final { scan-assembler-times {vsub.vx} 1 } } */
/* { dg-final { scan-assembler-times {vrsub.vx} 1 } } */
/* { dg-final { scan-assembler-times {vand.vx} 1 } } */
/* { dg-final { scan-assembler-times {vor.vx} 1 } } */
/* { dg-final { scan-assembler-times {vxor.vx} 1 } } */
/* { dg-final { scan-assembler-times {vmul.vx} 1 } } */
/* { dg-final { scan-assembler-times {vdiv.vx} 1 } } */
/* { dg-final { scan-assembler-times {vrem.vx} 1 } } */
