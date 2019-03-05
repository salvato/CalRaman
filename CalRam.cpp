#include "stdafx.h"
#include <math.h>

extern double freq[MAXDATA], s[MAXDATA], ttt, alpha, b;
extern int nRaman;

double __stdcall
CalRam(double x) {
  double r, dt, denom;
  int i;
  if(x <= freq[0]) {
    r = (s[0]/freq[0])*(x-freq[0])+s[0];
//    r = s[0];
  } else {
    for(i=1; i<nRaman; i++) {
      if(x <= freq[i]) break;
    }
    if(i<nRaman) {
      r = ((s[i]-s[i-1])/(freq[i]-freq[i-1]))*(x-freq[i])+s[i];
    } else {
      r = s[nRaman-1];
    }
  }
  dt = x/ttt;
  denom = -2.0 + exp(dt) + exp(-dt);

  return(r*x/(b+pow(x, alpha))) * (dt*dt)/denom;
}


double __stdcall
CalRam2(double x) {
  double dt, denom;
  dt = x/ttt;
  denom = -2.0 + exp(dt) + exp(-dt);
  return(x*x) * (dt*dt)/denom;
}


double __stdcall
CalRam3(double x) {
  double dt, denom;
  dt = x/ttt;
  denom = -2.0 + exp(dt) + exp(-dt);
  return(x*x*x*x) * (dt*dt)/denom;
}
