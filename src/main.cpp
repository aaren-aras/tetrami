#include <iostream>
#include "image_detect.h"

int main(int argc, char** argv)
{
	std::cout << "tetrami — medical imaging multitool\n";

	if (argc < 2)
	{
		std::cerr << "Usage: tetrami <image-file>\n";
		return 1;
	}

	std::string path = argv[1];
	ImageType type = detectImageType(path);

	std::cout << "Detected format: "
		<< imageTypeToString(type)
		<< std::endl;

	// next steps:
	// - load image
	// - dump metadata
	// - visualize
	// - convert
	// - segment

	return 0;
}
