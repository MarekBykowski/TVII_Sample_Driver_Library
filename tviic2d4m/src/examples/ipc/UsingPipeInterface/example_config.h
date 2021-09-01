#ifndef EXAMPLE_CONFIG_H
#define EXAMPLE_CONFIG_H


#define EP_INDEX_CM0P    0
#define EP_INDEX_CM7_0   1

#if (CY_CPU_CORTEX_M0P)
    #define EP_INDEX_THIS_CPU      EP_INDEX_CM0P
    #define EP_INDEX_OTHER_CPU     EP_INDEX_CM7_0
#else
    #define EP_INDEX_THIS_CPU      EP_INDEX_CM7_0
    #define EP_INDEX_OTHER_CPU     EP_INDEX_CM0P
#endif

#endif // EXAMPLE_CONFIG_H

