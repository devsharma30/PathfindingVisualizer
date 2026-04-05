# 🔍 Pathfinding Visualizer (C++ + SFML)

An interactive **pathfinding visualizer** built using **C++ and SFML**, demonstrating how classic graph algorithms work in real time through dynamic visualization.

---

## 🚀 Features

* 🟢 Interactive grid-based environment
* 🧱 Draw and erase walls using mouse
* 🎯 Set start and end nodes dynamically
* ⚡ Visualize **Breadth First Search (BFS)**
* 🧠 Visualize **A* (A-Star) algorithm**
* 🎨 Real-time color-coded visualization:

  * Blue → explored nodes
  * Yellow → shortest path
  * Green → start node
  * Red → end node
  * Black → obstacles (walls)

---

## 🎮 Controls

| Input      | Action         |
| ---------- | -------------- |
| S + Click  | Set Start Node |
| E + Click  | Set End Node   |
| Left Click | Draw Walls     |
| Space      | Run Algorithm  |
| R          | Reset Grid     |

---
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

## 🧠 Algorithms Implemented

### 🔹 Breadth First Search (BFS)

* Explores nodes level by level
* Guarantees shortest path in unweighted grids
* Slower due to uniform exploration

### 🔹 A* (A-Star)

* Uses **Manhattan distance heuristic**
* Prioritizes nodes closer to goal
* Faster and more efficient than BFS
* Produces optimal shortest path

---

## 🛠️ Tech Stack

* **C++ (Core Logic & Algorithms)**
* **SFML (Simple and Fast Multimedia Library)** for rendering

---

## ⚙️ Build & Run

Make sure SFML is installed and linked properly.

```bash
g++ src/main.cpp src/Grid.cpp src/Pathfinding.cpp -std=c++17 -I<sfml_include> -L<sfml_lib> -lsfml-graphics -lsfml-window -lsfml-system -o main
./main
```

---

## 💡 Future Improvements

* 🔄 Toggle between BFS and A* during runtime
* ⏱️ Adjustable visualization speed
* ↘️ Diagonal movement support
* 📊 Add Dijkstra’s Algorithm
* 🖥️ Improved UI panel / controls

---

## 👨‍💻 Author

**Dev Sharma**
