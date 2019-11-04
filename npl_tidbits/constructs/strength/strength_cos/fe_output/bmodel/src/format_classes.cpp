/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "format_classes.h"

#include "bm_field.h"

void obj_bus_t::set_port_type_cfg(_2bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 1;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((port_type_cfg(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    port_type_cfg(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->port_type_cfg: 0x" + port_type_cfg.to_string(SC_HEX_US, false));
    }
#endif
}

void obj_bus_t::set_port_num(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((port_num(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    port_num(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->port_num: 0x" + port_num.to_string(SC_HEX_US, false));
    }
#endif
}

void obj_bus_t::set_dst_modid(_8bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 7;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_modid(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_modid(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->dst_modid: 0x" + dst_modid.to_string(SC_HEX_US, false));
    }
#endif
}

void obj_bus_t::set_dst_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->dst_port: 0x" + dst_port.to_string(SC_HEX_US, false));
    }
#endif
}

obj_bus_t::obj_bus_t() {
    uint i;

    set_resetval();
}

obj_bus_t::~obj_bus_t() {
    uint i;

}

void obj_bus_t::set_resetval(void) {
    uint i;

    port_type_cfg = (_2bits)(0x0U);
    port_num = (_7bits)(0x0U);
    dst_modid = (_8bits)(0x0U);
    dst_port = (_7bits)(0x0U);
}

void obj_bus_t::set_randval(void) {
    uint i;

    port_type_cfg = (_2bits)(rand());
    port_num = (_7bits)(rand());
    dst_modid = (_8bits)(rand());
    dst_port = (_7bits)(rand());
}

void obj_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("obj_bus_t->port_type_cfg = 0x" + port_type_cfg.to_string(SC_HEX_US, false));
    bmi_log->normal("obj_bus_t->port_num = 0x" + port_num.to_string(SC_HEX_US, false));
    bmi_log->normal("obj_bus_t->dst_modid = 0x" + dst_modid.to_string(SC_HEX_US, false));
    bmi_log->normal("obj_bus_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
#endif
}

int obj_bus_t::compare(obj_bus_t *ref, obj_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (port_type_cfg != ref->port_type_cfg) {
            mismatch = 1;
        }
    } else {
        if ((port_type_cfg & ref_mask->port_type_cfg) != (ref->port_type_cfg & ref_mask->port_type_cfg)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (port_num != ref->port_num) {
            mismatch = 1;
        }
    } else {
        if ((port_num & ref_mask->port_num) != (ref->port_num & ref_mask->port_num)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (dst_modid != ref->dst_modid) {
            mismatch = 1;
        }
    } else {
        if ((dst_modid & ref_mask->dst_modid) != (ref->dst_modid & ref_mask->dst_modid)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (dst_port != ref->dst_port) {
            mismatch = 1;
        }
    } else {
        if ((dst_port & ref_mask->dst_port) != (ref->dst_port & ref_mask->dst_port)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void obj_bus_t::deep_copy(obj_bus_t *ref) {
    uint i;

    port_type_cfg = ref->port_type_cfg;
    port_num = ref->port_num;
    dst_modid = ref->dst_modid;
    dst_port = ref->dst_port;
}

void obj_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 1, &field);
    set_port_type_cfg((_2bits)field, -1, -1);
    bm_field_get(_data, 2, 8, &field);
    set_port_num((_7bits)field, -1, -1);
    bm_field_get(_data, 9, 16, &field);
    set_dst_modid((_8bits)field, -1, -1);
    bm_field_get(_data, 17, 23, &field);
    set_dst_port((_7bits)field, -1, -1);
}

void obj_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) port_type_cfg.range(1, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 1), &field);
    field = (uint32_t) port_num.range(6, 0).to_int();
    bm_field_set(_data, (offset + 2), (offset + 8), &field);
    field = (uint32_t) dst_modid.range(7, 0).to_int();
    bm_field_set(_data, (offset + 9), (offset + 16), &field);
    field = (uint32_t) dst_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 17), (offset + 23), &field);
}

int obj_bus_t::minbit() {
    return 0;
}

int obj_bus_t::maxbit() {
    return 23;
}

void ccbi_t::set_l2_pbm(_128bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 127;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((l2_pbm(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    l2_pbm(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: ccbi_t->l2_pbm: 0x" + l2_pbm.to_string(SC_HEX_US, false));
    }
#endif
}

void ccbi_t::set_l3_pbm(_128bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 127;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((l3_pbm(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    l3_pbm(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: ccbi_t->l3_pbm: 0x" + l3_pbm.to_string(SC_HEX_US, false));
    }
#endif
}

ccbi_t::ccbi_t() {
    uint i;

    set_resetval();
}

ccbi_t::~ccbi_t() {
    uint i;

}

void ccbi_t::set_resetval(void) {
    uint i;

    l2_pbm = (_128bits)(0x0U);
    l3_pbm = (_128bits)(0x0U);
}

void ccbi_t::set_randval(void) {
    uint i;

    l2_pbm = (_128bits)(rand());
    l3_pbm = (_128bits)(rand());
}

void ccbi_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ccbi_t->l2_pbm = 0x" + l2_pbm.to_string(SC_HEX_US, false));
    bmi_log->normal("ccbi_t->l3_pbm = 0x" + l3_pbm.to_string(SC_HEX_US, false));
#endif
}

int ccbi_t::compare(ccbi_t *ref, ccbi_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (l2_pbm != ref->l2_pbm) {
            mismatch = 1;
        }
    } else {
        if ((l2_pbm & ref_mask->l2_pbm) != (ref->l2_pbm & ref_mask->l2_pbm)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (l3_pbm != ref->l3_pbm) {
            mismatch = 1;
        }
    } else {
        if ((l3_pbm & ref_mask->l3_pbm) != (ref->l3_pbm & ref_mask->l3_pbm)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ccbi_t::deep_copy(ccbi_t *ref) {
    uint i;

    l2_pbm = ref->l2_pbm;
    l3_pbm = ref->l3_pbm;
}

void ccbi_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 127, &field);
    set_l2_pbm((_128bits)field, -1, -1);
    bm_field_get(_data, 128, 255, &field);
    set_l3_pbm((_128bits)field, -1, -1);
}

void ccbi_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
}

int ccbi_t::minbit() {
    return 0;
}

int ccbi_t::maxbit() {
    return 255;
}

void ccbe_t::set_dst_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: ccbe_t->dst_port: 0x" + dst_port.to_string(SC_HEX_US, false));
    }
#endif
}

ccbe_t::ccbe_t() {
    uint i;

    set_resetval();
}

ccbe_t::~ccbe_t() {
    uint i;

}

void ccbe_t::set_resetval(void) {
    uint i;

    dst_port = (_7bits)(0x0U);
}

void ccbe_t::set_randval(void) {
    uint i;

    dst_port = (_7bits)(rand());
}

void ccbe_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ccbe_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
#endif
}

int ccbe_t::compare(ccbe_t *ref, ccbe_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (dst_port != ref->dst_port) {
            mismatch = 1;
        }
    } else {
        if ((dst_port & ref_mask->dst_port) != (ref->dst_port & ref_mask->dst_port)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ccbe_t::deep_copy(ccbe_t *ref) {
    uint i;

    dst_port = ref->dst_port;
}

void ccbe_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 6, &field);
    set_dst_port((_7bits)field, -1, -1);
}

void ccbe_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) dst_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 6), &field);
}

int ccbe_t::minbit() {
    return 0;
}

int ccbe_t::maxbit() {
    return 6;
}

void control_id_t::set_otpid_enable(_4bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 3;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((otpid_enable(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    otpid_enable(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: control_id_t->otpid_enable: 0x" + otpid_enable.to_string(SC_HEX_US, false));
    }
#endif
}

void control_id_t::set_ts_enable(_1bit value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((ts_enable(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    ts_enable(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: control_id_t->ts_enable: 0x" + ts_enable.to_string(SC_HEX_US, false));
    }
#endif
}

control_id_t::control_id_t() {
    uint i;

    set_resetval();
}

control_id_t::~control_id_t() {
    uint i;

}

void control_id_t::set_resetval(void) {
    uint i;

    otpid_enable = (_4bits)(0x0U);
    ts_enable = (_1bit)(0x0U);
}

void control_id_t::set_randval(void) {
    uint i;

    otpid_enable = (_4bits)(rand());
    ts_enable = (_1bit)(rand());
}

void control_id_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("control_id_t->otpid_enable = 0x" + otpid_enable.to_string(SC_HEX_US, false));
    bmi_log->normal("control_id_t->ts_enable = 0x" + ts_enable.to_string(SC_HEX_US, false));
#endif
}

int control_id_t::compare(control_id_t *ref, control_id_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (otpid_enable != ref->otpid_enable) {
            mismatch = 1;
        }
    } else {
        if ((otpid_enable & ref_mask->otpid_enable) != (ref->otpid_enable & ref_mask->otpid_enable)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (ts_enable != ref->ts_enable) {
            mismatch = 1;
        }
    } else {
        if ((ts_enable & ref_mask->ts_enable) != (ref->ts_enable & ref_mask->ts_enable)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void control_id_t::deep_copy(control_id_t *ref) {
    uint i;

    otpid_enable = ref->otpid_enable;
    ts_enable = ref->ts_enable;
}

void control_id_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 3, &field);
    set_otpid_enable((_4bits)field, -1, -1);
    bm_field_get(_data, 4, 4, &field);
    set_ts_enable((_1bit)field, -1, -1);
}

void control_id_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) otpid_enable.range(3, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 3), &field);
    field = (uint32_t) ts_enable.range(0, 0).to_int();
    bm_field_set(_data, (offset + 4), (offset + 4), &field);
}

int control_id_t::minbit() {
    return 0;
}

int control_id_t::maxbit() {
    return 4;
}

void egr_obj_bus_t::set_dst_modid(_8bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 7;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_modid(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_modid(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->dst_modid: 0x" + dst_modid.to_string(SC_HEX_US, false));
    }
#endif
}

void egr_obj_bus_t::set_dst_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->dst_port: 0x" + dst_port.to_string(SC_HEX_US, false));
    }
#endif
}

void egr_obj_bus_t::set_ing_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((ing_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    ing_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->ing_port: 0x" + ing_port.to_string(SC_HEX_US, false));
    }
#endif
}

void egr_obj_bus_t::set_ingress_timestamp(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((ingress_timestamp(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    ingress_timestamp(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->ingress_timestamp: 0x" + ingress_timestamp.to_string(SC_HEX_US, false));
    }
#endif
}

egr_obj_bus_t::egr_obj_bus_t() {
    uint i;

    set_resetval();
}

egr_obj_bus_t::~egr_obj_bus_t() {
    uint i;

}

void egr_obj_bus_t::set_resetval(void) {
    uint i;

    dst_modid = (_8bits)(0x0U);
    dst_port = (_7bits)(0x0U);
    ing_port = (_7bits)(0x0U);
    ingress_timestamp = (_16bits)(0x0U);
}

void egr_obj_bus_t::set_randval(void) {
    uint i;

    dst_modid = (_8bits)(rand());
    dst_port = (_7bits)(rand());
    ing_port = (_7bits)(rand());
    ingress_timestamp = (_16bits)(rand());
}

void egr_obj_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("egr_obj_bus_t->dst_modid = 0x" + dst_modid.to_string(SC_HEX_US, false));
    bmi_log->normal("egr_obj_bus_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
    bmi_log->normal("egr_obj_bus_t->ing_port = 0x" + ing_port.to_string(SC_HEX_US, false));
    bmi_log->normal("egr_obj_bus_t->ingress_timestamp = 0x" + ingress_timestamp.to_string(SC_HEX_US, false));
#endif
}

int egr_obj_bus_t::compare(egr_obj_bus_t *ref, egr_obj_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (dst_modid != ref->dst_modid) {
            mismatch = 1;
        }
    } else {
        if ((dst_modid & ref_mask->dst_modid) != (ref->dst_modid & ref_mask->dst_modid)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (dst_port != ref->dst_port) {
            mismatch = 1;
        }
    } else {
        if ((dst_port & ref_mask->dst_port) != (ref->dst_port & ref_mask->dst_port)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (ing_port != ref->ing_port) {
            mismatch = 1;
        }
    } else {
        if ((ing_port & ref_mask->ing_port) != (ref->ing_port & ref_mask->ing_port)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (ingress_timestamp != ref->ingress_timestamp) {
            mismatch = 1;
        }
    } else {
        if ((ingress_timestamp & ref_mask->ingress_timestamp) != (ref->ingress_timestamp & ref_mask->ingress_timestamp)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void egr_obj_bus_t::deep_copy(egr_obj_bus_t *ref) {
    uint i;

    dst_modid = ref->dst_modid;
    dst_port = ref->dst_port;
    ing_port = ref->ing_port;
    ingress_timestamp = ref->ingress_timestamp;
}

void egr_obj_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 7, &field);
    set_dst_modid((_8bits)field, -1, -1);
    bm_field_get(_data, 8, 14, &field);
    set_dst_port((_7bits)field, -1, -1);
    bm_field_get(_data, 15, 21, &field);
    set_ing_port((_7bits)field, -1, -1);
    bm_field_get(_data, 22, 37, &field);
    set_ingress_timestamp((_16bits)field, -1, -1);
}

void egr_obj_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) dst_modid.range(7, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 7), &field);
    field = (uint32_t) dst_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 8), (offset + 14), &field);
    field = (uint32_t) ing_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 15), (offset + 21), &field);
    field = (uint32_t) ingress_timestamp.range(15, 0).to_int();
    bm_field_set(_data, (offset + 22), (offset + 37), &field);
}

int egr_obj_bus_t::minbit() {
    return 0;
}

int egr_obj_bus_t::maxbit() {
    return 37;
}

void aux_bus_t::set_drop_vector(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((drop_vector(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    drop_vector(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: aux_bus_t->drop_vector: 0x" + drop_vector.to_string(SC_HEX_US, false));
    }
#endif
}

aux_bus_t::aux_bus_t() {
    uint i;

    set_resetval();
}

aux_bus_t::~aux_bus_t() {
    uint i;

}

void aux_bus_t::set_resetval(void) {
    uint i;

    drop_vector = (_16bits)(0x0U);
}

void aux_bus_t::set_randval(void) {
    uint i;

    drop_vector = (_16bits)(rand());
}

void aux_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("aux_bus_t->drop_vector = 0x" + drop_vector.to_string(SC_HEX_US, false));
#endif
}

int aux_bus_t::compare(aux_bus_t *ref, aux_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (drop_vector != ref->drop_vector) {
            mismatch = 1;
        }
    } else {
        if ((drop_vector & ref_mask->drop_vector) != (ref->drop_vector & ref_mask->drop_vector)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void aux_bus_t::deep_copy(aux_bus_t *ref) {
    uint i;

    drop_vector = ref->drop_vector;
}

void aux_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 15, &field);
    set_drop_vector((_16bits)field, -1, -1);
}

void aux_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) drop_vector.range(15, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 15), &field);
}

int aux_bus_t::minbit() {
    return 0;
}

int aux_bus_t::maxbit() {
    return 15;
}

void local_bus_t::set_vlan_pri(_3bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 2;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((vlan_pri(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    vlan_pri(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: local_bus_t->vlan_pri: 0x" + vlan_pri.to_string(SC_HEX_US, false));
    }
#endif
}

void local_bus_t::set_dscp(_6bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 5;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dscp(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dscp(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: local_bus_t->dscp: 0x" + dscp.to_string(SC_HEX_US, false));
    }
#endif
}

void local_bus_t::set_cos(_3bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 2;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((cos(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    cos(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: local_bus_t->cos: 0x" + cos.to_string(SC_HEX_US, false));
    }
#endif
}

void local_bus_t::set_cos_strength(_4bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 3;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((cos_strength(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    cos_strength(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: local_bus_t->cos_strength: 0x" + cos_strength.to_string(SC_HEX_US, false));
    }
#endif
}

local_bus_t::local_bus_t() {
    uint i;

    set_resetval();
}

local_bus_t::~local_bus_t() {
    uint i;

}

void local_bus_t::set_resetval(void) {
    uint i;

    vlan_pri = (_3bits)(0x0U);
    dscp = (_6bits)(0x0U);
    cos = (_3bits)(0x0U);
    cos_strength = (_4bits)(0x0U);
}

void local_bus_t::set_randval(void) {
    uint i;

    vlan_pri = (_3bits)(rand());
    dscp = (_6bits)(rand());
    cos = (_3bits)(rand());
    cos_strength = (_4bits)(rand());
}

void local_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("local_bus_t->vlan_pri = 0x" + vlan_pri.to_string(SC_HEX_US, false));
    bmi_log->normal("local_bus_t->dscp = 0x" + dscp.to_string(SC_HEX_US, false));
    bmi_log->normal("local_bus_t->cos = 0x" + cos.to_string(SC_HEX_US, false));
    bmi_log->normal("local_bus_t->cos_strength = 0x" + cos_strength.to_string(SC_HEX_US, false));
#endif
}

int local_bus_t::compare(local_bus_t *ref, local_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (vlan_pri != ref->vlan_pri) {
            mismatch = 1;
        }
    } else {
        if ((vlan_pri & ref_mask->vlan_pri) != (ref->vlan_pri & ref_mask->vlan_pri)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (dscp != ref->dscp) {
            mismatch = 1;
        }
    } else {
        if ((dscp & ref_mask->dscp) != (ref->dscp & ref_mask->dscp)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (cos != ref->cos) {
            mismatch = 1;
        }
    } else {
        if ((cos & ref_mask->cos) != (ref->cos & ref_mask->cos)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (cos_strength != ref->cos_strength) {
            mismatch = 1;
        }
    } else {
        if ((cos_strength & ref_mask->cos_strength) != (ref->cos_strength & ref_mask->cos_strength)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void local_bus_t::deep_copy(local_bus_t *ref) {
    uint i;

    vlan_pri = ref->vlan_pri;
    dscp = ref->dscp;
    cos = ref->cos;
    cos_strength = ref->cos_strength;
}

void local_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 2, &field);
    set_vlan_pri((_3bits)field, -1, -1);
    bm_field_get(_data, 3, 8, &field);
    set_dscp((_6bits)field, -1, -1);
    bm_field_get(_data, 9, 11, &field);
    set_cos((_3bits)field, -1, -1);
    bm_field_get(_data, 12, 15, &field);
    set_cos_strength((_4bits)field, -1, -1);
}

void local_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) vlan_pri.range(2, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 2), &field);
    field = (uint32_t) dscp.range(5, 0).to_int();
    bm_field_set(_data, (offset + 3), (offset + 8), &field);
    field = (uint32_t) cos.range(2, 0).to_int();
    bm_field_set(_data, (offset + 9), (offset + 11), &field);
    field = (uint32_t) cos_strength.range(3, 0).to_int();
    bm_field_set(_data, (offset + 12), (offset + 15), &field);
}

int local_bus_t::minbit() {
    return 0;
}

int local_bus_t::maxbit() {
    return 15;
}

void time_bus_t::set_currenttime(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((currenttime(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    currenttime(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: time_bus_t->currenttime: 0x" + currenttime.to_string(SC_HEX_US, false));
    }
#endif
}

time_bus_t::time_bus_t() {
    uint i;

    set_resetval();
}

time_bus_t::~time_bus_t() {
    uint i;

}

void time_bus_t::set_resetval(void) {
    uint i;

    currenttime = (_16bits)(0x0U);
}

void time_bus_t::set_randval(void) {
    uint i;

    currenttime = (_16bits)(rand());
}

void time_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("time_bus_t->currenttime = 0x" + currenttime.to_string(SC_HEX_US, false));
#endif
}

int time_bus_t::compare(time_bus_t *ref, time_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (currenttime != ref->currenttime) {
            mismatch = 1;
        }
    } else {
        if ((currenttime & ref_mask->currenttime) != (ref->currenttime & ref_mask->currenttime)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void time_bus_t::deep_copy(time_bus_t *ref) {
    uint i;

    currenttime = ref->currenttime;
}

void time_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 15, &field);
    set_currenttime((_16bits)field, -1, -1);
}

void time_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) currenttime.range(15, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 15), &field);
}

int time_bus_t::minbit() {
    return 0;
}

int time_bus_t::maxbit() {
    return 15;
}

