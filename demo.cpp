#include "demo.h"


///*************************
//int main(int argc,char** argv)
//{
//cv::Mat src;
//src = cv::imread(_filePath);//image path
//
//corners[0]=cv::Point();
//
//cv::namedWindow("show1_src",CV_WINDOW_AUTOSIZE);
//cv::setMouseCallback("show1_src", mouse_callback);
//
//
///*******************获取源投影点*************/
//while ((cv::waitKey(10) & 255) != 'q')
//{
//	cv::Mat show1 = src.clone();
//
//	for (size_t i = 0; i <4; i++)
//	{
//		cv::circle(show1, corners[i], 5, cv::Scalar(0, 255, 0), 3);
//	}
//	cv::imshow("show1_src", show1);
//}
//
//
//cv::namedWindow("show1_dst", CV_WINDOW_AUTOSIZE);
//cv::setMouseCallback("show1_dst", mouse_callback);
//float roi_x0 = 0;
//float roi_y0 = 0;
//
//float IPM_WIDTH = 800;
//float N = 5;
////保证逆透视图的宽度大概为N个车头宽
//float IPM_HEIGHT = 500;
////逆透视图初始化
//corners_trans[0] = cv::Point2f(IPM_WIDTH / 2 - IPM_WIDTH / (2 * N), IPM_HEIGHT);   //P1 
//corners_trans[1] = cv::Point2f(IPM_WIDTH / 2 - IPM_WIDTH / (2 * N), 0);  //P2
//corners_trans[2] = cv::Point2f(IPM_WIDTH / 2 + IPM_WIDTH / (2 * N), 0);  //P3
//corners_trans[3] = cv::Point2f(IPM_WIDTH / 2 + IPM_WIDTH / (2 * N), IPM_HEIGHT);   //P4
//
//
//cv::Mat dst;
//dst = cv::Mat::zeros(IPM_HEIGHT + 50, IPM_WIDTH, src.type());
//while (true)
//{
//	int key = cv::waitKey(10);
//	if ((key & 255) == 'w')
//	{
//		for (size_t i = 0; i <4; i++)
//		{
//			corners_trans[i].y -= 10;
//		}
//		std::cout << "W" << corners_trans;
//	}
//	else if ((key & 255) == 's')
//	{
//		for (size_t i = 0; i <4; i++)
//		{
//			corners_trans[i].y += 10;
//		}
//		std::cout << "S" << corners_trans;
//	}
//	else if ((key & 255) == 'a')
//	{
//		for (size_t i = 0; i <4; i++)
//		{
//			corners_trans[i].x -= 10;
//		}
//		std::cout << "A" << corners_trans;
//	}
//	else if ((key & 255) == 'd')
//	{
//		for (size_t i = 0; i <4; i++)
//		{
//			corners_trans[i].x += 10;
//		}
//		std::cout << "D" << corners_trans;
//	}
//	else if ((key & 255) == 'q')
//	{
//		corners_trans[1].x -= 10;
//		corners_trans[2].x -= 10;
//		std::cout << "Q" << corners_trans;
//	}
//	else if ((key & 255) == 'e')
//	{
//
//		corners_trans[1].x += 10;
//		corners_trans[2].x += 10;
//		std::cout << "E:";
//
//		for (size_t i = 0; i <4; i++)
//		{
//			std::cout << corners_trans[i] << "\t";
//		}
//
//	}
//	else if (key == 27)
//	{
//
//	}
//	cv::Mat M = cv::getPerspectiveTransform(corners, corners_trans);
//	cv::warpPerspective(src, dst, M, dst.size());
//
//	cv::imshow("dst", dst);
//	cv::FileStorage fs("biaoding.xml", cv::FileStorage::WRITE);
//
//	fs << "src" << "{" << "point1" << corners[0] << "point2" << corners[1] << "point3" << corners[2] << "point4" << corners[3] << "}";
//	fs << "dst" << "{" << "point1" << corners[0] << "point2" << corners[1] << "point3" << corners[2] << "point4" << corners[3] << "}";
//	fs.release();
//
//}
//
//
//return 0;
//}
//
//
//**********************/


extern "C" int demo(std::string _filePath)
{
	cv::Mat src;
	src = cv::imread(_filePath);
	
	corners[0]=cv::Point();

	cv::namedWindow("show1_src",CV_WINDOW_AUTOSIZE);
	cv::setMouseCallback("show1_src", mouse_callback);
	/********************获取源投影点*************/
	while ((cv::waitKey(10)&255)!='q')
	{
		cv::Mat show1= src.clone();
		
		for (size_t i = 0; i <4; i++)
		{
			cv::circle(show1, corners[i],5,cv::Scalar(0,255,0),3);
		}
		cv::imshow("show1_src",show1);
	}


	cv::namedWindow("show1_dst", CV_WINDOW_AUTOSIZE);
	cv::setMouseCallback("show1_dst", mouse_callback);
	float roi_x0 = 0;
	float roi_y0 = 0;

	float IPM_WIDTH =800;
	float N = 5;
	//保证逆透视图的宽度大概为N个车头宽
	float IPM_HEIGHT =500;
	//逆透视图初始化
	corners_trans[0] = cv::Point2f(IPM_WIDTH / 2 - IPM_WIDTH / (2 * N), IPM_HEIGHT);   //P1 
	corners_trans[1] = cv::Point2f(IPM_WIDTH / 2 - IPM_WIDTH / (2 * N), 0);  //P2
	corners_trans[2] =	cv::Point2f(IPM_WIDTH / 2 + IPM_WIDTH / (2 * N), 0);  //P3
	corners_trans[3] = cv::Point2f(IPM_WIDTH / 2 + IPM_WIDTH / (2 * N), IPM_HEIGHT);   //P4

	
	cv::Mat dst;
	dst = cv::Mat::zeros(IPM_HEIGHT + 50, IPM_WIDTH, src.type());
	while (true)
	{
		int key = cv::waitKey(10);
		if ((key&255) == 'w')
		{
			for (size_t i = 0; i <4; i++)
			{
				corners_trans[i].y-=10;
			}
			std::cout <<"W" <<corners_trans;
		}
		else if ((key & 255) == 's')
		{
			for (size_t i = 0; i <4; i++)
			{
				corners_trans[i].y +=10;
			}
			std::cout << "S"<<corners_trans;
		}
		else if ((key & 255) =='a')
		{
			for (size_t i = 0; i <4; i++)
			{
				corners_trans[i].x-= 10;
			}
			std::cout << "A"<<corners_trans;
		}
		else if ((key & 255) == 'd')
		{
			for (size_t i = 0; i <4; i++)
			{
				corners_trans[i].x += 10;
			}
			std::cout <<"D"<< corners_trans;
		}
		else if ((key & 255) == 'q')
		{
			corners_trans[1].x -= 10;
			corners_trans[2].x -= 10;
			std::cout << "Q" << corners_trans;
		}
		else if ((key & 255) == 'e')
		{
			
			corners_trans[1].x += 10;
			corners_trans[2].x += 10;
			std::cout << "E:";
			
			for (size_t i = 0; i <4; i++)
			{
				std::cout<<corners_trans[i]<<"\t";
			}
			
		}
		else if (key==27)
		{

		}
		cv::Mat M = cv::getPerspectiveTransform(corners, corners_trans);
		cv::warpPerspective(src,dst,M, dst.size());
	
		cv::imshow("dst",dst);
		cv::FileStorage fs("biaoding.xml",cv::FileStorage::WRITE);
		
		fs<<"src"<<"{"<<"point1" <<corners[0]<<"point2"<< corners[1] <<"point3"<< corners[2] << "point4" << corners[3] <<"}";
		fs << "dst" << "{" << "point1" << corners[0] << "point2" << corners[1] << "point3" << corners[2] << "point4" << corners[3] << "}";
		fs.release();

	}
	

	return 0;
}

void mouse_callback(int event, int x, int y, int flags, void * param)
{
	static int i = 0;
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		corners[i++] = cv::Point(x,y);
		break;
	default:
		break;
	}


}
