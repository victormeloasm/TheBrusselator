# Brusselator Solver

This repository contains a C program that numerically solves the Brusselator system using the 4th-order Runge-Kutta method. The Brusselator is a mathematical model that describes a simplified version of a chemical reaction. This README provides an overview of the Brusselator system, the numerical method used for solving it, and how to run the program.

## Brusselator System

The Brusselator is a two-variable system of ordinary differential equations that models an autocatalytic reaction. It was introduced by Ilya Prigogine and Robert Lefever in 1968. The system is named after the city of Brussels, where Prigogine conducted much of his research.

The Brusselator equations describe the time evolution of the concentrations of two reactants, denoted as x and y. The equations are given by:

dx/dt = A + x^2 * y - (B+1) * x
dy/dt = B * x - x^2 * y

In these equations, x represents the concentration of the "activator," and y represents the concentration of the "inhibitor." The parameters A and B control the behavior of the system. The Brusselator exhibits interesting dynamics, including the formation of spatial and temporal patterns.

## Numerical Method: 4th-Order Runge-Kutta

To solve the Brusselator system numerically, we use the 4th-order Runge-Kutta method. The Runge-Kutta methods are a class of numerical integration techniques that approximate the solution of ordinary differential equations. The 4th-order Runge-Kutta method is a widely used and accurate method for solving such systems.

The 4th-order Runge-Kutta method involves evaluating several intermediate stages (k1, k2, k3, k4) to estimate the derivative at different points within a time step. These intermediate stages are then combined to update the solution for the next time step. The method provides a good balance between accuracy and computational efficiency.

## How to Run the Program

To run the Brusselator solver program, follow these steps:

1. Ensure you have a C compiler installed on your system (e.g., GCC).
2. Clone this repository or download the source code file (`brusselator.c`).
3. Open a terminal or command prompt and navigate to the directory containing the source code file.
4. Compile the program using the following command:
   ```
   gcc -o brusselator brusselator.c
   ```
5. Run the compiled program with the following command:
   ```
   ./brusselator
   ```

The program will solve the Brusselator system numerically and print the values of x and y at different time points. By default, the program solves the system from time 0 to 100, using the initial conditions x = 1.2 and y = 3.1. You can modify the initial conditions, parameters (A and B), time range, and other settings directly in the source code.

Feel free to experiment with different parameter values, initial conditions, and time step sizes to observe the behavior of the Brusselator system.

## License

This project is licensed under the MIT License. Feel free to use and modify the code for your own purposes.

This project was based in the paper https://analogparadigm.com/downloads/alpaca_40.pdf from Professor Phd. [@bernd-Ulmann.](https://github.com/bernd-ulmann)


