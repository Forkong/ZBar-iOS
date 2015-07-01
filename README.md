# ZBar-iOS

[ZBar](https://github.com/ZBar/ZBar)从2012年之后就没有更新过了，所以在iOS上，如果使用ZBar的话，那么ZBar默认提供的只有32位的静态库，当然我们可以直接下载到ZBar的源码,然后编译64位的版本，这很方便。

当我们有更深一层的需要的时候，我们可能会要求将ZBar的源码直接嵌入我们的项目中，而这个就是一个被剥离出来的ZBar-iOS部分。可以直接嵌入到项目中。

由于历史的悠久，ZBar在64位iOS下编译有大量的警告，我这里将Build Phases中的文件编译flag中加入了一些参数，默认不显示这些类型的警告。

由于在剥离后，在64位下编译有一些问题，我修改了部分内容，很少，我这就不写出了，但是并不影响大家使用。

当然，都已经是源码了，并且这个项目已死，大家可以直接修改，而不用担心升级更新的问题。

步骤：
1. 在你的项目中加入下面的库：
        libiconv.dylib
	CoreVideo.framework
	CoreMedia.framework
	AVFoundation.framework
2. 将ZBarSDK文件夹拖拽或者拷贝到你的工程目录下面
3. 参照ZBar官方给的[Demo](https://github.com/ZBar/ZBar/tree/master/iphone/examples)即可正常使用
