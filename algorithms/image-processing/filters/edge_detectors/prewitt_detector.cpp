void prewittEdgeDetection(Mat & image, const unsigned char threshold)
{
        vector xKernel = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

        vector yKernel = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }; 

	edgeDetection(image, xKernel, yKernel);

	image = image > threshold;
}
