fim 0p $00
fim 1p $01

loop,

ldm $0
xch r4
xch r5

clc
ld r1
add r3
xch r5

jms car

clc
ld r0
add r2
jcn c1 finish
clc
add r4
xch r4

jun jmp
car,
jcn c0 crr

ldm $1
xch r4

crr,
bbl 0
jmp
clc

ld r4
xch r0
ld r5
xch r1

ld r0
xch r6
ld r1
xch r7

;next iteration

ldm $0
xch r4
xch r5

clc
ld r1
add r3
xch r5

jms ca2

clc
ld r0
add r2
jcn c1 finish
clc
add r4
xch r4

jun jm2
ca2,
jcn c0 cr2

ldm $1
xch r4

cr2,
bbl 0
jm2,

ld r4
xch r2
ld r5
xch r3

ld r2
xch r6
ld r3
xch r7

jun loop

finish,
clc