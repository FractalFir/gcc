/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvl128b -mabi=lp64d --param=gpr2vr-cost=2" } */

#include "vx_binary.h"

#define T int8_t

DEF_VX_BINARY_CASE_1_WRAP(T, +, add, VX_BINARY_BODY_X16)
DEF_VX_BINARY_CASE_1_WRAP(T, -, sub, VX_BINARY_BODY_X16)
DEF_VX_BINARY_REVERSE_CASE_1(T, -, rsub, VX_BINARY_REVERSE_BODY_X16);
DEF_VX_BINARY_CASE_1_WRAP(T, &, and, VX_BINARY_BODY_X16)
DEF_VX_BINARY_CASE_1_WRAP(T, |, or, VX_BINARY_BODY_X16)
DEF_VX_BINARY_CASE_1_WRAP(T, ^, xor, VX_BINARY_BODY_X16)
DEF_VX_BINARY_CASE_1_WRAP(T, *, mul, VX_BINARY_BODY_X16)
DEF_VX_BINARY_CASE_1_WRAP(T, /, div, VX_BINARY_BODY_X8)
DEF_VX_BINARY_CASE_1_WRAP(T, %, rem, VX_BINARY_BODY_X8)

/* { dg-final { scan-assembler-not {vadd.vx} } } */
/* { dg-final { scan-assembler {vsub.vx} } } */
/* { dg-final { scan-assembler {vrsub.vx} } } */
/* { dg-final { scan-assembler {vand.vx} } } */
/* { dg-final { scan-assembler {vor.vx} } } */
/* { dg-final { scan-assembler {vxor.vx} } } */
/* { dg-final { scan-assembler-not {vmul.vx} } } */
/* { dg-final { scan-assembler {vdiv.vx} } } */
/* { dg-final { scan-assembler {vrem.vx} } } */
