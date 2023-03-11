ldm $2
xch r0
ldm $2
xch r1

ld r1
xch r3

loop:

ld r2
clc
add r0
xch r2
ld r3
dac
xch r3
ld r3

jcn an loop