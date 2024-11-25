/* ------------------------------------------------------------
name: "faustcode"
Code generated with Faust 2.54.9 (https://faust.grame.fr)
Compilation options: -lang c -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	int fSampleRate;
	float fConst1;
	float fConst3;
	float fConst4;
	int iRec1[2];
	float fRec0[3];
} mydsp;

mydsp* newmydsp();
void deletemydsp(mydsp* dsp);
int getSampleRatemydsp(mydsp* dsp);
int getNumInputsmydsp(mydsp* dsp);
int getNumOutputsmydsp(mydsp* dsp);
void classInitmydsp(int sample_rate);
void instanceResetUserInterfacemydsp(mydsp* dsp);
void instanceClearmydsp(mydsp* dsp);
void instanceConstantsmydsp(mydsp* dsp, int sample_rate);
void instanceInitmydsp(mydsp* dsp, int sample_rate);
void initmydsp(mydsp* dsp, int sample_rate);
void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs);

#ifdef __cplusplus
}
#endif

#endif
