#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <sys/stat.h>
#include <SFML/Graphics.hpp>

namespace fs = std::filesystem;

#include "gameOfLife.h"
#include "file.h"
#include "grid.h"
#include "cell.h"
#include "view.h"
#include "iteration.h"