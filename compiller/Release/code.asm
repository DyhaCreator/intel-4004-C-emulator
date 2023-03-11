ldm $1
xch r0

ldm $0
dcl
fim 4p %00000000
src 4p
ldm $0
wrm

clr,

ld r9
iac
jcn c1 fin
xch r9
src 4p
ldm $0
wrm

jun clr

fin,

clc

loo,

src 4p
rdm
add r0
xch r1
jms crr
ld r1
wrm

jun loo

crr,
jcn c0 qwe

clc
ld r9
dac
xch r9
src 4p
rdm
iac
xch r1
jms crr
ld r1
wrm
ld r9
iac
xch r9
src 4p
ldm $0
xch r1
wrm

qwe,
bbl 0