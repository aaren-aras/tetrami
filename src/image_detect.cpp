#include "image_detect.h"
#include <fstream>

static bool isDicom(const std::string& path)
{
	std::ifstream file(path, std::ios::binary);
	if (!file)
		return false;

	file.seekg(128);
	char magic[4];
	file.read(magic, 4);

	return std::string(magic, 4) == "DICM";
}

static bool isNifti(const std::string& path)
{
	return path.ends_with(".nii") || path.ends_with(".nii.gz");
}

ImageType detectImageType(const std::string& path)
{
	if (isNifti(path))
		return ImageType::NIFTI;

	if (isDicom(path))
		return ImageType::DICOM;

	return ImageType::UNKNOWN;
}

const char* imageTypeToString(ImageType type)
{
	switch (type)
	{
	case ImageType::DICOM: return "DICOM";
	case ImageType::NIFTI: return "NIfTI";
	default: return "UNKNOWN";
	}
}
