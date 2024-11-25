#include <faustcode.h>


mydsp* newmydsp() {
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) {
	free(dsp);
}

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
