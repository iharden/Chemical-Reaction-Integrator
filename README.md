# Chemical-Reaction-Integrator
A GUI tool for for the simulation of reaction kinetics

## Description

The program provides a graphical user interface for the computation of reaction kinetics. 
In molecular chemistry, the reaction rates are governed by the activation barriers of the corresponding forward and backward reactions. Mathematically, the connection between the concentration $c$ of a species $A$ and the reaction speed is given by a differential equation, e.g.
$$\frac{dc_A(t)}{dt} = -k \cdot c_A(t)^2$$
$k$ is the rate constant and can be obtained from experiment or quantumchemical calculations.
For a more complicated reaction system, the individual concenctrations are coupled to each other leading to a set of coupled ordinary differential equations (ODE). Please look at the following reaction equation system:
$$2A \rightarrow B, k_1$$
$$B + A \rightarrow C, k_2$$
The differential equations for this system are:
$$\frac{dc_A(t)}{dt} = -k_1 \cdot c_A(t)^2 - k_2 \cdot c_A(t) \cdot c_B(t)$$
$$\frac{dc_B(t)}{dt} = k_1 \cdot c_A(t)^2 - k_2 \cdot c_A(t) \cdot c_B(t)$$
$$\frac{dc_C(t)}{dt} = k_2 \cdot c_A(t) \cdot c_B(t)$$
In order to obtain the indiviual concentration profile, this ODE system must be integrated numerically, given some initial concentrations $c_{A0}, c_{B0}, c_{C0}$.
For a given system of reaction equations, rate constants and initial concentrations, the program numerically integrates the ODE system and produces a plot of the species' concentrations as a function of time.

The rate constants can be measured in experiment. Alternatively, they can be calculated from the activation energies which in turn can be obtained from quantumchemical calculations (see for example Eyring equation (https://en.wikipedia.org/wiki/Eyring_equation)).

For a description of how the program works and how you can use it properly, see the next section.

## Usage
Here we describe the main featues of the program. The basic idea is that in the first step the user provides the necessary information. That is the reaction equation system, the temperature and the reaction rates (or the activation energies). For this, the user can use the following text fields:

![](Figures/snapshot_2.png?raw=true "Title")

The left column is mandatory and takes the reaction equation. We strongly advise to stick to simple letters for your system. In any case, your identifier for a species is not allowed to contain numbers. As delimiter between reactands and products, you have to use "->". Individual species are seperated by "+".
Examples:

$A + 3B + C -> D +E$ Okay, species are $A, B, C, D, E$

$AX + 2DF -> A + D$ Okay, species are $AX, DF, A, D$

$2 CH3OH -> CH3OCH3 + H2O$ Not okay, specifiers include numbers!

The middle column is mandatory as well and specifies the reaction rate (or activation energy) of the forward reaction. The right column is optional and specifies the reaction rate (or activation energy) of the back reaction. An example of how this window could look like is:

![](Figures/snapshot_3.png?raw=true "Title")

After specifying your system hit the "read in system" button. This will check how many different species are present and will create another set of text fields in which you can specify in initial concentration of the individual species. For example:

![](Figures/snapshot_4.png?raw=true "Title")

Afterwards just click "Calculate" and the concentration profiles are computed!

A plot is generated with the concentration profiles of all the species. For a quick overview, there is the possibility to use logarithmic x- and y-axes instead of linear scaling. The image and the raw data can easily be exported.


![](Figures/snapshot_5.png?raw=true "Title")

One last important feature: It is possible to safe and load the current state via the `save` and `load` buttons:


![](Figures/snapshot_6.png?raw=true "Title")

As file format we use `.chemsys` which is just a text file containing all the reaction equations, barriers, initial concentrations and settings.

The final overview of the window:

![](Figures/snapshot_7.png?raw=true "Title")


## Requirements

Precompiled binary for Windows is available and can be used right away. The binaries are dynamically linked to a couple of libraries which are provided together with the executable. It is therefore suggested to just download the corresponding directory (Windows/ or Ubuntu/). 
The program makes use of a couple of third-party libraries, which are needed in order to compile the source code from scratch:

Qt (https://www.qt.io/?hsLang=en): Creation of the GUI.

Boost (https://www.boost.org/): Provides the Rosenbrock solver used to integrate the ODE system. Header-only

JSON for modern c++ (https://github.com/nlohmann/json): Easy usage of the json file format. Header-only

## Contributor

contributed by Ingolf Harden

## License

Chemical-Reaction-Integrator is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Chemical-Reaction-Integrator is distributed in the hope that it will be useful, but without any warranty; without even the implied warranty of merchantability or fitness for a particular purpose. See the GNU Lesser General Public License for more details.

Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in Chemical-Reaction-Integrator by you, as defined in the GNU Lesser General Public license, shall be licensed as above, without any additional terms or conditions
