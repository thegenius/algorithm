/***************************************************
*  作者：汪蔚                                      *
*  更新：2014-07-17                                *
****************************************************/
#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__
#include <math.h>
#include <cocos2d.h>
USING_NS_CC;

// 叉乘
float cross(Vec2 a, Vec2 b);

// 点乘
float dot(Vec2 a, Vec2 b);

// 两点之间距离
float getDistance(Vec2 p1, Vec2 p2);

// 给出 定点 和 一个圆 ，计算过定点的切线的切点坐标
bool getTangentPoint(Vec2 point,                  
					 Vec2 center, float radius,     
					 Vec2& tangentPoint1, Vec2& tangentPoint2);

// 计算点到直线的距离
float getDistanceToLine(Vec2 pointC, Vec2 linePointA, Vec2 linePointB);

// 计算点到线段的距离
float getDistanceToSegment(Vec2 pointC, Vec2 linePointA, Vec2 linePointB);

// 判断点是否在矩形中
// rectPoint1为左下角顶点 rectPoint2为右上角顶点
bool isRectContainPoint(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 point);

// 判定矩形和圆是有重叠
// rectPoint1为左下角顶点 rectPoint2为右上角顶点
bool isRectCircleOverlap(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 center, float radius);


#endif