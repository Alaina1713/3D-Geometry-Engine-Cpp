# 3D Geometry Engine in C++

## Project Overview
This is a **3D Geometry Engine** written in C++ that allows you to model basic 3D objects, calculate their **volume**, **surface area**, and **bounding boxes**, and perform simple queries on a scene. The project is designed using **Object-Oriented Programming (OOP)** principles, file handling, and the C++ Standard Library (STL).  


---

## Features
- Supports multiple 3D objects:  
  - Sphere  
  - Cube  
  - Cylinder  
- Calculates **volume** and **surface area** for each object.  
- Computes **bounding boxes** for spatial queries.  
- Reads input scene data from a file (`scene.txt`).  
- Outputs results to a file (`results.txt`).  
- Fully modular and easy to extend with additional 3D shapes.  
- Demonstrates **shared pointers** and STL containers.  

## Code Highlights

- Object-Oriented Design: Base class Object3D with derived classes Sphere, Cube, Cylinder.
- STL Usage: Uses vector to store multiple objects.
- Memory Safety: Uses shared_ptr for dynamic memory management.
- File Handling: Reads input from scene.txt and writes output to results.txt.
- Extensible: Adding a new 3D shape requires minimal changes.

## Tools & Requirements

- C++ compiler: g++ (version >= 5.0 recommended)
- Optional IDE: VS Code, CLion, or any C++ editor
- OS: Ubuntu 24.04 LTS recommended (or Windows with MinGW)

## Future Improvements

- Add more 3D shapes: Cone, Torus, Pyramid.
- Implement transformations: Translate, Scale, Rotate objects.
- Add interactive console UI or graphical UI using Qt.

Add collision detection and nearest object queries.

Include unit tests for each shape’s volume and surface area calculations.
