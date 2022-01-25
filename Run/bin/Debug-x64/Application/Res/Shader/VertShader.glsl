 #version 460 core

 layout (location = 0) in vec3 aPos;
 layout (location = 1) in vec2 aTexCoord;

 out vec2 TexCoord;

 uniform mat4 model;
 uniform mat4 view;
 uniform mat4 projection;

 void main()
 {
    mat4 pvm = projection * view * model;
    gl_Position = pvm * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    TexCoord = aTexCoord;
 }