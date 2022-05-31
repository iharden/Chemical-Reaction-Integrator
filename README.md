# Chemical-Reaction-Integrator
A GUI tool for for the simulation of reaction kinetics

## Description

The program provides a graphical user interface for the computation of reaction kinetics. 
In molecular chemistry the reaction rates are governed by the activation barriers of the corresponding forward and backward reactions. Mathematically, the connection between the concentration $c$ of a species $A$ and the reaction speed is given by a differential equation, e.g.
$$\frac{dc_A(t)}{dt} = -k \cdot c_A(t)^2$$
$k$ is the rate constant and can be obtained from experiment or quantumchemical calculations.
For a more complicated reaction system the individual concenctrations are coupled to each other, leading to a set of coupled ordinary differential equations (ODE). Please look at the following reaction equation system:
$$ 2A \rightarrow B, k_1 $$
$$ B + A \rightarrow C, k_2  $$
The differential equations for this system are:
$$ \frac{dc_A(t)}{dt} = -k_1 \cdot c_A(t)^2 - k_2 \cdot c_A(t) \cdot c_B(t) $$
$$ \frac{dc_B(t)}{dt} = k_1 \cdot c_A(t)^2 - k_2 \cdot c_A(t) \cdot c_B(t) $$
$$ \frac{dc_C(t)}{dt} = k_2 \cdot c_A(t) \cdot c_B(t) $$
In order to obtain the indiviual concentration profile, this ODE system must be integrated numerically, given some initial concentrations $c_{A0}, c_{B0}, c_{C0} $.
For a given system of reaction equations, rate constants and initial concentrations the program numerically integrates the ODE system and produces a plot of the species concentrations as a function of time.

The rate constants can be measured in experiment. Alternatively, they can be calculated from the activation energies, which on the other hand can be obtained from quantumchemical calculations (see for example Eyring equation (https://en.wikipedia.org/wiki/Eyring_equation)).

For a detailed description of how the program works and how you can use it properly see the next section.

## Usage
tbd

## Requirements

Precompiled binaries for Ubuntu and Windows 10 are available and can be used right away. The binaries are dynamically linked to a couple of libraries, which are provided together with the executable. It is therefore suggested to just Download the corresponding directory (Windows/ or Ubuntu/). Within the directory the executable can be used without further installations.
The program makes use of a couple of third-party libraries, which are needed in order to compile the source code from scratch:

Qt (https://www.qt.io/?hsLang=en): Creation of the GUI.

QCustomPlot (https://www.qcustomplot.com/): Creation of nice looking Scatter plots within the Qt framework. Header and source file are provided in src/

Boost (https://www.boost.org/): Provides the Rosenbrock solver used to integrate the ODE system. Header-only

JSON for modern c++ (https://github.com/nlohmann/json): Easy usage of the json file format. Header-only

## Contributor

contributed by Ingolf Harden
