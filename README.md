# ESP32-CAM + YOLOv8 Real-Time Security Camera System (2025)

A **professional-grade**, **zero-cost**, **100% local** security camera that detects people (or anything) in real time using **full YOLOv8** on your laptop/PC with **instant notifications** on browser, desktop, and phone.

No cloud. No subscription. Runs at 30–100+ FPS.
<img width="904" height="947" alt="Gemini_Generated_Image_e8qw77e8qw77e8qw" src="https://github.com/user-attachments/assets/13b4337f-5d4b-4b43-bec7-68addd1e0c56" />

![9 43 28 AM](https://github.com/user-attachments/assets/54f54e4e-f01e-48a0-ac32-ec0876bc8fde)


<img width="1920" height="1030" alt="Copy of Fencing_minor_1 ipynb - Colab - Google Chrome 11-12-2025 09_42_05" src="https://github.com/user-attachments/assets/b0ed860b-625b-4710-9b64-0260939a700e" />

![WhatsApp Image 2025-12-11 at 9 43 28 AM](https://github.com/user-attachments/assets/bafed1f0-7668-45dd-a541-82b5c0bbf0cc)

![2025-12-11 at 9 43 28 AM](https://github.com/user-attachments/assets/e3fb3d5a-06ff-4195-9aae-e9dda9294e25)





## Features
- Full YOLOv8 (nano/small/medium) – not tiny ML
- Live stream from ESP32-CAM
- Instant red flashing alerts + photo capture
- Desktop + browser notifications
- Works offline on local WiFi
- Easily add Telegram, Pushover, siren, etc.

## Demo
![Alert](screenshots/alert-desktop.png)

## Hardware
- ESP32-CAM (AI-Thinker)
- Any laptop/PC (Windows/Mac/Linux)
- Optional: Arduino Uno for siren/relay

## Quick Start (5 minutes)
```bash
# 1. Flash ESP32-CAM with code in /ESP32-CAM
# 2. Install Python dependencies
pip install -r Laptop-PC-Brain/requirements.txt

# 3. Run server
python Laptop-PC-Brain/server.py

# 4. Run YOLO detector
python Laptop-PC-Brain/yolo_alert.py


ESP32-CAM-YOLOv8-Security-Camera/
├── ESP32-CAM/                → Code to flash on ESP32-CAM
├── Laptop-PC-Brain/          → All Python magic (run here)
│   ├── yolo_alert.py         → Main detection engine
│   ├── server.py             → Beautiful web dashboard
│   ├── requirements.txt      → One-click install
│   └── alerts/               → Auto-saved photos when detected
├── Arduino-Uno/              → Optional buzzer/LED control
├── screenshots/              → Example photos
└── README.md                 → This file







### Step-by-Step Setup (Takes 10–15 minutes total)

#### Step 1: Flash the ESP32-CAM (One-Time Only)
1. Connect ESP32-CAM to FTDI like this:  
   `FTDI GND → ESP GND`  
   `FTDI 5V → ESP 5V`  
   `FTDI TX → ESP U0R (RX)`  
   `FTDI RX → ESP U0T (TX)`  
   **Connect GPIO0 to GND** (very important for flashing mode!)

2. Open Arduino IDE → Install ESP32 board (Tools → Board → Boards Manager → search "esp32")

3. Open file: `ESP32-CAM/ESP32_CAM_Live_Stream.ino`

4. Change these two lines:
   ```cpp
   const char* ssid = "YOUR_WIFI_NAME";
   const char* password = "YOUR_WIFI_PASSWORD";


5)Select board: AI Thinker ESP32-CAM
Upload speed: 115200
Press the RESET button on ESP32-CAM when upload starts

6) After upload, remove GPIO0 from GND, power cycle
Open Serial Monitor (115200 baud) → you will see:



WiFi connected
Camera Stream Ready! Go to: http://192.168.x.x


Step 2: Install Python & Dependencies on Your Laptop
Open Terminal (Mac/Linux) or Command Prompt/Anaconda (Windows)
