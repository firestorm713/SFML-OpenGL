# Firestorm713's Implementation of a Component-Based 3D Game Engine
This project is basically to help me understand how both OpenGL works, and to better understand C++, object oriented programming, and component-based, data oriented design. I'm working off of the Modern OpenGL Tutorials ( http://ogldev.atspace.co.uk/ ) and http://open.gl for the OpenGL, but don't expect my code to look much like theirs, since I'm adapting it into a more object oriented paradigm. I'm using the Simple and Fast Multimedia Library (http://www.sfml-dev.org/) for my OpenGL context, and for handling everything that isn't graphics. The Component Based Design is based on the outline found in the blog entry Cowboy Programming: Evolve Your Hierarchy (http://cowboyprogramming.com/2007/01/05/evolve-your-heirachy/ ). 
My end goals are to play around with several advanced real-time rendering concepts:
* Water Simulation Algorithms ( http://graphics.ucsd.edu/courses/rendering/2005/jdewall/tessendorf.pdf )( http://cemyuksel.com/research/waveparticles/ )( http://dice.se/wp-content/uploads/water-interaction-ottosson_bjorn.pdf )
* Screen-Space Reflections and Shadows ( http://www.gamedev.net/blog/1323/entry-2254101-real-time-local-reflections/ )
* Marching Cubes, Dual Contouring, Metaballs( http://paulbourke.net/geometry/polygonise/ )( http://www.cs.rice.edu/~jwarren/papers/dualcontour.pdf )( http://www.geisswerks.com/ryan/BLOBS/blobs.html )

For now, I'm still programming in a lot of basic stuff, and it won't be until later that I actually start putting things into components, as right now I'm still getting this to the point where it's an actual engine, rather than just a super-basic triangle renderer.