;Develop an ALP to find the largest member in the array of 32 nás.

  AREA, LARGEST, CODE, READONLY
ENTRY
START
  MOV R5, #6
  LDR R1,= Value1
Value
  LDR R2, [R1], #4

LOOP
  LDR R4, [R1], #4
  CMP R2, R4
  BHI Loop1
  MOV R2, R4

Loop1 
  SUBS R5, R5, #1
  CMP R5,#0
  BNE Loop
  LDR R4, =Result
  STR R2, [R4]

XSS B XSS
Value1 
  DCD 0x44444444
  DCD 0x22222222
  DCD 0x11111111
  DCD 0x33333333
  DCD 0xAAAAAAAA
  DCD 0x88888888
  DCD 0x99999999
  AREA, DATA2,CODE, READWRITE
Result DCD 0x0
END
