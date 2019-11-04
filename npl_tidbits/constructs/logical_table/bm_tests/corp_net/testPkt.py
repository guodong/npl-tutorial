
#####################################################################
#
# Purpose:
#   To generate traffic for 'logical table' construct example.
#
# Steps:
# (a). Send vlan-2 packet to port-0 of BM.
#      Receive packet from BM and print hexdump.
# (b). Send vlan-3 packet to port-0 of BM.
#      Receive packet from BM and print hexdump.
#
#####################################################################

from scapy.all import *
import os
bm_rpc_lib = os.path.join(os.environ['NCS_ROOT'], 'bmi/cli')
sys.path.append(bm_rpc_lib)
from bm_rpc_intf import *

from datetime import datetime

#Pkt config
dst_mac = "00:00:00:00:01:10"
src_mac = "00:00:00:00:02:00"
dip = "0.0.0.4"
sip = "0.0.0.2"
ihl = 5
ip_len = 108
dataofs = 5
vlan_id = 1

def get_tx_packet(test_num):
    pkt = Ether()/Dot1Q()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[Dot1Q].vlan = vlan_id
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf()
    port = [0]
    numpkts = 1

    # send vlan-2 packet.
    vlan_id = 2
    for count  in range(numpkts):
        for i in port:
            pkt = get_tx_packet(i+1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

    # send vlan-3 packet.
    vlan_id = 3
    for count  in range(numpkts):
        for i in port:
            pkt = get_tx_packet(i+1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

#
# Example output with above test.
#
#{logical_table}$: python bm_tests/corp_net/testPkt.py
#'Connected to Switch'
###################################
#TX PKT on port 0:
#RX PKT on port 2:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 00 02   ................
#0010   08 00 45 00 00 5A 00 01  00 00 40 06 7A 98 00 00   ..E..Z....@.z...
#0020   00 02 00 00 00 04 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 76 7A  00 00 54 68 69 73 20 70   ..P. .vz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  D4 4C 43 F9               om CLI t.LC.
##################################
#TX PKT on port 0:
#RX PKT on port 3:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 00 03   ................
#0010   08 00 45 00 00 5A 00 01  00 00 40 06 7A 98 00 00   ..E..Z....@.z...
#0020   00 02 00 00 00 04 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 76 7A  00 00 54 68 69 73 20 70   ..P. .vz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  5C 21 7F 9D               om CLI t\!..
#
