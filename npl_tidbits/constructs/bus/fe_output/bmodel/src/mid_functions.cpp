/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__ingress_pkt__l2_hdr__inner_tag() {
    if (ingress_pkt->l2_hdr->inner_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l2_hdr__l2() {
    if (ingress_pkt->l2_hdr->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l3_hdr() {
    if (ingress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
}

void _BModel::update_mid__ingress_pkt() {
    if (ingress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
    if (ingress_pkt->l2_hdr->inner_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->l2_hdr->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
    if (ingress_pkt->l2_hdr->outer_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l3_hdr__ipv4() {
    if (ingress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l2_hdr__outer_tag() {
    if (ingress_pkt->l2_hdr->outer_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l2_hdr() {
    if (ingress_pkt->l2_hdr->inner_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->l2_hdr->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
    if (ingress_pkt->l2_hdr->outer_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

