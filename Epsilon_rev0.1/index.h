#ifndef INDEX_H
#define INDEX_H

#include <Arduino.h>

const char html[] PROGMEM = R"rawliteral(
      <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 Kontrol Paneli</title>
    <style>
      body {
        font-family: monospace;
        background-color: #e0f0f0;
        display: flex;
        justify-content: center;
        margin-top: 30px;
      }
      #lcd {
        border: 2px solid #000;
        padding: 10px;
        background-color: #dcecf2;
        width: 320px;
      }
      p, .row {
        margin: 10px 0;
        display: flex;
        justify-content: space-between;
        align-items: center;
      }

      
      
      button {
        padding: 6px 12px;
        border-radius: 6px;
        font-size: 14px;
        cursor: pointer;
        background-color: #f8f8ff;
        border: 1px solid black;
      }
      #ModeBtn {
        font-weight: bold;
        width: 100%;
      }
    </style>
  </head>
  <body>
    <div id="Date&Time">
      <!-- Tarih - Saat -->
      <p><span id="date">--.--.----</span> <span id="time">--:--</span></p>

      <!-- LCD Buraya Gelecek --> 
      <br><br><br><br><br>

      <!-- AutoMan ve reset -->
      <div class="row">
      <p><button id="ModeBtn" onclick="toggleMode()">Auto/Man</button></p>
      <p><button onclick="sendCommand('reset')">RST</button></p>
      </div>

      <!-- Fazlar -->
      <div class="row">
        <span>L1: <span id="l1">---</span></span>
        <button onclick="sendCommand('L1')">▶</button>
        <button onclick="sendCommand('L1stop')">■</button>
      </div>

      <div class="row">
        <span>L2: <span id="l2">---</span></span>
        <button onclick="sendCommand('L2')">▶</button>
        <button onclick="sendCommand('L2stop')">■</button>
      </div>

      <div class="row">
        <span>L3: <span id="l3">---</span></span>
        <button onclick="sendCommand('L3')">▶</button>
        <button onclick="sendCommand('L3stop')">■</button>
      </div>
      <br>
      <!-- Alt Butonlar -->
      <div class="row">
        <button onclick="sendCommand('menu')">☰</button>
        <button onclick="sendCommand('back')">↶</button>
        <button onclick="sendCommand('ok')">✓</button>
        <button onclick="sendCommand('up')">˄</button>
        <button onclick="sendCommand('down')">˅</button>
      </div>
    </div>

    <script>
      function toggleMode() {
        fetch('/autoMan')
          .then(res => res.text())
          .then(data => {
            document.getElementById("ModeBtn").innerText = data;
          });
      }

      function sendMode(charCode) {
        fetch('/setMode?mode=' + charCode)
          .then(res => res.text())
          .then(data => {
            alert("Mod: " + data);
          });
      }

      function sendCommand(target) {
        fetch('/command?target=' + target)
          .then(res => res.text())
          .then(data => {
            console.log("Komut gönderildi: " + target);
          });
      }

      // Sayfa açıldığında mevcut veriyi al
      fetch('/status')
        .then(res => res.json())
        .then(data => {
          document.getElementById("ModeBtn").innerText = data.mode || "MODE";
          document.getElementById("l1").innerText = data.l1 || "---";
          document.getElementById("l2").innerText = data.l2 || "---";
          document.getElementById("l3").innerText = data.l3 || "---";
          document.getElementById("date").innerText = data.date || "--.--.----";
          document.getElementById("time").innerText = data.time || "--:--";
        });
    </script>
  </body>
  </html>
    )rawliteral";

#endif