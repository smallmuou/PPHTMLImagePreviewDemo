# PPHTMLImagePreviewDemo

## 概述
该DEMO主要用于演示iOS APP中点击HTML的图片来实现本地预览，如下是演示图
![image](https://github.com/smallmuou/PPHTMLImagePreviewDemo/blob/master/PPHTMLImagePreviewDemo.gif)

## 原理阐述
### 1. 背景知识
在了解该原理之前，需要知道如下内容

* html中的点击动作一般都是通过javascript来实现的，如下面代码:
<pre>
var img = document.getElementById('test');
img.onclick = function() {
	alert("test");
}
</pre>
PS: 以上代码实现的是点击< img id="test">来弹出含`test`的提示框. 当然可以通过getElementsByTagName，getElementsByClassName获取标签元素

* javascript与objc交互

在iOS APP开发过程中，是通过UIWebView来加载html页面，因此javascript要与objc交互，桥梁应该就在UIWebview提供的API中，通过查找，发现如下一些接口:
<pre>
//objc 传参给javascript
- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script;

//javascript 传参给objc， 参数是存在于request中
 - (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
</pre>

### 2. 实现细节
* 在UIWebview加载完html后，调用stringByEvaluatingJavaScriptFromString来执行如下javascript代码，可以使用[javascript压缩工具](http://tool.lu/js/)压缩下
<pre>
function assignImageClickAction() {
	var imgs = document.getElementsByTagName('img');
	var length = imgs.length;
	for (var i = 0; i < length; i++) {
		img = imgs[i];
		img.onclick = function() {
			window.location.href = 'image-preview:' + this.src
		}
	}
}
assignImageClickAction();
</pre>

* 在webView:shouldStartLoadWithRequest:navigationType处理image-preview

## 许可
该代码遵循MIT许可.

## 联系方式
email: lvyexuwenfa100@126.com