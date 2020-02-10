#ifndef scan_zip_h
#define scan_zip_h

namespace cv
{
	class Mat;
}

bool save_scanzip(const cv::Mat& position, const cv::Mat& color, const cv::Mat& flags, const cv::Mat& depth, const char* zip_file);
bool load_scanzip(cv::Mat& position, cv::Mat& color, cv::Mat& flags, cv::Mat& depth, const char* zip_file);

//zip_file �򿪻򱣴���ļ�������չ��.zip��������ǣ�ʵ�ֻ�����.zip
//position ��������, ��zip�ĵ��б���Ϊposition.yml, Mat��Ԫ�ظ�ʽ�� CV_32FC3 
//color    ������ɫ����zip�ĵ��б���Ϊcolor.bmp����ɫͼƬMatԪ�ظ�ʽ�� CV_8UC3 �� CV_8UC4�� �Ұ�ͼƬMatԪ�ظ�ʽ�� CV_8UC1
//flags    ��־����zip�ĵ��б���Ϊflags.bmp�� Mat��Ԫ�ظ�ʽ�� CV_8UC1
//depth    ���ͼ����zip�ĵ��б���Ϊdepth.bmp��Mat��Ԫ�ظ�ʽ�� CV_8UC1

//���صĹ�����Ҫ����δ��ʼ������ӦMat������ļ����سɹ������ݻ�����Ӧ��Mat

#endif // scan_zip_h