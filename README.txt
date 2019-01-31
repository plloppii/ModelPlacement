Toolpather Software Engineer Coding Challenge
Noah Pan

Resources:
STL Formating Info
https://all3dp.com/what-is-stl-file-format-extension-3d-printing/
STL Parser Example
/home/noah/Documents/ModelPlacement/stlparser/3DBenchy.stl

Goal:


Design Considerations:

A previous algorithm can be implemented before the packing algorithm to orient the model in it's optimal printing orientation. This algorithm would first look for the largest collection of triangles that are parallel. The area with the largest surface area would be the surface that would stick the best to the build surface.
Another method of model orientation would be to calculate the orientation with the least amount of overhangs (angles greater than 45 degrees).


Assumptions:
Binary STL file used
Models are orieted in the optimal printing orientation



Directions for Compliation:


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 25-35 hours >



DESCRIPTION OF YOUR CREATIVE STATISTIC:
