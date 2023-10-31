#pragma once
// Local small (not)stdafx file)
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <random>

#define WIDTH 1000
#define HEIGHT 600
#define PLATFORM_PADDING 65
#define PLATFORM_WIDTH 10
#define PLATFORM_HEIGHT 60
#define BALL_RADIUS 5

static float GetRandomFloat(float min, float max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(min, max);

	return dis(gen);
}