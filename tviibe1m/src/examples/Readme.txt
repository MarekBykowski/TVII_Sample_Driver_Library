
The examples are common across cores, and only application core example will be made available.
i.e., main_cm4.c only for lot of features.
In case if there is any dependency on CM0+ core, respective source (main_cm0plus.c) will be available.

How to convert main_cm4.c into main_cm0plus.c ?
1. Rename the file from main_cm0plus.c
2. Add the API "Cy_SysEnableApplCore" into the example source, sample is shown below
    SystemInit();
    __enable_irq();
    /* Enable CM4. CY_CORTEX_M4_APPL_ADDR is calculated in linker script, check it in case of problems. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR);
3. This will enable the application core and its respective power, otherwise not possible.

How do you use the example source ?
1. Copy the source file above into the src folder after renaming them as "main_cm0plus.c" or "main_cm4.c"
2. Open the respective workspace 
3. Rebuild, run or debug the sample