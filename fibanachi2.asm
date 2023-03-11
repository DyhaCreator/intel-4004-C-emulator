;загружаем данные в оперативку
;первый регистр
ldm $0
dcl
fim 4p %00000000
src 4p
ldm 0
wrm

ldm $0
dcl
fim 4p %00000001
src 4p
ldm 0
wrm

ldm $0
dcl
fim 4p %00000010
src 4p
ldm 0
wrm

ldm $0
dcl
fim 4p %00000011
src 4p
ldm 0
wrm

;второй регистр
ldm $0
dcl
fim 4p %00010000
src 4p
ldm 0
wrm

ldm $0
dcl
fim 4p %00010001
src 4p
ldm 0
wrm

ldm $0
dcl
fim 4p %00010010
src 4p
ldm 0
wrm

ldm $0
dcl
fim 4p %00010011
src 4p
ldm 1
wrm
;завершили загрузку

loop,

;считываем младшие биты
ldm $0
dcl
fim 4p %00000011
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010011
src 4p
rdm
xch r1

;складываем
ld r0
add r1
xch r5
jms crr

jun jmp
crr,
jcn c0 car

ldm 1
xch r4

car,
bbl 0
jmp,

ldm $0
dcl
fim 4p %00100011
src 4p
ld r5
wrm

ldm $0
dcl
fim 4p %00100010
src 4p
ld r4
wrm
;очищаем регистры
fim 0p $00
fim 1p $00
fim 2p $00
;загружаем следующую пару
ldm $0
dcl
fim 4p %00000010
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010010
src 4p
rdm
xch r1

ldm $0
dcl
fim 4p %00100010
src 4p
rdm
xch r2

;складываем
clc
ld r0
add r1
xch r5
jms cr2

jun jm2
cr2,
jcn c0 ca2

ldm 1
xch r4

ca2,
bbl 0
jm2,

clc
ld r5
add r2
xch r5

ldm $0
dcl
fim 4p %00100010
src 4p
ld r5
wrm

ldm $0
dcl
fim 4p %00100001
src 4p
ld r4
wrm

fim 0p $00
fim 1p $00
fim 2p $00
;загружаем следующие
ldm $0
dcl
fim 4p %00000001
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010001
src 4p
rdm
xch r1

ldm $0
dcl
fim 4p %00100001
src 4p
rdm
xch r2
;складываем
clc
ld r0
add r1
xch r5
jms cr3

jun jm3
cr3,
jcn c0 ca3

ldm 1
xch r4

ca3,
bbl 0
jm3,

clc
ld r5
add r2
xch r5

;записываем результаты
ldm $0
dcl
fim 4p %00100001
src 4p
ld r5
wrm

ldm $0
dcl
fim 4p %00100000
src 4p
ld r4
wrm

fim 0p $00
fim 1p $00
fim 2p $00

;загружаем следующие
ldm $0
dcl
fim 4p %00000000
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010000
src 4p
rdm
xch r1

ldm $0
dcl
fim 4p %00100000
src 4p
rdm
xch r2
;складываем
clc
ld r0
add r1
xch r5
jms cr4

jun jm4
cr4,
jcn c0 ca4

ldm 1
xch r4

ca4,
bbl 0
jm4,

clc
ld r5
add r2
xch r5
;записываем результаты
ldm $0
dcl
fim 4p %00100000
src 4p
ld r5
wrm

fim 0p $00
fim 1p $00
fim 2p $00

;0 copy

ldm $0
dcl
fim 4p %00100000
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00000000
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110000
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100000
src 4p
ldm 0
wrm

;1 copy --------------

ldm $0
dcl
fim 4p %00100001
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00000001
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110001
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100001
src 4p
ldm 0
wrm

;2 copy --------------

ldm $0
dcl
fim 4p %00100010
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00000010
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110010
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100010
src 4p
ldm 0
wrm

;3 copy --------------

ldm $0
dcl
fim 4p %00100011
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00000011
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110011
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100011
src 4p
ldm 0
wrm

;считываем младшие биты
ldm $0
dcl
fim 4p %00000011
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010011
src 4p
rdm
xch r1

;складываем
ld r0
add r1
xch r5
jms cr5

jun jm5
cr5,
jcn c0 ca5

ldm 1
xch r4

ca5,
bbl 0
jm5,

ldm $0
dcl
fim 4p %00100011
src 4p
ld r5
wrm

ldm $0
dcl
fim 4p %00100010
src 4p
ld r4
wrm
;очищаем регистры
fim 0p $00
fim 1p $00
fim 2p $00
;загружаем следующую пару
ldm $0
dcl
fim 4p %00000010
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010010
src 4p
rdm
xch r1

ldm $0
dcl
fim 4p %00100010
src 4p
rdm
xch r2

;складываем
clc
ld r0
add r1
xch r5
jms cr6

jun jm6
cr6,
jcn c0 ca6

ldm 1
xch r4

ca6,
bbl 0
jm6,

clc
ld r5
add r2
xch r5

ldm $0
dcl
fim 4p %00100010
src 4p
ld r5
wrm

ldm $0
dcl
fim 4p %00100001
src 4p
ld r4
wrm
;очищаем регистры
fim 0p $00
fim 1p $00
fim 2p $00
;загружаем следующие
ldm $0
dcl
fim 4p %00000001
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010001
src 4p
rdm
xch r1

ldm $0
dcl
fim 4p %00100001
src 4p
rdm
xch r2
;складываем
clc
ld r0
add r1
xch r5
jms cr7

jun jm7
cr7,
jcn c0 ca7

ldm 1
xch r4

ca7,
bbl 0
jm7,

clc
ld r5
add r2
xch r5

;записываем результаты
ldm $0
dcl
fim 4p %00100001
src 4p
ld r5
wrm

ldm $0
dcl
fim 4p %00100000
src 4p
ld r4
wrm

fim 0p $00
fim 1p $00
fim 2p $00
;загружаем следующие
ldm $0
dcl
fim 4p %00000000
src 4p
rdm
xch r0

ldm $0
dcl
fim 4p %00010000
src 4p
rdm
xch r1

ldm $0
dcl
fim 4p %00100000
src 4p
rdm
xch r2
;складываем
clc
ld r0
add r1
xch r5
jms cr8

jun jm8
cr8,
jcn c0 ca8

ldm 1
xch r4

ca8,
bbl 0
jm8,

clc
ld r5
add r2
xch r5
;записываем результаты
ldm $0
dcl
fim 4p %00100000
src 4p
ld r5
wrm

fim 0p $00
fim 1p $00
fim 2p $00

;0 copy

ldm $0
dcl
fim 4p %00100000
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00010000
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110000
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100000
src 4p
ldm 0
wrm

;1 copy --------------

ldm $0
dcl
fim 4p %00100001
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00010001
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110001
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100001
src 4p
ldm 0
wrm

;2 copy --------------

ldm $0
dcl
fim 4p %00100010
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00010010
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110010
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100010
src 4p
ldm 0
wrm

;3 copy --------------

ldm $0
dcl
fim 4p %00100011
src 4p
rdm

xch r0

ldm $0
dcl
fim 4p %00010011
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00110011
src 4p
ld r0
wrm

ldm $0
dcl
fim 4p %00100011
src 4p
ldm 0
wrm

jun loop