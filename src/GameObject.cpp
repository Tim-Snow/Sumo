#include "GameObject.h"

GameObject::GameObject(){
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(0, 0, 0), 1.0, 1.0, 1.0));
}

GameObject::~GameObject(){}

void GameObject::compileShaders(){

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	//get shader src
	vertShaderStr = ReadFile("vshader.v");
	fragShaderStr = ReadFile("fshader.f");

	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	//compile vertex shader
	glShaderSource(vertexShader, 1, &vertShaderSrc, NULL);
	glCompileShader(vertexShader);

	//compile fragment shader
	glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
	glCompileShader(fragShader);

	//link the program
	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);
}

bool GameObject::collidesWith(GameObject & a) {
	return bbox->collidesWith((*a.bbox));
}

void GameObject::draw(){

	glUseProgram(program);

	Vector4 tx = Camera::getInstance().getCameraM() * *(bbox->getCentre());
	float tx_unpacked[] = { tx.getX(), tx.getY(), tx.getZ(), tx.getW() };

	glUniform4fv(tx_uniform, 1, tx_unpacked);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glEnableVertexAttribArray(position_attrib);
	glEnableVertexAttribArray(colour_attrib);
	glVertexAttribPointer(position_attrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
	glVertexAttribPointer(colour_attrib, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glDrawElements(GL_TRIANGLES, 3 * this->num_triangles, GL_UNSIGNED_SHORT, (GLvoid*)0);

	glDisableVertexAttribArray(colour_attrib);
	glDisableVertexAttribArray(position_attrib);
}


string GameObject::ReadFile(const char* path) {
	string content;
	ifstream fileStream(path, ios::in);

	if (!fileStream.is_open()) {
		cerr << "File could not be opened" << endl;
		return "";
	}

	string line = "";
	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}

void GameObject::makeResources(){

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3f)* this->num_vertices, Vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &colourBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(RGBA)* this->num_vertices, Colours, GL_STATIC_DRAW);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(GLushort)* this->num_triangles, Indexes, GL_STATIC_DRAW);

	compileShaders();

	position_attrib = glGetAttribLocation(program, "position");
	colour_attrib = glGetAttribLocation(program, "colour");
	tx_uniform = glGetUniformLocation(program, "tx");
}