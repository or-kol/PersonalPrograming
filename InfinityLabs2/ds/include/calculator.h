#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__



typedef enum status {
    SUCCESS,
    INVALID_INPUT,
    DIV_ZERO,
    DOUBLE_OVERFLOW,
    ALLOC_FAIL
} status_t;


status_t Calculator (const char *math_exp, double *result);

#endif /*__CALCULATOR_H__*/




