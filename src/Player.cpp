#include "Player.h"

void Player::drawPlayer(int size){
	static const GLfloat g_vertex_buffer_data[] = {
		-size, -size, -size, -size, -size, size, -size, size, size,
		size, size, -size, -size, -size, -size, -size, size, -size,
		size, -size, size, -size, -size, -size, size, -size, -size,

		size, size, -size, size, -size, -size, -size, -size, -size,
		-size, -size, -size, -size, size, size, -size, size, -size,
		size, -size, size, -size, -size, size, -size, -size, -size,

		-size, size, size, -size, -size, size, size, -size, size,
		size, size, size, size, -size, -size, size, size, -size,
		size, -size, -size, size, size, size, size, -size, size,

		size, size, size, size, size, -size, -size, size, -size,
		size, size, size, -size, size, -size, -size, size, size,
		size, size, size, -size, size, size, size, -size, size
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

}