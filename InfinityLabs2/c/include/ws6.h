#ifndef __WS6_H__
#define __WS6_H__

typedef void (*FUNCPTR)();

void ATPressedIf();

void ATPressedSwitch();

void ATPressedLUT(FUNCPTR press_func[]);

void APressed();

void TPressed();

void NullPressed();

#endif 
__WS6_H__
