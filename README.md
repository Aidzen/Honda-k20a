<div align="center">

# 🏎️ HONDA K20A i-VTEC CONSOLE SIMULATOR
### *High-Performance C++ Engine Dynamics & Shaft Power Engine*

![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge&logo=githubactions)
![License](https://img.shields.io/badge/License-Academic-red?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey?style=for-the-badge)

_____                      ___    ___ _____ _____ _____ 
  /  ___|                    | \ \  / /|_   _|  ___/  __ \
  \ `--.  _ __   ___  ___ ___| |\ \/ /   | | | |__ | /  \/
   `--. \| '_ \ / _ \/ __/ __| | \  /    | | |  __|| |    
  /\__/ /| |_) |  __/ (_/\__ \ |  \/     | | | |___| \__/\
  \____/ | .__/ \___|\___|___/_|  \/     \_/ \____/ \____/
         | |                                              
         |_|


         **[ Features ]** • **[ Architecture ]** • **[ Quick Start ]** • **[ Engine Curves ]**

</div>

---

## 🏎️ Executive Summary

The **Honda K20A Educational Console** is a high-precision C++ application modeling the atmospheric physics, valve-timing transitions, and mechanical torque curves of Honda’s legendary **FD2 Civic Type R (K20A)** engine. 

Built with strict input validation and zero external library bloat, it calculates real-time mechanical shaft power while detailing the historical evolution of VTEC technology.

---

## ⚡ Technical Dashboard & K20A Engine Specs

| Metric / Parameter | Value | Gauge / Status |
| :--- | :--- | :--- |
| **Engine Configuration** | 2.0L DOHC i-VTEC (NA) | `[====================] 100% NA` |
| **Peak Shaft Power** | 165 kW (225 PS) @ 8,000 RPM | `[██████████████████░░] 90%` |
| **Peak Torque Output** | 215 Nm @ 6,100 RPM | `[████████████████████] 100%` |
| **VTEC Crossover Point** | ~5,800 RPM | `⚡ HIGH-CAM LIFT ENGAGED` |
| **Engine Redline** | 8,400 RPM | `[████████████████████] MAX LIMIT` |

---

## 📈 VTEC Lift & Torque Dynamics

Torque (Nm)
^
220 |                       /------------------\  <-- High-Cam Profile (i-VTEC)
200 |                      /

180 |         /-----------/ <--- VTEC Crossover (~5800 RPM)
160 |        /  Low-Cam Profile
100 |/________________________________> Engine RPM
0     2000     4000    5800    7000    8400 (Redline)

---

## 🛠️ System Architecture

```mermaid
graph TD
    A[main Menu Loop] --> B[showTechnology]
    A --> C[calculatePower]
    A --> D[showTimeline]
    A --> E[showK20ASpecs]
    A --> F[showSources]
    
    C --> G[readNumber Validation]


---

## 🧮 Mathematical Engine

Mechanical shaft power $P$ in Kilowatts ($\text{kW}$) is calculated dynamically using rotational physics:

$$P = \frac{\tau \times \omega}{1000} = \frac{\tau \times N \times 2\pi}{60000}$$

Where:
* $\tau$ = Measured Shaft Torque ($\text{Nm}$)
* $N$ = Engine Speed ($\text{RPM}$)
* $\omega$ = Angular Velocity ($\text{rad/s}$)

---

## 🚀 Quick Start & Build Pipeline

### Prerequisites
Ensure you have a C++17 compliant compiler (`g++`, `clang`, or MSVC).

### 1. Compile
```powershell
g++ -std=c++17 Vtec.cpp -o HondaVTEC.exe