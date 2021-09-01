
#import logging
import time
import ConfigParser
#import crcmod

from PCANBasic import *        ## PCAN-Basic library import

#crc32_func= crcmod.mkCrcFun(0x104c11db7, initCrc=0, xorOut=0xFFFFFFFF)
#crc16_func = crcmod.mkCrcFun(0x11021, 0xffff, False, 0x0000)

# Activate the Config parser
config = ConfigParser.RawConfigParser()
config.read('test_config.cfg')

#logging.basicConfig(filename='PCAN_Logger.txt', level=logging.DEBUG)
today = time.asctime( time.localtime(time.time()) )
print today

#logging.info('--------------------------------------------------')
#logging.info('CAN FD Information Logger: %s', today)
#logging.info('--------------------------------------------------')

# make :1 for logging output
LOG_status=1;
if LOG_status==1:
    print "Log of Data -Active"
else:
    print "Log of Data -NOT Active"

# Read config data from the file
f_clock_mhz = config.getint('Section1', 'f_clock_mhz')
nom_brp = config.getint('Section1', 'nom_brp')
nom_tseg1 = config.getint('Section1', 'nom_tseg1')
nom_tseg2 = config.getint('Section1', 'nom_tseg2')
nom_sjw = config.getint('Section1', 'nom_sjw')
data_brp = config.getint('Section1', 'data_brp')
data_tseg1 = config.getint('Section1', 'data_tseg1')
data_tseg2 = config.getint('Section1', 'data_tseg2')
data_sjw = config.getint('Section1', 'data_sjw')

# Update the bitrate variable for initialization
bitrate = "f_clock_mhz=" + str(f_clock_mhz)
bitrate += ", nom_brp=" + str(nom_brp)
bitrate += ", nom_tseg1=" + str(nom_tseg1)
bitrate += ", nom_tseg2=" + str(nom_tseg2)
bitrate += ", nom_sjw=" + str(nom_sjw)
bitrate += ", data_brp=" + str(data_brp)
bitrate += ", data_tseg1=" + str(data_tseg1)
bitrate += ", data_tseg2=" + str(data_tseg2)
bitrate += ", data_sjw=" + str(data_sjw)
print bitrate
#logging.info( 'bitrate: %s', bitrate )

# The FD capable Channel (PCAN-USB Pro FD) is initialized
objPCAN = PCANBasic()
result = objPCAN.InitializeFD(PCAN_USBBUS1, bitrate)

if result != PCAN_ERROR_OK:
    # An error occurred, get a text describing the error and show it
    result = objPCAN.GetErrorText(result)
    print result[1]
    #logging.warning('CANFD Initialization error: %s', result[1])
else:
    print "PCAN-USB Pro FD (Ch-1) was initialized"
    #logging.info( 'PCAN-USB Pro FD (Ch-1) was initialized' )

# Check the status of the USB Channel
result = objPCAN.GetStatus(PCAN_USBBUS1)
if result == PCAN_ERROR_BUSLIGHT:
    print("PCAN-USB (Ch-x): Handling a BUS-LIGHT status...")
    #logging.warning( 'PCAN-USB (Ch-x): Handling a BUS-LIGHT status...' )
elif result == PCAN_ERROR_BUSHEAVY:
    print("PCAN-USB (Ch-x): Handling a BUS-HEAVY status...")
    #logging.warning( 'PCAN-USB (Ch-x): Handling a BUS-HEAVY status...' )
elif result == PCAN_ERROR_BUSOFF:
    print("PCAN-USB (Ch-x): Handling a BUS-OFF status...")
    #logging.warning( 'PCAN-USB (Ch-x): Handling a BUS-OFF status...' )
elif result == PCAN_ERROR_OK:
    print("PCAN_USB (Ch-x): Status is OK")
    #logging.info( 'PCAN_USB (Ch-x): Status is OK' )
else:
    # An error occured, get a text describing the error and show it
    result = objPCAN.GetErrorText(result)
    print(result[1])
    #logging.warning( 'CANFD Status Error: %s', result[1] )

# Set Message Filter
#filter_start = config.getint('Section2', 'filter_start')
#filter_end = config.getint('Section2', 'filter_end')
#print ("filter_start: 0x%x filter_end: 0x%x" % (filter_start, filter_end))
#logging.info( 'filter_start: 0x%x filter_end: 0x%x', filter_start, filter_end )

#result = objPCAN.FilterMessages(PCAN_USBBUS1, filter_start, filter_end, PCAN_MESSAGE_STANDARD)
#if result != PCAN_ERROR_OK:
#    result = objPCAN.GetErrorText(result)
#    print(result[1])
#    logging.warning( 'CANFD Filter Addition Error: %s', result[1] )
#else:
#    print("Message Filter Applied Successfully")
#    logging.info( 'Message Filter Applied Successfully' )

# get iterations and the CAN ID to transmit
iterations = config.getint('Section3', 'iterations')
can_id = config.getint('Section3', 'can_id')
print ("iterations: %d can_id: 0x%x" % (iterations, can_id))
#if LOG_status == 1:
#    logging.info( 'iterations: %d can_id: 0x%x', iterations, can_id )

iter=0
Error_Flag=0
while(iter < iterations):
    Rec_CRC32 = ''
    # A CAN message is configured
    msg = TPCANMsgFD()
    msg.ID = can_id
    msg.MSGTYPE = PCAN_MESSAGE_STANDARD.value | PCAN_MESSAGE_FD.value
    #print "TX MSGTYPE = %x" % msg.MSGTYPE
    
    # DLC 9 means 12 data bytes
    msg.DLC = 9
    for i in range(12):
        msg.DATA[i] = i
    
    #  The message is sent using the PCAN-USB Channel 1
    result = objPCAN.WriteFD(PCAN_USBBUS1,msg)
    if result != PCAN_ERROR_OK:
        # An error occurred, get a text describing the error and show it
        result = objPCAN.GetErrorText(result)
        print result
        Error_Flag=Error_Flag+1
        if LOG_status == 1:
            print "CANFD Message sent Error"
            #logging.warning( 'CANFD Write Error: %s', result )
    else:
        if LOG_status == 1:
            print "Message sent successfully"
            #logging.info( 'Message sent successfully' )
    
    readResult = PCAN_ERROR_OK,
    while(readResult[0] & PCAN_ERROR_QRCVEMPTY) != PCAN_ERROR_QRCVEMPTY:
        # Check the receive queue for new messages
        readResult = objPCAN.ReadFD(PCAN_USBBUS1)
        if readResult[0] != PCAN_ERROR_QRCVEMPTY:
            # Process the received message
            #if LOG_status == 1:
            #print "A message was received"
            today = time.asctime( time.localtime(time.time()) )
            #logging.info( 'A CANFD message was received: %s', today )
            msg = readResult[1]
            checkdata = ", " . join("%02x" % b for b in msg.DATA)

            print( 'Received Msg: ID: %x Msg Type: %x, DLC: %d', msg.ID, msg.MSGTYPE, msg.DLC )
            print "ID = 0x%x" % msg.ID, "RX MSGTYPE = %x" % msg.MSGTYPE, "DLC = %d" % msg.DLC
            #if LOG_status == 1:
                #logging.info( 'Received Msg: ID: %x Msg Type: %x, DLC: %d', msg.ID, msg.MSGTYPE, msg.DLC )
            #print( ", " . join("%02x" % b for b in msg.DATA))               

        else:
            # An error occurred, get a text describing the error and show it
            result = objPCAN.GetErrorText(readResult[0])
            #print result[1]
            #HandleReadError(readResult[0]) # Possible errors handling function, HandleError(function_result)

    iter = iter + 1
    print "Iteration Number", iter
        
    time.sleep(1)
    if Error_Flag<1000:
        print "Total Error ",Error_Flag,"Iteration Number", iter
        #logging.info("*%s,Total Error:%d Iteration No %d", str(today),Error_Flag,iter)
    else:
        print "Error OverFlow Logging Stopped", Error_Flag
        #Error_Flag = Error_Flag + 1
        #LOG_status = 0;
    if Error_Flag > 999:
        if LOG_status == 1:
            #logging.error("*Error Log Stopped*%s,Total Error:%d Iteration No %d", str(today), Error_Flag,iter)
            LOG_status=0;


# All initialized channels are released
objPCAN.Uninitialize(PCAN_NONEBUS)



