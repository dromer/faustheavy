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

mydsp* newmydsp() {
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) {
	free(dsp);
}

// void metadatamydsp(MetaGlue* m) {
// 	m->declare(m->metaInterface, "compile_options", "-lang c -es 1 -mcd 16 -single -ftz 0");
// 	m->declare(m->metaInterface, "filename", "faustcode.dsp");
// 	m->declare(m->metaInterface, "filters.lib/fir:author", "Julius O. Smith III");
// 	m->declare(m->metaInterface, "filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
// 	m->declare(m->metaInterface, "filters.lib/fir:license", "MIT-style STK-4.3 license");
// 	m->declare(m->metaInterface, "filters.lib/iir:author", "Julius O. Smith III");
// 	m->declare(m->metaInterface, "filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
// 	m->declare(m->metaInterface, "filters.lib/iir:license", "MIT-style STK-4.3 license");
// 	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
// 	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
// 	m->declare(m->metaInterface, "filters.lib/resonlp:author", "Julius O. Smith III");
// 	m->declare(m->metaInterface, "filters.lib/resonlp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
// 	m->declare(m->metaInterface, "filters.lib/resonlp:license", "MIT-style STK-4.3 license");
// 	m->declare(m->metaInterface, "filters.lib/tf2:author", "Julius O. Smith III");
// 	m->declare(m->metaInterface, "filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
// 	m->declare(m->metaInterface, "filters.lib/tf2:license", "MIT-style STK-4.3 license");
// 	m->declare(m->metaInterface, "filters.lib/tf2s:author", "Julius O. Smith III");
// 	m->declare(m->metaInterface, "filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
// 	m->declare(m->metaInterface, "filters.lib/tf2s:license", "MIT-style STK-4.3 license");
// 	m->declare(m->metaInterface, "filters.lib/version", "0.3");
// 	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
// 	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
// 	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
// 	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
// 	m->declare(m->metaInterface, "maths.lib/version", "2.5");
// 	m->declare(m->metaInterface, "name", "faustcode");
// 	m->declare(m->metaInterface, "noises.lib/name", "Faust Noise Generator Library");
// 	m->declare(m->metaInterface, "noises.lib/version", "0.4");
// 	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
// 	m->declare(m->metaInterface, "platform.lib/version", "0.3");
// }

int getSampleRatemydsp(mydsp* dsp) {
	return dsp->fSampleRate;
}

int getNumInputsmydsp(mydsp* dsp) {
	return 0;
}
int getNumOutputsmydsp(mydsp* dsp) {
	return 1;
}

void classInitmydsp(int sample_rate) {
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->iRec1[l0] = 0;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 3; l1 = l1 + 1) {
			dsp->fRec0[l1] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	float fConst0 = tanf(1570.7964f / fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate))));
	dsp->fConst1 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fConst0));
	float fConst2 = 1.0f / fConst0;
	dsp->fConst3 = (fConst2 + -0.2f) / fConst0 + 1.0f;
	dsp->fConst4 = 1.0f / ((fConst2 + 0.2f) / fConst0 + 1.0f);
}

void instanceInitmydsp(mydsp* dsp, int sample_rate) {
	instanceConstantsmydsp(dsp, sample_rate);
	instanceResetUserInterfacemydsp(dsp);
	instanceClearmydsp(dsp);
}

void initmydsp(mydsp* dsp, int sample_rate) {
	classInitmydsp(sample_rate);
	instanceInitmydsp(dsp, sample_rate);
}

// void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface) {
// 	ui_interface->openVerticalBox(ui_interface->uiInterface, "faustcode");
// 	ui_interface->closeBox(ui_interface->uiInterface);
// }

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iRec1[0] = 1103515245 * dsp->iRec1[1] + 12345;
			dsp->fRec0[0] = 4.656613e-10f * (float)(dsp->iRec1[0]) - dsp->fConst4 * (dsp->fConst3 * dsp->fRec0[2] + dsp->fConst1 * dsp->fRec0[1]);
			output0[i0] = (FAUSTFLOAT)(dsp->fConst4 * (dsp->fRec0[2] + dsp->fRec0[0] + 2.0f * dsp->fRec0[1]));
			dsp->iRec1[1] = dsp->iRec1[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
