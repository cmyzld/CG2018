# CG2018
本项目是南京大学图形学大作业，实现一个完整的图形系统，包含输出图元的生成，图形编辑，裁剪，图象保存，三维模型显示等。

----

## 已实现功能
![](https://github.com/cmyzld/CG2018/blob/master/screen/screen.png)
### 一. 绘制
##### 1. 直线 -- Bresenham算法
##### 2. 圆的 -- 中点圆算法
##### 3. 椭圆 -- 中点椭圆算法
##### 4. Brazier曲线 
##### 5. 多边形 
##### 6. 矩形

### 二. 填充
##### 1. 矩形填充
##### 2. 圆的填充
##### 3. 多边形填充 

### 三. 图形选中和编辑
##### 1. 图形选中
点击图形上的点(必须是图形上，封闭图形内部的点无效), 被选中的图形会显示关键点(如圆心，线段端点，曲线控制点等)，可以删除，编辑，填充，平移等。
##### 2. 编辑关键点
* 直线端点
* 拖拉圆上的点可以改变半径
* 椭圆外接矩形的顶点
* 多边形和矩形的顶点
* 曲线的控制点
##### 3. 删除图形

### 四. 图形基本变换
选中的图形可以进行如下基本变换
##### 1. 缩放
##### 2. 平移
##### 3. 旋转
只能支持左右旋转90度

### 五. 裁剪
##### 1. 线段裁剪 - 梁友栋-Barsky算法
##### 2. 矩形裁剪 - 求重叠区域
##### 3. 多边形裁剪 - Sutherland-Hodgeman算法

### 六. 保存
支持选中的单个图形的保存，以及全屏保存，可选择保存文件路径

### 七. 三维模型显示
