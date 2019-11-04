/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "header_classes.h"
#include "bmodel.h"

tcp_t::tcp_t() {
    src_port = (_16bits)(0x0U);
    dst_port = (_16bits)(0x0U);
    sn = (_32bits)(0x0U);
    ack = (_32bits)(0x0U);
    hdr_len = (_4bits)(0x0U);
    reserved = (_3bits)(0x0U);
    flags_ecn = (_3bits)(0x0U);
    flags_urg = (_1bit)(0x0U);
    flags_ack = (_1bit)(0x0U);
    flags_psh = (_1bit)(0x0U);
    flags_rst = (_1bit)(0x0U);
    flags_syn = (_1bit)(0x0U);
    flags_fin = (_1bit)(0x0U);
    win_size = (_16bits)(0x0U);
    checksum = (_16bits)(0x0U);
    urgent_ptr = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 20;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

tcp_t::~tcp_t() {
    delete[] hdr_bytes;
}

void tcp_t::set_resetval() {
    uint i;

    reset_header_base_class();
    src_port = (_16bits)(0x0U);
    dst_port = (_16bits)(0x0U);
    sn = (_32bits)(0x0U);
    ack = (_32bits)(0x0U);
    hdr_len = (_4bits)(0x0U);
    reserved = (_3bits)(0x0U);
    flags_ecn = (_3bits)(0x0U);
    flags_urg = (_1bit)(0x0U);
    flags_ack = (_1bit)(0x0U);
    flags_psh = (_1bit)(0x0U);
    flags_rst = (_1bit)(0x0U);
    flags_syn = (_1bit)(0x0U);
    flags_fin = (_1bit)(0x0U);
    win_size = (_16bits)(0x0U);
    checksum = (_16bits)(0x0U);
    urgent_ptr = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 20;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int tcp_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+20)) {
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
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            sn |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (4 - i - 1))));
        } else {
            sn |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 8;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            ack |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (4 - i - 1))));
        } else {
            ack |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 12;
    hdr_len = (_4bits)((pkt[*hdr_ptr + byte_ptr] >> 4) & 0xf);

    byte_ptr = 12;
    reserved = (_3bits)((pkt[*hdr_ptr + byte_ptr] >> 1) & 0x7);

    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            flags_ecn |= (((_3bits)(pkt[*hdr_ptr + byte_ptr + i]) << ((8 * (2 - i - 1)) - 6)));
        } else {
            flags_ecn |= (((_3bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 6));
        }
    }

    byte_ptr = 13;
    flags_urg = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 5) & 0x1);

    byte_ptr = 13;
    flags_ack = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 4) & 0x1);

    byte_ptr = 13;
    flags_psh = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 3) & 0x1);

    byte_ptr = 13;
    flags_rst = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 2) & 0x1);

    byte_ptr = 13;
    flags_syn = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 1) & 0x1);

    byte_ptr = 13;
    flags_fin = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0x1);

    byte_ptr = 14;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            win_size |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            win_size |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 16;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 18;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            urgent_ptr |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            urgent_ptr |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void tcp_t::pack() {
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
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sn) >> (8 * (4 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sn) << 0));
        }
    }
    byte_ptr = 8;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ack) >> (8 * (4 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ack) << 0));
        }
    }
    byte_ptr = 12;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(hdr_len)) << 4) & (_8bits)(0xf0U));
    byte_ptr = 12;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(reserved)) << 1) & (_8bits)(0xeU));
    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((flags_ecn) >> ((8 * (2 - i - 1)) - 6)));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((flags_ecn) << 6));
        }
    }
    byte_ptr = 13;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags_urg)) << 5) & (_8bits)(0x20U));
    byte_ptr = 13;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags_ack)) << 4) & (_8bits)(0x10U));
    byte_ptr = 13;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags_psh)) << 3) & (_8bits)(0x8U));
    byte_ptr = 13;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags_rst)) << 2) & (_8bits)(0x4U));
    byte_ptr = 13;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags_syn)) << 1) & (_8bits)(0x2U));
    byte_ptr = 13;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags_fin)) << 0) & (_8bits)(0x1U));
    byte_ptr = 14;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((win_size) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((win_size) << 0));
        }
    }
    byte_ptr = 16;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((checksum) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((checksum) << 0));
        }
    }
    byte_ptr = 18;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((urgent_ptr) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((urgent_ptr) << 0));
        }
    }
    update_header_location();

}

void tcp_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("tcp_t->src_port = 0x" + src_port.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->sn = 0x" + sn.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->ack = 0x" + ack.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->hdr_len = 0x" + hdr_len.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->reserved = 0x" + reserved.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->flags_ecn = 0x" + flags_ecn.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->flags_urg = 0x" + flags_urg.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->flags_ack = 0x" + flags_ack.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->flags_psh = 0x" + flags_psh.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->flags_rst = 0x" + flags_rst.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->flags_syn = 0x" + flags_syn.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->flags_fin = 0x" + flags_fin.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->win_size = 0x" + win_size.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->checksum = 0x" + checksum.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->urgent_ptr = 0x" + urgent_ptr.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("tcp_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void tcp_t::deep_copy(tcp_t *ref) {
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
    sn = ref->sn;
    ack = ref->ack;
    hdr_len = ref->hdr_len;
    reserved = ref->reserved;
    flags_ecn = ref->flags_ecn;
    flags_urg = ref->flags_urg;
    flags_ack = ref->flags_ack;
    flags_psh = ref->flags_psh;
    flags_rst = ref->flags_rst;
    flags_syn = ref->flags_syn;
    flags_fin = ref->flags_fin;
    win_size = ref->win_size;
    checksum = ref->checksum;
    urgent_ptr = ref->urgent_ptr;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

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

void group2_t::set_tcp(tcp_t *ref) {
    uint i;
    tcp->deep_copy(ref);
}

group2_t::group2_t() {
    uint i;
    ipv4 = new ipv4_t;
    udp = new udp_t;
    tcp = new tcp_t;
}

void group2_t::set_resetval() {
    uint i;
    ipv4->set_resetval();
    udp->set_resetval();
    tcp->set_resetval();
}

group2_t::~group2_t() {
    uint i;
    delete ipv4;
    delete udp;
    delete tcp;
}

void group2_t::deep_copy(group2_t *ref) {
    uint i;
    ipv4->deep_copy(ref->ipv4);
    udp->deep_copy(ref->udp);
    tcp->deep_copy(ref->tcp);
}

void ing_pkt_t::set_group2(group2_t *ref) {
    uint i;
    group2->deep_copy(ref);
}

void ing_pkt_t::set_group1(group1_t *ref) {
    uint i;
    group1->deep_copy(ref);
}

ing_pkt_t::ing_pkt_t() {
    uint i;
    _match_id = 0;
    group2 = new group2_t;
    group1 = new group1_t;

    num_hdr = 4;
    hdr_ptr_array = (header_base_t **)(malloc(4 * sizeof(header_base_t *)));

}

ing_pkt_t::~ing_pkt_t() {
    delete group2;
    delete group1;
    free(hdr_ptr_array);
}

void ing_pkt_t::set_resetval() {
    group2->set_resetval();
    group1->set_resetval();
    num_hdr = 4;
    group1->l2->hdr_id = 0;
    hdr_ptr_array[0] = group1->l2;
    group2->ipv4->hdr_id = 1;
    hdr_ptr_array[1] = group2->ipv4;
    group2->udp->hdr_id = 2;
    hdr_ptr_array[2] = group2->udp;
    group2->tcp->hdr_id = 3;
    hdr_ptr_array[3] = group2->tcp;
}

void ing_pkt_t::deep_copy(ing_pkt_t *ref) {
    uint i;
    group2->deep_copy(ref->group2);
    group1->deep_copy(ref->group1);
}

