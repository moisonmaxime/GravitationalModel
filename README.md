# GravitationalModel
C++ implementation of gravity between bodies (i.e. planets, stars, moons...)

- ```Universe``` represent an object containing all the bodies for which you want to simulate physics.
- ```Body``` represent an object for which you want to simulate physics.
- ```Vector3d``` represent a 3d vector to simplify 3d physics calculations.

_Explanation_<br>
This works frame by frame with a given precision. 
Each frame, each body's acceleration is calculated by applying the force from all other bodies. 
It then calculates the velocity and position vectors of the object in the next frame.
