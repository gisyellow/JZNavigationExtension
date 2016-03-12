// The MIT License (MIT)
//
// Copyright (c) 2015-2016 JazysYu ( https://github.com/JazysYu )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#import <UIKit/UIKit.h>

/// The "UINavigationController+JZExtension" category integrates some convenient functions and open some hide property
/// for UINavigationController, such as gives your UINavigationController a fullscreen interactivePopGestureRecognizer,
/// all you need is enable/disable "fullScreenInteractivePopGestureRecognizer" property for each ViewController.
/// If you have some ViewController which doesn't wants a navigation bar, you can set the "wantsNavigationBarVisible"
/// property to NO.
/// You can also adjust your navigationBar or toolbar's background alpha.
@interface UINavigationController (JZExtension)

/**
 *  @author JazysYu, 16-01-25 14:01:53
 *
 *  If YES, then you can have a fullscreen gesture recognizer responsible for popping the top view controller off the navigation stack, and the property is still "interactivePopGestureRecognizer", see more for "UINavigationController.h", Default is NO.
 */
@property (nonatomic, assign) BOOL jz_fullScreenInteractivePopGestureRecognizer NS_AVAILABLE_IOS(7_0);

/**
 *  @author JazysYu, 16-01-25 14:01:24
 *
 *  navigationBar's background alpha, when 0 your navigationBar will be invisable, default is 1. Animatable
 */
@property (nonatomic, assign) CGFloat jz_navigationBarBackgroundAlpha NS_AVAILABLE_IOS(7_0);

/**
 *  @author JazysYu, 16-01-25 14:01:57
 *
 *  Current navigationController's toolbar background alpha, make sure the toolbarHidden property is NO, default is 1. Animatable
 */
@property (nonatomic, assign) CGFloat jz_toolbarBackgroundAlpha NS_AVAILABLE_IOS(7_0);

/**
 *  @author JazysYu, 16-01-25 14:01:38
 *
 *  The view controller that is being popped when the interactive pop gesture recognizer's UIGestureRecognizerState is UIGestureRecognizerStateChanged.
 */
@property (nonatomic, readonly, strong) UIViewController *jz_interactivePopedViewController NS_AVAILABLE_IOS(7_0);

/**
 *  @author JazysYu, 16-03-12 16:03:12
 *
 *  Could use this propery to adjust navigation controller's operation, then do some logic.
 *
 */
@property (nonatomic, assign, readonly) UINavigationControllerOperation jz_operation;

/**
 *  @author JazysYu, 16-01-25 14:01:04
 *
 *  Change navigationBar to any size, if you want default value, then set to 0.f.
 */
@property (nonatomic, assign, readwrite) CGSize jz_navigationBarSize;

/**
 *  @author JazysYu, 16-01-25 14:01:06
 *
 *  Change toolBar to any size, if you want default value, then set to 0.f.
 */
@property (nonatomic, assign, readwrite) CGSize jz_toolbarSize;

/**
 *  @author JazysYu, 16-01-25 14:01:37
 *
 *  Return the gives view controller's previous view controller in the navigation stack.
 *
 */
- (UIViewController *)jz_previousViewControllerForViewController:(UIViewController *)viewController;

/**
 *  @author JazysYu, 16-01-25 14:01:20
 *
 *  Called at end of animation of push/pop or immediately if not animated.
 *
 */
- (void)jz_pushViewController:(UIViewController *)viewController animated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

/**
 *  @author JazysYu, 16-01-25 14:01:20
 *
 *  Called at end of animation of push/pop or immediately if not animated.
 *
 */
- (UIViewController *)jz_popViewControllerAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

/**
 *  @author JazysYu, 16-01-25 14:01:20
 *
 *  Called at end of animation of push/pop or immediately if not animated.
 *
 */
- (NSArray *)jz_popToRootViewControllerAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

/**
 *  @author JazysYu, 16-01-25 14:01:20
 *
 *  Called at end of animation of push/pop or immediately if not animated.
 *
 */
- (NSArray *)jz_popToViewController:(UIViewController *)viewController animated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

/**
 *  @author JazysYu, 16-01-25 14:01:20
 *
 *  Called at end of interactive pop gesture immediately. You could use poppedViewController/visibleViewController/interactivePopedViewController properties to decide what to do.
 *
 */
- (void)setJz_interactivePopGestureRecognizerCompletion:(void (^)(UINavigationController *, UIViewController *, BOOL))jz_interactivePopGestureRecognizerCompletion;

@end
