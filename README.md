# Simul8
Fun simulations in raylib using C++  

This repo contains two exciting simulations:  
1. Solar System: A dynamic solar system with planets and moons that orbit.
   - solarsystem.cpp
2. Random Walker: A simple, fun simulation where a pixel takes random steps across the screen.
   - random_walker.cpp

## Prerequisites      
- C++ compiler: To compile and run the code

## How to run   
To build and run for 
- Solar system simulaion:  
  `g++ src/solarsystem.cpp -Ideps/raylib/include/ -Ldeps/raylib/lib -lraylib -lgdi32 -lwinmm`
  
- Random walker simulation:  
  `g++ src/random_walker.cpp -Ideps/raylib/include/ -Ldeps/raylib/lib -lraylib -lgdi32 -lwinmm`










