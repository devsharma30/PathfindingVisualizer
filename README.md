# 🧭 Pathfinding Visualizer (C++)

A visual simulation of pathfinding algorithms built using **C++** and **SFML**.
This project allows users to interactively create a grid, place obstacles, and define start/end nodes.

---

## 🚀 Features

* 🟦 Interactive grid system
* ⬛ Mouse-based wall creation
* 🟢 Start node selection (**Press ****`S`**** + Click**)
* 🔴 End node selection (**Press ****`E`**** + Click**)
* ⚡ Real-time rendering using SFML

---

## 🛠 Tech Stack

* **Language:** C++
* **Graphics Library:** SFML

---

## ▶️ How to Run

### 1. Compile

```bash
g++ src/main.cpp src/Grid.cpp -std=c++17 -IC:\SFML\include -Iinclude -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -o main
```

### 2. Run

```bash
.\main.exe
```

---

## 🎮 Controls

| Action         | Input             |
| -------------- | ----------------- |
| Create Wall    | Left Click        |
| Set Start Node | Press `S` + Click |
| Set End Node   | Press `E` + Click |

---

## 📂 Project Structure

```
PathfindingVisualizer/
├── src/
│   ├── main.cpp
│   ├── Grid.cpp
├── include/
│   ├── Grid.h
├── assets/
├── README.md 
├── .gitignore
```

---

## 🔮 Upcoming Features

* 🔍 BFS (Breadth First Search) Visualization
* ⚡ Dijkstra Algorithm
* 🚀 A* Algorithm
* 🎞️ Path animation

---


