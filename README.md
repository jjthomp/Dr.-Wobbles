# Dr. Wobbles – Low-Cost Open Source Pain Relief Device

Dr. Wobbles is a compact, wearable medical device designed to reduce procedural pain during injections through combined vibration and cooling. It was developed by UBC SBME Capstone Team 12 in partnership with the Digital Lab (September 2025 – April 2026), with a primary focus on children living with Juvenile Idiopathic Arthritis (JIA) and broader applicability across injection-based clinical settings.

---

## Repository Contents

### 📁 `/PCB`
Contains all files required for PCB fabrication and assembly.
- Gerber files (for PCB manufacturer submission)
- Drill files
- Bill of Materials (BOM)
- Fusion Electronics source files
- PCB schematic and routing diagrams

> For assembly instructions, see the [Assembly Guide](#assembly--instructions-for-use) section below.

---

### 📁 `/CAD`
Contains all 3D model files for the mechanical housing, designed in OnShape.
- `housing_bottom.stl` – Bottom housing piece with battery and motor slots
- `housing_lid.stl` – Top lid piece with twist-and-lock mechanism and strap tabs
- `pcb_holder.stl` – Circuit board housing insert (for use with custom PCB)
- `breadboard_holder.stl` – Circuit board housing insert (for use with breadboard prototype)
- OnShape source files

> All parts are designed to be 3D printed.

---

### 📁 `/Software`
Contains the firmware for the Adafruit QTPY ESP32-S2 microcontroller.
- `dr_wobbles.ino` – Main Arduino firmware file

**Key firmware features:**
- Two vibration intensities: LOW (PWM 120/255) and HIGH (PWM 255/255)
- 5-minute auto-shutoff on HIGH setting
- Light-sleep mode during OFF state to conserve battery
- Debounce logic for button inputs

To set up the Arduino environment for the QTPY ESP32-S2, follow the official Adafruit guide:  
👉 https://learn.adafruit.com/adafruit-qt-py-esp32-s3/arduino-ide-setup-4mb-2mb-psram

### 📁 `/Docs`
Contains the complete bill of materials and sticker design
- Sticker design
- Bill of materials

> For assembly instructions, see the [Assembly Guide](#assembly--instructions-for-use) section below.
---

## Assembly & Instructions for Use

Full step-by-step assembly and usage guides are available online:

- **Assembly Manual:** https://jjthomp.github.io/Dr.-Wobbles/
- **Instructions for Use:** https://jjthomp.github.io/Dr.-Wobbles/

---

## License
This project is open source. All hardware, software, and documentation are freely available for use, modification, and distribution. Please credit UBC SBME Capstone Team 12 and the Digital Lab if you build upon this work.

---

## Contact
For questions about this project, please contact the Digital Lab or open an issue in this repository.
