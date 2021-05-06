# 1.Objection
  1. เพื่อเป็นการสร้างมาตรฐานใหม่ของระบบไฟภายในบ้านให้กลายเป็น Smart House
  2. นำเสนอการใช้ Relay และ ESP32 NodeMCU 
  3. เป็นการนำเสนอแนวทางของการนำไปต่อยอดในวันข้างหน้าเกี่ยวกับระบบไฟภายใน


# 2.Component
  1. หลอดไฟ 5 วัตต์
  2. เบ้าหลอดไฟ
  3. 4 Channel Relay Module 5V 10A (JQC-3FF-S-Z)
  4. ESP32 NodeMCU ESP-WROOM-32
  5. สายไฟ
  6. กล่อง


# 3.Description
  เนื่องจากทางผู้จัดทำต้องการที่จะทำอุปกรณ์ที่มีการใช้ Relay พวกเราเลยทำอุปกรณ์ที่สามารถควบคุมการเปิดปิดหลอดไฟผ่าน Webapp ได้ ซึ่งหากอิงจากยุคสมัยปัจจุบัน เราจะพบว่าอุปกรณ์ต่างๆในครัวเรือนนั้น มีการใช้ที่เชื่อมโยงกับอุปกรณ์อิเล็คทรอนิคใกล้ตัวของพวกเรามากขึ้น เช่น สมาร์ทโฟน สมาร์ทวอช หรือ คอมพิวเตอร์ เป็นต้น โดยครั้งนี้พวกเราได้สร้างอุปกรณ์ที่มีการใช้งานที่เชื่อมโยงกับ คอมพิวเตอร์ ซึ่งเป็นอุปกรณ์ใช้งานที่ใกล้ตัวพวกเราเหมือนกัน

อุปกรณ์ดังกล่าวนั้นพวกเราเลือกใช้เป็น 4 Channel Relay ซึ่งสามารถควบคุมอุปกรณ์ได้ถึงสี่ตัว ซึ่งพวกเราได้เลือกใช้ Relay กับหลอดไฟ อุปกรณ์ตัวนี้สามารถเปิด-ปิดไฟได้ผ่าน Webapp โดยตัว Webapp เป็นเพียงตัวกลางในการออกคำสั่งระหว่างผู้ใช้งานกับตัวหลอดไฟ พวกเราได้มีการใช้ ตัว Microcontroller (ESP32 NodeMCU) ซึ่งพวกเราใช้ภาษา C++ ในการออกแบบชุดคำสั่งที่ใช้ควบคุมการเปิด-ปิดหลอดไฟแต่ละดวง

โดยตัว Relay ปกติหน้าสัมผัสจะปิดจะสัมผัสกับขา Common ในขณะที่ปิดอยู่นี้จะอยู่ในสถานะหน้าสัมผัส Normally Close ถ้าเปิดจะอยู่ในสถานะ Normally Open เมื่อเป็นดังกล่าวเราก็จะออกคำสั่งผ่านตัวชุดคำสั่งที่เราได้ใส่เข้าไปใน Microcontroller ดังที่กล่าวไว้ข้างต้น

สุดท้ายอุปกรณ์ชิ้นนี้สามารถนำไปต่อยอดได้อีกมากมาย ไม่ว่าจะเป็นการควบคุมไฟทั้งบ้านผ่านสวิทช์เพียงตัวเดียว หรืออื่นๆอีกมากมาย ดังนั้นพวกเราต้องการให้อุปกรณ์ตัวนี้เป็นตัวที่จะจุดประกายความคิดริเริ่ม และเป็นไอเดียใหม่ให้แก่ผู้ที่ได้ลองใช้งานอุปกรณ์ชิ้นนี้ โดยทั้งนี้ทั้งนั้นพวกเราก็ต้องการให้อุปกรณ์ชิ้นนี้สร้างความสะดวกสบายให้แก่ตัวผู้ใช้งานได้ในอีกระดับเมื่อเทียบกับการใช้งานในปัจจุบัน



## Structure

| Codebase              |      Description      |
| :-------------------- | :-------------------: |
| [mozart](mozart)      |      Arduino Code     |
| [beethoven](beethoven)|      Landing Page     |
| [rihanna](rihanna)    |     Controller Web    |

# Contributor
<b>IT KMITL#18</b> <br />
 1.Mr.  Noppawan Pakinsee       63070092 <br />
 2.Mr.  Peerawit Kongkitkul     63070126 <br />
 3.Mr.  Panuwat Kongchansawang  63070135 <br />
 4.Mr.  Santakorn Wongsiripa    63070174 <br />
 
<center><table>
 <tr>
  <th><img src="https://media.discordapp.net/attachments/802479714127314974/839244227220340776/vlcsnap-2021-04-19-22h57m04s531_2.png?width=670&height=671" height="150" width="150"></th>
  <th><img src="https://media.discordapp.net/attachments/802479714127314974/839244069590401104/peera-pic.jpg?width=670&height=670" height="150" width="150"></th>
  <th><img src="https://media.discordapp.net/attachments/802479714127314974/839244508315254786/mek-pic.jpg" height="150" width="150"></th>
  <th><img src="https://media.discordapp.net/attachments/802479714127314974/839244513867857961/ing-pic.jpg?width=669&height=669" height="150" width="150"></th>
 </tr>
 <tr>
  <th><p align="center">Noppawan Pakinsee</p></th> 
  <th><p align="center">Peerawit Kongkitkul</p></th>
  <th><p align="center">Panuwat Kongchansawang</p></th>
  <th><p align="center">Santakorn Wongsiripa</p></th>
 </tr>
 <tr>
  <th><p align="center">63070092</p></th>
  <th><p align="center">63070126</p></th>
  <th><p align="center">63070135</p></th>
  <th><p align="center">63070174</p></th>
 </table></center>
 
<br />
