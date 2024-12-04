#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <chrono>
#include <filesystem>
#include <stdexcept>
#include <sys/stat.h>

namespace fs = std::filesystem;

#include "gameOfLife.h"
#include "file.h"
#include "grid.h"
#include "cell.h"
#include "view.h"
#include "iteration.h"