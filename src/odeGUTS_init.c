#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .C calls */
extern void gutsredit_free(void);
extern void gutsredsd_free(void);

extern void gutsredsd_init(void (* odeparms)(int *, double *));
extern void gutsredsd_forc(void (* odeforcs)(int *, double *));
extern void gutsredsd_func(int *neq, double *t, double *y, double *ydot, double *yout, int*ip);

extern void gutsredit_init(void (* odeparms)(int *, double *));
extern void gutsredit_forc(void (* odeforcs)(int *, double *));
extern void gutsredit_func(int *neq, double *t, double *y, double *ydot, double *yout, int*ip);


static const R_CMethodDef CEntries[] = {
    {"gutsredit_free", (DL_FUNC) &gutsredit_free, 0},
    {"gutsredsd_free", (DL_FUNC) &gutsredsd_free, 0},
    {"gutsredsd_init", (DL_FUNC) &gutsredsd_init, 1},
    {"gutsredsd_forc", (DL_FUNC) &gutsredsd_forc, 1},
    {"gutsredsd_func", (DL_FUNC) &gutsredsd_func, 6},
    {"gutsredit_init", (DL_FUNC) &gutsredit_init, 1},
    {"gutsredit_forc", (DL_FUNC) &gutsredit_forc, 1},
    {"gutsredit_func", (DL_FUNC) &gutsredit_func, 6},
    {NULL, NULL, 0}
};

void R_init_odeGUTS(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
