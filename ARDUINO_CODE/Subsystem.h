//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem.h
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
#ifndef Subsystem_h_
#define Subsystem_h_
#include <cmath>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "Subsystem_types.h"

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

// Class declaration for model Subsystem
class Subsystem final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_Subsystem_T {
    real_T last_x_PreviousInput[5];    // '<S3>/last_x'
    boolean_T Memory_PreviousInput[42];// '<S3>/Memory'
  };

  // Invariant block signals (default storage)
  struct ConstB_Subsystem_T {
    real_T MathFunction[2];            // '<S3>/Math Function'
    real_T MathFunction1;              // '<S3>/Math Function1'
    real_T MathFunction2;              // '<S3>/Math Function2'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_Subsystem_T {
    real_T moorx[2];                   // '<Root>/mo or x'
    real_T Reference[2];               // '<Root>/Reference'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_Subsystem_T {
    real_T Steeringanglerad;           // '<Root>/Steeringangle (rad)'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_Subsystem_T {
    const char_T * volatile errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
  };

  // Copy Constructor
  Subsystem(Subsystem const&) = delete;

  // Assignment Operator
  Subsystem& operator= (Subsystem const&) & = delete;

  // Move Constructor
  Subsystem(Subsystem &&) = delete;

  // Move Assignment Operator
  Subsystem& operator= (Subsystem &&) = delete;

  // Real-Time Model get method
  Subsystem::RT_MODEL_Subsystem_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_Subsystem_T *pExtU_Subsystem_T)
  {
    Subsystem_U = *pExtU_Subsystem_T;
  }

  // Root outports get method
  const ExtY_Subsystem_T &getExternalOutputs() const
  {
    return Subsystem_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  Subsystem();

  // Destructor
  ~Subsystem();

  // private data and function members
 private:
  // External inputs
  ExtU_Subsystem_T Subsystem_U;

  // External outputs
  ExtY_Subsystem_T Subsystem_Y;

  // Block states
  DW_Subsystem_T Subsystem_DW;

  // private member function(s) for subsystem '<Root>'
  real_T Subsystem_norm(const real_T x[4]);
  real_T Subsystem_maximum(const real_T x[4]);
  real_T Subsystem_xnrm2(int32_T n, const real_T x[16], int32_T ix0);
  void Subsystem_xgemv(int32_T b_m, int32_T n, const real_T b_A[16], int32_T ia0,
                       const real_T x[16], int32_T ix0, real_T y[4]);
  void Subsystem_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T ix0, const
                       real_T y[4], real_T b_A[16], int32_T ia0);
  real_T Subsystem_KWIKfactor(const real_T b_Ac[168], const int32_T iC[42],
    int32_T nA, const real_T b_Linv[16], real_T RLinv[16], real_T D[16], real_T
    b_H[16], int32_T n);
  void Subsystem_DropConstraint(int32_T kDrop, boolean_T iA[42], int32_T *nA,
    int32_T iC[42]);
  void Subsystem_qpkwik(const real_T b_Linv[16], const real_T b_Hinv[16], const
                        real_T f[4], const real_T b_Ac[168], const real_T b[42],
                        boolean_T iA[42], int32_T maxiter, real_T FeasTol,
                        real_T x[4], real_T lambda[42], int32_T *status);

  // Real-Time Model
  RT_MODEL_Subsystem_T Subsystem_M;
};

extern const Subsystem::ConstB_Subsystem_T Subsystem_ConstB;// constant block i/o 

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Constant' : Unused code path elimination
//  Block '<S3>/Floor' : Unused code path elimination
//  Block '<S3>/Floor1' : Unused code path elimination
//  Block '<S4>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S5>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S6>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S7>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S8>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S9>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S10>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S11>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S12>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S13>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S14>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S15>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S16>/Vector Dimension Check' : Unused code path elimination
//  Block '<S17>/Vector Dimension Check' : Unused code path elimination
//  Block '<S18>/Vector Dimension Check' : Unused code path elimination
//  Block '<S19>/Vector Dimension Check' : Unused code path elimination
//  Block '<S20>/Vector Dimension Check' : Unused code path elimination
//  Block '<S21>/Vector Dimension Check' : Unused code path elimination
//  Block '<S3>/Min' : Unused code path elimination
//  Block '<S3>/constant' : Unused code path elimination
//  Block '<S22>/Vector Dimension Check' : Unused code path elimination
//  Block '<S3>/umin_scale2' : Unused code path elimination
//  Block '<S3>/umin_scale3' : Unused code path elimination
//  Block '<S3>/umin_scale5' : Unused code path elimination
//  Block '<S3>/ym_zero' : Unused code path elimination
//  Block '<S2>/m_zero' : Unused code path elimination
//  Block '<S2>/p_zero' : Unused code path elimination
//  Block '<S3>/Reshape' : Reshape block reduction
//  Block '<S3>/Reshape1' : Reshape block reduction
//  Block '<S3>/Reshape2' : Reshape block reduction
//  Block '<S3>/Reshape3' : Reshape block reduction
//  Block '<S3>/Reshape4' : Reshape block reduction
//  Block '<S3>/Reshape5' : Reshape block reduction
//  Block '<S3>/ext.mv_scale' : Eliminated nontunable gain of 1
//  Block '<S3>/ext.mv_scale1' : Eliminated nontunable gain of 1
//  Block '<S3>/umin_scale1' : Eliminated nontunable gain of 1
//  Block '<S3>/umin_scale4' : Eliminated nontunable gain of 1
//  Block '<S3>/ymin_scale2' : Eliminated nontunable gain of 1


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('exportarC_digo/Subsystem')    - opens subsystem exportarC_digo/Subsystem
//  hilite_system('exportarC_digo/Subsystem/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'exportarC_digo'
//  '<S1>'   : 'exportarC_digo/Subsystem'
//  '<S2>'   : 'exportarC_digo/Subsystem/MPC Controller'
//  '<S3>'   : 'exportarC_digo/Subsystem/MPC Controller/MPC'
//  '<S4>'   : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Matrix Signal Check'
//  '<S5>'   : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Matrix Signal Check1'
//  '<S6>'   : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Matrix Signal Check2'
//  '<S7>'   : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check'
//  '<S8>'   : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S9>'   : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check2'
//  '<S10>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S11>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S12>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check5'
//  '<S13>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check6'
//  '<S14>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check7'
//  '<S15>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Preview Signal Check8'
//  '<S16>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Scalar Signal Check'
//  '<S17>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S18>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S19>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Vector Signal Check'
//  '<S20>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S21>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/MPC Vector Signal Check6'
//  '<S22>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/moorx'
//  '<S23>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/optimizer'
//  '<S24>'  : 'exportarC_digo/Subsystem/MPC Controller/MPC/optimizer/optimizer'

#endif                                 // Subsystem_h_

//
// File trailer for generated code.
//
// [EOF]
//
