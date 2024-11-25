#ifndef _HEAVY_SIGNAL_FAUST_H_
#define _HEAVY_SIGNAL_FAUST_H_

#include "HvHeavyInternal.h"
#include "faustcode.c"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct SignalFaust {
    mydsp * faust;
} SignalFaust;

hv_size_t sFaust_init(SignalFaust *o, double samplerate);

static inline void __hv_faust_f(SignalFaust *o, hv_bInf_t bIn, hv_bOutf_t bOut) {
    float *input = &bIn;
    float *output = bOut;
    computemydsp(o->faust, 1, &input, &output);
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_SIGNAL_PAUST_H_
