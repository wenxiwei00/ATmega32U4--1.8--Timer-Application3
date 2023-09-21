# ATmega32U4--1.8--Timer-Application3
用Timer（计数器）让LED模拟心跳变缓的过程。
####  电路图  
![695225563352722851](https://github.com/wenxiwei00/ATmega32U4--1.4--Timer2/assets/114196821/adbdb2fa-d7a5-402b-97ab-48bd1e391e8f)  
注意这里一定要用PC6口才可以，因为我的代码里面用到了OCR3A寄存器，只有PC6与OCR3A关联  
<img width="474" alt="40b7affe50dca9e6497f2fd98db97e3" src="https://github.com/wenxiwei00/ATmega32U4--1.4--Timer2/assets/114196821/13a6e06d-37fe-4839-b3e1-d59b9d8f8c29">
####  最终效果  
最终效果也可以在youtube上查看：https://youtu.be/m96aMSdByPw     
小灯会模拟心脏跳动20次，逐渐变暗，最终熄灭 
####  参考资料  
可以找到如何设置Timer mode，如何设置pre-scaler...  
https://medesign.seas.upenn.edu/index.php/Guides/MaEvArM-timer3
