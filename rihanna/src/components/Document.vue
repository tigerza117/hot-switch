<template>
  <div class="doc mx-auto space-y-8 p-8">
    <div class="text-6xl font-bold text-center my-16">Document</div>

    <section>
      <h2 class="text-2xl font-bold">Objection</h2>
      <ol class="list-inside list-disc ml-4 mt-4">
        <li>
          เพื่อเป็นการสร้างมาตรฐานใหม่ของระบบไฟภายในบ้านให้กลายเป็น Smart House
        </li>
        <li>นำเสนอการใช้ Relay และ ESP32 NodeMCU</li>
        <li>
          เป็นการนำเสนอแนวทางของการนำไปต่อยอดในวันข้างหน้าเกี่ยวกับระบบไฟภายใน
        </li>
      </ol>
    </section>

    <section>
      <h2 class="text-2xl font-bold">Component</h2>
      <ol class="list-inside list-disc ml-4 mt-4">
        <li>หลอดไฟ 5 วัตต์</li>
        <li>เบ้าหลอดไฟ</li>
        <li>4 Channel Relay Module 5V 10A (JQC-3FF-S-Z)</li>
        <li>ESP32 NodeMCU ESP-WROOM-32</li>
        <li>สายไฟ</li>
        <li>กล่อง</li>
      </ol>
    </section>

    <section>
      <h2 class="text-2xl font-bold">Description</h2>
      <ol class="list-inside ml-4 mt-4 space-y-6">
        <li>
          เนื่องจากทางผู้จัดทำต้องการที่จะทำอุปกรณ์ที่มีการใช้ Relay
          พวกเราเลยทำอุปกรณ์ที่สามารถควบคุมการเปิดปิดหลอดไฟผ่าน Webapp ได้
          ซึ่งหากอิงจากยุคสมัยปัจจุบัน เราจะพบว่าอุปกรณ์ต่างๆในครัวเรือนนั้น
          มีการใช้ที่เชื่อมโยงกับอุปกรณ์อิเล็คทรอนิคใกล้ตัวของพวกเรามากขึ้น เช่น
          สมาร์ทโฟน สมาร์ทวอช หรือ คอมพิวเตอร์ เป็นต้น
          โดยครั้งนี้พวกเราได้สร้างอุปกรณ์ที่มีการใช้งานที่เชื่อมโยงกับ
          คอมพิวเตอร์ ซึ่งเป็นอุปกรณ์ใช้งานที่ใกล้ตัวพวกเราเหมือนกัน
        </li>
        <li>
          อุปกรณ์ดังกล่าวนั้นพวกเราเลือกใช้เป็น 4 Channel Relay
          ซึ่งสามารถควบคุมอุปกรณ์ได้ถึงสี่ตัว ซึ่งพวกเราได้เลือกใช้ Relay
          กับหลอดไฟ อุปกรณ์ตัวนี้สามารถเปิด-ปิดไฟได้ผ่าน Webapp โดยตัว Webapp
          เป็นเพียงตัวกลางในการออกคำสั่งระหว่างผู้ใช้งานกับตัวหลอดไฟ
          พวกเราได้มีการใช้ ตัว Microcontroller (ESP32 NodeMCU)
          ซึ่งพวกเราใช้ภาษา C++
          ในการออกแบบชุดคำสั่งที่ใช้ควบคุมการเปิด-ปิดหลอดไฟแต่ละดวง
        </li>
        <li>
          โดยตัว Relay ปกติหน้าสัมผัสจะปิดจะสัมผัสกับขา Common
          ในขณะที่ปิดอยู่นี้จะอยู่ในสถานะหน้าสัมผัส Normally Close
          ถ้าเปิดจะอยู่ในสถานะ Normally Open
          เมื่อเป็นดังกล่าวเราก็จะออกคำสั่งผ่านตัวชุดคำสั่งที่เราได้ใส่เข้าไปใน
          Microcontroller ดังที่กล่าวไว้ข้างต้น
        </li>
        <li>
          สุดท้ายอุปกรณ์ชิ้นนี้สามารถนำไปต่อยอดได้อีกมากมาย
          ไม่ว่าจะเป็นการควบคุมไฟทั้งบ้านผ่านสวิทช์เพียงตัวเดียว
          หรืออื่นๆอีกมากมาย
          ดังนั้นพวกเราต้องการให้อุปกรณ์ตัวนี้เป็นตัวที่จะจุดประกายความคิดริเริ่ม
          และเป็นไอเดียใหม่ให้แก่ผู้ที่ได้ลองใช้งานอุปกรณ์ชิ้นนี้
          โดยทั้งนี้ทั้งนั้นพวกเราก็ต้องการให้อุปกรณ์ชิ้นนี้สร้างความสะดวกสบายให้แก่ตัวผู้ใช้งานได้ในอีกระดับเมื่อเทียบกับการใช้งานในปัจจุบัน
        </li>
      </ol>
    </section>

    <section>
      <h2 class="text-2xl font-bold">How to use</h2>
      <div class="how space-y-4 mt-4">
        <div>
          <p class="mb-2">ทำการ login ด้วย google account</p>
          <img src="../assets/how/1.png" alt="img" />
        </div>
        <div>
          <p class="mb-2">เมื่อทำการ login แล้วจะเข้ามาสู่ dashboard</p>
          <p class="mb-2">
            ถ้าเคยเพิ่ม device แล้วจะมี device
            ที่เคยเชื่อมอยู่แต่ถ้าไม่มีจะต้องเพิ่ม
          </p>
          <img src="../assets/how/2.png" alt="img" />
        </div>
        <div>
          <p class="mb-2">กด + เพื่อเพิ่ม device</p>
          <img src="../assets/how/3.png" alt="img" />
        </div>
        <div>
          <p class="mb-2">จะขึ้นให้กรอก device id ซึ่งจะมาจากการตั้งหลังบ้าน</p>
          <img src="../assets/how/4.png" alt="img" />
        </div>
        <div>
          <p class="mb-2">กรอกชื่อ device ที่ต้องการให้แสดง</p>
          <img src="../assets/how/5.png" alt="img" />
        </div>
        <div>
          <p class="mb-2">เมื่อทำการ เพิ่มสำเร็จจะขึ้น alert แจ้งว่าสำเร็จ</p>
          <img src="../assets/how/6.png" alt="img" />
        </div>
        <div>
          <p class="mb-2">หลังจากเพิ่ม device แล้วจะมี device โผล่มาใหม่</p>
          <img src="../assets/how/7.png" alt="img" />
        </div>
        <div>
          <p class="mb-2">
            ลองกดเข้าไปดูจะพบ switch ต่างๆ สามารถลองปิดเปิดได้เลยถ้า device
            เปิดและเชื่อม wifi อยู่
          </p>
          <img src="../assets/how/8.png" alt="img" />
        </div>
      </div>
    </section>
  </div>
</template>

<script>
export default {
  name: 'Document',
};
</script>

<style scoped>
.doc section {
  max-width: 960px;
}
.how > * > * {
  border-radius: 20px;
}
</style>
