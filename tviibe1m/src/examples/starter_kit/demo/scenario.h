#ifndef SCENARIO_H
#define SCENARIO_H

#include <stdint.h>

typedef void (*BeginningLoutine)(void);
typedef void (*CyclicLoutine)(void);
typedef void (*EndingLoutine)(void);

typedef struct
{
    BeginningLoutine beginLoutine;
    CyclicLoutine    cyclicLoutine;
    EndingLoutine    endLoutine;
} stc_scenario;

void ScenarioInit(uint32_t initialMode, uint32_t numOfMode);
void ScenarioMain(stc_scenario* scenario);
void SetNextMode(uint32_t ModeNo);
uint32_t GetCurrentMode(void);
#endif
