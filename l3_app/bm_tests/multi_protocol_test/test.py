"""
nplsim test script
"""

from scapy.all import Ether, Dot1Q, IP, IPv6, TCP, Raw, hexdump

import os
import sys

BATCH_TEST_DIR = os.path.join(os.path.dirname(__file__), os.environ['NCS_ROOT'] + '/bmi/cli/bti')
sys.path.append(BATCH_TEST_DIR)
from batch_test_base import BatchTestBase, socket_port_get, reg_file_get

CFG_FILE = 'bm_tests/multi_protocol_test/tbl_cfg.txt'


#Pkt config
dst_mac = "00:00:00:00:01:10"
src_mac = "00:00:00:00:02:00"
vlan_id = 1

#V4 Packet Properties
ipv4_dip = "0.0.0.4"
ipv4_sip = "0.0.0.2"
ihl = 5
ip_len = 108
dataofs = 5

#V6 Packet Properties
ipv6_dip = "0:0:0:0::5"
ipv6_sip = "0:0:0:0:0::2"

#v4 Tunnel encapped Packet
encap_sip = "0x300"
encap_dip ="0x500"
inner_ipv4_dip = "0.0.0.6"
inner_ipv4_sip = "0.0.0.8"

def get_tx_ipv4_packet(test_num):
    pkt = Ether()/Dot1Q()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[Dot1Q].vlan = vlan_id
    pkt[IP].dst = ipv4_dip
    pkt[IP].src = ipv4_sip 
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

def get_tx_ipv6_packet(test_num):
    pkt = Ether()/Dot1Q()/IPv6()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[Dot1Q].vlan = vlan_id
    pkt[IPv6].dst = ipv6_dip
    pkt[IPv6].src = ipv6_sip 
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

def get_tx_ipv4tunnel_packet(test_num):
    pkt = Ether()/Dot1Q()/IP(src=encap_sip, dst=encap_dip)/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[Dot1Q].vlan = vlan_id
    pkt[IP][1].dst = inner_ipv4_dip
    pkt[IP][1].src = inner_ipv4_sip
    pkt[IP][1].ihl = ihl	
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

class Test(object):
    """ test class
        connect to nplsim, run test, disconnect from nplsim
    """
    bt_if = None
    connected = False
    batch_mode = True

    def __init__(self, batch_mode, host, sport, reg_file, cfg_file):
        self.batch_mode = batch_mode
        self.bt_if = BatchTestBase()

        self.connected = self.bt_if.connect(host, sport, reg_file)

        if self.batch_mode:
            # if batch_mode then then load config file
            stat = self.bt_if.configure(cfg_file)

            (stat, data) = self.bt_if.process_txt_cmd('debug_level 4')
    

    def run(self):
        """ run test
        """
        # port list to send packets
        port = [0, 2, 4]

        # number of packets to send
        numpkts = 1

        for count in range(numpkts):

            for i in port:

                # get packet
                if (i == 0):
                    pkt = get_tx_ipv4_packet(i+1)
                elif (i == 2):
                    pkt = get_tx_ipv6_packet(i+1)
                elif (i == 4):
                    pkt = get_tx_ipv4tunnel_packet(i+1)

                print "##################################"
                print "TX PKT num {} on port {}:".format(count, i)
                hexdump(pkt)

                # transmit packet
                recv_pkts = self.bt_if.send_pkt(i, pkt, len(str(pkt)))

                for rx_pkt in recv_pkts:
                    # check tx status
                    if rx_pkt['STATUS'] < 0:
                        print "TX ERROR"
                        continue

                    # check receive packet status
                    if rx_pkt['STATUS']:
                        print "Packet is Dropped!"
                        continue

                    print "RX PKT on port {}:".format(rx_pkt['PORT'])
                    hexdump(rx_pkt['PACKET'])


    def exit(self):
        """ disconnect from nplsim
        """
        if self.batch_mode:
            # if batch_mode then close nplsim,
            self.bt_if.exit()


if __name__ == '__main__':
    """ test.py -port <socket port num> -fe <output dir>
        if -fe is specified then running in batch_mode:
            configure nplsim tables
            terminate nplsim process
    """
    # get socket port
    socket_port = socket_port_get(sys.argv)

    # get register file
    reg_file = reg_file_get(sys.argv)
    batch_mode = True
    if reg_file == None:
        batch_mode = False

    # connect to nplsim
    test_if = Test(batch_mode, 'localhost', socket_port, reg_file, CFG_FILE)

    # run tests
    test_if.run()

    # close nplsim
    test_if.exit()
         
