Auto Layout Algorithm
Noah Pan

References:
STL Formating Info
https://all3dp.com/what-is-stl-file-format-extension-3d-printing/
Bin Packing Algorithm
http://blackpawn.com/texts/lightmaps/default.html
https://codeincomplete.com/posts/bin-packing/

Summary of Code:
1) Take in a series of models and parse them to extact the width and length details. 
2) Models are sorted according to the max(width, length)
3) Call Buildplatform object
4) Take in each model and place each one on the buildplatform creating a tree structure
5) Function that inserts node into tree is called recursively to divide the buildplatform into smaller rectangular sections. (see design notes)


Design Notes:
-A previous algorithm can be implemented before the packing algorithm to orient the model in it's optimal printing orientation. This algorithm would first look for the largest collection of triangles that are parallel. The area with the largest surface area would be the surface that would stick the best to the build surface.
-Another method of model orientation would be to calculate the orientation with the least amount of overhangs (angles greater than 45 degrees).
-The tree structure would be created based on keeping the total model width and length as square as possible.


Assumptions:
Binary STL file used
Models are orieted in the optimal printing orientation


File Structure:
Buildplatform.h -> Node.h -> Model.h -> Triangle.h -> Point.h
						  \->Rectangle2D.h



Directions for Compliation:
Compile with: g++ -Wall -o Makefile.exe main.cpp Triangle.cpp Point.cpp Model.cpp Buildplatform.cpp Rectangle2D.cpp Node.cpp

Running output file:
./Makefile.exe