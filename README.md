# EELE 465 Project 3

Template repository for project 3.

In this project, a keypad will be used to select from different time-varying patterns displayed on eight LEDs using your MSP430 and a breadboard. Patterns will be selected based on which button is pressed on your keypad. An unlock code will be required to begin the display of the LED patterns. An RGB LED will be used a status indicator.

## Flow Chart
```mermaid
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 800 550">
  <!-- Background -->
  <rect width="800" height="550" fill="white"/>
  
  <!-- Title -->
  <text x="400" y="30" font-family="Arial" font-size="20" text-anchor="middle" font-weight="bold">4x4 Matrix Keypad and LED Bar Circuit Diagram</text>
  
  <!-- MSP430 Microcontroller -->
  <rect x="350" y="150" width="150" height="250" rx="5" ry="5" fill="white" stroke="black" stroke-width="2"/>
  <text x="425" y="180" font-family="Arial" font-size="16" text-anchor="middle" font-weight="bold">MSP430</text>
  
  <!-- MSP430 Pins (left side) -->
  <line x1="350" y1="210" x2="330" y2="210" stroke="black" stroke-width="2"/>
  <text x="345" y="215" font-family="Arial" font-size="12" text-anchor="end">P1.0</text>
  
  <line x1="350" y1="230" x2="330" y2="230" stroke="black" stroke-width="2"/>
  <text x="345" y="235" font-family="Arial" font-size="12" text-anchor="end">P1.1</text>
  
  <line x1="350" y1="250" x2="330" y2="250" stroke="black" stroke-width="2"/>
  <text x="345" y="255" font-family="Arial" font-size="12" text-anchor="end">P1.2</text>
  
  <line x1="350" y1="270" x2="330" y2="270" stroke="black" stroke-width="2"/>
  <text x="345" y="275" font-family="Arial" font-size="12" text-anchor="end">P1.3</text>
  
  <line x1="350" y1="290" x2="330" y2="290" stroke="black" stroke-width="2"/>
  <text x="345" y="295" font-family="Arial" font-size="12" text-anchor="end">P1.4</text>
  
  <line x1="350" y1="310" x2="330" y2="310" stroke="black" stroke-width="2"/>
  <text x="345" y="315" font-family="Arial" font-size="12" text-anchor="end">P1.5</text>
  
  <line x1="350" y1="330" x2="330" y2="330" stroke="black" stroke-width="2"/>
  <text x="345" y="335" font-family="Arial" font-size="12" text-anchor="end">P1.6</text>
  
  <line x1="350" y1="350" x2="330" y2="350" stroke="black" stroke-width="2"/>
  <text x="345" y="355" font-family="Arial" font-size="12" text-anchor="end">P1.7</text>
  
  <!-- MSP430 Pins (right side) -->
  <line x1="500" y1="210" x2="520" y2="210" stroke="black" stroke-width="2"/>
  <text x="505" y="215" font-family="Arial" font-size="12" text-anchor="start">P2.0</text>
  
  <line x1="500" y1="230" x2="520" y2="230" stroke="black" stroke-width="2"/>
  <text x="505" y="235" font-family="Arial" font-size="12" text-anchor="start">P2.1</text>
  
  <line x1="500" y1="250" x2="520" y2="250" stroke="black" stroke-width="2"/>
  <text x="505" y="255" font-family="Arial" font-size="12" text-anchor="start">P2.2</text>
  
  <line x1="500" y1="270" x2="520" y2="270" stroke="black" stroke-width="2"/>
  <text x="505" y="275" font-family="Arial" font-size="12" text-anchor="start">P2.3</text>
  
  <line x1="500" y1="290" x2="520" y2="290" stroke="black" stroke-width="2"/>
  <text x="505" y="295" font-family="Arial" font-size="12" text-anchor="start">P2.4 (PWM)</text>
  
  <line x1="500" y1="310" x2="520" y2="310" stroke="black" stroke-width="2"/>
  <text x="505" y="315" font-family="Arial" font-size="12" text-anchor="start">P2.5 (PWM)</text>
  
  <line x1="500" y1="330" x2="520" y2="330" stroke="black" stroke-width="2"/>
  <text x="505" y="335" font-family="Arial" font-size="12" text-anchor="start">P2.6 (PWM)</text>
  
  <line x1="500" y1="350" x2="520" y2="350" stroke="black" stroke-width="2"/>
  <text x="505" y="355" font-family="Arial" font-size="12" text-anchor="start">P2.7</text>
  
  <!-- 4x4 Matrix Keypad -->
  <rect x="120" y="200" width="120" height="160" rx="5" ry="5" fill="white" stroke="black" stroke-width="2"/>
  <text x="180" y="180" font-family="Arial" font-size="14" text-anchor="middle" font-weight="bold">4x4 Matrix Keypad</text>
  
  <!-- Keypad Layout (simple representation) -->
  <line x1="150" y1="200" x2="150" y2="360" stroke="black" stroke-width="1"/>
  <line x1="180" y1="200" x2="180" y2="360" stroke="black" stroke-width="1"/>
  <line x1="210" y1="200" x2="210" y2="360" stroke="black" stroke-width="1"/>
  
  <line x1="120" y1="240" x2="240" y2="240" stroke="black" stroke-width="1"/>
  <line x1="120" y1="280" x2="240" y2="280" stroke="black" stroke-width="1"/>
  <line x1="120" y1="320" x2="240" y2="320" stroke="black" stroke-width="1"/>
  
  <text x="135" y="225" font-family="Arial" font-size="12" text-anchor="middle">1</text>
  <text x="165" y="225" font-family="Arial" font-size="12" text-anchor="middle">2</text>
  <text x="195" y="225" font-family="Arial" font-size="12" text-anchor="middle">3</text>
  <text x="225" y="225" font-family="Arial" font-size="12" text-anchor="middle">A</text>
  
  <text x="135" y="265" font-family="Arial" font-size="12" text-anchor="middle">4</text>
  <text x="165" y="265" font-family="Arial" font-size="12" text-anchor="middle">5</text>
  <text x="195" y="265" font-family="Arial" font-size="12" text-anchor="middle">6</text>
  <text x="225" y="265" font-family="Arial" font-size="12" text-anchor="middle">B</text>
  
  <text x="135" y="305" font-family="Arial" font-size="12" text-anchor="middle">7</text>
  <text x="165" y="305" font-family="Arial" font-size="12" text-anchor="middle">8</text>
  <text x="195" y="305" font-family="Arial" font-size="12" text-anchor="middle">9</text>
  <text x="225" y="305" font-family="Arial" font-size="12" text-anchor="middle">C</text>
  
  <text x="135" y="345" font-family="Arial" font-size="12" text-anchor="middle">*</text>
  <text x="165" y="345" font-family="Arial" font-size="12" text-anchor="middle">0</text>
  <text x="195" y="345" font-family="Arial" font-size="12" text-anchor="middle">#</text>
  <text x="225" y="345" font-family="Arial" font-size="12" text-anchor="middle">D</text>
  
  <!-- Keypad Connection Lines -->
  <!-- Columns -->
  <line x1="135" y1="370" x2="135" y2="400" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  <line x1="165" y1="370" x2="165" y2="400" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  <line x1="195" y1="370" x2="195" y2="400" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  <line x1="225" y1="370" x2="225" y2="400" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  
  <line x1="135" y1="400" x2="90" y2="400" stroke="black" stroke-width="1.5"/>
  <line x1="165" y1="400" x2="90" y2="400" stroke="black" stroke-width="1.5"/>
  <line x1="195" y1="400" x2="90" y2="400" stroke="black" stroke-width="1.5"/>
  <line x1="225" y1="400" x2="90" y2="400" stroke="black" stroke-width="1.5"/>
  
  <text x="85" y="405" font-family="Arial" font-size="10" text-anchor="end">Columns</text>
  
  <line x1="90" y1="400" x2="90" y2="240" stroke="black" stroke-width="1.5"/>
  <line x1="90" y1="240" x2="330" y2="240" stroke="black" stroke-width="1.5"/>
  <line x1="330" y1="240" x2="330" y2="210" stroke="black" stroke-width="1.5"/>
  <line x1="330" y1="230" x2="330" y2="270" stroke="black" stroke-width="1.5"/>
  
  <!-- Rows -->
  <line x1="250" y1="220" x2="280" y2="220" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  <line x1="250" y1="260" x2="280" y2="260" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  <line x1="250" y1="300" x2="280" y2="300" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  <line x1="250" y1="340" x2="280" y2="340" stroke="black" stroke-width="1.5" stroke-dasharray="4"/>
  
  <line x1="280" y1="220" x2="280" y2="420" stroke="black" stroke-width="1.5"/>
  <line x1="280" y1="260" x2="280" y2="420" stroke="black" stroke-width="1.5"/>
  <line x1="280" y1="300" x2="280" y2="420" stroke="black" stroke-width="1.5"/>
  <line x1="280" y1="340" x2="280" y2="420" stroke="black" stroke-width="1.5"/>
  
  <line x1="280" y1="420" x2="330" y2="420" stroke="black" stroke-width="1.5"/>
  <text x="285" y="435" font-family="Arial" font-size="10" text-anchor="start">Rows</text>
  
  <line x1="330" y1="420" x2="330" y2="290" stroke="black" stroke-width="1.5"/>
  <line x1="330" y1="290" x2="330" y2="350" stroke="black" stroke-width="1.5"/>
  
  <!-- RGB LED -->
  <circle cx="600" cy="240" r="15" fill="white" stroke="black" stroke-width="2"/>
  <text x="600" y="215" font-family="Arial" font-size="14" text-anchor="middle" font-weight="bold">RGB LED</text>
  
  <!-- RGB LED Connections -->
  <line x1="520" y1="290" x2="570" y2="290" stroke="black" stroke-width="1.5"/>
  <line x1="570" y1="290" x2="570" y2="230" stroke="black" stroke-width="1.5"/>
  <line x1="570" y1="230" x2="585" y2="230" stroke="black" stroke-width="1.5"/>
  <text x="575" y="225" font-family="Arial" font-size="10" text-anchor="end">R</text>
  
  <line x1="520" y1="310" x2="580" y2="310" stroke="black" stroke-width="1.5"/>
  <line x1="580" y1="310" x2="580" y2="240" stroke="black" stroke-width="1.5"/>
  <line x1="580" y1="240" x2="585" y2="240" stroke="black" stroke-width="1.5"/>
  <text x="575" y="245" font-family="Arial" font-size="10" text-anchor="end">G</text>
  
  <line x1="520" y1="330" x2="590" y2="330" stroke="black" stroke-width="1.5"/>
  <line x1="590" y1="330" x2="590" y2="250" stroke="black" stroke-width="1.5"/>
  <line x1="590" y1="250" x2="585" y2="250" stroke="black" stroke-width="1.5"/>
  <text x="575" y="255" font-family="Arial" font-size="10" text-anchor="end">B</text>
  
  <!-- Resistor symbols -->
  <rect x="585" y="230" width="10" height="5" fill="white" stroke="black" stroke-width="1"/>
  <rect x="585" y="240" width="10" height="5" fill="white" stroke="black" stroke-width="1"/>
  <rect x="585" y="250" width="10" height="5" fill="white" stroke="black" stroke-width="1"/>
  
  <!-- LED Bar -->
  <rect x="570" y="380" width="160" height="30" rx="3" ry="3" fill="white" stroke="black" stroke-width="2"/>
  <text x="650" y="370" font-family="Arial" font-size="14" text-anchor="middle" font-weight="bold">8-LED Bar</text>
  
  <!-- LED Symbols in Bar -->
  <circle cx="580" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  <circle cx="600" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  <circle cx="620" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  <circle cx="640" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  <circle cx="660" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  <circle cx="680" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  <circle cx="700" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  <circle cx="720" cy="395" r="5" fill="white" stroke="black" stroke-width="1"/>
  
  <!-- Resistor array for LED bar -->
  <rect x="570" y="440" width="160" height="15" rx="0" ry="0" fill="white" stroke="black" stroke-width="1.5"/>
  <text x="650" y="470" font-family="Arial" font-size="12" text-anchor="middle">Resistor Array</text>
  
  <!-- LED Bar connections -->
  <line x1="580" y1="425" x2="580" y2="440" stroke="black" stroke-width="1"/>
  <line x1="600" y1="425" x2="600" y2="440" stroke="black" stroke-width="1"/>
  <line x1="620" y1="425" x2="620" y2="440" stroke="black" stroke-width="1"/>
  <line x1="640" y1="425" x2="640" y2="440" stroke="black" stroke-width="1"/>
  <line x1="660" y1="425" x2="660" y2="440" stroke="black" stroke-width="1"/>
  <line x1="680" y1="425" x2="680" y2="440" stroke="black" stroke-width="1"/>
  <line x1="700" y1="425" x2="700" y2="440" stroke="black" stroke-width="1"/>
  <line x1="720" y1="425" x2="720" y2="440" stroke="black" stroke-width="1"/>
  
  <!-- LED Bar to MSP430 -->
  <line x1="520" y1="210" x2="550" y2="210" stroke="black" stroke-width="1.5"/>
  <line x1="550" y1="210" x2="550" y2="455" stroke="black" stroke-width="1.5"/>
  <line x1="550" y1="455" x2="580" y2="455" stroke="black" stroke-width="1.5"/>
  
  <line x1="520" y1="230" x2="540" y2="230" stroke="black" stroke-width="1.5"/>
  <line x1="540" y1="230" x2="540" y2="455" stroke="black" stroke-width="1.5"/>
  <line x1="540" y1="455" x2="600" y2="455" stroke="black" stroke-width="1.5"/>
  
  <!-- Simplified connections for other LEDs -->
  <line x1="520" y1="250" x2="530" y2="250" stroke="black" stroke-width="1.5"/>
  <line x1="530" y1="250" x2="530" y2="490" stroke="black" stroke-width="1.5"/>
  <line x1="530" y1="490" x2="650" y2="490" stroke="black" stroke-width="1.5"/>
  <line x1="650" y1="490" x2="650" y2="455" stroke="black" stroke-width="1.5"/>
  
  <line x1="520" y1="270" x2="520" y2="490" stroke="black" stroke-width="1.5"/>
  <line x1="520" y1="490" x2="720" y2="490" stroke="black" stroke-width="1.5"/>
  <line x1="720" y1="490" x2="720" y2="455" stroke="black" stroke-width="1.5"/>
  
  <!-- Heartbeat LED -->
  <circle cx="550" cy="350" r="10" fill="white" stroke="black" stroke-width="1.5"/>
  <text x="550" y="375" font-family="Arial" font-size="12" text-anchor="middle">Heartbeat LED</text>
  <line x1="520" y1="350" x2="540" y2="350" stroke="black" stroke-width="1.5"/>
  
  <!-- Power and Ground -->
  <line x1="400" y1="490" x2="400" y2="465" stroke="black" stroke-width="2"/>
  <text x="400" y="505" font-family="Arial" font-size="12" text-anchor="middle">GND</text>
  
  <line x1="450" y1="490" x2="450" y2="465" stroke="black" stroke-width="2"/>
  <text x="450" y="505" font-family="Arial" font-size="12" text-anchor="middle">3.3V</text>
  
  <!-- Notes -->
  <text x="400" y="530" font-family="Arial" font-size="12" text-anchor="middle" font-style="italic">Note: Actual pin connections may vary based on implementation</text>
</svg>
```

## Circuit Diagram

## Software Architecture


