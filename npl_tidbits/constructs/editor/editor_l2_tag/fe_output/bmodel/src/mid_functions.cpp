/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__ingress_pkt__grp__inner_tag() {
    if (ingress_pkt->grp->inner_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__egress_pkt__grp__inner_tag() {
    if (egress_pkt->grp->inner_tag->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__egress_pkt() {
    if (egress_pkt->grp->inner_tag->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
    if (egress_pkt->grp->outer_tag->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
    if (egress_pkt->grp->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt() {
    if (ingress_pkt->grp->inner_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->grp->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
    if (ingress_pkt->grp->outer_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__egress_pkt__grp() {
    if (egress_pkt->grp->inner_tag->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
    if (egress_pkt->grp->outer_tag->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
    if (egress_pkt->grp->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__grp() {
    if (ingress_pkt->grp->inner_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->grp->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
    if (ingress_pkt->grp->outer_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__egress_pkt__grp__l2() {
    if (egress_pkt->grp->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__grp__l2() {
    if (ingress_pkt->grp->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__egress_pkt__grp__outer_tag() {
    if (egress_pkt->grp->outer_tag->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__grp__outer_tag() {
    if (ingress_pkt->grp->outer_tag->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

