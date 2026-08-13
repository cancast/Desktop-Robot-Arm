#include <Arduino.h>
#include <Servo.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Desktop-Robot-Arm";
const char* password = "123456789";

WebServer server(80);

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

int servoValues[3] = {1500, 1500, 1500};

String createPage() {
  String page = R"rawliteral(<!DOCTYPE html>
<html lang="tr">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, viewport-fit=cover">
    <meta name="theme-color" content="#0b1020">
    <title>Desktop Robot Arm</title>

    <style>
      :root {
        color-scheme: dark;
        --background: #080b14;
        --panel: rgba(19, 25, 43, 0.88);
        --panel-border: rgba(255, 255, 255, 0.09);
        --text: #f4f7ff;
        --muted: #8f9bb8;
        --primary: #6577ff;
        --primary-light: #8d9aff;
        --danger: #ff4d67;
        --success: #35d39a;
      }

      * {
        box-sizing: border-box;
      }

      body {
        min-height: 100vh;
        min-height: 100dvh;
        margin: 0;
        padding: max(24px, env(safe-area-inset-top)) 18px max(24px, env(safe-area-inset-bottom));
        display: grid;
        place-items: center;
        overflow-x: hidden;
        font-family: Inter, ui-sans-serif, system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
        color: var(--text);
        background:
          radial-gradient(circle at 15% 10%, rgba(101, 119, 255, 0.18), transparent 34%),
          radial-gradient(circle at 85% 90%, rgba(53, 211, 154, 0.1), transparent 28%),
          var(--background);
      }

      .control-panel {
        width: min(100%, 440px);
        padding: clamp(24px, 6vw, 40px);
        border: 1px solid var(--panel-border);
        border-radius: 30px;
        background: var(--panel);
        box-shadow: 0 30px 80px rgba(0, 0, 0, 0.42);
        backdrop-filter: blur(18px);
      }

      .panel-header {
        display: flex;
        align-items: flex-start;
        justify-content: space-between;
        gap: 20px;
        margin-bottom: 30px;
      }

      .eyebrow {
        margin: 0 0 7px;
        color: var(--primary-light);
        font-size: 0.72rem;
        font-weight: 800;
        letter-spacing: 0.16em;
        text-transform: uppercase;
      }

      h1 {
        margin: 0;
        font-size: clamp(1.55rem, 6vw, 2rem);
        line-height: 1.1;
        letter-spacing: -0.04em;
      }

      .connection {
        display: inline-flex;
        align-items: center;
        gap: 8px;
        flex: 0 0 auto;
        margin-top: 4px;
        padding: 8px 11px;
        border: 1px solid rgba(53, 211, 154, 0.22);
        border-radius: 999px;
        color: #b8f5df;
        background: rgba(53, 211, 154, 0.08);
        font-size: 0.75rem;
        font-weight: 700;
      }

      .connection-dot {
        width: 7px;
        height: 7px;
        border-radius: 50%;
        background: var(--success);
        box-shadow: 0 0 0 4px rgba(53, 211, 154, 0.12);
      }

      .joystick-wrap {
        display: grid;
        place-items: center;
        padding: 16px 0 24px;
      }

      #joystick {
        position: relative;
        width: clamp(220px, 67vw, 280px);
        aspect-ratio: 1;
        border: 1px solid rgba(255, 255, 255, 0.08);
        border-radius: 50%;
        cursor: grab;
        touch-action: none;
        user-select: none;
        background:
          linear-gradient(rgba(255, 255, 255, 0.055), rgba(255, 255, 255, 0.055)) center / 1px 72% no-repeat,
          linear-gradient(90deg, rgba(255, 255, 255, 0.055), rgba(255, 255, 255, 0.055)) center / 72% 1px no-repeat,
          radial-gradient(circle, #171e33 0 38%, #111729 39% 63%, #0d1221 64%);
        box-shadow:
          inset 0 0 0 12px rgba(255, 255, 255, 0.018),
          inset 0 14px 30px rgba(255, 255, 255, 0.025),
          0 18px 40px rgba(0, 0, 0, 0.38);
      }

      #joystick:active {
        cursor: grabbing;
      }

      #joystick::after {
        content: "";
        position: absolute;
        inset: 12%;
        border: 1px dashed rgba(143, 155, 184, 0.13);
        border-radius: 50%;
      }

      #stick {
        position: absolute;
        z-index: 1;
        width: 36%;
        aspect-ratio: 1;
        left: 32%;
        top: 32%;
        border: 1px solid rgba(255, 255, 255, 0.22);
        border-radius: 50%;
        pointer-events: none;
        background: linear-gradient(145deg, var(--primary-light), var(--primary));
        box-shadow:
          inset 0 8px 15px rgba(255, 255, 255, 0.18),
          inset 0 -10px 18px rgba(31, 38, 122, 0.28),
          0 14px 28px rgba(42, 55, 180, 0.46);
        transform: translate(0, 0);
        transition: transform 140ms ease;
        will-change: transform;
      }

      #joystick.is-active #stick {
        transition: none;
      }

      .readouts {
        display: grid;
        grid-template-columns: repeat(2, 1fr);
        gap: 12px;
        margin-bottom: 24px;
      }

      .readout {
        padding: 14px 16px;
        border: 1px solid rgba(255, 255, 255, 0.065);
        border-radius: 16px;
        background: rgba(255, 255, 255, 0.035);
      }

      .readout-label {
        display: block;
        margin-bottom: 3px;
        color: var(--muted);
        font-size: 0.72rem;
        font-weight: 700;
        letter-spacing: 0.08em;
        text-transform: uppercase;
      }

      .readout-value {
        font-size: 1.25rem;
        font-variant-numeric: tabular-nums;
        font-weight: 800;
      }

      #servoButton {
        width: 100%;
        min-height: 58px;
        display: flex;
        align-items: center;
        justify-content: space-between;
        gap: 16px;
        padding: 10px 12px 10px 19px;
        border: 1px solid rgba(255, 77, 103, 0.26);
        border-radius: 18px;
        cursor: pointer;
        color: var(--text);
        background: rgba(255, 77, 103, 0.1);
        font: inherit;
        font-weight: 800;
        transition: transform 160ms ease, background 160ms ease, border-color 160ms ease;
      }

      #servoButton:hover {
        transform: translateY(-1px);
        background: rgba(255, 77, 103, 0.16);
      }

      #servoButton:active {
        transform: translateY(1px);
      }

      #servoButton:focus-visible,
      #joystick:focus-visible {
        outline: 3px solid rgba(141, 154, 255, 0.55);
        outline-offset: 4px;
      }

      #servoButton.is-open {
        border-color: rgba(53, 211, 154, 0.28);
        background: rgba(53, 211, 154, 0.11);
      }

      #servoButton.is-open:hover {
        background: rgba(53, 211, 154, 0.17);
      }

      .button-state {
        min-width: 78px;
        padding: 8px 12px;
        border-radius: 11px;
        color: #ffd8de;
        background: rgba(255, 77, 103, 0.16);
        font-size: 0.76rem;
        letter-spacing: 0.06em;
        text-align: center;
        text-transform: uppercase;
      }

      #servoButton.is-open .button-state {
        color: #b8f5df;
        background: rgba(53, 211, 154, 0.14);
      }

      .hint {
        margin: 17px 0 0;
        color: var(--muted);
        font-size: 0.78rem;
        line-height: 1.5;
        text-align: center;
      }

      @media (max-width: 380px) {
        .control-panel {
          padding: 22px 18px;
          border-radius: 24px;
        }

        .connection {
          padding: 8px;
        }

        .connection-text {
          display: none;
        }
      }

      @media (prefers-reduced-motion: reduce) {
        *,
        *::before,
        *::after {
          scroll-behavior: auto !important;
          transition-duration: 0.01ms !important;
        }
      }
    </style>
  </head>

  <body>
    <main class="control-panel">
      <header class="panel-header">
        <div>
          <p class="eyebrow">Control Station</p>
          <h1>Desktop Robot Arm</h1>
        </div>

        <div class="connection" aria-label="Bağlantı aktif">
          <span class="connection-dot" aria-hidden="true"></span>
          <span class="connection-text">Hazır</span>
        </div>
      </header>

      <section aria-label="Robot kolu yön kontrolü">
        <div class="joystick-wrap">
          <div id="joystick" role="application" aria-label="Robot kolu joystick kontrolü" tabindex="0">
            <div id="stick"></div>
          </div>
        </div>

        <div class="readouts" aria-live="polite">
          <div class="readout">
            <span class="readout-label">X ekseni</span>
            <span class="readout-value"><span id="xValue">90</span>°</span>
          </div>
          <div class="readout">
            <span class="readout-label">Y ekseni</span>
            <span class="readout-value"><span id="yValue">90</span>°</span>
          </div>
        </div>
      </section>

      <button id="servoButton" type="button" aria-pressed="false">
        <span>Gripper</span>
        <span class="button-state">Kapalı</span>
      </button>

      <p class="hint">Kolu hareket ettirmek için joystick'i sürükleyin. Bıraktığınızda merkez konumuna döner.</p>
    </main>

    <script>
      const joystick = document.getElementById("joystick");
      const stick = document.getElementById("stick");
      const servoButton = document.getElementById("servoButton");
      const buttonState = servoButton.querySelector(".button-state");
      const xValue = document.getElementById("xValue");
      const yValue = document.getElementById("yValue");

      let joystickActive = false;
      let servoOpen = false;
      let xServo = 90;
      let yServo = 90;

      function renderServoValues() {
        xValue.textContent = xServo;
        yValue.textContent = yServo;
      }

      function updateJoystick(clientX, clientY) {
        const rect = joystick.getBoundingClientRect();
        const stickRect = stick.getBoundingClientRect();
        const centerX = rect.width / 2;
        const centerY = rect.height / 2;

        let x = clientX - rect.left - centerX;
        let y = clientY - rect.top - centerY;

        const maxDistance = (rect.width - stickRect.width) / 2;
        const distance = Math.hypot(x, y);

        if (distance > maxDistance) {
          x = (x / distance) * maxDistance;
          y = (y / distance) * maxDistance;
        }

        stick.style.transform = `translate(${x}px, ${y}px)`;
        xServo = Math.round(90 + (x / maxDistance) * 90);
        yServo = Math.round(90 - (y / maxDistance) * 90);
        renderServoValues();
      }

      function centerJoystick() {
        joystickActive = false;
        joystick.classList.remove("is-active");
        stick.style.transform = "translate(0, 0)";

        xServo = 90;
        yServo = 90;
        renderServoValues();
        sendJoystick();
      }

      function sendJoystick() {
        fetch(`/joystick?x=${xServo}&y=${yServo}`).catch(error => console.error(error));
      }

      joystick.addEventListener("pointerdown", event => {
        joystickActive = true;
        joystick.classList.add("is-active");
        joystick.setPointerCapture(event.pointerId);
        updateJoystick(event.clientX, event.clientY);
      });

      joystick.addEventListener("pointermove", event => {
        if (!joystickActive) return;
        updateJoystick(event.clientX, event.clientY);
      });

      joystick.addEventListener("pointerup", centerJoystick);
      joystick.addEventListener("pointercancel", centerJoystick);

      setInterval(() => {
        if (joystickActive) sendJoystick();
      }, 50);

      servoButton.addEventListener("click", () => {
        servoOpen = !servoOpen;
        servoButton.classList.toggle("is-open", servoOpen);
        servoButton.setAttribute("aria-pressed", String(servoOpen));
        buttonState.textContent = servoOpen ? "Açık" : "Kapalı";

        fetch(`/gripper?s=${servoOpen ? "1" : "0"}`).catch(error => console.error(error));
      });
    </script>
  </body>
</html>
)rawliteral";
  return page;

}

void handleMotor() {
  if(!server.hasArg("x") || !server.hasArg("y")) {
    server.send(400, "text/plain", "Bad Request");
    return;
  }

  servoValues[0] = map(constrain(server.arg("x").toInt(), 0, 180), 0, 180, 1300, 1700);
  servoValues[1] = map(constrain(server.arg("y").toInt(), 0, 180), 0, 180, 1300, 1700);
  servoValues[2] = map(constrain(server.arg("y").toInt(), 0, 180), 0, 180, 1300, 1700);

  motor1.writeMicroseconds(servoValues[0]);
  motor2.writeMicroseconds(servoValues[1]);
  motor3.writeMicroseconds(servoValues[2]);

  server.send(200, "text/plain", "OK");
}

void handleGripper() {
  if(!server.hasArg("s")) {
    server.send(400, "text/plain", "Bad Request");
    return;
  }

  Serial.println("Gripper");
  if(server.arg("s") == "1") {
    motor4.write(40);
  } else {
    motor4.write(90);
  }

  server.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(7);
  motor4.attach(8);

  motor4.write(90);

  WiFi.softAP(ssid, password);
  WiFi.setTxPower(WIFI_POWER_8_5dBm);

  Serial.print("Desktop Robot Arm Ip Adresi :");
  Serial.println(WiFi.softAPIP());

  server.on("/", []() {
    server.send(200, "text/html; charset=utf-8", createPage());
  });

  server.on("/joystick", HTTP_GET, handleMotor);
  server.on("/gripper", HTTP_GET, handleGripper);

  server.begin();
  Serial.println("Server baslatildıi");
}

void loop() {
  server.handleClient();
}
