#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class texture
{
public:
	unsigned int id;
	int w;
	int h;
	texture() {}
	texture(std::string path);
	void activate(int);
};

#endif
