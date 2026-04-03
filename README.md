# 🧭 Pathfinding Visualizer (C++ + SFML)

A visual simulation of pathfinding algorithms built using **C++** and **SFML**.
This project allows users to interactively create a grid, place obstacles, and visualize how algorithms explore paths.

---

## 🚀 Features

* 🟦 Interactive grid system
* ⬛ Mouse-based wall creation
* 🟢 Start node selection (**Press ****`S`**** + Click**)
* 🔴 End node selection (**Press ****`E`**** + Click**)
* 🔵 BFS visualization (visited cells highlighted in real-time)

---

## 🛠 Tech Stack

* **Language:** C++
* **Graphics Library:** SFML
* **Concepts Used:**

  * Object-Oriented Programming (OOP)
  * Breadth First Search (BFS)
  * 2D Grid Representation
  * Event Handling

---

## ▶️ How to Run

### 1. Compile

```bash
g++ src/main.cpp src/Grid.cpp src/Pathfinding.cpp -std=c++17 -IC:\SFML\include -Iinclude -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -o main
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
| Run BFS        | Press `Space`     |

---

## 📂 Project Structure

```
PathfindingVisualizer/
├── src/
│   ├── main.cpp
│   ├── Grid.cpp
│   ├── Pathfinding.cpp
├── include/
│   ├── Grid.h
│   ├── Pathfinding.h
├── assets/
├── README.md
├── .gitignore
```

---

## 🧠 How It Works

* The grid is represented using a **2D vector**
* BFS (Breadth First Search) explores the grid **level-by-level**
* Each visited cell is marked and visualized in **blue**
* Walls block traversal and are ignored during BFS

---

## 🔮 Upcoming Features

* 🎞️ Step-by-step BFS animation
* 🟡 Shortest path highlighting
* ⚡ Speed control for visualization
* 🔁 Reset / Clear grid functionality
* 🚀 Additional algorithms (Dijkstra, A*)

---

## ⭐ Notes

This project demonstrates:

* Clean project structure using `.h` and `.cpp` separation
* Implementation of graph traversal algorithms
* Real-time visualization using SFML

---
CODER:-> DEV SHARMA
