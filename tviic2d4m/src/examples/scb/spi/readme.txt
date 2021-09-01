
In case of silicon on TVII-C CPU board, some of the configured SPI signals are on the same pin like some LED signals.
So please ensure that the cores where the example is not running on, does not use these LED signals.

Pin Assignment For TV-2D-C-4M revA 216pin MCU with 4M-216-CPU-REVA

SCB Signal / CPU_BOARD pin
MISO       / J55_7
MOSI       / J47_2
CLK        / J43_2
SS         / R678_1 // Slave Select 3 is used

