

# FdF

FdF (*Fil de Fer*) is a 42 School graphics project whose goal is to display a **3D wireframe representation** of a map using a simple graphical library.

The project focuses on computer graphics fundamentals such as coordinate systems, projections, transformations, and event handling.

---

## Project Goal

The program reads a map file containing height values and renders it as a **wireframe model** in a window.

Each point of the map is projected from 3D space to 2D space and connected with lines, forming a visual representation of the terrain.

---

## Compilation & Usage

### Build

```bash
make
```

### Run

```bash
./fdf <map_file>
```

Example:
```bash
./fdf test_maps/42.fdf
```

---

## How It Works

1. **Parsing**
   - The map file is read and parsed line by line.
   - Each value represents a height (`z`) at a given `(x, y)` coordinate.
   - The data is stored in a structured grid.

2. **Projection**
   - 3D coordinates are converted into 2D screen coordinates.
   - An isometric projection is used to give depth to the rendering.

3. **Rendering**
   - Points are connected horizontally and vertically.
   - Lines are drawn between projected points to create the wireframe.

4. **Display Loop**
   - The program opens a window and continuously redraws the scene.
   - User inputs are handled through keyboard and window events.

---

## Project Structure

```text
includes/
└── fdf.h          # Main header

src/
├── fdf.c          # Program entry point
├── coordinates.c  # Coordinate calculations and projections
├── line_draw.c    # Line drawing algorithm
├── get_window.c   # Window and image initialization
├── hook.c         # Keyboard and window event handling
├── retab.c        # Map parsing and data storage
└── utils.c        # Utility functions
```

Each source file is dedicated to a specific responsibility, keeping the project modular and readable.

---

## Interactions

The program supports basic interactions to explore the rendered model, such as:
- Zooming in and out
- Translating the model
- Rotating the model (not a true rotation)

These features allow better visualization of the map and improve user experience.

---

## What This Project Demonstrates

- Understanding of 3D to 2D projections
- Manual line drawing algorithms
- Event-driven programming
- Memory management in C
- Clean separation of logic and rendering

FdF serves as an introduction to graphics programming while enforcing rigor and structure in C.

---

## Author

**Anthony Goldberg** ***agoldber***

42 student – core curriculum completed