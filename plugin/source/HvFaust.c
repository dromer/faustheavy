#include "HvFaust.h"

hv_size_t sFaust_init(SignalFaust *o, double samplerate){
    o->faust = newmydsp();

    initmydsp(o->faust, (int)samplerate);

    return sizeof(mydsp);
}
