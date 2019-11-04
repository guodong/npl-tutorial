/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _REG_CLASSES
#define _REG_CLASSES

#include "bit_types.h"

class ts_ctrl;

class ts_ctrl {
public:
    _1bit enable;

    ts_ctrl(void);

    void set_enable(_1bit, int, int);

    void print(void);
    int compare(ts_ctrl *ref, ts_ctrl *ref_mask);
    void deep_copy(ts_ctrl *ref);

};

#endif
