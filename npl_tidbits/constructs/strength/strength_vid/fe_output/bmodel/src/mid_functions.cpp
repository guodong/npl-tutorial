/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__ingress_pkt__group1() {
    if (ingress_pkt->group1->llc->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 3) = 2;
    }
    if (ingress_pkt->group1->snap_or_llc->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->group1->snap->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 3) = 1;
    }
    if (ingress_pkt->group1->vlan_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group1__llc() {
    if (ingress_pkt->group1->llc->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 3) = 2;
    }
}

void _BModel::update_mid__ingress_pkt() {
    if (ingress_pkt->group1->llc->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 3) = 2;
    }
    if (ingress_pkt->group1->snap_or_llc->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->group1->snap->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 3) = 1;
    }
    if (ingress_pkt->group1->vlan_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group1__snap_or_llc() {
    if (ingress_pkt->group1->snap_or_llc->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group1__snap() {
    if (ingress_pkt->group1->snap->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 3) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group1__l2() {
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group1__vlan_tag() {
    if (ingress_pkt->group1->vlan_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

