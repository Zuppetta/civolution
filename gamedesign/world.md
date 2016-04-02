# World Generation

In order to create a world that make sense, we will need to use a fractal world creation.
The idea is to create the world by going from a coarse mesh to a very fine one and at each step adding some new possible element.
For exemple at the beginning, we are using a voronoi diagram in order to define water/earth, then we work on a hex made of 7 smallest hex in order to define the forest, desert, mountains, ...
The last step consists in adding the strategic ressources.

This code should be done in c++ in order to make it fast.

The idea of the voronoi diagram is to choose randomly some points and attributing the value earth or sea, then at each position, the value is attributed by the closest voronoi point.

The way to create the thinnest layer is to use a simplex noise.
The rivers should be created at the end of the process.

List of Possible Ressources
---------------------------

- Thermal (volcano)
- Solar
- Food
- Productivity
- Technology
- Religion
- Money
- Iron
- Oil
- Uranium
- Anti-matter
