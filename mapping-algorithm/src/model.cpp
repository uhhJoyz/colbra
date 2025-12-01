#include "model.h"
#include "types.h"

#include <vector>
#include <math.h>

u32 bank_level_est(size_t size, size_t operation)
{
  switch (operation)
  {
  case OP_VEC_ADD:
    return 1.266e-07 * pow((float)size, 0.999);
  case OP_VEC_DOT:
    return 1.393e-07 * pow((float)size, 0.996);
  case OP_MAT_VEC:
    return 6.208e-02 * pow((float)size, 0.999);
  case OP_MAT_MAT:
    return 8.043e-02 * pow((float)size, 0.998);
  default:
    // return largest possible value if none selected
    return -1u;
  }
}

u32 bit_serial_est(size_t size, size_t operation)
{
  switch (operation)
  {
  case OP_VEC_ADD:
    return 1.086e-03 * pow((float)size, 0.393);
  case OP_VEC_DOT:
    return 6.647e-04 * pow((float)size, 0.423);
  case OP_MAT_VEC:
    return 6.208e-02 * pow((float)size, 0.999);
  case OP_MAT_MAT:
    return 1.589e+01 * pow((float)size, 0.999);
  default:
    // return largest possible value if none selected
    return -1u;
  }
}

u32 gpu_est(size_t size, size_t operation)
{
  switch (operation)
  {
  case OP_VEC_ADD:
    return 2.689e-06 * pow((float)size, 0.164);
  case OP_VEC_DOT:
    return 3.720e-06 * pow((float)size, 0.161);
  case OP_MAT_VEC:
    return 2.798e-06 * pow((float)size, 1.850);
  case OP_MAT_MAT:
    return 1.749e-04 * pow((float)size, 0.796);
  default:
    // return largest possible value if none selected
    return -1u;
  }
}

u32 cpu_est(size_t size, size_t operation)
{
  switch (operation)
  {
  case OP_VEC_ADD:
    return 1.387e-06 * pow((float)size, 0.215);
  case OP_VEC_DOT:
    return 1.648e-10 * pow((float)size, 1.037);
  case OP_MAT_VEC:
    return 1.128e-06 * pow((float)size, 0.991);
  case OP_MAT_MAT:
    return 2.781e-05 * pow((float)size, 0.952);
  default:
    // return largest possible value if none selected
    return -1u;
  }
}
