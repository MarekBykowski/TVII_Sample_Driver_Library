/******* Connection Steps for the CXPI Polling method NRZ_Master mode **********/


For CTYVII-C-2D-6M-A0-CPU Board
--------------------------------------------------------------------------------
1. Use a TVII-Baseboard with a 1M CPU board, power it up
2. Follow the connections mentioned in the below table.

| Sl.No | 500-BGA CPU Board-Pins | TVII-BB-Pins |
|-------|------------------------|--------------|
|	1   | JP25.2	             | J12.2(CLK)   |
|	2   | JP25.6	             | J11.1(TxD)   |
|	3   | JP25.14	             | J14.1(RxD)   |
|   4   | JP25.16                | J13.2(NSLP)  |
|   5   | P8.9                   | J9.2(SELMS)  |
--------|------------------------|--------------|

3. Connect the ground of the 500-BGA CPU board's to the TVII-BB (BaseBoard) ground.
4. Power the 500-BGA CPU board and flash the CXPI NRZ_Master code.
5. Connect the Pin #7 of P1 DB connector in the TVII-BB to the BUS of external slave/analyzer.
6. Example is based on the polling method it continuously pType is sent in the bus and the slave responds with a CXPI frame if it has anything to send.
7. Also the example send the PID and the salve responds with a response to the PID and also it send the PID with response to the slave.

CXPI Interface used: PRISM CXPI Analyzer (Multi Protocol Simulator, MLT PX-10 Navigator)


For CTYVII-C-2D-6M-B0-CPU Board
--------------------------------------------------------------------------------
1. Short jumpers J84(1-2), J88(1-2), J75(1-2).
2. Please make sure J28(9-10), J28(11-12), J28(13-14), J28(15-16) is closed.

Only waveform observed on the CXPI Bus, clock and data verified.
