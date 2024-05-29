<p align="center">
  <img src="https://github.com/busra-ashak/Shell-Texturing/assets/79407881/8755453d-e041-4fd5-9f8b-2969a1359a6c" />
</p>

# Shell Texturing

A minimal implementation of the shell texturing method in C++ via OpenGL 4.5 where we rendered a plane of grass. The application includes a moveable 3D camera allowing interactive navigation through the scene and allows users to increase or decrease both the spacing between the shells and the number of the shells at runtime.


## Description

Shell texturing is a technique used in computer graphics to render complex-looking geometry, such as grass or fur, with very few vertices. This method involves layering multiple semi-transparent planes, or "shells," on top of each other to simulate the appearance and depth of foliage. Each shell contributes to the overall look, mimicking the natural variation in grass blades. This technique is particularly efficient for rendering grass and fur in real-time applications like video games, providing a visually rich environment with less computational cost.


User can navigate in the scene using these keyboard inputs:
- `W` to move forward
- `A` to move left
- `S` to move backward
- `D` to move right
- `Z` to increase the number of shells
- `X` to decrease the number of shells
- `C` to increase the spacing between the shells
- `V` to decrease the spacing between the shells

User can also rotate the plane along its x and y axes by dragging the mouse.

## Getting Started

### Dependencies

* OpenGL 4.5 via GLAD
* GLFW
* GLM

### Building

To generate a debug build:

```
cmake --preset debug -G <your generator of choice e.g "Ninja">
```

To generate a release build:

```
cmake --preset release -G <your generator of choice e.g "Ninja">
```

After generation, navigate into build/debug or build/release. There you can find your build files (depending on which cmake generator you provided). The executable target is called shell
