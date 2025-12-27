#pragma once
#include <string>

enum class ImageType
{
	DICOM,
	NIFTI,
	UNKNOWN
};

ImageType detectImageType(const std::string& path);
const char* imageTypeToString(ImageType type);
