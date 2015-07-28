//
//  ViewController.h
//  PPHTMLImagePreviewDemo
//
//  Created by StarNet on 7/22/15.
//  Copyright (c) 2015 StarNet. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (nonatomic, retain) IBOutlet UIWebView* webView;

@property (nonatomic, retain) IBOutlet UITextField* urlTextField;

//显示预览图
@property (nonatomic, retain) IBOutlet UIImageView* imageView;

@end

