#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>

class shader
{
public:
	unsigned int id;
	shader(std::string vertPath, std::string fragpath);
	void activate();

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVector(const std::string& name, float* value) const;
};

#endif
