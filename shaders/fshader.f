#version 330

in vec4 theColour;
in vec2 theTexture; 

uniform sampler2D texture;
void main()
{
	gl_FragColor = texture2D(texture, theTexture.st * vec2(1.0, -1.0))* theColour;
}