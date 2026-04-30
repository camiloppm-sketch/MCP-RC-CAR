//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem.cpp
//
// Code generated for Simulink model 'Subsystem'.
//
// Model version                  : 7.2
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Apr 28 18:42:53 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Subsystem.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "Subsystem_private.h"
#include "cmath"

// Named constants for MATLAB Function: '<S23>/optimizer'
const int32_T Subsystem_degrees{ 4 };

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S23>/optimizer'
real_T Subsystem::Subsystem_norm(const real_T x[4])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[3]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  y = scale * std::sqrt(y);
  if (std::isnan(y)) {
    int32_T b_k;
    b_k = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (b_k < 4) {
        if (std::isnan(x[b_k])) {
          exitg1 = 1;
        } else {
          b_k++;
        }
      } else {
        y = (rtInf);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return y;
}

// Function for MATLAB Function: '<S23>/optimizer'
real_T Subsystem::Subsystem_maximum(const real_T x[4])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 5; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S23>/optimizer'
real_T Subsystem::Subsystem_xnrm2(int32_T n, const real_T x[16], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T k;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
      if (std::isnan(y)) {
        k = ix0;
        int32_T exitg1;
        do {
          exitg1 = 0;
          if (k <= kend) {
            if (std::isnan(x[k - 1])) {
              exitg1 = 1;
            } else {
              k++;
            }
          } else {
            y = (rtInf);
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else if (std::isnan(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S23>/optimizer'
void Subsystem::Subsystem_xgemv(int32_T b_m, int32_T n, const real_T b_A[16],
  int32_T ia0, const real_T x[16], int32_T ix0, real_T y[4])
{
  if ((b_m != 0) && (n != 0)) {
    int32_T b;
    if (n - 1 >= 0) {
      std::memset(&y[0], 0, static_cast<uint32_T>(n) * sizeof(real_T));
    }

    b = ((n - 1) << 2) + ia0;
    for (int32_T b_iy{ia0}; b_iy <= b; b_iy += 4) {
      real_T c;
      int32_T d;
      int32_T ia;
      c = 0.0;
      d = b_iy + b_m;
      for (ia = b_iy; ia < d; ia++) {
        c += x[((ix0 + ia) - b_iy) - 1] * b_A[ia - 1];
      }

      ia = (b_iy - ia0) >> 2;
      y[ia] += c;
    }
  }
}

// Function for MATLAB Function: '<S23>/optimizer'
void Subsystem::Subsystem_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T
  ix0, const real_T y[4], real_T b_A[16], int32_T ia0)
{
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (int32_T j{0}; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = b_m + jA;
        for (int32_T ijA{jA}; ijA < b; ijA++) {
          b_A[ijA - 1] += b_A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 4;
    }
  }
}

// Function for MATLAB Function: '<S23>/optimizer'
real_T Subsystem::Subsystem_KWIKfactor(const real_T b_Ac[168], const int32_T iC
  [42], int32_T nA, const real_T b_Linv[16], real_T RLinv[16], real_T D[16],
  real_T b_H[16], int32_T n)
{
  real_T Q[16];
  real_T R[16];
  real_T TL[16];
  real_T b_A[16];
  real_T tau[4];
  real_T work[4];
  real_T RLinv_0;
  real_T RLinv_1;
  real_T RLinv_2;
  real_T Status;
  real_T tmp;
  real_T xnorm;
  int32_T b_lastv;
  int32_T c_lastc;
  int32_T e;
  int32_T exitg1;
  int32_T ii;
  int32_T k_i;
  int32_T knt;
  boolean_T exitg2;
  Status = 1.0;
  std::memset(&RLinv[0], 0, sizeof(real_T) << 4U);
  for (ii = 0; ii < nA; ii++) {
    b_lastv = iC[ii];
    xnorm = 0.0;
    RLinv_0 = 0.0;
    RLinv_1 = 0.0;
    RLinv_2 = 0.0;
    for (k_i = 0; k_i < 4; k_i++) {
      tmp = b_Ac[(42 * k_i + b_lastv) - 1];
      c_lastc = k_i << 2;
      xnorm += b_Linv[c_lastc] * tmp;
      RLinv_0 += b_Linv[c_lastc + 1] * tmp;
      RLinv_1 += b_Linv[c_lastc + 2] * tmp;
      RLinv_2 += b_Linv[c_lastc + 3] * tmp;
    }

    k_i = ii << 2;
    RLinv[k_i + 3] = RLinv_2;
    RLinv[k_i + 2] = RLinv_1;
    RLinv[k_i + 1] = RLinv_0;
    RLinv[k_i] = xnorm;
  }

  std::memcpy(&b_A[0], &RLinv[0], sizeof(real_T) << 4U);
  tau[0] = 0.0;
  work[0] = 0.0;
  tau[1] = 0.0;
  work[1] = 0.0;
  tau[2] = 0.0;
  work[2] = 0.0;
  tau[3] = 0.0;
  work[3] = 0.0;
  for (k_i = 0; k_i < 4; k_i++) {
    ii = (k_i << 2) + k_i;
    if (k_i + 1 < 4) {
      RLinv_0 = b_A[ii];
      b_lastv = ii + 2;
      tau[k_i] = 0.0;
      xnorm = Subsystem_xnrm2(3 - k_i, b_A, ii + 2);
      if (xnorm != 0.0) {
        RLinv_1 = b_A[ii];
        xnorm = rt_hypotd_snf(RLinv_1, xnorm);
        if (RLinv_1 >= 0.0) {
          xnorm = -xnorm;
        }

        if (std::abs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          e = (ii - k_i) + 4;
          do {
            knt++;
            for (c_lastc = b_lastv; c_lastc <= e; c_lastc++) {
              b_A[c_lastc - 1] *= 9.9792015476736E+291;
            }

            xnorm *= 9.9792015476736E+291;
            RLinv_0 *= 9.9792015476736E+291;
          } while ((std::abs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

          xnorm = rt_hypotd_snf(RLinv_0, Subsystem_xnrm2(3 - k_i, b_A, ii + 2));
          if (RLinv_0 >= 0.0) {
            xnorm = -xnorm;
          }

          tau[k_i] = (xnorm - RLinv_0) / xnorm;
          RLinv_0 = 1.0 / (RLinv_0 - xnorm);
          for (c_lastc = b_lastv; c_lastc <= e; c_lastc++) {
            b_A[c_lastc - 1] *= RLinv_0;
          }

          for (b_lastv = 0; b_lastv < knt; b_lastv++) {
            xnorm *= 1.0020841800044864E-292;
          }

          RLinv_0 = xnorm;
        } else {
          tau[k_i] = (xnorm - RLinv_1) / xnorm;
          RLinv_0 = 1.0 / (RLinv_1 - xnorm);
          knt = (ii - k_i) + 4;
          for (c_lastc = b_lastv; c_lastc <= knt; c_lastc++) {
            b_A[c_lastc - 1] *= RLinv_0;
          }

          RLinv_0 = xnorm;
        }
      }

      b_A[ii] = 1.0;
      if (tau[k_i] != 0.0) {
        b_lastv = 4 - k_i;
        c_lastc = (ii - k_i) + 3;
        while ((b_lastv > 0) && (b_A[c_lastc] == 0.0)) {
          b_lastv--;
          c_lastc--;
        }

        c_lastc = 3 - k_i;
        exitg2 = false;
        while ((!exitg2) && (c_lastc > 0)) {
          knt = (((c_lastc - 1) << 2) + ii) + 4;
          e = knt;
          do {
            exitg1 = 0;
            if (e + 1 <= knt + b_lastv) {
              if (b_A[e] != 0.0) {
                exitg1 = 1;
              } else {
                e++;
              }
            } else {
              c_lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        c_lastc = 0;
      }

      if (b_lastv > 0) {
        Subsystem_xgemv(b_lastv, c_lastc, b_A, ii + 5, b_A, ii + 1, work);
        Subsystem_xgerc(b_lastv, c_lastc, -tau[k_i], ii + 1, work, b_A, ii + 5);
      }

      b_A[ii] = RLinv_0;
    } else {
      tau[3] = 0.0;
    }
  }

  for (k_i = 0; k_i < 4; k_i++) {
    for (ii = 0; ii <= k_i; ii++) {
      b_lastv = k_i << 2;
      R[ii + b_lastv] = b_A[b_lastv + ii];
    }

    for (ii = k_i + 2; ii < 5; ii++) {
      R[(ii + (k_i << 2)) - 1] = 0.0;
    }

    work[k_i] = 0.0;
  }

  for (k_i = 3; k_i >= 0; k_i--) {
    ii = (k_i << 2) + k_i;
    if (k_i + 1 < 4) {
      b_A[ii] = 1.0;
      if (tau[k_i] != 0.0) {
        b_lastv = 4 - k_i;
        c_lastc = (ii - k_i) + 3;
        while ((b_lastv > 0) && (b_A[c_lastc] == 0.0)) {
          b_lastv--;
          c_lastc--;
        }

        c_lastc = 3 - k_i;
        exitg2 = false;
        while ((!exitg2) && (c_lastc > 0)) {
          knt = (((c_lastc - 1) << 2) + ii) + 4;
          e = knt;
          do {
            exitg1 = 0;
            if (e + 1 <= knt + b_lastv) {
              if (b_A[e] != 0.0) {
                exitg1 = 1;
              } else {
                e++;
              }
            } else {
              c_lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        c_lastc = 0;
      }

      if (b_lastv > 0) {
        Subsystem_xgemv(b_lastv, c_lastc, b_A, ii + 5, b_A, ii + 1, work);
        Subsystem_xgerc(b_lastv, c_lastc, -tau[k_i], ii + 1, work, b_A, ii + 5);
      }

      c_lastc = (ii - k_i) + 4;
      for (b_lastv = ii + 2; b_lastv <= c_lastc; b_lastv++) {
        b_A[b_lastv - 1] *= -tau[k_i];
      }
    }

    b_A[ii] = 1.0 - tau[k_i];
    for (b_lastv = 0; b_lastv < k_i; b_lastv++) {
      b_A[(ii - b_lastv) - 1] = 0.0;
    }
  }

  for (k_i = 0; k_i < 4; k_i++) {
    ii = k_i << 2;
    Q[ii] = b_A[ii];
    Q[ii + 1] = b_A[ii + 1];
    Q[ii + 2] = b_A[ii + 2];
    Q[ii + 3] = b_A[ii + 3];
  }

  k_i = 0;
  do {
    exitg1 = 0;
    if (k_i <= nA - 1) {
      if (std::abs(R[(k_i << 2) + k_i]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        k_i++;
      }
    } else {
      for (k_i = 0; k_i < n; k_i++) {
        for (ii = 0; ii < n; ii++) {
          b_lastv = k_i << 2;
          c_lastc = ii << 2;
          TL[k_i + c_lastc] = ((b_Linv[b_lastv + 1] * Q[c_lastc + 1] +
                                b_Linv[b_lastv] * Q[c_lastc]) + b_Linv[b_lastv +
                               2] * Q[c_lastc + 2]) + b_Linv[b_lastv + 3] *
            Q[c_lastc + 3];
        }
      }

      std::memset(&RLinv[0], 0, sizeof(real_T) << 4U);
      for (b_lastv = nA; b_lastv >= 1; b_lastv--) {
        k_i = (b_lastv - 1) << 2;
        ii = (b_lastv + k_i) - 1;
        RLinv[ii] = 1.0;
        for (c_lastc = b_lastv; c_lastc <= nA; c_lastc++) {
          e = (((c_lastc - 1) << 2) + b_lastv) - 1;
          RLinv[e] /= R[ii];
        }

        if (b_lastv > 1) {
          for (c_lastc = 0; c_lastc <= b_lastv - 2; c_lastc++) {
            for (knt = b_lastv; knt <= nA; knt++) {
              ii = (knt - 1) << 2;
              e = ii + c_lastc;
              RLinv[e] -= RLinv[(ii + b_lastv) - 1] * R[k_i + c_lastc];
            }
          }
        }
      }

      for (b_lastv = 0; b_lastv < n; b_lastv++) {
        for (c_lastc = b_lastv + 1; c_lastc <= n; c_lastc++) {
          k_i = ((c_lastc - 1) << 2) + b_lastv;
          b_H[k_i] = 0.0;
          for (knt = nA + 1; knt <= n; knt++) {
            ii = (knt - 1) << 2;
            b_H[k_i] -= TL[(ii + c_lastc) - 1] * TL[ii + b_lastv];
          }

          b_H[(c_lastc + (b_lastv << 2)) - 1] = b_H[k_i];
        }
      }

      for (b_lastv = 0; b_lastv < nA; b_lastv++) {
        for (c_lastc = 0; c_lastc < n; c_lastc++) {
          k_i = (b_lastv << 2) + c_lastc;
          D[k_i] = 0.0;
          for (knt = b_lastv + 1; knt <= nA; knt++) {
            ii = (knt - 1) << 2;
            D[k_i] += TL[ii + c_lastc] * RLinv[ii + b_lastv];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

// Function for MATLAB Function: '<S23>/optimizer'
void Subsystem::Subsystem_DropConstraint(int32_T kDrop, boolean_T iA[42],
  int32_T *nA, int32_T iC[42])
{
  if (kDrop > 0) {
    iA[iC[kDrop - 1] - 1] = false;
    if (kDrop < *nA) {
      for (int32_T i{kDrop}; i < *nA; i++) {
        iC[i - 1] = iC[i];
      }
    }

    iC[*nA - 1] = 0;
    (*nA)--;
  }
}

// Function for MATLAB Function: '<S23>/optimizer'
void Subsystem::Subsystem_qpkwik(const real_T b_Linv[16], const real_T b_Hinv[16],
  const real_T f[4], const real_T b_Ac[168], const real_T b[42], boolean_T iA[42],
  int32_T maxiter, real_T FeasTol, real_T x[4], real_T lambda[42], int32_T
  *status)
{
  real_T cTol[42];
  real_T D[16];
  real_T RLinv[16];
  real_T U[16];
  real_T b_H[16];
  real_T Opt[8];
  real_T Rhs[8];
  real_T r[4];
  real_T varargin_1[4];
  real_T Xnorm0;
  real_T cMin;
  real_T cVal;
  real_T rMin;
  real_T rVal;
  real_T t;
  real_T t1;
  real_T z;
  real_T z_idx_2;
  real_T z_idx_3;
  real_T z_tmp;
  int32_T iC[42];
  int32_T U_tmp;
  int32_T U_tmp_0;
  int32_T b_exponent;
  int32_T exitg1;
  int32_T exitg3;
  int32_T exponent;
  int32_T i;
  int32_T iSave;
  int32_T nA;
  int32_T r_tmp;
  int32_T tmp;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1;
  boolean_T guard2;
  x[0] = 0.0;
  x[1] = 0.0;
  x[2] = 0.0;
  x[3] = 0.0;
  *status = 1;
  r[0] = 0.0;
  r[1] = 0.0;
  r[2] = 0.0;
  r[3] = 0.0;
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 42; i++) {
    lambda[i] = 0.0;
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (i = 0; i < 42; i++) {
    if (iA[i]) {
      nA++;
      iC[nA - 1] = i + 1;
    }
  }

  guard1 = false;
  if (nA > 0) {
    std::memset(&Opt[0], 0, sizeof(real_T) << 3U);
    Rhs[0] = f[0];
    Rhs[4] = 0.0;
    Rhs[1] = f[1];
    Rhs[5] = 0.0;
    Rhs[2] = f[2];
    Rhs[6] = 0.0;
    Rhs[3] = f[3];
    Rhs[7] = 0.0;
    DualFeasible = false;
    tmp = static_cast<int32_T>(rt_roundd_snf(0.3 * static_cast<real_T>(nA)));
    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (*status <= maxiter)) {
        Xnorm0 = Subsystem_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D, b_H,
          Subsystem_degrees);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2;
            exitg3 = 2;
          } else {
            nA = 0;
            std::memset(&iC[0], 0, 42U * sizeof(int32_T));
            for (i = 0; i < 42; i++) {
              iA[i] = false;
            }

            ColdReset = true;
          }
        } else {
          for (i = 0; i < nA; i++) {
            Rhs[i + 4] = b[iC[i] - 1];
            for (r_tmp = i + 1; r_tmp <= nA; r_tmp++) {
              U_tmp_0 = ((i << 2) + r_tmp) - 1;
              U[U_tmp_0] = 0.0;
              for (iSave = 0; iSave < nA; iSave++) {
                U_tmp = iSave << 2;
                U[U_tmp_0] += RLinv[(U_tmp + r_tmp) - 1] * RLinv[U_tmp + i];
              }

              U[i + ((r_tmp - 1) << 2)] = U[U_tmp_0];
            }
          }

          for (i = 0; i < 4; i++) {
            Opt[i] = ((b_H[i + 4] * Rhs[1] + b_H[i] * Rhs[0]) + b_H[i + 8] *
                      Rhs[2]) + b_H[i + 12] * Rhs[3];
            for (r_tmp = 0; r_tmp < nA; r_tmp++) {
              Opt[i] += D[(r_tmp << 2) + i] * Rhs[r_tmp + 4];
            }
          }

          Xnorm0 = -1.0E-12;
          i = -1;
          for (r_tmp = 0; r_tmp < nA; r_tmp++) {
            iSave = r_tmp << 2;
            Opt[r_tmp + 4] = ((D[iSave + 1] * Rhs[1] + D[iSave] * Rhs[0]) +
                              D[iSave + 2] * Rhs[2]) + D[iSave + 3] * Rhs[3];
            for (iSave = 0; iSave < nA; iSave++) {
              Opt[r_tmp + 4] += U[(iSave << 2) + r_tmp] * Rhs[iSave + 4];
            }

            cMin = Opt[r_tmp + 4];
            lambda[iC[r_tmp] - 1] = cMin;
            if ((cMin < Xnorm0) && (r_tmp + 1 <= nA)) {
              i = r_tmp;
              Xnorm0 = cMin;
            }
          }

          if (i + 1 <= 0) {
            DualFeasible = true;
            x[0] = Opt[0];
            x[1] = Opt[1];
            x[2] = Opt[2];
            x[3] = Opt[3];
          } else {
            (*status)++;
            if (tmp <= 5) {
              r_tmp = 5;
            } else {
              r_tmp = tmp;
            }

            if (*status > r_tmp) {
              nA = 0;
              std::memset(&iC[0], 0, 42U * sizeof(int32_T));
              for (i = 0; i < 42; i++) {
                iA[i] = false;
              }

              ColdReset = true;
            } else {
              lambda[iC[i] - 1] = 0.0;
              Subsystem_DropConstraint(i + 1, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          std::memset(&lambda[0], 0, 42U * sizeof(real_T));
          Xnorm0 = f[1];
          cMin = f[0];
          cVal = f[2];
          z_idx_2 = f[3];
          for (tmp = 0; tmp < 4; tmp++) {
            x[tmp] = ((-b_Hinv[tmp + 4] * Xnorm0 + -b_Hinv[tmp] * cMin) +
                      -b_Hinv[tmp + 8] * cVal) + -b_Hinv[tmp + 12] * z_idx_2;
          }
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    Xnorm0 = f[1];
    cMin = f[0];
    cVal = f[2];
    z_idx_2 = f[3];
    for (tmp = 0; tmp < 4; tmp++) {
      x[tmp] = ((-b_Hinv[tmp + 4] * Xnorm0 + -b_Hinv[tmp] * cMin) + -b_Hinv[tmp
                + 8] * cVal) + -b_Hinv[tmp + 12] * z_idx_2;
    }

    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = Subsystem_norm(x);
    exitg2 = false;
    while ((!exitg2) && (*status <= maxiter)) {
      cMin = -FeasTol;
      tmp = -1;
      for (i = 0; i < 42; i++) {
        if (!cTolComputed) {
          varargin_1[0] = std::abs(b_Ac[i] * x[0]);
          varargin_1[1] = std::abs(b_Ac[i + 42] * x[1]);
          varargin_1[2] = std::abs(b_Ac[i + 84] * x[2]);
          varargin_1[3] = std::abs(b_Ac[i + 126] * x[3]);
          cTol[i] = std::fmax(cTol[i], Subsystem_maximum(varargin_1));
        }

        if (!iA[i]) {
          cVal = ((((b_Ac[i + 42] * x[1] + b_Ac[i] * x[0]) + b_Ac[i + 84] * x[2])
                   + b_Ac[i + 126] * x[3]) - b[i]) / cTol[i];
          if (cVal < cMin) {
            cMin = cVal;
            tmp = i;
          }
        }
      }

      cTolComputed = true;
      if (tmp + 1 <= 0) {
        exitg2 = true;
      } else if (*status == maxiter) {
        *status = 0;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((tmp + 1 > 0) && (*status < maxiter)) {
            guard2 = false;
            if (nA == 0) {
              cMin = 0.0;
              cVal = 0.0;
              z_idx_2 = 0.0;
              z_idx_3 = 0.0;
              for (r_tmp = 0; r_tmp < 4; r_tmp++) {
                t1 = b_Ac[42 * r_tmp + tmp];
                i = r_tmp << 2;
                cMin += b_Hinv[i] * t1;
                cVal += b_Hinv[i + 1] * t1;
                z_idx_2 += b_Hinv[i + 2] * t1;
                z_idx_3 += b_Hinv[i + 3] * t1;
              }

              guard2 = true;
            } else {
              cMin = Subsystem_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D, b_H,
                Subsystem_degrees);
              if (cMin <= 0.0) {
                *status = -2;
                exitg1 = 1;
              } else {
                for (r_tmp = 0; r_tmp < 16; r_tmp++) {
                  U[r_tmp] = -b_H[r_tmp];
                }

                cMin = 0.0;
                cVal = 0.0;
                z_idx_2 = 0.0;
                z_idx_3 = 0.0;
                for (r_tmp = 0; r_tmp < 4; r_tmp++) {
                  t1 = b_Ac[42 * r_tmp + tmp];
                  i = r_tmp << 2;
                  cMin += U[i] * t1;
                  cVal += U[i + 1] * t1;
                  z_idx_2 += U[i + 2] * t1;
                  z_idx_3 += U[i + 3] * t1;
                }

                for (i = 0; i < nA; i++) {
                  r_tmp = i << 2;
                  r[i] = ((D[r_tmp + 1] * b_Ac[tmp + 42] + D[r_tmp] * b_Ac[tmp])
                          + D[r_tmp + 2] * b_Ac[tmp + 84]) + D[r_tmp + 3] *
                    b_Ac[tmp + 126];
                }

                guard2 = true;
              }
            }

            if (guard2) {
              i = 0;
              t1 = 0.0;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0) {
                r_tmp = 0;
                exitg4 = false;
                while ((!exitg4) && (r_tmp <= nA - 1)) {
                  if (r[r_tmp] >= 1.0E-12) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    r_tmp++;
                  }
                }
              }

              if ((nA != 0) && (!ColdReset)) {
                for (r_tmp = 0; r_tmp < nA; r_tmp++) {
                  rVal = r[r_tmp];
                  if (rVal > 1.0E-12) {
                    rVal = lambda[iC[r_tmp] - 1] / rVal;
                    if ((i == 0) || (rVal < rMin)) {
                      rMin = rVal;
                      i = r_tmp + 1;
                    }
                  }
                }

                if (i > 0) {
                  t1 = rMin;
                  DualFeasible = false;
                }
              }

              rVal = b_Ac[tmp + 42];
              t = b_Ac[tmp + 84];
              z_tmp = b_Ac[tmp + 126];
              z = ((rVal * cVal + cMin * b_Ac[tmp]) + t * z_idx_2) + z_tmp *
                z_idx_3;
              if (z <= 0.0) {
                rVal = 0.0;
                ColdReset = true;
              } else {
                rVal = (b[tmp] - (((rVal * x[1] + b_Ac[tmp] * x[0]) + t * x[2])
                                  + z_tmp * x[3])) / z;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1;
                exitg1 = 1;
              } else {
                if (ColdReset) {
                  t = t1;
                } else if (DualFeasible) {
                  t = rVal;
                } else if (t1 < rVal) {
                  t = t1;
                } else {
                  t = rVal;
                }

                for (r_tmp = 0; r_tmp < nA; r_tmp++) {
                  iSave = iC[r_tmp];
                  lambda[iSave - 1] -= t * r[r_tmp];
                  if ((iSave <= 42) && (lambda[iSave - 1] < 0.0)) {
                    lambda[iSave - 1] = 0.0;
                  }
                }

                lambda[tmp] += t;
                std::frexp(1.0, &exponent);
                if (std::abs(t - t1) < 2.2204460492503131E-16) {
                  Subsystem_DropConstraint(i, iA, &nA, iC);
                }

                if (!ColdReset) {
                  x[0] += t * cMin;
                  x[1] += t * cVal;
                  x[2] += t * z_idx_2;
                  x[3] += t * z_idx_3;
                  std::frexp(1.0, &b_exponent);
                  if (std::abs(t - rVal) < 2.2204460492503131E-16) {
                    if (nA == Subsystem_degrees) {
                      *status = -1;
                      exitg1 = 1;
                    } else {
                      nA++;
                      iC[nA - 1] = tmp + 1;
                      i = nA - 1;
                      exitg4 = false;
                      while ((!exitg4) && (i + 1 > 1)) {
                        r_tmp = iC[i - 1];
                        if (iC[i] > r_tmp) {
                          exitg4 = true;
                        } else {
                          iSave = iC[i];
                          iC[i] = r_tmp;
                          iC[i - 1] = iSave;
                          i--;
                        }
                      }

                      iA[tmp] = true;
                      tmp = -1;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            cMin = Subsystem_norm(x);
            if (std::abs(cMin - Xnorm0) > 0.001) {
              Xnorm0 = cMin;
              for (tmp = 0; tmp < 42; tmp++) {
                cTol[tmp] = std::fmax(std::abs(b[tmp]), 1.0);
              }

              cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

// Model step function
void Subsystem::step()
{
  real_T a__1[42];
  real_T b_Mlim[42];
  real_T rseq[30];
  real_T g_a[5];
  real_T rtb_xest[5];
  real_T xk[5];
  real_T f[4];
  real_T zopt[4];
  real_T y_innov[2];
  real_T Reference;
  real_T Reference_0;
  int32_T i;
  int32_T rseq_tmp;
  static const real_T b_RYscale[2]{ 1.0, 0.1 };

  static const real_T a[10]{ 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  static const real_T b_a[10]{ 0.000574185369674547, 0.0810328878138843,
    0.0063858081714686012, 0.04922690654856713, -0.0071590052998311516,
    0.000560594275538174, 0.0057345405841590725, 0.006234654685888805,
    0.00094428348155686348, 0.094859122572588342 };

  static const real_T b_Linv[16]{ 1.8745865112062678, -6.3288353926340992,
    -3.3352230540958177, 0.0, 0.0, 7.49889630889296, -3.3730781555103611, 0.0,
    0.0, 0.0, 8.4612581740056836, 0.0, 0.0, 0.0, 0.0, 0.003162277660168379 };

  static const real_T b_Hinv[16]{ 54.691944835626742, -36.20931233788982,
    -28.220183328600438, 0.0, -36.20931233788982, 67.611102094709651,
    -28.540485114872055, 0.0, -28.220183328600438, -28.540485114872055,
    71.592889887177989, 0.0, 0.0, 0.0, 0.0, 9.9999999999999974E-6 };

  static const real_T b_Ac[168]{ -0.00806794795166478, -0.017427833599812929,
    -0.028037719247961078, -0.039897604896109225, -0.053007490544257373,
    -0.067367376192405515, -0.082977261840553665, -0.099837147488701816,
    -0.11794703313684997, -0.13730691878499812, -0.15791680443314626,
    -0.1797766900812944, -0.20288657572944255, -0.22724646137759069,
    -0.25285634702573884, 0.00806794795166478, 0.017427833599812929,
    0.028037719247961078, 0.039897604896109225, 0.053007490544257373,
    0.067367376192405515, 0.082977261840553665, 0.099837147488701816,
    0.11794703313684997, 0.13730691878499812, 0.15791680443314626,
    0.1797766900812944, 0.20288657572944255, 0.22724646137759069,
    0.25285634702573884, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, -1.0, -0.0, -0.0, 1.0,
    0.0, 0.0, -0.0, -0.00806794795166478, -0.017427833599812929,
    -0.028037719247961078, -0.039897604896109225, -0.053007490544257373,
    -0.067367376192405515, -0.082977261840553665, -0.099837147488701816,
    -0.11794703313684997, -0.13730691878499812, -0.15791680443314626,
    -0.1797766900812944, -0.20288657572944255, -0.22724646137759069, 0.0,
    0.00806794795166478, 0.017427833599812929, 0.028037719247961078,
    0.039897604896109225, 0.053007490544257373, 0.067367376192405515,
    0.082977261840553665, 0.099837147488701816, 0.11794703313684997,
    0.13730691878499812, 0.15791680443314626, 0.1797766900812944,
    0.20288657572944255, 0.22724646137759069, -0.0, -1.0, -1.0, 0.0, 1.0, 1.0,
    -0.0, -1.0, -0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.00806794795166478,
    -0.017427833599812929, -0.028037719247961078, -0.039897604896109225,
    -0.053007490544257373, -0.067367376192405515, -0.082977261840553665,
    -0.099837147488701816, -0.11794703313684997, -0.13730691878499812,
    -0.15791680443314626, -0.1797766900812944, -0.20288657572944255, 0.0, 0.0,
    0.00806794795166478, 0.017427833599812929, 0.028037719247961078,
    0.039897604896109225, 0.053007490544257373, 0.067367376192405515,
    0.082977261840553665, 0.099837147488701816, 0.11794703313684997,
    0.13730691878499812, 0.15791680443314626, 0.1797766900812944,
    0.20288657572944255, -0.0, -0.0, -1.0, 0.0, 0.0, 1.0, -0.0, -0.0, -1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T b_Kx[15]{ 0.00093830459611742533, 0.27514257501670036,
    0.00017813653122112445, 1.672557212330527, 0.0099918981481481491,
    0.00079645218543598591, 0.23942046392782659, 0.00015501303586934898,
    1.4197008653047882, 0.00874243827160494, 0.00066896692060315762,
    0.20606021352245568, 0.00013341736554826089, 1.1924544039271976,
    0.0075763117283950635 };

  static const real_T b_Mlim_0[42]{ 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0,
    4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0,
    4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 0.523598775598299, 0.523598775598299,
    0.523598775598299, 0.523598775598299, 0.523598775598299, 0.523598775598299,
    0.261799387799149, 0.261799387799149, 0.261799387799149, 0.261799387799149,
    0.261799387799149, 0.261799387799149 };

  static const real_T d_a[42]{ -0.00806794795166478, -0.017427833599812929,
    -0.028037719247961078, -0.039897604896109225, -0.053007490544257373,
    -0.067367376192405515, -0.082977261840553665, -0.099837147488701816,
    -0.11794703313684997, -0.13730691878499812, -0.15791680443314626,
    -0.1797766900812944, -0.20288657572944255, -0.22724646137759069,
    -0.25285634702573884, 0.00806794795166478, 0.017427833599812929,
    0.028037719247961078, 0.039897604896109225, 0.053007490544257373,
    0.067367376192405515, 0.082977261840553665, 0.099837147488701816,
    0.11794703313684997, 0.13730691878499812, 0.15791680443314626,
    0.1797766900812944, 0.20288657572944255, 0.22724646137759069,
    0.25285634702573884, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const real_T c_a[210]{ -0.00056099999999999976, -0.00056099999999999976,
    -0.00056099999999999976, -0.00056099999999999976, -0.00056099999999999976,
    -0.00056099999999999976, -0.00056099999999999976, -0.00056099999999999976,
    -0.00056099999999999976, -0.00056099999999999976, -0.00056099999999999976,
    -0.00056099999999999976, -0.00056099999999999976, -0.00056099999999999976,
    -0.00056099999999999976, 0.00056099999999999976, 0.00056099999999999976,
    0.00056099999999999976, 0.00056099999999999976, 0.00056099999999999976,
    0.00056099999999999976, 0.00056099999999999976, 0.00056099999999999976,
    0.00056099999999999976, 0.00056099999999999976, 0.00056099999999999976,
    0.00056099999999999976, 0.00056099999999999976, 0.00056099999999999976,
    0.00056099999999999976, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.015, -0.03, -0.045, -0.06, -0.075, -0.09, -0.105, -0.12, -0.135,
    -0.15000000000000002, -0.16500000000000004, -0.18000000000000005,
    -0.19500000000000006, -0.21000000000000008, -0.22500000000000009, 0.015,
    0.03, 0.045, 0.06, 0.075, 0.09, 0.105, 0.12, 0.135, 0.15000000000000002,
    0.16500000000000004, 0.18000000000000005, 0.19500000000000006,
    0.21000000000000008, 0.22500000000000009, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -9.6046661522633779E-6, -1.9326888374485602E-5,
    -2.9049110596707827E-5, -3.8771332818930048E-5, -4.8493555041152279E-5,
    -5.8215777263374496E-5, -6.7937999485596728E-5, -7.7660221707818959E-5,
    -8.7382443930041176E-5, -9.7104666152263407E-5, -0.00010682688837448565,
    -0.00011654911059670788, -0.00012627133281893011, -0.00013599355504115233,
    -0.00014571577726337458, 9.6046661522633779E-6, 1.9326888374485602E-5,
    2.9049110596707827E-5, 3.8771332818930048E-5, 4.8493555041152279E-5,
    5.8215777263374496E-5, 6.7937999485596728E-5, 7.7660221707818959E-5,
    8.7382443930041176E-5, 9.7104666152263407E-5, 0.00010682688837448565,
    0.00011654911059670788, 0.00012627133281893011, 0.00013599355504115233,
    0.00014571577726337458, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const real_T b_Ku1[3]{ 0.27456994151912395, 0.24016818520750066,
    0.207913557588142 };

  static const real_T b_Kr[90]{ -0.00806794795166478, -8.2793209876543247E-5,
    -0.017427833599812929, -0.0001661265432098766, -0.028037719247961078,
    -0.00024945987654321, -0.039897604896109225, -0.00033279320987654335,
    -0.053007490544257373, -0.00041612654320987672, -0.067367376192405515,
    -0.00049945987654321, -0.082977261840553665, -0.00058279320987654341,
    -0.099837147488701816, -0.00066612654320987678, -0.11794703313684997,
    -0.00074945987654321, -0.13730691878499812, -0.00083279320987654341,
    -0.15791680443314626, -0.00091612654320987667, -0.1797766900812944,
    -0.00099945987654321, -0.20288657572944255, -0.0010827932098765433,
    -0.22724646137759069, -0.0011661265432098768, -0.25285634702573884,
    -0.00124945987654321, -0.0, -0.0, -0.00806794795166478,
    -8.2793209876543247E-5, -0.017427833599812929, -0.0001661265432098766,
    -0.028037719247961078, -0.00024945987654321, -0.039897604896109225,
    -0.00033279320987654335, -0.053007490544257373, -0.00041612654320987672,
    -0.067367376192405515, -0.00049945987654321, -0.082977261840553665,
    -0.00058279320987654341, -0.099837147488701816, -0.00066612654320987678,
    -0.11794703313684997, -0.00074945987654321, -0.13730691878499812,
    -0.00083279320987654341, -0.15791680443314626, -0.00091612654320987667,
    -0.1797766900812944, -0.00099945987654321, -0.20288657572944255,
    -0.0010827932098765433, -0.22724646137759069, -0.0011661265432098768, -0.0,
    -0.0, -0.0, -0.0, -0.00806794795166478, -8.2793209876543247E-5,
    -0.017427833599812929, -0.0001661265432098766, -0.028037719247961078,
    -0.00024945987654321, -0.039897604896109225, -0.00033279320987654335,
    -0.053007490544257373, -0.00041612654320987672, -0.067367376192405515,
    -0.00049945987654321, -0.082977261840553665, -0.00058279320987654341,
    -0.099837147488701816, -0.00066612654320987678, -0.11794703313684997,
    -0.00074945987654321, -0.13730691878499812, -0.00083279320987654341,
    -0.15791680443314626, -0.00091612654320987667, -0.1797766900812944,
    -0.00099945987654321, -0.20288657572944255, -0.0010827932098765433 };

  static const real_T f_a[5]{ 0.074929875, 0.08279320987654322,
    0.83333333333333348, 0.00806794795166478, 0.0 };

  static const real_T e_a[25]{ 3.8517123819350844E-78, 0.0, 0.0,
    0.00056099999999999976, 0.0, 0.0, 1.0, 0.0, 0.015, 0.0,
    -6.1806747643591655E-71, 0.00064814814814814835, 9.8756490763801986E-68,
    9.6046661522633779E-6, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
  };

  static const real_T g_a_0[10]{ -1.7348797996370932E-18, 0.081037026763625078,
    -4.220239230425052E-18, 0.050442783317323381, -0.0071590052998312184,
    -2.358352337351945E-18, 0.0057385815640480587, -3.0033131360118033E-18,
    0.0010306759654846597, 0.094859122572588217 };

  // Outputs for Atomic SubSystem: '<Root>/Subsystem'
  // MATLAB Function: '<S23>/optimizer' incorporates:
  //   Inport: '<Root>/Reference'
  //   Inport: '<Root>/mo or x'
  //   Memory: '<S3>/last_x'
  //   UnitDelay: '<S3>/last_mv'

  Reference = Subsystem_U.Reference[0];
  Reference_0 = Subsystem_U.Reference[1];
  for (i = 0; i < 15; i++) {
    rseq_tmp = i << 1;
    rseq[rseq_tmp] = Reference;
    rseq[rseq_tmp + 1] = Reference_0 * 0.1;
  }

  for (i = 0; i < 5; i++) {
    xk[i] = Subsystem_DW.last_x_PreviousInput[i];
  }

  for (i = 0; i < 2; i++) {
    Reference = 0.0;
    for (rseq_tmp = 0; rseq_tmp < 5; rseq_tmp++) {
      Reference += a[(rseq_tmp << 1) + i] * xk[rseq_tmp];
    }

    y_innov[i] = Subsystem_U.moorx[i] * b_RYscale[i] - Reference;
  }

  Reference = y_innov[1];
  Reference_0 = y_innov[0];
  for (i = 0; i < 5; i++) {
    rtb_xest[i] = (b_a[i + 5] * Reference + b_a[i] * Reference_0) + xk[i];
  }

  f[0] = 0.0;
  f[1] = 0.0;
  f[2] = 0.0;
  f[3] = 0.0;
  for (rseq_tmp = 0; rseq_tmp < 3; rseq_tmp++) {
    Reference = 0.0;
    for (i = 0; i < 5; i++) {
      Reference += b_Kx[5 * rseq_tmp + i] * rtb_xest[i];
    }

    Reference_0 = 0.0;
    for (i = 0; i < 30; i++) {
      Reference_0 += b_Kr[30 * rseq_tmp + i] * rseq[i];
    }

    f[rseq_tmp] = (Reference + Reference_0) + b_Ku1[rseq_tmp] *
      Subsystem_Y.Steeringanglerad;
  }

  for (i = 0; i < 42; i++) {
    Reference = 0.0;
    for (rseq_tmp = 0; rseq_tmp < 5; rseq_tmp++) {
      Reference += c_a[42 * rseq_tmp + i] * rtb_xest[rseq_tmp];
    }

    b_Mlim[i] = -((b_Mlim_0[i] + Reference) + d_a[i] *
                  Subsystem_Y.Steeringanglerad);
  }

  // Update for Memory: '<S3>/Memory' incorporates:
  //   MATLAB Function: '<S23>/optimizer'

  Subsystem_qpkwik(b_Linv, b_Hinv, f, b_Ac, b_Mlim,
                   Subsystem_DW.Memory_PreviousInput, 184, 1.0E-6, zopt, a__1,
                   &i);

  // MATLAB Function: '<S23>/optimizer' incorporates:
  //   UnitDelay: '<S3>/last_mv'

  if ((i < 0) || (i == 0)) {
    zopt[0] = 0.0;
  }

  Subsystem_Y.Steeringanglerad += zopt[0];
  for (i = 0; i < 5; i++) {
    Reference = 0.0;
    for (rseq_tmp = 0; rseq_tmp < 5; rseq_tmp++) {
      Reference += e_a[5 * rseq_tmp + i] * xk[rseq_tmp];
    }

    rtb_xest[i] = f_a[i] * Subsystem_Y.Steeringanglerad + Reference;
    g_a[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    Reference = y_innov[i];
    for (rseq_tmp = 0; rseq_tmp < 5; rseq_tmp++) {
      g_a[rseq_tmp] += g_a_0[5 * i + rseq_tmp] * Reference;
    }
  }

  // Update for Memory: '<S3>/last_x' incorporates:
  //   MATLAB Function: '<S23>/optimizer'

  for (i = 0; i < 5; i++) {
    Subsystem_DW.last_x_PreviousInput[i] = rtb_xest[i] + g_a[i];
  }

  // End of Update for Memory: '<S3>/last_x'
  // End of Outputs for SubSystem: '<Root>/Subsystem'
}

// Model initialize function
void Subsystem::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void Subsystem::terminate()
{
  // (no terminate code required)
}

const char_T* Subsystem::RT_MODEL_Subsystem_T::getErrorStatus() const
{
  return (errorStatus);
}

void Subsystem::RT_MODEL_Subsystem_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
Subsystem::Subsystem() :
  Subsystem_U(),
  Subsystem_Y(),
  Subsystem_DW(),
  Subsystem_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Subsystem::~Subsystem() = default;

// Real-Time Model get method
Subsystem::RT_MODEL_Subsystem_T * Subsystem::getRTM()
{
  return (&Subsystem_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
