//
//  ViewController.m
//  QY_GPUImage_Demo
//
//  Created by ihefe－hulinhua on 16/6/28.
//  Copyright © 2016年 ihefe_hlh. All rights reserved.
//

#import "ViewController.h"
#import "GPUImage.h"

@interface ViewController ()
{
    GPUImageBrightnessFilter *brightnessFilter;// 亮度滤波
    GPUImageContrastFilter *contrastFilter; //对比度
    GPUImageExposureFilter *exposureFilter; //曝光滤波

    GPUImagePicture *staticPicture;
    UIImage *inputImage;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    // Do any additional setup after loading the view, typically from a nib.
    inputImage = [UIImage imageNamed:@"test.jpg"];
    staticPicture = [[GPUImagePicture alloc] initWithImage:inputImage smoothlyScaleOutput:YES];
    
    brightnessFilter = [GPUImageBrightnessFilter new];
    [brightnessFilter forceProcessingAtSize:inputImage.size];
    
    exposureFilter = [GPUImageExposureFilter new];
    [exposureFilter forceProcessingAtSize:inputImage.size];
    
    contrastFilter = [GPUImageContrastFilter new];
    [contrastFilter forceProcessingAtSize:inputImage.size];
    contrastFilter.contrast = 1;
    [self shouView];
    
}

- (IBAction)liangdu:(UISlider *)sender {
    brightnessFilter.brightness = sender.value - 0.5;
    [self shouView];
}

- (IBAction)baoguang:(UISlider *)sender {
    exposureFilter.exposure = sender.value;
    [self shouView];
}

- (IBAction)sedu:(UISlider *)sender {
    contrastFilter.contrast = sender.value;
    [self shouView];
}

- (void)shouView
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [staticPicture removeAllTargets];
        
        [staticPicture addTarget:brightnessFilter];
        [brightnessFilter addTarget:exposureFilter];
        [exposureFilter addTarget:contrastFilter];
        [contrastFilter useNextFrameForImageCapture];
        
        [staticPicture processImageWithCompletionHandler:^{
            dispatch_async(dispatch_get_main_queue(), ^{
                _imgView.image = [contrastFilter imageFromCurrentFramebuffer];
            });
            
        }];
        
    });
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
