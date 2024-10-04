#include <R.h>
#include <Rinternals.h>
#include <stdlib.h>
#include <math.h>

// Function from the morse v 3.3.1 package.

/**
 * Number of MCMC iterations
 */
static int MCMC;
/**
 * Arrays storing parameter values
 */
static double *kd=NULL;
static double *hb=NULL;

/**
 * Array contains the forcing data Cw(t) for the current point in time
 * and its alias
 */
static double forc[1];
#define Cw forc[0]

/**
 * Parameter initializer
 *
 * Two parameters have to be passed from the R environment to the solver in
 * the following order: kd and hb
 */
void gutsredit_init(void (* odeparms)(int *, double *))
{
  // get access to parameters supplied to deSolve
  SEXP (*fun)(void);
  fun = (SEXP(*)(void))R_GetCCallable("deSolve", "get_deSolve_gparms");
  if(LENGTH(fun())==0)
    error("no parameters supplied");

  // peak into first argument
  MCMC = (int)REAL(fun())[0];
  // allocate memory
  int N = MCMC*2+1;
  double *arr = (double*)calloc(N, sizeof(double));
  kd = (double*)calloc(MCMC, sizeof(double));
  hb = (double*)calloc(MCMC, sizeof(double));
  // import parameters
  odeparms(&N, arr);
  // by copying the array we avoid index magic later on
  for(int i=0; i<MCMC; i++) {
    kd[i] = arr[i+1];
    hb[i] = arr[MCMC+i+1];
  }
  free(arr);
}

/**
 * Free allocated memory
 */
void gutsredit_free(void)
{
  free(kd);
  free(hb);
}

/**
 * Forcings initializer
 *
 * Data is passed from R environment to solver
 */
void gutsredit_forc(void (* odeforcs)(int *, double *))
{
  int N=1;
  odeforcs(&N, forc);
}

/**
 * ODEs of the GUTS-RED-IT model
 */
void gutsredit_func(int *neq, double *t, double *y, double *ydot, double *yout, int*ip)
{
  for(int i=0; i<MCMC; i++) {
    // dDw/dt
    ydot[i] = kd[i]*(Cw-y[i]);
    // dH/dt
    ydot[MCMC+i] = hb[i];
  }

  // Add Cw(t) to output if requested for e.g. debugging purposes
  if(ip[0]>0)
    yout[0] = Cw;
}
