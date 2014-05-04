g++ -c src/*.cpp res/*.bmp shaders/*.* -std=c++11 -I /usr/include/SDL2 -I /usr/include/GL -I ./include 
g++ *.o Game -o -l SDL2 -l GL -l GLU -l GLEW