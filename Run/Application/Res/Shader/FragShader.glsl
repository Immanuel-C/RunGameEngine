#version 460 core

vec4 color;

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D myTexture;
void main()
{
	color = texture(myTexture, TexCoord);

	if (color.a < 1.0)
	{
		discard;
	}

	FragColor = color;
}