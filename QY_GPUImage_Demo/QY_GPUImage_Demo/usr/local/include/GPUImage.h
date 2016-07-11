#import "GLProgram.h"

// Base classes
#import "GPUImageContext.h"
#import "GPUImageOutput.h"
#import "GPUImageView.h"
#import "GPUImageVideoCamera.h"
#import "GPUImageStillCamera.h"
#import "GPUImageMovie.h"
#import "GPUImagePicture.h"
#import "GPUImageRawDataInput.h"
#import "GPUImageRawDataOutput.h"
#import "GPUImageMovieWriter.h"
#import "GPUImageFilterPipeline.h"
#import "GPUImageTextureOutput.h"
#import "GPUImageFilterGroup.h"
#import "GPUImageTextureInput.h"
#import "GPUImageUIElement.h"
#import "GPUImageBuffer.h"
#import "GPUImageFramebuffer.h"
#import "GPUImageFramebufferCache.h"

// Filters
#import "GPUImageFilter.h"
#import "GPUImageTwoInputFilter.h"
#import "GPUImagePixellateFilter.h"
#import "GPUImagePixellatePositionFilter.h"
#import "GPUImageSepiaFilter.h"  //褐色（怀旧）
#import "GPUImageColorInvertFilter.h" //反色
#import "GPUImageSaturationFilter.h" //饱和度
#import "GPUImageContrastFilter.h" //对比度
#import "GPUImageExposureFilter.h" //曝光
#import "GPUImageBrightnessFilter.h" //亮度
#import "GPUImageLevelsFilter.h" //色阶
#import "GPUImageSharpenFilter.h" //锐化
#import "GPUImageGammaFilter.h" //伽马线
#import "GPUImageSobelEdgeDetectionFilter.h"
#import "GPUImageSketchFilter.h"
#import "GPUImageToonFilter.h"
#import "GPUImageSmoothToonFilter.h"
#import "GPUImageMultiplyBlendFilter.h"
#import "GPUImageDissolveBlendFilter.h"
#import "GPUImageKuwaharaFilter.h"
#import "GPUImageKuwaharaRadius3Filter.h"
#import "GPUImageVignetteFilter.h"
#import "GPUImageGaussianBlurFilter.h"
#import "GPUImageGaussianBlurPositionFilter.h"
#import "GPUImageGaussianSelectiveBlurFilter.h"
#import "GPUImageOverlayBlendFilter.h"
#import "GPUImageDarkenBlendFilter.h"
#import "GPUImageLightenBlendFilter.h"
#import "GPUImageSwirlFilter.h"
#import "GPUImageSourceOverBlendFilter.h"
#import "GPUImageColorBurnBlendFilter.h"
#import "GPUImageColorDodgeBlendFilter.h"
#import "GPUImageScreenBlendFilter.h"
#import "GPUImageExclusionBlendFilter.h"
#import "GPUImageDifferenceBlendFilter.h"
#import "GPUImageSubtractBlendFilter.h"
#import "GPUImageHardLightBlendFilter.h"
#import "GPUImageSoftLightBlendFilter.h"
#import "GPUImageColorBlendFilter.h"
#import "GPUImageHueBlendFilter.h"
#import "GPUImageSaturationBlendFilter.h"
#import "GPUImageLuminosityBlendFilter.h"
#import "GPUImageCropFilter.h" //裁剪
#import "GPUImageGrayscaleFilter.h" //灰度
#import "GPUImageTransformFilter.h" //形状变换
#import "GPUImageChromaKeyBlendFilter.h"
#import "GPUImageHazeFilter.h"
#import "GPUImageLuminanceThresholdFilter.h"
#import "GPUImagePosterizeFilter.h"
#import "GPUImageBoxBlurFilter.h"
#import "GPUImageAdaptiveThresholdFilter.h"
#import "GPUImageSolarizeFilter.h"
#import "GPUImageUnsharpMaskFilter.h" //反遮罩锐化
#import "GPUImageBulgeDistortionFilter.h"
#import "GPUImagePinchDistortionFilter.h"
#import "GPUImageCrosshatchFilter.h"
#import "GPUImageCGAColorspaceFilter.h"
#import "GPUImagePolarPixellateFilter.h"
#import "GPUImageStretchDistortionFilter.h"
#import "GPUImagePerlinNoiseFilter.h"
#import "GPUImageJFAVoronoiFilter.h"
#import "GPUImageVoronoiConsumerFilter.h"
#import "GPUImageMosaicFilter.h"
#import "GPUImageTiltShiftFilter.h"
#import "GPUImage3x3ConvolutionFilter.h"
#import "GPUImageEmbossFilter.h"
#import "GPUImageCannyEdgeDetectionFilter.h"
#import "GPUImageThresholdEdgeDetectionFilter.h"
#import "GPUImageMaskFilter.h"
#import "GPUImageHistogramFilter.h" //色彩直方图，显示在图片上
#import "GPUImageHistogramGenerator.h" //色彩直方图
#import "GPUImageHistogramEqualizationFilter.h"
#import "GPUImagePrewittEdgeDetectionFilter.h"
#import "GPUImageXYDerivativeFilter.h"
#import "GPUImageHarrisCornerDetectionFilter.h"
#import "GPUImageAlphaBlendFilter.h"
#import "GPUImageNormalBlendFilter.h"
#import "GPUImageNonMaximumSuppressionFilter.h"
#import "GPUImageRGBFilter.h" //rgb
#import "GPUImageMedianFilter.h"
#import "GPUImageBilateralFilter.h"
#import "GPUImageCrosshairGenerator.h" //十字
#import "GPUImageToneCurveFilter.h" //色调曲线
#import "GPUImageNobleCornerDetectionFilter.h"
#import "GPUImageShiTomasiFeatureDetectionFilter.h"
#import "GPUImageErosionFilter.h"
#import "GPUImageRGBErosionFilter.h"
#import "GPUImageDilationFilter.h"
#import "GPUImageRGBDilationFilter.h"
#import "GPUImageOpeningFilter.h"
#import "GPUImageRGBOpeningFilter.h"
#import "GPUImageClosingFilter.h"
#import "GPUImageRGBClosingFilter.h"
#import "GPUImageColorPackingFilter.h"
#import "GPUImageSphereRefractionFilter.h"
#import "GPUImageMonochromeFilter.h" //单色
#import "GPUImageOpacityFilter.h" //不透明度
#import "GPUImageHighlightShadowFilter.h" //提亮阴影
#import "GPUImageFalseColorFilter.h" // 色彩替换（替换亮部和暗部色彩）
#import "GPUImageHSBFilter.h"
#import "GPUImageHueFilter.h" // 色度
#import "GPUImageGlassSphereFilter.h"
#import "GPUImageLookupFilter.h" //色彩调整
#import "GPUImageAmatorkaFilter.h"
#import "GPUImageMissEtikateFilter.h"
#import "GPUImageSoftEleganceFilter.h"
#import "GPUImageAddBlendFilter.h"
#import "GPUImageDivideBlendFilter.h"
#import "GPUImagePolkaDotFilter.h"
#import "GPUImageLocalBinaryPatternFilter.h"
#import "GPUImageColorLocalBinaryPatternFilter.h"
#import "GPUImageLanczosResamplingFilter.h"
#import "GPUImageAverageColor.h" //像素平均色值
#import "GPUImageSolidColorGenerator.h" //纯色
#import "GPUImageLuminosity.h" //亮度平均
#import "GPUImageAverageLuminanceThresholdFilter.h" //像素色值亮度平均，图像黑白（有类似漫画效果
#import "GPUImageWhiteBalanceFilter.h" // 白平衡
#import "GPUImageChromaKeyFilter.h" // 色度建
#import "GPUImageLowPassFilter.h"
#import "GPUImageHighPassFilter.h"
#import "GPUImageMotionDetector.h"
#import "GPUImageHalftoneFilter.h"
#import "GPUImageThresholdedNonMaximumSuppressionFilter.h"
#import "GPUImageHoughTransformLineDetector.h"
#import "GPUImageParallelCoordinateLineTransformFilter.h"
#import "GPUImageThresholdSketchFilter.h"
#import "GPUImageLineGenerator.h" //线条
#import "GPUImageLinearBurnBlendFilter.h"
#import "GPUImageGaussianBlurPositionFilter.h"
#import "GPUImagePixellatePositionFilter.h"
#import "GPUImageTwoInputCrossTextureSamplingFilter.h"
#import "GPUImagePoissonBlendFilter.h"
#import "GPUImageMotionBlurFilter.h"
#import "GPUImageZoomBlurFilter.h"
#import "GPUImageLaplacianFilter.h"
#import "GPUImageiOSBlurFilter.h"
#import "GPUImageLuminanceRangeFilter.h"
#import "GPUImageDirectionalNonMaximumSuppressionFilter.h"
#import "GPUImageDirectionalSobelEdgeDetectionFilter.h"
#import "GPUImageSingleComponentGaussianBlurFilter.h"
#import "GPUImageThreeInputFilter.h"
#import "GPUImageFourInputFilter.h"
#import "GPUImageWeakPixelInclusionFilter.h"
#import "GPUImageColorConversion.h"
#import "GPUImageColourFASTFeatureDetector.h"
#import "GPUImageColourFASTSamplingOperation.h"

