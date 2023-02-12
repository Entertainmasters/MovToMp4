#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <Windows.h>

namespace fs = std::filesystem;

int main() {
	// Video file ID to avoid duplicates
	int id = 1;

	// Collection of the files in the path
	std::vector<fs::path> files;
	std::string path;
	std::cout << "Enter file path: ";
	std::cin >> path;

	for (const auto& entry : fs::directory_iterator(path)) {
		std::cout << entry.path() << std::endl;
		files.push_back(entry.path());
	}

	Sleep(1000);

	for (const auto v : files) {

		std::string fileName = "Video" + std::to_string(id) + ".mp4";
		std::string currentFile = v.string();
		std::string cmd = "ffmpeg -i " + currentFile + " -qscale 0 " + path + "\\" + fileName;
		const char* Fcmd = cmd.c_str();

		system(Fcmd);

		id++;
	}
}