# Packets list

Packet protorcol :
Packet info : Packet name : Packet ID | Packet args0(tpye);Packet args1(tpye);...

Packet data : Packet ID;Packet args0;Packet args1;...;

Exemple for motor direction packet : 0x01;0x01;0x03;0x00;0x00;

Max packet args is 9 !

## Motor status packet
- Ignore change : 0x00
- Forward : 0x01
- Backward : 0x02
- Stoped : 0x03

## Boolean packet
- true : 0x01
- false : !0x01

## Motor packet
- Direction packet : 0x01 | MotrorState1;MotrorState1;MotrorState1;MotrorState1
- Stop packet : 0x02
- Auto mode : 0x03 | modeStatus(bolean)
- Impulse direction mode : 0x04 | modeStatus(bolean)
