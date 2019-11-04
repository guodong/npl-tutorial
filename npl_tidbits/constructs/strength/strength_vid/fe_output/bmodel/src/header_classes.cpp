/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "header_classes.h"
#include "bmodel.h"

l2_t::l2_t() {
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

l2_t::~l2_t() {
    delete[] hdr_bytes;
}

void l2_t::set_resetval() {
    uint i;

    reset_header_base_class();
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int l2_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+14)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            macda |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            macda |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            macsa |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            macsa |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void l2_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macda) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macda) << 0));
        }
    }
    byte_ptr = 6;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macsa) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macsa) << 0));
        }
    }
    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) << 0));
        }
    }
    update_header_location();

}

void l2_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("l2_t->macda = 0x" + macda.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->macsa = 0x" + macsa.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->ethertype = 0x" + ethertype.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void l2_t::deep_copy(l2_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    macda = ref->macda;
    macsa = ref->macsa;
    ethertype = ref->ethertype;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

vlan_t::vlan_t() {
    pcp = (_3bits)(0x0U);
    cfi = (_1bit)(0x0U);
    vid = (_12bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 4;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

vlan_t::~vlan_t() {
    delete[] hdr_bytes;
}

void vlan_t::set_resetval() {
    uint i;

    reset_header_base_class();
    pcp = (_3bits)(0x0U);
    cfi = (_1bit)(0x0U);
    vid = (_12bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 4;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int vlan_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+4)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    pcp = (_3bits)((pkt[*hdr_ptr + byte_ptr] >> 5) & 0x7);

    byte_ptr = 0;
    cfi = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 4) & 0x1);

    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            vid |= (((_12bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            vid |= (((_12bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void vlan_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(pcp)) << 5) & (_8bits)(0xe0U));
    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(cfi)) << 4) & (_8bits)(0x10U));
    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((vid) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((vid) << 0));
        }
    }
    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) << 0));
        }
    }
    update_header_location();

}

void vlan_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("vlan_t->pcp = 0x" + pcp.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->cfi = 0x" + cfi.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->vid = 0x" + vid.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->ethertype = 0x" + ethertype.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void vlan_t::deep_copy(vlan_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    pcp = ref->pcp;
    cfi = ref->cfi;
    vid = ref->vid;
    ethertype = ref->ethertype;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

snap_t::snap_t() {
    oui = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 8;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

snap_t::~snap_t() {
    delete[] hdr_bytes;
}

void snap_t::set_resetval() {
    uint i;

    reset_header_base_class();
    oui = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 8;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int snap_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+8)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            oui |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            oui |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void snap_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((oui) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((oui) << 0));
        }
    }
    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) << 0));
        }
    }
    update_header_location();

}

void snap_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("snap_t->oui = 0x" + oui.to_string(SC_HEX_US, false));
    bmi_log->normal("snap_t->ethertype = 0x" + ethertype.to_string(SC_HEX_US, false));
    bmi_log->normal("snap_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("snap_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void snap_t::deep_copy(snap_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    oui = ref->oui;
    ethertype = ref->ethertype;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

snap_llc_t::snap_llc_t() {
    snap_llc = (_48bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 6;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

snap_llc_t::~snap_llc_t() {
    delete[] hdr_bytes;
}

void snap_llc_t::set_resetval() {
    uint i;

    reset_header_base_class();
    snap_llc = (_48bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 6;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int snap_llc_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+6)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            snap_llc |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            snap_llc |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void snap_llc_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((snap_llc) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((snap_llc) << 0));
        }
    }
    update_header_location();

}

void snap_llc_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("snap_llc_t->snap_llc = 0x" + snap_llc.to_string(SC_HEX_US, false));
    bmi_log->normal("snap_llc_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("snap_llc_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void snap_llc_t::deep_copy(snap_llc_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    snap_llc = ref->snap_llc;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

llc_t::llc_t() {
    llc = (_24bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 3;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

llc_t::~llc_t() {
    delete[] hdr_bytes;
}

void llc_t::set_resetval() {
    uint i;

    reset_header_base_class();
    llc = (_24bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 3;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int llc_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+3)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 3; i++) {
        if (i != 2) {
            llc |= (((_24bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (3 - i - 1))));
        } else {
            llc |= (((_24bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void llc_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 3; i++) {
        if (i != 2) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((llc) >> (8 * (3 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((llc) << 0));
        }
    }
    update_header_location();

}

void llc_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("llc_t->llc = 0x" + llc.to_string(SC_HEX_US, false));
    bmi_log->normal("llc_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("llc_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void llc_t::deep_copy(llc_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    llc = ref->llc;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

void group1_t::set_l2(l2_t *ref) {
    uint i;
    l2->deep_copy(ref);
}

void group1_t::set_vlan_tag(vlan_t *ref) {
    uint i;
    vlan_tag->deep_copy(ref);
}

void group1_t::set_snap(snap_t *ref) {
    uint i;
    snap->deep_copy(ref);
}

void group1_t::set_llc(llc_t *ref) {
    uint i;
    llc->deep_copy(ref);
}

void group1_t::set_snap_or_llc(snap_llc_t *ref) {
    uint i;
    snap_or_llc->deep_copy(ref);
}

group1_t::group1_t() {
    uint i;
    l2 = new l2_t;
    vlan_tag = new vlan_t;
    snap = new snap_t;
    llc = new llc_t;
    snap_or_llc = new snap_llc_t;
}

void group1_t::set_resetval() {
    uint i;
    l2->set_resetval();
    vlan_tag->set_resetval();
    snap->set_resetval();
    llc->set_resetval();
    snap_or_llc->set_resetval();
}

group1_t::~group1_t() {
    uint i;
    delete l2;
    delete vlan_tag;
    delete snap;
    delete llc;
    delete snap_or_llc;
}

void group1_t::deep_copy(group1_t *ref) {
    uint i;
    l2->deep_copy(ref->l2);
    vlan_tag->deep_copy(ref->vlan_tag);
    snap->deep_copy(ref->snap);
    llc->deep_copy(ref->llc);
    snap_or_llc->deep_copy(ref->snap_or_llc);
}

void ing_pkt_t::set_group1(group1_t *ref) {
    uint i;
    group1->deep_copy(ref);
}

ing_pkt_t::ing_pkt_t() {
    uint i;
    _match_id = 0;
    group1 = new group1_t;

    num_hdr = 5;
    hdr_ptr_array = (header_base_t **)(malloc(5 * sizeof(header_base_t *)));

}

ing_pkt_t::~ing_pkt_t() {
    delete group1;
    free(hdr_ptr_array);
}

void ing_pkt_t::set_resetval() {
    group1->set_resetval();
    num_hdr = 5;
    group1->l2->hdr_id = 0;
    hdr_ptr_array[0] = group1->l2;
    group1->snap_or_llc->hdr_id = 1;
    hdr_ptr_array[1] = group1->snap_or_llc;
    group1->snap->hdr_id = 2;
    hdr_ptr_array[2] = group1->snap;
    group1->llc->hdr_id = 3;
    hdr_ptr_array[3] = group1->llc;
    group1->vlan_tag->hdr_id = 4;
    hdr_ptr_array[4] = group1->vlan_tag;
}

void ing_pkt_t::deep_copy(ing_pkt_t *ref) {
    uint i;
    group1->deep_copy(ref->group1);
}

