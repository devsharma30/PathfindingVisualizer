# 🧭 Pathfinding Visualizer (C++ + SFML)

A real-time visualization of pathfinding algorithms built using **C++** and **SFML**.
This project allows users to interactively create a grid, place obstacles, and observe how algorithms explore and compute the shortest path.

---

## 🚀 Features

* 🟦 Interactive grid system
* ⬛ Mouse-based wall creation
* 🟢 Start node selection (**S + Click**)
* 🔴 End node selection (**E + Click**)
* 🔵 BFS exploration visualization
* 🟡 Shortest path reconstruction

---

## 🧠 How It Works

### 1. Grid Representation

* Implemented using a **2D vector**
* Each cell stores a state:

  * `0` → Empty
  * `1` → Wall
  * `2` → Start
  * `3` → End
  * `4` → Visited (BFS)
  * `5` → Final Path

---

### 2. BFS Algorithm

* Uses a **queue** to explore nodes level-by-level
* Ensures shortest path in an unweighted grid
* Maintains a `visited` matrix to avoid revisiting

---

### 3. Parent Tracking (Key Concept)

Each cell stores:

```text
parent[row][col] = previous cell
```

This allows reconstruction of the shortest path after reaching the destination.

---

### 4. Path Reconstruction

* Start from the **end node**
* Follow parent pointers back to the start
* Mark each cell as part of the path (yellow)

---

## ▶️ How to Run

### Compile

```bash
g++ src/main.cpp src/Grid.cpp src/Pathfinding.cpp -std=c++17 -IC:\SFML\include -Iinclude -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -o main
```

### Run

```bash
.\main.exe
```

---

## 🎮 Controls

| Action      | Input      |
| ----------- | ---------- |
| Create Wall | Left Click |
| Set Start   | S + Click  |
| Set End     | E + Click  |
| Run BFS     | Space      |

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

## 📌 Concepts Demonstrated

* Object-Oriented Programming (OOP)
* Breadth First Search (BFS)
* Graph traversal on grids
* Real-time rendering with SFML
* State-based simulation
* Path reconstruction using parent tracking

---

## 🔮 Future Improvements

* ⚡ Dijkstra Algorithm
* 🚀 A* Algorithm
* 🎞️ Animation speed control
* 🔁 Reset / Clear grid
* 🎮 UI enhancements

---

## 👨‍💻 Author

**Dev Sharma**

