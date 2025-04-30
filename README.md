# 42 FDF

FDF (Fil de Fer) is a project aimed at rendering a 3D wireframe representation of landscapes from a file containing height data. This project combines graphical programming with complex data visualization using the MiniLibX library.

## Features

- **3D Wireframe Rendering:** Visualize 3D landscapes as wireframe models.  
- **Map Parsing:** Reads map files containing numerical data that represent terrain elevations.  
- **Interactive Controls:** Navigate, zoom, and rotate the view in real time.  
- **Graphics with MiniLibX:** Utilizes a simple graphics library to handle window management and drawing.

## Requirements

- **Compiler:** GCC (or any C compliant compiler)  
- **Platform:** X11 environment for Linux (or equivalent on macOS)  
- **Library:** MiniLibX

## Installation

Clone the repository (bash):
```
git clone https://github.com/RubBarkhudaryan/42-FDF.git
```

## MiniLibX Setup

Before building **fdf**, you must have MiniLibX installed:

1. **Clone the MiniLibX repo (bash)**  
   ```
   git clone https://github.com/42Paris/minilibx-linux.git ~/minilibx
    ```
2. **Build the MiniLibX (bash)**
   ```
    cd ./minilibx
    make
    cd ../
    ```  
3. **Now minilibx is ready so you can go on and compile the project.To run project compile it with command**
  ```
    make
  ```
4.  **Run fdf after compilation**
  ```
    ./fdf test_maps/42.fdf
  ```

## Map Building Example

![image](https://github.com/user-attachments/assets/77c60e6b-42cb-4d7d-a8cd-deeb116a50f7)

## Bonus features
# Zoom in/out: 
```+/-```

# Rotate by x, y, z:
```1 2 3```

# Projections:

**Top:** ```t```
**Front:** ```r```
**Right:** ```f```
**Izometric:** ```i```

# Random Color:
```c```

# Move 
```w a s d``` or ```arrow up, down, left, right```

## Project Structure

**includes/** – Get next line for parsing and libft for additional utils.

**test_maps/** – Sample map files for testing.

**fdf.h** - header file for function declarations and macroses.

**C files** - logic of the program.

**Author Rub Barkhudaryan**
