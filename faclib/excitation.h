#ifndef _EXCITATION_H_
#define _EXCITATION_H_

#include "consts.h"
#include "structure.h"

typedef struct _CEPW_SCRATCH_ {
  int qr;
  int max_kl;
  int kl_cb;
  double tolerance;
  int nkl0;
  int nkl;
  int ns;
  double kl[MAXNKL+1];
  double log_kl[MAXNKL];
} CEPW_SCRATCH;

typedef struct _CEPK_ {
  short nkl;
  short nkappa;
  short *kappa0;
  short *kappa1;
  double *pkd;
  double *pke;
} CEPK;

CEPW_SCRATCH *GetCEPWScratch(void);
int FreeExcitationQk(void);
int InitExcitation(void);
int ReinitExcitation(int m);
int SetCETEGrid(int n, double emin, double emax);
int SetCETEGridDetail(int n, double *x);
int SetAngleGrid(int m, int n, double xmin, double xmax);
int SetAngleGridDetail(int m, int n, double *xg);
int SetCEPWFile(char *fn);
int SetCEBorn(double e, double x, double x1, double x0);
void SetCELQR(int m);
void SetCELMax(int m);
void SetCELCB(int m);
void SetCETol(double t);
int SetCEPWOptions(int qr, int max, int kl_cb, double tol);
int AddCEPW(int n, int step);
int SetCEFormat(int m);
int SetCEPWGrid(int ns, int *n, int *step);
int SetCEEGridLimits(double min, double max, int type);
int SetCEEGridType(int type);
int SetUsrCEEGridType(int type);
int SetCEPWGridType(int type);
int SetCEEGridDetail(int n, double *x);
int SetCEEGrid(int n, double emin, double emax, double eth);
int SetUsrCEEGridDetail(int n, double *x);
int SetUsrCEEGrid(int n, double emin, double emax, double eth);

int CERadialPk(CEPK **pk, int ie, int k0, int k1, int k);
int CERadialQkBorn(int k0, int k1, int k2, int k3, int k, 
		   double te, double e1, double *qk, int m);
int CERadialQkBornMSub(int k0, int k1, int k2, int k3, int k, int kp,
		       double te, double e1, 
		       int nq, int *q, double *qk, int m);
double *CERadialQkTable(int k0, int k1, int k2, int k3, int k);
double *CERadialQkMSubTable(int k0, int k1, int k2, int k3, int k, int kp);
int CERadialQk(double *r, double te, 
	       int k0, int k1, int k2, int k3, int k);
int CERadialQkMSub(double *rq, double te, int k0, int k1,
		   int k2, int k3, int k, int kp);
void CERadialQkFromFit(int np, double *p, int n, double *x, double *logx,
		       double *y, double *dy, int ndy, void *extra);
int CollisionStrength(const TRANSITION *tr, int msub,
                      double *qkt, double *params, double *bethe);
int SaveExcitation(int nlow, int *low, int nup, int *up, int msub, char *fn);
int CollisionStrengthEB(double *s, double *e, double *bethe, int lower, int upper);
int CollisionStrengthEBD(double *s, double *e, double *bethe, double *born,
			 int lower, int upper);
int SaveExcitationEB(int nlow, int *low, int nup, int *up, char *fn);
int SaveExcitationEBD(int nlow, int *low, int nup, int *up, char *fn);

#endif
