# Orbit Simulator

A C++ simulation of satellites orbiting Earth, featuring realistic orbital mechanics, collisions, and satellite fragmentation.

## Overview

The Orbit Simulator allows users to control a spacecraft while navigating through various satellites in Earth's orbit. The simulation includes multiple types of satellites with realistic orbital mechanics and collision detection.

## Features

- **Multiple Satellite Types**
  - Crew Dragon
  - GPS Satellites
  - Hubble Space Telescope
  - Starlink
  - Sputnik
  - Player-controlled Spacecraft

- **Realistic Physics**
  - Orbital mechanics
  - Gravity simulation
  - Velocity and acceleration calculations
  - Collision detection

- **Destruction System**
  - Satellites break into realistic fragments upon collision
  - Different satellite types break into unique component parts
  - Fragment trajectory simulation

- **Interactive Controls**
  - Control spacecraft movement
  - Fire projectiles
  - Reset simulation

## Technical Details

### Core Components

- **Satellite Base Class**: Provides common functionality for all orbital objects
- **Part System**: Handles satellite components and fragmentation
- **Physics Engine**: Manages orbital mechanics and collisions
- **OpenGL Graphics**: Renders the simulation visually

### Key Classes

- `Demo`: Main simulation controller
- `Satellite`: Base class for all orbital objects
- `Part`: Base class for satellite components
- `Fragment`: Handles debris physics
- `Position`, `Velocity`, `Acceleration`: Physics calculation classes

## Building and Running

1. Ensure you have a C++ compiler and OpenGL dependencies installed
2. Build using your preferred build system
3. Run the executable
4. Use keyboard controls to navigate the spacecraft

## Testing

The project includes comprehensive unit tests for all major components:
- Position and velocity calculations
- Collision detection
- Satellite behavior
- Fragment generation
- Physics calculations

## Contributors

- Nathan Bird
- Jared Davey
- Brock Hoskins

## License

This project is provided as-is for educational purposes.