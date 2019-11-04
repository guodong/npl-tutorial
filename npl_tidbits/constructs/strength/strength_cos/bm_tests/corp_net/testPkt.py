
#####################################################################
#
# Purpose:
#   To generate traffic for 'strength' construct example.
#
# Steps:
#   (a). Send a packet with pri = 0, dscp = 0
#        Receive packet from BM and print hexdump
#   (b). Send a packet with pri = 3, dscp = 8
#        Receive packet from BM and print hexdump
#   (c). Send a packet with pri = 3, dscp = 40
#        Receive packet from BM and print hexdump
#
#####################################################################
from scapy.all import *
import os
import time
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



def get_tx_packet(test_num, pri, dscp):
    pkt = Ether()/Dot1Q()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[Dot1Q].vlan = vlan_id
    pkt[Dot1Q].prio = pri
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[IP].tos = dscp << 2
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf()
    #sending the first Packet
    port = [0]

    numpkts = 1
    for count  in range(numpkts):
        for i in port:
            # pri = 0, dscp = 0
            pri = 0
            dscp = 0
            pkt = get_tx_packet(i+1, pri, dscp)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])
            time.sleep(1)

            # pri = 3, dscp = 8
            pri = 3
            dscp = 8
            pkt = get_tx_packet(i+2, pri, dscp)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])
            time.sleep(1)

            # pri = 3, dscp = 40
            pri = 3
            dscp = 40
            pkt = get_tx_packet(i+3, pri, dscp)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

###########################################################################
# Example output with above test.
#
#{strength/strength_cos}$: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 00 01   ................
#0010   08 00 45 00 00 5A 00 01  00 00 40 06 7A 98 00 00   ..E..Z....@.z...
#0020   00 02 00 00 00 04 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 76 7A  00 00 54 68 69 73 20 70   ..P. .vz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  4C FA 07 55               om CLI tL..U
###################################
#TX PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 60 01   ..............`.
#0010   08 00 45 20 00 5A 00 01  00 00 40 06 7A 78 00 00   ..E .Z....@.zx..
#0020   00 02 00 00 00 04 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 75 7A  00 00 54 68 69 73 20 70   ..P. .uz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 32 20 66 72   ent by test 2 fr
#0060   6F 6D 20 43 4C 49 20 74  44 D0 8A A6               om CLI tD...
###################################
#TX PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 60 01   ..............`.
#0010   08 00 45 A0 00 5A 00 01  00 00 40 06 79 F8 00 00   ..E..Z....@.y...
#0020   00 02 00 00 00 04 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 74 7A  00 00 54 68 69 73 20 70   ..P. .tz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 33 20 66 72   ent by test 3 fr
#0060   6F 6D 20 43 4C 49 20 74  13 70 0E AE               om CLI t.p..

