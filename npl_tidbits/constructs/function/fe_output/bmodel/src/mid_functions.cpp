/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__ingress_pkt__group1() {
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group2__tcp() {
    if (ingress_pkt->group2->tcp->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 2) = 2;
    }
}

void _BModel::update_mid__ingress_pkt__group2() {
    if (ingress_pkt->group2->tcp->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 2) = 2;
    }
    if (ingress_pkt->group2->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->group2->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt() {
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
    if (ingress_pkt->group2->tcp->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 2) = 2;
    }
    if (ingress_pkt->group2->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->group2->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group2__ipv4() {
    if (ingress_pkt->group2->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group2__udp() {
    if (ingress_pkt->group2->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group1__l2() {
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

