/******* Connection Steps for the CXPI Polling method NRZ_Master mode **********/

1. Use a TVII-Baseboard with a 1M CPU board, power it up
2. Follow the connections mentioned in the below table.

| Sl.No | 216-TQFP CPU Board-Pins | TVII-BB-Pins |
|-------|-------------------------|--------------|
|	1   | J107_2	              | J12.2(CLK)   |
|	2   | J112_2	              | J11.1(TxD)   |
|	3   | J25_4		              | J14.1(RxD)   |
|   4   | J25_2		              | J13.2(NSLP)  |
|   5   | R123_2                  | J9.2(SELMS)  |
--------|-------------------------|--------------|

3. Connect the ground of the 216-TQFP CPU board's to the TVII-BB (BaseBoard) ground.
4. Power the 216-TQFP CPU board and flash the CXPI NRZ_Master code.
5. Connect the Pin #7 of P1 DB connector in the TVII-BB to the BUS of external slave/analyzer.
6. Example is based on the polling method it continuously pType is sent in the bus and the slave responds with a CXPI frame if it has anything to send.
7. Also the example send the PID and the salve responds with a response to the PID and also it send the PID with response to the slave.

CXPI Interface used: PRISM CXPI Analyzer (Multi Protocol Simulator, MLT PX-10 Navigator)
