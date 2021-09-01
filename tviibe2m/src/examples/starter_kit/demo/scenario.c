#include "scenario.h"

static uint32_t g_previousMode;
static uint32_t g_currentMode;
static uint32_t g_nextMode;
static uint32_t g_modeMax;

void ScenarioInit(uint32_t initialMode, uint32_t numOfMode)
{
    g_previousMode = 0xFFFFFFFF;
    g_currentMode  = initialMode;
    g_nextMode     = initialMode;
    g_modeMax      = numOfMode;
    return;
}

void ScenarioMain(stc_scenario* scenario)
{
    // 1. check if current mode is not bigger than max mode number.
    if(g_currentMode > g_modeMax)
    {
        g_currentMode = g_modeMax;
    }

    // 2. Execute the beginning function. if the mode has been changed.
    if(g_currentMode != g_previousMode)
    {
        scenario[g_currentMode].beginLoutine();
        g_previousMode = g_currentMode;
    }

    // 3. Execute the main (cyclic) function
    scenario[g_currentMode].cyclicLoutine();

    // 4. Execute the ending function, if the mode has been changed.
    // Note!!: to make it roubust, here need to disable interrupt.
    if(g_nextMode != g_currentMode)
    {
        scenario[g_currentMode].endLoutine();
        g_currentMode = g_nextMode;
        // Note!!: to make it roubust, here need to enable interrupt.
    }

    return;
}

void SetNextMode(uint32_t ModeNo)
{
    g_nextMode = ModeNo;
    return;
}

uint32_t GetCurrentMode(void)
{
    return(g_currentMode);
}

