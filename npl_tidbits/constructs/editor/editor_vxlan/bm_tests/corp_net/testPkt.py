
#####################################################################
#
# Purpose:
#   To generate traffic for 'editor' construct example.
#
# Steps:
#   (a). Send a non-VXLAN packet to port-0 of BM.
#        Receive packet from BM and print hexdump
#   (b). Send a VXLAN packet to port-0 of BM
#        Receive packet from BM and print hexdump
#
#####################################################################

from scapy.all import *
from scapy.contrib import vxlan
import os
import time
bm_rpc_lib = os.path.join(os.environ['NCS_ROOT'], 'bmi/cli')
sys.path.append(bm_rpc_lib)
from bm_rpc_intf import *

from datetime import datetime

#Pkt config
dst_mac = "00:00:00:00:01:10"
src_mac = "00:00:00:00:02:00"
dip = "10.10.10.1"
sip = "11.11.11.2"
ihl = 5
ip_len = 108
dataofs = 5
vlan_id = 1

# Normal IPv4 packet setup
def get_tx_packet(test_num):
    pkt = Ether()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

# VXLAN packet setup
def get_tx_vxlan_packet(test_num):
    pkt = Ether(dst="00:00:00:00:00:bb", src="00:00:00:00:00:aa")/IP(src="1.1.1.1", dst="2.2.2.2")/UDP()/VXLAN(vni=0xf)/Ether(dst=dst_mac, src=src_mac)/IP(src=sip, dst=dip)/Raw()
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':

    # load vxlan variable
    for k,v in vxlan.__dict__.iteritems():
        globals()[k] = v

    bmintf = BMRpcIntf()
    #sending the first Packet
    port = [0]

    numpkts = 1
    for count  in range(numpkts):
        for i in port:
            # Sending a non-VXLAN packet
            pkt = get_tx_packet(i+1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX non-VXLAN PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

            time.sleep(1)
            # Sending a VXLAN packet
            pkt = get_tx_vxlan_packet(i+2)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX VXLAN PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

###########################################################################
# Example output with above test.
#
#{editor/editor_vxlan}$: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX non-VXLAN PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 00 BB 00 00  00 00 00 AA 08 00 45 00   ..............E.
#0010   00 88 00 00 00 00 40 11  74 60 01 01 01 01 02 02   ......@.t`......
#0020   02 02 12 34 12 B5 00 6C  00 00 FF 00 00 00 00 00   ...4...l........
#0030   0F 00 00 00 00 00 01 10  00 00 00 00 02 00 08 00   ................
#0040   45 00 00 5A 00 01 00 00  40 06 50 86 0B 0B 0B 02   E..Z....@.P.....
#0050   0A 0A 0A 01 00 14 00 50  00 00 00 00 00 00 00 00   .......P........
#0060   50 02 20 00 4C 68 00 00  54 68 69 73 20 70 61 63   P. .Lh..This pac
#0070   6B 65 74 20 69 73 20 62  65 69 6E 67 20 73 65 6E   ket is being sen
#0080   74 20 62 79 20 74 65 73  74 20 31 20 66 72 6F 6D   t by test 1 from
#0090   20 43 4C 49 20 74 E7 C6  6A 54                      CLI t..jT
###################################
#TX VXLAN PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#0010   00 46 00 01 00 00 40 00  50 A0 0B 0B 0B 02 0A 0A   .F....@.P.......
#0020   0A 01 54 68 69 73 20 70  61 63 6B 65 74 20 69 73   ..This packet is
#0030   20 62 65 69 6E 67 20 73  65 6E 74 20 62 79 20 74    being sent by t
#0040   65 73 74 20 31 20 66 72  6F 6D 20 43 4C 49 20 74   est 1 from CLI t
#0050   24 6E B5 CD                                        $n..

