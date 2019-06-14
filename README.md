#**README1.0**

###操作引导
`git clone git@github.com:gitsshylalala/mykdc.git`
克隆完成后
```
cd mykdc
make
```
目录介绍：
1. ./lib/  表示静态库目录，如果要以-lkdcapi方式使用，执行命令
    `cp ./lib/*.a /usr/lib`
2. ./item/ 目标文件集合。
3. ./include/ 头文件集合。

---
###项目介绍
本项目为基于C++的对称密钥分发平台客户端程序
目的是以客户端程序、函数接口的形式安全分发和保存用户对称密钥。
还有一个目的是完成鄙人的毕业设计。
同时用到开源有rapidjson、glog。还有我从脚本之家找的DES算法代码。
[rapidjson文档](http://rapidjson.org/zh-cn/)
[glog于git上代码](https://github.com/google/glog)
[脚本之家DES算法](https://www.jb51.net/article/98430.htm)

---
###使用方式
执行命令make后可以看到两个可执行程序。
其中client为客户端进程，可以执行程序以操作。
KdcApi_example为示例程序，详细代码在./example/下。

---
###注意事项
1. 不要自己修改配置文件。
2. 调用KDCAPI对象的加密手段是，底层对In的字符串进行了两次In.size()的内存开辟。如果输入数据块In过大建议自己攥写DES算法实现而非调用接口。
3. 有问题麻烦发给邮箱shihongyuhaha@outlook.com，感激不尽。

