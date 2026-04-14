# 🔍 Pathfinding Visualizer (C++ + SFML)

An interactive **pathfinding visualizer** built using **C++ and SFML**, designed to demonstrate how graph algorithms like **BFS and A*** work in real time with smooth animations and user interaction.

---

## 🚀 Features

* 🟢 Interactive grid-based environment
* 🧱 Draw and erase walls using mouse
* 🎯 Dynamically set **start** and **end** nodes
* ⚡ Visualize **Breadth First Search (BFS)**
* 🧠 Visualize **A* (A-Star) algorithm**
* 🔄 Switch between BFS and A* during runtime
* 🎮 Adjustable visualization speed (UP / DOWN keys)
* ♻️ Smart reset (preserves walls, start & end nodes)
* 📊 Live status display (current algorithm + speed)

---

## 🎮 Controls

| Input      | Action                    |
| ---------- | ------------------------- |
| S + Click  | Set Start Node            |
| E + Click  | Set End Node              |
| Left Click | Draw Walls                |
| Space      | Run Algorithm             |
| 1          | Switch to BFS             |
| 2          | Switch to A*              |
| ↑ / ↓      | Increase / Decrease Speed |
| R          | Reset Grid                |

---

## 🎨 Visualization

| Color     | Meaning           |
| --------- | ----------------- |
| 🟦 Blue   | Explored Nodes    |
| 🟨 Yellow | Shortest Path     |
| 🟩 Green  | Start Node        |
| 🟥 Red    | End Node          |
| ⬛ Black   | Walls / Obstacles |

---

## 🧠 Algorithms Implemented

### 🔹 Breadth First Search (BFS)

* Explores nodes level-by-level
* Guarantees shortest path in unweighted grids
* Explores entire space → slower

---

### 🔹 A* (A-Star)

* Uses **Manhattan Distance heuristic**
* Prioritizes nodes closer to destination
* Explores fewer nodes → faster
* Still guarantees shortest path

---

## ⚙️ Build & Run

Make sure **SFML is installed**.

```bash
g++ src/main.cpp src/Grid.cpp src/Pathfinding.cpp -std=c++17 -I<sfml_include> -L<sfml_lib> -lsfml-graphics -lsfml-window -lsfml-system -o main
./main
```

---

## 🛠️ Tech Stack

* **C++ (Core Logic & Algorithms)**
* **SFML (Rendering & UI)**

---

## 📈 Key Highlights

* Real-time algorithm visualization
* Clean separation of **Grid**, **Pathfinding**, and **UI logic**
* Step-by-step execution for better understanding
* Interactive controls for experimentation

---

## 💡 Future Improvements

* 🖱️ Drag to draw walls (continuous drawing)
* 📊 Add Dijkstra’s Algorithm
* ↘️ Diagonal movement support
* 🎛️ UI buttons (instead of keyboard-only)
* ⏱️ Adjustable animation speed slider
* 💾 Save / Load grid state

---

## 👨‍💻 Author

**Dev Sharma**

---

## ⭐ Why this project?

This project demonstrates:

* Strong understanding of **data structures & algorithms**
* Ability to build **interactive graphical applications**
* Clean implementation of **real-world problem solving**

---

