
#####################################################################
#
# Purpose:
#   To generate traffic for 'packet drop' construct example.
#
# Steps:
#   (a). Send a UC packet to port-0 of BM.
#        Receive packet from BM and print hexdump
#   (b). Send a MC packet to port-0 of BM
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
vlan_id = 1



def get_tx_packet(test_num):
    pkt = Ether()/Dot1Q()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[Dot1Q].vlan = vlan_id
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf()
    #sending the first Packet
    port = [0]

    numpkts = 1
    for count  in range(numpkts):
        for i in port:
            # Sending UC packet
            pkt = get_tx_packet(i+1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX UC PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

            time.sleep(1)
            # Sending MC packet
            dst_mac = "01:00:00:00:01:10"
            pkt = get_tx_packet(i+1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX MC PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

###########################################################################
# Example output with above test.
#
#{packet_drop}$: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX UC PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 00 01   ................
#0010   00 00 54 68 69 73 20 70  61 63 6B 65 74 20 69 73   ..This packet is
#0020   20 62 65 69 6E 67 20 73  65 6E 74 20 62 79 20 74    being sent by t
#0030   65 73 74 20 31 20 66 72  6F 6D 20 43 4C 49 20 74   est 1 from CLI t
#0040   67 6D 5B FA                                        gm[.
###################################
#TX MC PKT on port 0:
#RX PKT on port 1:
#0000   01 00 00 00 01 10 00 00  00 00 02 00 81 00 00 01   ................
#0010   00 00 54 68 69 73 20 70  61 63 6B 65 74 20 69 73   ..This packet is
#0020   20 62 65 69 6E 67 20 73  65 6E 74 20 62 79 20 74    being sent by t
#0030   65 73 74 20 31 20 66 72  6F 6D 20 43 4C 49 20 74   est 1 from CLI t
#0040   F2 40 6E 75                                        .@nu

