/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _REG_CLASSES
#define _REG_CLASSES

#include "bit_types.h"

class tpid_values;
class tpid_enable;

class tpid_values {
public:
    _16bits tpid0;
    _16bits tpid1;
    _16bits tpid2;
    _16bits tpid3;

    tpid_values(void);

    void set_tpid0(_16bits, int, int);
    void set_tpid1(_16bits, int, int);
    void set_tpid2(_16bits, int, int);
    void set_tpid3(_16bits, int, int);

    void print(void);
    int compare(tpid_values *ref, tpid_values *ref_mask);
    void deep_copy(tpid_values *ref);

};

class tpid_enable {
public:
    _4bits reg_val;

    tpid_enable(void);

    void set_reg_val(_4bits, int, int);

    void print(void);
    int compare(tpid_enable *ref, tpid_enable *ref_mask);
    void deep_copy(tpid_enable *ref);

};

#endif
