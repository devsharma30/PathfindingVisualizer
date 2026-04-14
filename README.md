# 🔍 Pathfinding Visualizer (C++ + SFML)

An interactive **pathfinding visualizer** built using **C++ and SFML**, demonstrating how graph search algorithms work in real time through dynamic visualization.

---

## 🚀 Features

* 🟢 Interactive grid system
* 🧱 Draw and erase walls using mouse
* 🎯 Set start and end nodes dynamically
* ⚡ Visualize **Breadth First Search (BFS)**
* 🧠 Visualize **A* (A-Star) algorithm**
* 🔄 **Switch between BFS and A*** during runtime
* ♻️ Smart reset (preserves walls/start/end while clearing path)
* 🎨 Color-coded visualization:

  * Blue → explored nodes
  * Yellow → shortest path
  * Green → start node
  * Red → end node
  * Black → walls

---

## 🎮 Controls

| Input      | Action         |
| ---------- | -------------- |
| S + Click  | Set Start Node |
| E + Click  | Set End Node   |
| Left Click | Draw Walls     |
| Space      | Run Algorithm  |
| 1          | Switch to BFS  |
| 2          | Switch to A*   |
| R          | Reset Grid     |

---

## 🧠 Algorithms Implemented

### 🔹 Breadth First Search (BFS)

* Explores nodes level-by-level
* Guarantees shortest path in unweighted grids
* Explores entire space → more nodes visited

### 🔹 A* (A-Star)

* Uses **Manhattan distance heuristic**
* Prioritizes nodes closer to goal
* More efficient than BFS
* Produces optimal shortest path

---

## 🛠️ Tech Stack

* **C++ (Core Logic & Algorithms)**
* **SFML (Graphics Library)**

---

## ⚙️ Build & Run

Make sure SFML is installed and linked properly.

```bash
g++ src/main.cpp src/Grid.cpp src/Pathfinding.cpp -std=c++17 -I<sfml_include> -L<sfml_lib> -lsfml-graphics -lsfml-window -lsfml-system -o main
./main
```

---

## 💡 Future Improvements

* ⏱️ Speed control (animation tuning)
* 🧠 Add Dijkstra’s Algorithm
* ↘️ Diagonal movement support
* 🎛️ UI buttons for better interaction
* 📊 Performance comparison between algorithms

---

## 👨‍💻 Author

**Dev Sharma**

