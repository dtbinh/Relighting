#ifndef UTILS_H
#define UTILS_H
#include "common.h"


void CreateCubemap(int face_index, int x, int y, int cubemap_length, std::vector<cv::Mat>& cubeface);
int subPixelF(cv::Vec3f& color, const cv::Mat& image, float x, float y);
int ConvertCubemapToLightProbe(cv::Mat& light_probe, const std::vector<cv::Mat>& cubemap, const cv::Size light_probe_size);
int saveAsCrossHorEnv(const std::string& filename, const std::vector<cv::Mat>& cvEnvs);
cv::Vec3d CubeLightDirection(double u, double v, int face_index);
/// <summary>
/// A progress bar used to show current progress.
/// </summary>
/// <param name="curr">Current progress.</param>
/// <param name="total">Total number of steps.</param>
inline void UpdateProgressBar(int curr, int total, int step_size){
	curr = curr + 1;
	if (curr < total && curr % step_size != 0){
		return;
	}
	double progress = curr / (double)(total - 1);
	int barWidth = 70;
	std::cout << "[";
	int pos = (int)(barWidth * progress);
	for (int i = 0; i < barWidth; ++i) {
		if (i < pos) std::cout << "=";
		else if (i == pos) std::cout << ">";
		else std::cout << " ";
	}
	if (curr != total){
		std::cout << "] " << int(progress * 100.0) << " %\r";
		std::cout.flush();
	}
	else{
		std::cout << "] " << int(progress * 100.0) << " %" << std::endl;
	}
}

float GetSHValue(const cv::Vec3f& dir, int sh_index);
void CreateSHCubemap(int cubemap_length, int sh_index, std::vector<cv::Mat>& cubeface);
void SaveSHBasisImage(int cubemap_length, int sh_index, const cv::Size& probe_size, const char* file_name);
#endif