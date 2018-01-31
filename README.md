# Object Transformation and Texture Mapping

#### CS411 - Computer Graphics Course

#### Assignment 4
This is an assigment which requires student to render the 3D objects (cone, cube, hyperboloid, paraboloid, sphere, torus, circle, cylinder), do the transformation between coordinate spaces and map the texture to each object. 



## Implementation Details

### 1. Drawing Objects

A good way to begin drawing 3D objects is rendering the meshes. These meshes can be obtained through the parametric equations. Simply by iterating the parameter, we can get the mesh's points and connect the points to form a mesh. The more we split the meshes (draw more meshes), the smoother the object is. 



![MeshImg](/Screenshots/meshimg.PNG)



### 2. Transforming Objects

The rendered objects are currently located at their local space. In order to see these objects, we need to transform it into the world space (model transformation). Also, we can make the object rotate around by using the *glRotatef()* function after transforming the object into world space, along with a *timer()* function to handle the rotate rate.



### 3. Mapping the Textures

The rendered object can be fill up with texture. This can be done thanks to [SOIL](http://www.lonesock.net/soil.html) (Simple OpenGL Image Library). It provides some functionalities for loading and mapping the texture to the objects.



There are multiple way to map the texture to object. One simple approach could be loading the entire texture to each mesh. But for a better visualization, my approach is spliting the texture into cells. The number of cells will be the same as the number of meshes. And finally perform the mapping each cell to the corresponding mesh. 



![TextureMapImg](/Screenshots/texturemapimg.PNG)

