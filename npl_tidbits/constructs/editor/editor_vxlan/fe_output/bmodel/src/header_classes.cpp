/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "header_classes.h"
#include "bmodel.h"

udp_t::udp_t() {
    src_port = (_16bits)(0x0U);
    dst_port = (_16bits)(0x0U);
    udp_length = (_16bits)(0x0U);
    checksum = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 8;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

udp_t::~udp_t() {
    delete[] hdr_bytes;
}

void udp_t::set_resetval() {
    uint i;

    reset_header_base_class();
    src_port = (_16bits)(0x0U);
    dst_port = (_16bits)(0x0U);
    udp_length = (_16bits)(0x0U);
    checksum = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 8;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int udp_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+8)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            src_port |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            src_port |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            dst_port |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            dst_port |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            udp_length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            udp_length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void udp_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((src_port) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((src_port) << 0));
        }
    }
    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dst_port) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dst_port) << 0));
        }
    }
    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((udp_length) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((udp_length) << 0));
        }
    }
    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((checksum) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((checksum) << 0));
        }
    }
    update_header_location();

}

void udp_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("udp_t->src_port = 0x" + src_port.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->udp_length = 0x" + udp_length.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->checksum = 0x" + checksum.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void udp_t::deep_copy(udp_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    src_port = ref->src_port;
    dst_port = ref->dst_port;
    udp_length = ref->udp_length;
    checksum = ref->checksum;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

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

vxlan_t::vxlan_t() {
    f_flag1 = (_4bits)(0x0U);
    i_flag = (_1bit)(0x0U);
    f_flag2 = (_3bits)(0x0U);
    reserved1 = (_24bits)(0x0U);
    vn_id = (_24bits)(0x0U);
    reserved2 = (_8bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 8;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

vxlan_t::~vxlan_t() {
    delete[] hdr_bytes;
}

void vxlan_t::set_resetval() {
    uint i;

    reset_header_base_class();
    f_flag1 = (_4bits)(0x0U);
    i_flag = (_1bit)(0x0U);
    f_flag2 = (_3bits)(0x0U);
    reserved1 = (_24bits)(0x0U);
    vn_id = (_24bits)(0x0U);
    reserved2 = (_8bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 8;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int vxlan_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+8)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    f_flag1 = (_4bits)((pkt[*hdr_ptr + byte_ptr] >> 4) & 0xf);

    byte_ptr = 0;
    i_flag = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 3) & 0x1);

    byte_ptr = 0;
    f_flag2 = (_3bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0x7);

    byte_ptr = 1;
    for (i = 0; i < 3; i++) {
        if (i != 2) {
            reserved1 |= (((_24bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (3 - i - 1))));
        } else {
            reserved1 |= (((_24bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 4;
    for (i = 0; i < 3; i++) {
        if (i != 2) {
            vn_id |= (((_24bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (3 - i - 1))));
        } else {
            vn_id |= (((_24bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 7;
    i = 1;
    reserved2 = (_8bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xff);

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void vxlan_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(f_flag1)) << 4) & (_8bits)(0xf0U));
    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(i_flag)) << 3) & (_8bits)(0x8U));
    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(f_flag2)) << 0) & (_8bits)(0x7U));
    byte_ptr = 1;
    for (i = 0; i < 3; i++) {
        if (i != 2) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((reserved1) >> (8 * (3 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((reserved1) << 0));
        }
    }
    byte_ptr = 4;
    for (i = 0; i < 3; i++) {
        if (i != 2) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((vn_id) >> (8 * (3 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((vn_id) << 0));
        }
    }
    byte_ptr = 7;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(reserved2)) << 0) & (_8bits)(0xffU));
    update_header_location();

}

void vxlan_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("vxlan_t->f_flag1 = 0x" + f_flag1.to_string(SC_HEX_US, false));
    bmi_log->normal("vxlan_t->i_flag = 0x" + i_flag.to_string(SC_HEX_US, false));
    bmi_log->normal("vxlan_t->f_flag2 = 0x" + f_flag2.to_string(SC_HEX_US, false));
    bmi_log->normal("vxlan_t->reserved1 = 0x" + reserved1.to_string(SC_HEX_US, false));
    bmi_log->normal("vxlan_t->vn_id = 0x" + vn_id.to_string(SC_HEX_US, false));
    bmi_log->normal("vxlan_t->reserved2 = 0x" + reserved2.to_string(SC_HEX_US, false));
    bmi_log->normal("vxlan_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("vxlan_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void vxlan_t::deep_copy(vxlan_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    f_flag1 = ref->f_flag1;
    i_flag = ref->i_flag;
    f_flag2 = ref->f_flag2;
    reserved1 = ref->reserved1;
    vn_id = ref->vn_id;
    reserved2 = ref->reserved2;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

ipv4_t::ipv4_t() {
    version = (_4bits)(0x0U);
    tos = (_8bits)(0x0U);
    v4_length = (_16bits)(0x0U);
    id = (_16bits)(0x0U);
    flags = (_3bits)(0x0U);
    frag_offset = (_13bits)(0x0U);
    ttl = (_8bits)(0x0U);
    protocol = (_8bits)(0x0U);
    hdr_checksum = (_16bits)(0x0U);
    sip = (_32bits)(0x0U);
    dip = (_32bits)(0x0U);
    option = (_512bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    _VARBIT_LENGTH = (_32bits)(0x0U);
    hdr_len = (_4bits)(5);

    num_bytes = 84;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

ipv4_t::~ipv4_t() {
    delete[] hdr_bytes;
}

void ipv4_t::set_resetval() {
    uint i;

    reset_header_base_class();
    version = (_4bits)(0x0U);
    tos = (_8bits)(0x0U);
    v4_length = (_16bits)(0x0U);
    id = (_16bits)(0x0U);
    flags = (_3bits)(0x0U);
    frag_offset = (_13bits)(0x0U);
    ttl = (_8bits)(0x0U);
    protocol = (_8bits)(0x0U);
    hdr_checksum = (_16bits)(0x0U);
    sip = (_32bits)(0x0U);
    dip = (_32bits)(0x0U);
    option = (_512bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    _VARBIT_LENGTH = (_32bits)(0x0U);
    hdr_len = (_4bits)(5);

    num_bytes = 84;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int ipv4_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint _loc_hdr_len;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+20)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    version = (_4bits)((pkt[*hdr_ptr + byte_ptr] >> 4) & 0xf);

    byte_ptr = 0;
    hdr_len = (_4bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xf);

    byte_ptr = 1;
    tos = (_8bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xff);

    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            v4_length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            v4_length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    flags = (_3bits)((pkt[*hdr_ptr + byte_ptr] >> 5) & 0x7);

    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            frag_offset |= (((_13bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            frag_offset |= (((_13bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 8;
    ttl = (_8bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xff);

    byte_ptr = 9;
    protocol = (_8bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xff);

    byte_ptr = 10;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            hdr_checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 12;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            sip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (4 - i - 1))));
        } else {
            sip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 16;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            dip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (4 - i - 1))));
        } else {
            dip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    _loc_hdr_len = (hdr_len * 4 + 0);
    if (_loc_hdr_len < 20) {
        // Variable header length is less than fixed header
        _loc_hdr_len = 20;
    }
    if (_loc_hdr_len > (512/8 + 20)) {
        // variable header length is greater than max header size
        _loc_hdr_len = (512/8 + 20);
    }
    if (*pkt_len < (start_byte + _loc_hdr_len)) {
        // Remaining packet bytes are less than variable header size
        _loc_hdr_len = *pkt_len - start_byte;
    }
    byte_ptr = 20;
    _VARBIT_LENGTH = (_loc_hdr_len - 20)*8;
    for (i = 0; i < (_loc_hdr_len - 20); i++) {
        if (i != ((_loc_hdr_len - 20) - 1)) {
            option |= (((_512bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * ((_loc_hdr_len - 20) - i - 1))));
        } else {
            option |= (((_512bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    num_bytes = (byte_ptr + i);
    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void ipv4_t::pack() {
    uint byte_ptr;
    uint _loc_hdr_len;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(version)) << 4) & (_8bits)(0xf0U));
    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(hdr_len)) << 0) & (_8bits)(0xfU));
    byte_ptr = 1;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(tos)) << 0) & (_8bits)(0xffU));
    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((v4_length) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((v4_length) << 0));
        }
    }
    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((id) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((id) << 0));
        }
    }
    byte_ptr = 6;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags)) << 5) & (_8bits)(0xe0U));
    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((frag_offset) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((frag_offset) << 0));
        }
    }
    byte_ptr = 8;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(ttl)) << 0) & (_8bits)(0xffU));
    byte_ptr = 9;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(protocol)) << 0) & (_8bits)(0xffU));
    byte_ptr = 10;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((hdr_checksum) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((hdr_checksum) << 0));
        }
    }
    byte_ptr = 12;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sip) >> (8 * (4 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sip) << 0));
        }
    }
    byte_ptr = 16;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dip) >> (8 * (4 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dip) << 0));
        }
    }
    _loc_hdr_len = (hdr_len * 4 + 0);
    if (_loc_hdr_len < 20) {
        // Variable header length is less than fixed header
        _loc_hdr_len = 20;
    }
    if (_loc_hdr_len > (512/8 + 20)) {
        // variable header length is greater than max header size
        _loc_hdr_len = (512/8 + 20);
    }
    byte_ptr = 20;
    for (i = 0; i < (_loc_hdr_len - 20); i++) {
        if (i != ((_loc_hdr_len - 20) - 1)) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((option) >> (8 * ((_loc_hdr_len - 20) - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((option) << 0));
        }
    }
    num_bytes = (byte_ptr + i);
    update_header_location();

}

void ipv4_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("ipv4_t->version = 0x" + version.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->hdr_len = 0x" + hdr_len.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->tos = 0x" + tos.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->v4_length = 0x" + v4_length.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->id = 0x" + id.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->flags = 0x" + flags.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->frag_offset = 0x" + frag_offset.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->ttl = 0x" + ttl.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->protocol = 0x" + protocol.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->hdr_checksum = 0x" + hdr_checksum.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->sip = 0x" + sip.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->dip = 0x" + dip.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->option = 0x" + option.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->_VARBIT_LENGTH = 0x" + _VARBIT_LENGTH.to_string(SC_HEX_US, false));
#endif
}

void ipv4_t::deep_copy(ipv4_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    version = ref->version;
    hdr_len = ref->hdr_len;
    tos = ref->tos;
    v4_length = ref->v4_length;
    id = ref->id;
    flags = ref->flags;
    frag_offset = ref->frag_offset;
    ttl = ref->ttl;
    protocol = ref->protocol;
    hdr_checksum = ref->hdr_checksum;
    sip = ref->sip;
    dip = ref->dip;
    option = ref->option;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

void group1_t::set_l2(l2_t *ref) {
    uint i;
    l2->deep_copy(ref);
}

group1_t::group1_t() {
    uint i;
    l2 = new l2_t;
}

void group1_t::set_resetval() {
    uint i;
    l2->set_resetval();
}

group1_t::~group1_t() {
    uint i;
    delete l2;
}

void group1_t::deep_copy(group1_t *ref) {
    uint i;
    l2->deep_copy(ref->l2);
}

void group2_t::set_ipv4(ipv4_t *ref) {
    uint i;
    ipv4->deep_copy(ref);
}

void group2_t::set_udp(udp_t *ref) {
    uint i;
    udp->deep_copy(ref);
}

void group2_t::set_vxlan(vxlan_t *ref) {
    uint i;
    vxlan->deep_copy(ref);
}

group2_t::group2_t() {
    uint i;
    ipv4 = new ipv4_t;
    udp = new udp_t;
    vxlan = new vxlan_t;
}

void group2_t::set_resetval() {
    uint i;
    ipv4->set_resetval();
    udp->set_resetval();
    vxlan->set_resetval();
}

group2_t::~group2_t() {
    uint i;
    delete ipv4;
    delete udp;
    delete vxlan;
}

void group2_t::deep_copy(group2_t *ref) {
    uint i;
    ipv4->deep_copy(ref->ipv4);
    udp->deep_copy(ref->udp);
    vxlan->deep_copy(ref->vxlan);
}

void egr_pkt_t::set_group4(group2_t *ref) {
    uint i;
    group4->deep_copy(ref);
}

void egr_pkt_t::set_group2(group2_t *ref) {
    uint i;
    group2->deep_copy(ref);
}

void egr_pkt_t::set_group1(group1_t *ref) {
    uint i;
    group1->deep_copy(ref);
}

void egr_pkt_t::set_group3(group1_t *ref) {
    uint i;
    group3->deep_copy(ref);
}

egr_pkt_t::egr_pkt_t() {
    uint i;
    _match_id = 0;
    group4 = new group2_t;
    group2 = new group2_t;
    group1 = new group1_t;
    group3 = new group1_t;

    num_hdr = 8;
    hdr_ptr_array = (header_base_t **)(malloc(8 * sizeof(header_base_t *)));

}

egr_pkt_t::~egr_pkt_t() {
    delete group4;
    delete group2;
    delete group1;
    delete group3;
    free(hdr_ptr_array);
}

void egr_pkt_t::set_resetval() {
    group4->set_resetval();
    group2->set_resetval();
    group1->set_resetval();
    group3->set_resetval();
    num_hdr = 8;
    group1->l2->hdr_id = 0;
    hdr_ptr_array[0] = group1->l2;
    group2->ipv4->hdr_id = 1;
    hdr_ptr_array[1] = group2->ipv4;
    group2->udp->hdr_id = 2;
    hdr_ptr_array[2] = group2->udp;
    group2->vxlan->hdr_id = 3;
    hdr_ptr_array[3] = group2->vxlan;
    group3->l2->hdr_id = 4;
    hdr_ptr_array[4] = group3->l2;
    group4->ipv4->hdr_id = 5;
    hdr_ptr_array[5] = group4->ipv4;
    group4->udp->hdr_id = 6;
    hdr_ptr_array[6] = group4->udp;
    group4->vxlan->hdr_id = 7;
    hdr_ptr_array[7] = group4->vxlan;
}

void egr_pkt_t::deep_copy(egr_pkt_t *ref) {
    uint i;
    group4->deep_copy(ref->group4);
    group2->deep_copy(ref->group2);
    group1->deep_copy(ref->group1);
    group3->deep_copy(ref->group3);
}

void ing_pkt_t::set_group4(group2_t *ref) {
    uint i;
    group4->deep_copy(ref);
}

void ing_pkt_t::set_group2(group2_t *ref) {
    uint i;
    group2->deep_copy(ref);
}

void ing_pkt_t::set_group1(group1_t *ref) {
    uint i;
    group1->deep_copy(ref);
}

void ing_pkt_t::set_group3(group1_t *ref) {
    uint i;
    group3->deep_copy(ref);
}

ing_pkt_t::ing_pkt_t() {
    uint i;
    _match_id = 0;
    group4 = new group2_t;
    group2 = new group2_t;
    group1 = new group1_t;
    group3 = new group1_t;

    num_hdr = 8;
    hdr_ptr_array = (header_base_t **)(malloc(8 * sizeof(header_base_t *)));

}

ing_pkt_t::~ing_pkt_t() {
    delete group4;
    delete group2;
    delete group1;
    delete group3;
    free(hdr_ptr_array);
}

void ing_pkt_t::set_resetval() {
    group4->set_resetval();
    group2->set_resetval();
    group1->set_resetval();
    group3->set_resetval();
    num_hdr = 8;
    group1->l2->hdr_id = 8;
    hdr_ptr_array[0] = group1->l2;
    group2->ipv4->hdr_id = 9;
    hdr_ptr_array[1] = group2->ipv4;
    group2->udp->hdr_id = 10;
    hdr_ptr_array[2] = group2->udp;
    group2->vxlan->hdr_id = 11;
    hdr_ptr_array[3] = group2->vxlan;
    group3->l2->hdr_id = 12;
    hdr_ptr_array[4] = group3->l2;
    group4->ipv4->hdr_id = 13;
    hdr_ptr_array[5] = group4->ipv4;
    group4->udp->hdr_id = 14;
    hdr_ptr_array[6] = group4->udp;
    group4->vxlan->hdr_id = 15;
    hdr_ptr_array[7] = group4->vxlan;
}

void ing_pkt_t::deep_copy(ing_pkt_t *ref) {
    uint i;
    group4->deep_copy(ref->group4);
    group2->deep_copy(ref->group2);
    group1->deep_copy(ref->group1);
    group3->deep_copy(ref->group3);
}

